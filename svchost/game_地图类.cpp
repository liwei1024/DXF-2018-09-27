#include "pch.h"
#include "game_地图类.h"
#include "game_Util.h"
#include "base_内存读写.h"

using namespace std;

game_地图类::game_地图类(DWORD dwObjectPointer)
{
	首地址 = readInteger(readInteger(readInteger(__人物基址) + __地图偏移) + __首地址);
	尾地址 = readInteger(readInteger(readInteger(__人物基址) + __地图偏移) + __尾地址);
	怪物数量 = (尾地址 - 首地址) / 4;
}


game_地图类::~game_地图类()
{
}

const char *game_地图类::GetName()
{

}

vector<int> game_地图类::地图通道()
{

}

宽高 game_地图类::获取宽高()
{

}

bool game_地图类::是否已开门()
{

}

bool game_地图类::是否BOSS房间()
{

}

bool game_地图类::是否已通关()
{

}

vector<int> game_地图类::取怪物列表()
{

}