#include "pch.h"
#include "game_��ɫ��.h"
#include "base_�ڴ��д.h"
#include "game_Util.h"


game_��ɫ��::game_��ɫ��():game_������(object_pointer)
{

	object_pointer = readInteger(__�����ַ);
	//printf("123\n");
}


game_��ɫ��::~game_��ɫ��()
{
}


Pos game_��ɫ��::GetPos()
{
	Pos _Pos;
	//DWORD pos_pointer = readInteger(readInteger(__�����ַ) + __��������ƫ��);
	_Pos.x = (int)readFloat(__��ɫ���� - 4);
	_Pos.y = (int)readFloat(__��ɫ����);
	_Pos.z = (int)readFloat(__��ɫ���� + 4);
	return _Pos;
}



