#include <rpc_server.h>
#include "Hall.hpp"

using namespace rest_rpc;
using namespace rpc_service;
#include <fstream>
using namespace std;

Hall GameHall;//游戏大厅——数据和方法集

uint32_t RpcRegister(connection* conn, string name, string passwd) {
	 return GameHall.Register(name,passwd);
}
uint32_t RpcLogin(connection* conn, uint32_t id, string passwd)
{
    return GameHall.Login(id, passwd);
}

bool RpcMatchAndWait(connection* conn,uint32_t id)
{
    return GameHall.PushIdInMatchPool(id);
}

bool RpcPlayerReady(connection* conn, uint32_t id)
{
    return GameHall.IsPlayerReady(id);
}

string RpcBoard(connection* conn, uint32_t room_id)
{
    return GameHall.GetPlayerBoard(room_id);
}

uint32_t RpcPlayerRoomId(connection* conn, uint32_t id)
{
    return GameHall.GetPlayerRoomId(id); 
}

char RpcPlayerPiece(connection* conn, uint32_t room_id, uint32_t id)
{
   return GameHall.GetPlayerPiece(room_id, id);
}

bool RpcIsMyTurn(connection* conn, uint32_t room_id, uint32_t id)
{
    return GameHall.IsMyTurn(room_id, id);
}

void RpcStep(connection* conn, uint32_t room_id, uint32_t id, int x, int y)
{
    return GameHall.Step(room_id, id, x, y);
}

char RpcJudge(connection* conn, uint32_t room_id, uint32_t id)
{
    return GameHall.Judge(room_id, id); 
}

bool RpcPopMatchPool(connection* conn, uint32_t id)
{
    return GameHall.PopIdMatchPool(id);
}
int main() {

	rpc_server server(9000, 4);
    LOG(INFO,"服务器初始化成功");

    server.register_handler("RpcRegister", RpcRegister);
    server.register_handler("RpcLogin", RpcLogin);
    server.register_handler("RpcMatchAndWait",RpcMatchAndWait);
    server.register_handler("RpcPlayerReady",RpcPlayerReady);
    server.register_handler("RpcPlayerRoomId",RpcPlayerRoomId);
    server.register_handler("RpcPlayerPiece",RpcPlayerPiece);
    server.register_handler("RpcBoard", RpcBoard);
    server.register_handler("RpcIsMyTurn",RpcIsMyTurn);
    server.register_handler("RpcStep", RpcStep);
    server.register_handler("RpcJudge",RpcJudge);
    server.register_handler("RpcPopMatchPool", RpcPopMatchPool);

    LOG(INFO,"方法注册完毕");
    LOG(INFO,"服务器已启动");
    GameHall.InitHall();

	server.run();
    std::string str;
   	std::cin >> str;
}
