#pragma once

#include <iostream>
#include <rpc_client.hpp>
#include <chrono>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "codec.h"

using namespace std;
using namespace std::chrono_literals;
using namespace rest_rpc;
using namespace rest_rpc::rpc_service;

//用户注册
uint32_t Register(const string &ip, const int &port,\
        string &name,string &passwd, uint32_t &id)
{
    cout<<"请输入昵称:>";
    cin>>name;
    cout<<"请输入你的密码:>";
    cin>>passwd;
    string passwd_;
    cout<<"请再次确认密码:>";
    cin>>passwd_;
    if(passwd != passwd_)
    {
        cout<<"密码不匹配！"<<endl;
        return 1;
    }
    try{
        rpc_client client(ip,port);
        bool r=client.connect();
        if(!r){
            std::cout<<"连接超时"<<std::endl;
            return 2;
        }
       id = client.call<uint32_t>("RpcRegister", name, passwd);

    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}
//用户登录  ID，密码
uint32_t Login(const string &ip,const int &port)
{
    uint32_t id;
    string passwd;

    std::cout<<"请输入你的登录ID：";
    cin>>id;

    cout<<"请输入登录密码：";
    cin>>passwd;
    uint32_t result=0;
   try{
     rpc_client client(ip, port);
     bool r = client.connect();
     if(!r){
         std::cout<<"连接超时！"<<std::endl;
         return 3;
     }
     result=client.call<uint32_t>("RpcLogin", id, passwd);
   
   }
   catch(const std::exception& e){
       std::cout<<e.what()<<std::endl;
   }
   return result;
}

//匹配
bool PushMatchPool(string &ip, int &port,uint32_t &id)//将ID放到匹配池中
{
    try{
        rpc_client client(ip, port);
        bool r=client.connect();
        if(!r){
            std::cout<<"connect timeout"<<std::endl;
            return 3;
        }
       return client.call<bool>("RpcMatchAndWait",id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}

int CheckReady(string &ip,int &port,uint32_t &id)
{
   try{
       rpc_client client(ip,port);
       bool r = client.connect();
       if(!r){
           std::cout<<"connect timeout"<<std::endl;
           return 3;
       }
       return client.call<int>("RpcPlayerReady", id);
   }
   catch(const std::exception& e)
   {
       std::cout<<e.what()<<endl;
   }
}
bool PopMatchPool(string &ip, int &port, uint32_t &id)
{
    try{
        rpc_client client(ip,port);//短链接，操作一次就断开
        bool r = client.connect();
        if(!r){
            std::cout<<"connect timeout"<<std::endl;
            return false;
        }
        return client.call<bool>("RpcPopMatchPool",id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    return false;
}

bool Match(string &ip, int &port, uint32_t &id)//匹配
{
    PushMatchPool(ip,port,id);
    int count = 20;
    while(1){
        int result = CheckReady(ip, port, id);
        if(result == 3){
            cout<<"匹配成功啦！！"<<endl;
            return true;
        }else if(result == 1){
            cout<<"匹配失败啦!"<<endl;
            //PopMatchPool(ip,port,id);
            return false;
        }else{
          printf("匹配中.............. %2d\r", count--);
          fflush(stdout);
          if(count < 0)
          {
            cout<<endl;
            cout<<"匹配超时!!"<<endl;
            PopMatchPool(ip,port,id);
            //客户端从匹配池中拿走ID
            break;
          }
          sleep(1);//这里虽然是死循环，但是服务器是会超时的
        }
    }
    return false;
}
//获得棋盘
int GetBoard(string &ip, int &port, uint32_t &room_id, string &board)
{
    try{
         rpc_client client(ip, port);
         bool r = client.connect();
         if(!r){
            std::cout<<"connect timeout..."<<endl;
            return 3;
         }
         board = client.call<string>("RpcBoard", room_id);
    }
    catch(const std::exception& e){
      std::cout<<e.what()<<std::endl;
}
}

//获得房间号
uint32_t GetMyRoomId(string &ip, int &port, uint32_t &id)
{
    try{
        rpc_client client(ip, port);
        bool r=client.connect();
        if(!r){
            std::cout<<"connect timeout"<<std::endl;
            return 3;
        }
        return client.call<uint32_t>("RpcPlayerRoomId", id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}

//获得棋子
char GetMyPiece(string &ip, int &port, uint32_t &room_id, uint32_t &id)
{
    try{
        rpc_client client(ip, port);
        bool r = client.connect();
        if(!r){
            std::cout<<"connect timeout"<<endl;
            return 3;
        }
        return client.call<char>("RpcPlayerPiece",room_id, id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}
//显示棋盘
void ShowBoard(string &board)
{
    //行
    cout<<"    ";
    for(auto i=1;i<=5;i++)
    {
        cout<<i<<"   ";
        
    }
    cout<<endl;
    for(auto i=0;i<=5;i++)
    {
        cout<<"----";
    }
    cout<<endl;
    //列
    int size=board.size();
    int basic_size = 5;
    for(auto i = 0;i<size/basic_size;i++)
    {
        cout<<i+1<<" |";
       for(auto j = 0; j<basic_size;j++)
       {
           cout<<" "<<board[i*basic_size+j]<<" |";
       }
        cout<<endl;
        for(auto i=0; i<=5; i++)
        {
            cout<<"----";
        }
        cout<<endl;
    }
}

//当前该谁走
bool IsMyTurn(string &ip, int &port, uint32_t &room_id, uint32_t &id)
{
    try{
        rpc_client client(ip, port);
        bool r = client.connect();
        if(!r){
            std::cout<<"connect timeout"<<endl;
            return 3;
        }
        return client.call<bool>("RpcIsMyTurn",room_id,id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    return false;
}
//落子位置是否正确
bool PosIsRight(string &board, int x, int y)
{
    int pos=(x-1)*5+(y-1);
    return board[pos]==' '? true:false;
}
//步骤
int Step(string &ip, int &port, uint32_t room_id, uint32_t &id, int x, int y)
{
    try{
        rpc_client client(ip, port);
        bool r = client.connect();
        if(!r){
            std::cout<<"connect timeout"<<std::endl;
            return 3;
        }
       client.call<void>("RpcStep", room_id, id, x-1, y-1);
       return 0;
    }
    catch(const std::exception& e){
        std::cout<< e.what()<<std::endl;
    }


}

//判断
char Judge(string &ip, int &port, uint32_t &room_id,uint32_t &id)
{
    try{
        rpc_client client(ip, port);
        bool r = client.connect();
        if(!r){
            std::cout<<"connect timeout"<<std::endl;
            return 3;
        }
        return client.call<char>("RpcJudge",room_id, id);
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}

//开始玩游戏
void PlayGame(string &ip, int &port, uint32_t &id)
{
    int x,y;
    char result='N';
    string board;

    //匹配成功后玩家应当知道自己的执子颜色和房间号，又通过房间号建立一个接口来查看自己所执子的颜色
    //这里通过房间号找到对应房间，再通过自己的ID来判断当前是否该我走。
    uint32_t room_id = GetMyRoomId(ip, port, id);
    cout<<"client room_id :"<<room_id<<endl;
    if(room_id < 1024)
    {
        return;
    }
    cout<<"房间号"<<room_id<<endl;
    char piece=GetMyPiece(ip, port, room_id, id);
    cout<<"piece:"<<piece<<endl;
  
   for(; ;)
   {
       system("clear");
      GetBoard(ip,port,room_id, board);
      ShowBoard(board);
      
      if(result=Judge(ip, port, room_id,id) != 'N')
      {
         break;
      }
      if(!IsMyTurn(ip, port, room_id, id))
      {
          cout<<"对方正在思考，请稍等。。。"<<endl;
          sleep(1);
          continue;
      }
         cout<<"请输入落子位置：>";
         cin >>x>>y;
         if(x>=1 && x<=5 && y>=1 && y<=5)
         {
             if(!PosIsRight(board,x,y))
             {
                 cout<<"这里已经有棋子了哦，请重新落子！"<<endl;
             }
             else
             {
                 Step(ip, port, room_id, id, x, y);//rpc完成的
                 result=Judge(ip, port, room_id, id);
                  if(result != 'N')//说明游戏已经有结果了
                  {
                      break;
                  }
                  //否则
             }
         }
         else
         {
             cout<<"输入的位置有误，请重新输入！"<<endl;
         }
   } 

     if(result == 'E')
     {
       cout<<"恭喜你们，是平局哦！"<<endl;
     }
     else if(result == piece)
     {
         cout<<"你赢了啦，真是太厉害了！"<<endl;
     }
     else
     {
         cout<<"这局你输了，再来一局吗？"<<endl;
     }
}

void Game(string &ip, int &port, uint32_t &id)
{

    //登录注册完毕，进入游戏
    int select = 0;
    volatile bool quit = false;
    while(!quit)
    {
    cout<<"############################################"<<endl;
    cout<<"###### 1.匹配                  2.退出 ######"<<endl;
    cout<<"############################################"<<endl;
    cout<<"请选择：";
    cin>>select;

    switch(select)
    {
        //进入匹配
        case 1:
            {
                if(Match(ip,port,id))
                {
                    //匹配成功，开始游戏
                    PlayGame(ip, port, id);
                    
                }
                else
                {
                  cout<<"太遗憾了，匹配失败！请重试一次"<<endl;
                }
            }
            break;
         //选择退出
        case 2:
            quit = true;
            break;
        default:
            cout<<"输入不正确哦，请重新选择！"<<endl;
            break;
    }
    }
}
