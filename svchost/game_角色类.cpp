#include "pch.h"
#include "game_角色类.h"
#include "base_内存读写.h"
#include "game_Util.h"


game_角色类::game_角色类():game_公共类(object_pointer)
{

	object_pointer = readInteger(__人物基址);
	//printf("123\n");
}


game_角色类::~game_角色类()
{
}


Pos game_角色类::GetPos()
{
	Pos _Pos;
	//DWORD pos_pointer = readInteger(readInteger(__人物基址) + __人物坐标偏移);
	_Pos.x = (int)readFloat(__角色坐标 - 4);
	_Pos.y = (int)readFloat(__角色坐标);
	_Pos.z = (int)readFloat(__角色坐标 + 4);
	return _Pos;
}



