#include "pch.h"
#include "game_公共类.h"
#include "base_内存读写.h"


game_公共类::game_公共类(DWORD dwObjectPointer)
{
	object_pointer = dwObjectPointer;
	type = GetType();
	pos = GetPos();
	name = GetName();
	code = GetCode();
	camp = GetCamp();
	HP = GetHP();
	
}


game_公共类::~game_公共类()
{
}

// 获取位置
Pos game_公共类::GetPos()
{
	Pos _Pos;
	DWORD pos_pointer = readInteger(readInteger(__人物基址) + __坐标偏移);
	_Pos.x = (int)readFloat(pos_pointer + 0x10);
	_Pos.y = (int)readFloat(pos_pointer + 0x14);
	_Pos.z = (int)readFloat(pos_pointer + 0x18);
	return _Pos;
}

//获取名称
const char *game_公共类::GetName()
{
	const char * name = "";
	name = readString(readInteger(object_pointer + __名称偏移),100);
	return name;
}

// 获取代码
DWORD game_公共类::GetCode()
{
	DWORD code = NULL;
	code = readInteger(object_pointer + __代码偏移);
	return code;
}

// 获取阵营
DWORD game_公共类::GetCamp()
{
	DWORD camp = NULL;
	camp = readInteger(object_pointer + __阵营偏移);
	return camp;
}

// 获取血量
DWORD game_公共类::GetHP()
{
	DWORD HP = NULL;
	HP = readInteger(object_pointer + __血量偏移);
	return HP;
}

// 获取类型
DWORD game_公共类::GetType()
{
	DWORD type = NULL;
	type = readInteger(object_pointer + __类型偏移);
	return type;
}