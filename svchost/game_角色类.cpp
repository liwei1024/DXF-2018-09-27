#include "pch.h"
#include "game_角色类.h"
#include "base_内存读写.h"
#include "game_Util.h"


game_角色类::game_角色类(DWORD dwObjectPointer):game_公共类(dwObjectPointer)
{

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

int game_角色类::取角色等级()
{
	int Retn = readInteger(__角色等级);
	return Retn;
}

int  game_角色类::取疲劳值()
{
	int 返回值;
	int 最小 = 解密(__当前疲劳);
	int 最大 = 解密(__最大疲劳);
	返回值 = 最大 - 最小;
	return 返回值;
}

