#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "Room.hpp"
#include <pthread.h>

#define ROOM_ID 1024

using namespace std; 

class RoomManager{
   private:
       unordered_map<uint32_t, Room> room_set;
       uint32_t assign_id;
       pthread_mutex_t lock;
   public:
       RoomManager():assign_id(ROOM_ID)
       {
           pthread_mutex_init(&lock, NULL);
       }

       void Lock()
       {
           pthread_mutex_lock(&lock);
       }
       void Unlock()
       {
           pthread_mutex_unlock(&lock); 
       }
       uint32_t CreateRoom(uint32_t &one, uint32_t &two)
       {
           Room r(one, two);
           Lock();
           uint32_t id=assign_id++;
           room_set.insert({id, r});
           Unlock();
           return id;
       }
       //拿到棋盘
       void GetBoard(uint32_t &room_id, string &_board)
       {
          Lock();
          room_set[room_id].Board(_board);
          Unlock();
       }

       //拿到棋子
       char GetPlayerPiece(uint32_t &room_id, uint32_t &id)
       {
           Lock();
           char st = room_set[room_id].Piece(id);
           Unlock();
           return st;
       }

       //该谁走
       bool IsMyTurn(uint32_t &room_id, uint32_t &id)
       {
           Lock();
           bool is_my_turn =  room_set[room_id].IsMyTurn(id);
           Unlock();
           return is_my_turn;
       }

       void Step(uint32_t &room_id, uint32_t &id, int &x, int &y)
       {
           Lock();
           room_set[room_id].Step(id,x,y);
           Unlock();
       }

       char Judge(uint32_t &room_id, uint32_t &id)
       {
           Lock();
          char res = room_set[room_id].GameResult(id);
          Unlock();
          return res;
       }
       ~RoomManager()
       {
           pthread_mutex_destroy(&lock);
       }
};
