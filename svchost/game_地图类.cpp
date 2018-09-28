#include "pch.h"
#include "game_地图类.h"
#include "game_Util.h"
#include "base_内存读写.h"
#include "game_怪物类.h"
#include "game_物品类.h"
#include "base_Util.h"

using namespace std;

game_地图类::game_地图类()
{
	首地址 = readInteger(readInteger(readInteger(__人物基址) + __地图偏移) + __首地址);
	尾地址 = readInteger(readInteger(readInteger(__人物基址) + __地图偏移) + __尾地址);
	数量 = (尾地址 - 首地址) / 4;
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

void game_地图类::遍历()
{
	DWORD object_pointer;
	string str;
	
	for (DWORD i = 0; i < 数量; i++)
	{
		object_pointer = readInteger(首地址 + 4 * i);
		game_怪物类 _game_怪物类(object_pointer);
		str += "地址:" + FormatString("0x%8x", object_pointer);
		str += "\t代码:" + FormatString("%8d", _game_怪物类.code); 
		str += "\t类型:" + FormatString("%8d", _game_怪物类.type);
		str += "\t阵营:" + FormatString("%8d", _game_怪物类.camp);
		str += "\t血量:" + FormatString("%16d", _game_怪物类.HP);
		str += "\t位置:" + PosToString(_game_怪物类.pos);
		str += "\t名称:" + FormatString("%s",_game_怪物类.name);
		str += "\n";
		青色打印("%s", str.c_str());
		str.clear();
	}
}

vector<DWORD> game_地图类::取怪物列表()
{
	vector<DWORD> 怪物列表;
	DWORD object_pointer;
	for (size_t i = 数量; i >= 0; i--)
	{
		object_pointer = readInteger(首地址 + 4 * i);
		game_怪物类 _game_怪物类(object_pointer);
		if (_game_怪物类.HP > 0 || _game_怪物类.camp > 0)
		{
			if (_game_怪物类.type == 529 || _game_怪物类.type == 273 || _game_怪物类.type == 545)
			{
				怪物列表.insert(怪物列表.end(), object_pointer);
			}
		}
	}
	return 怪物列表;
}

bool game_地图类::是否有怪物()
{
	DWORD object_pointer;
	for (size_t i = 数量; i >= 0; i--)
	{
		object_pointer = readInteger(首地址 + 4 * i);
		game_怪物类 _game_怪物类(object_pointer);
		if (_game_怪物类.camp > 0)
		{
			if (_game_怪物类.type == 529 || _game_怪物类.type == 273 || _game_怪物类.type == 545)
			{
				if (_game_怪物类.HP > 0 || _game_怪物类.code == 8104 || _game_怪物类.code == 817)
				{
					return true;
				}
			}
		}
	}
	return false;
}

