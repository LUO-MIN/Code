#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include "PlayerManager.hpp"
#include "RoomManager.hpp"
using namespace std;
#define MATCH_LEVEL 101   //数组大小与胜率范围相应


class Hall{
    private:
        PlayerManager pm;  //用户管理员
        RoomManager rm;
        vector<vector<uint32_t> > match_pool;  //匹配池
        int match_num;
        pthread_mutex_t match_lock;//匹配锁
        pthread_cond_t match_cond;//可以写一个简单的生产者消费者模型
    public:
        Hall():match_pool(MATCH_LEVEL),match_num(0)
        {
        }

        int MatchNum(){
           return match_num;
        }
        
        void DecMatchNum()
        {
            match_num--;
        }
        void IncMatchNum(){
           match_num++;
        }
        void ResetMatchNum(){
           match_num=0;
        }
        
//将所有的ID放到id_list中
        void GetAllMatchId(vector<uint32_t> &id_list)
        {
            for(auto i=MATCH_LEVEL-1; i>=0; i--)
            {
                auto &v=match_pool[i];
                if(v.empty()){
                   continue;
                }
                for(auto it=v.begin(); it !=v.end(); it++){
                     id_list.push_back(*it);
                }
            }
        }
        
//对匹配池加锁解锁
        void LockMatchPool()
        {
            pthread_mutex_lock(&match_lock);
        }
        void UnlockMatchPool()
        {
            pthread_mutex_unlock(&match_lock);
        }

//线程等待
        void ServiceWait()
        {
           pthread_cond_wait(&match_cond,&match_lock);
        }
//线程唤醒
        void ServiceWakeup()
        {
            pthread_cond_signal(&match_cond);
        }

//注册
        uint32_t Register(string &name, string &passwd)
        {
            return pm.InsertPlayer(name, passwd);
        }
//登录
        uint32_t Login(uint32_t &id, string &passwd)
        {
            return pm.SearchPlayer(id, passwd);
        }

//将ID放到匹配池里
        bool PushIdInMatchPool(uint32_t &id)
        {
            LOG(INFO,"玩家信息放入匹配池...");
            pm.SetMatching(id);//把ID放到匹配池的时候，同时将用户的状态修改成匹配状态
            
            int rate=pm.GetRate(id);
            cout<<"胜率"<<rate<<endl;
            LockMatchPool();
            auto &v = match_pool[rate];
            auto it = v.begin();
            for(; it!=v.end();it++){
                if(*it == id){
                    return false;//说明匹配池中已经有ID，说明匹配过了
                }
            }
           //否则将新的id放到匹配池里
            v.push_back(id);
            IncMatchNum();
            UnlockMatchPool();
            ServiceWakeup();//这里重新唤醒匹配线程，进行下一轮的匹配
            //走到这里说明ID已经放到匹配池了
            return true;
            //return pm.PlayerWait(id);//玩家等待匹配

        }
//将ID从匹配池移出
        bool PopIdMatchPool(uint32_t &id)
        {
            LockMatchPool();
           // MatchPoolClear(id);
        //把自己的ID移走，就要获得胜率,找到自己的位置，一一移除
          int rate = pm.GetRate(id);
          auto &v= match_pool[rate];
          for(auto it = v.begin();it != v.end();it++)
          {
              if(*it== id){
              v.erase(it);//因为删除之后不再会有遍历。所以不存在迭代器失效的问题
              break;
              }
          }
            DecMatchNum();
            UnlockMatchPool();
            pm.SetOnline(id);
            return true;
        }

//完成一次匹配，清空匹配池，使用与临时对象交换方法，使匹配池保持初始状态
        void MatchPoolClear(uint32_t &id)
        {
            LOG(INFO,"匹配池被清空...");
            for(auto i=MATCH_LEVEL-1;i >= 0;i--)
            {
                auto &v=match_pool[i];
                if(v.empty())
                {
                    continue;
                }
                vector<uint32_t>().swap(v);
            }
            ResetMatchNum();//重置匹配数
            if(id >= 10000){
              pm.SetOnline(id);//last
            }
        }
 

        int IsPlayerReady(uint32_t &id)
        {
            return pm.Ready(id);
        }

        void GamePrepare(uint32_t &one, uint32_t &two)
        {
             pm.SetPlayStatus(one, two);//修改两个玩家的状态
             uint32_t room_id = rm.CreateRoom(one, two);//为匹配好的玩家创建房间,并且将房间号返回
             pm.SetPlayRoom(room_id, one, two);//设置游戏房间
             cout<<"debug: 房间号: "<<room_id <<endl;
             //pm.SignalPlayer(one, two);//唤醒客户端/玩家
        }


//检测ID的匹配线程，当match_num>2时，启动
       static void *MatchService(void *arg)
           //注意MatchService是成员函数，所以它有两个参数，另一个是this指针，
           //但是这时候我们不能让它带this指针，所以加上static，但是static无法访问成员函数或者成员变量
        {
            pthread_detach(pthread_self());//将线程分离
            Hall *hp= (Hall*)arg;

            while(1){//使用循环的原因：匹配线程在匹配一次之后就退出了，为了保证它一直能够完成匹配任务，加循环控制它

                uint32_t last = 0;
            hp->LockMatchPool();
            while(hp->MatchNum() < 2)//有可能在检测num的时候，别的线程也可能也在检测，所以num是临界资源
            {
                 LOG(INFO,"服务线程开始等待...");
                //匹配数不够，匹配线程还需要等待
                  hp->ServiceWait();
            }

            //匹配数大于2，可以进行匹配
              LOG(INFO,"服务线程被唤醒..");
              vector<uint32_t> id_list;//实现胜率相近匹配，另外的一个vector
              hp->GetAllMatchId(id_list);
              int num=id_list.size();
              if(num & 1)
              {
                  last = id_list[id_list.size()-1];
                  num &= (~1);//保证最低位都是0，且都是偶数
              }
              else
              {
                  last = 0;
              }
          
          for(auto i=0;i<num; i+=2)
          {
              uint32_t player_one=id_list[i];
              uint32_t player_two=id_list[i+1];//下标连续的匹配，实现胜率相同或相近匹配
              hp->GamePrepare(player_one, player_two);

          }
          hp->MatchPoolClear(last);
          hp->UnlockMatchPool();
        }
    }

       void InitHall()
       {

           pthread_mutex_init(&match_lock,NULL);
           pthread_cond_init(&match_cond,NULL);

           pthread_t tid;
           pthread_create(&tid,NULL,MatchService,this);
       }


//拿到用户的棋盘
      string GetPlayerBoard(uint32_t &room_id)
      {
          string board;
         // uint32_t room_id=pm.GetPlayerRoomId(id);
          rm.GetBoard(room_id,board);
          return board;
      }

//获得用户的房间号
      uint32_t GetPlayerRoomId(uint32_t &id)
      {
          return pm.GetPlayerRoomId(id);
      }

//获得用户棋子
      char GetPlayerPiece(uint32_t &room_id, uint32_t &id)
      {
         return rm.GetPlayerPiece(room_id, id);
      }

//该谁走
      bool IsMyTurn(uint32_t &room_id, uint32_t &id)
      {
          return rm.IsMyTurn(room_id, id);
      }

      void Step(uint32_t &room_id, uint32_t &id, int x, int y)
      {
          return rm.Step(room_id, id,x,y);
      }

      char Judge(uint32_t &room_id,uint32_t &id)
      {
          return rm.Judge(room_id, id);
      }
    

        ~Hall()
        {
            pthread_mutex_destroy(&match_lock);
            pthread_cond_destroy(&match_cond);
        }
};
