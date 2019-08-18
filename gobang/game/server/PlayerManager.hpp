#pragma once
#include <iostream>
#include "Player.hpp"
#include <unordered_map>
#include <utility>
#include "Log.hpp"
#include "Player.hpp"
#include <pthread.h>

#define DEFAUIT_ID 10000
using namespace std;

class PlayerManager{
private:
    std::unordered_map<uint32_t,Player> player_set;//用unordered_map将用户ID和用户个人信息映射起来
    uint32_t assign_id;//为用户分配ID
    pthread_mutex_t lock;
public:
    PlayerManager():assign_id(DEFAUIT_ID)
    {
        pthread_mutex_init(&lock,NULL);
    }
    void Lock()
    {
       pthread_mutex_lock(&lock);
    }
    void Unlock()
    {
        pthread_mutex_unlock(&lock);
    }
    uint32_t InsertPlayer(string &name, string &passwd)
    {
        Lock();
        uint32_t _id= assign_id++;
        Player p(name, passwd, _id);
        //player_set.insert(std::make_pair<uint32_t, Player>(id_, p));
        player_set.insert({_id, p});
        Unlock();
        LOG(INFO,"玩家插入成功...");
        return _id;
        
    }

    uint32_t SearchPlayer(uint32_t &id, string &passwd)
    {
        Lock();
        auto iter=player_set.find(id);
        if(iter == player_set.end()){
            LOG(WARNING,"查找用户失败...");
            Unlock();
            return 1;
        }

        Player &p = iter->second;
        if(p.Passwd()!=passwd){
            Unlock();
            LOG(WARNING,"密码错误...");
            return 2;
        }
        p.Online();
        Unlock();
        LOG(INFO,"Player Online Success...");
        return id;
    }


    void SetPlayStatus(uint32_t &one, uint32_t &two)
    {
        Lock();
        player_set[one].Playing();
        player_set[two].Playing();
        Unlock();
    }

    void SetPlayRoom(uint32_t &room_id, uint32_t &one, uint32_t &two)
    {
        Lock();
        player_set[one].SetRoom(room_id);
        player_set[two].SetRoom(room_id);
        Unlock();
    }

    void SetMatching(uint32_t &id)
    {
        Lock();
        player_set[id].Matching();
        Unlock();
    }

    void SetOnline(uint32_t &id)
    {
        Lock();
        player_set[id].Online();
        Unlock();
    }

    //拿到玩家的房间号
    uint32_t GetPlayerRoomId(uint32_t &id)
    {
         Lock();
        uint32_t _room_id= player_set[id].Room();
         Unlock();
        return _room_id;
    }
    int GetRate(uint32_t &id)
    {
        Lock();
        int rate = player_set[id].Rate();
        Unlock();
        return rate;
    }

    int Ready(uint32_t &id)
    {
       Lock();
       int st =  player_set[id].status();
       Unlock();
        return st;
    }
    ~PlayerManager()
    {
       pthread_mutex_destroy(&lock);
    }
};
