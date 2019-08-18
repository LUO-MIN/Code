#pragma once

#include <iostream>
#include <string>

#define SIZE 5
#define BLACK 'X'
#define WHITE 'O'

using namespace std;

class Room{
    private:
       uint32_t one;//'X'
       uint32_t two;//'O'
       char piece[2];
       uint32_t current;//当前该哪个用户走
       char board[SIZE][SIZE];
       char result;// X O E(平局) N(继续走)

       pthread_mutex_t lock;
    public:
       Room()
       {
       }
       Room(uint32_t &id1, uint32_t &id2):one(id1),two(id2)
       {
           piece[0]='X';
           piece[1]='O';
           memset(board,' ', sizeof(board));
           result = 'N';
           current=one;
           pthread_mutex_init(&lock, NULL);
       }

       //创建棋盘
       void Board(string &_board)
       {
           
           for(auto i=0;i<SIZE;i++)
           {
               for(auto j=0;j<SIZE;j++)
               {
                   _board.push_back(board[i][j]);

               }
           }
       }

       char Piece(uint32_t &id)
       {
           int pos = (id == one? 0 : 1 );
           return piece[pos];
       }

       //是否该我走
       bool IsMyTurn(uint32_t &id)
       {
           return id == current ? true : false;
       }

       void Step(uint32_t &id, int &x, int &y)
       {
           if(current == id){

           int pos = (id==one? 0:1);
           board[x][y]=piece[pos];
           current =(id==one?two:one);
           result = Judge();
           }           
       }
       char GameResult(uint32_t &id)
       {
           return result;
       }
       char Judge()
       {
           //判断输赢的方法：行，列，正对角线，副对角线
           int row = SIZE;
           int col = SIZE;
           //判断行
           for(auto i=0;i<row;i++)
           {
               if(board[i][0] != ' ' && 
                  board[i][0] != board[i][1] && \
                  board[i][1] != board[i][2] && \
                  board[i][2] != board[i][3] && \
                  board[i][3] != board[i][4] )
               {
                    return board[i][0];
               }
           }
           //判断列
           for(auto i=0;i<col; i++)
           {
               if(board[0][i] != ' ' && \
                  board[0][i] != board[1][i] && \
                  board[1][i] != board[2][i] && \
                  board[2][i] != board[3][i] && \
                  board[3][i] != board[4][i])
               {
                   return board[0][i];
               }
           }

           //判断正对角线
           if(board[0][0] != ' ' && \
              board[0][0] == board[1][1] && \
              board[1][1] == board[2][2] && \
              board[2][2] == board[3][3] && \
              board[3][3] == board[4][4])
           {
               return board[0][0];
           }

          //判断副对角线
           if(board[0][0] != ' ' && \
              board[0][4] == board[1][3] && \
              board[1][3] == board[2][2] && \
              board[2][2] == board[3][1] && \
              board[3][1] == board[4][0])
           {
               return board[0][4];
           }

           //判断棋盘是否满了
           for(auto i=0;i<row;i++)
           {
              for(auto j=0;j<col;j++)
              {
                  if(board[i][j] = ' '){
                  return 'N';
                  }
              }
           }
           return 'E';
       }
       ~Room()
       {
           pthread_mutex_destroy(&lock);
       }

};
