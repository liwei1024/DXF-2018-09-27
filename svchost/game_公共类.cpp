#include "pch.h"
#include "game_������.h"
#include "base_�ڴ��д.h"


game_������::game_������(DWORD dwObjectPointer)
{
	object_pointer = dwObjectPointer;
	type = GetType();
	pos = GetPos();
	name = GetName();
	code = GetCode();
	camp = GetCamp();
	HP = GetHP();
	
}


game_������::~game_������()
{
}

// ��ȡλ��
Pos game_������::GetPos()
{
	Pos _Pos;
	DWORD pos_pointer = readInteger(readInteger(__�����ַ) + __����ƫ��);
	_Pos.x = (int)readFloat(pos_pointer + 0x10);
	_Pos.y = (int)readFloat(pos_pointer + 0x14);
	_Pos.z = (int)readFloat(pos_pointer + 0x18);
	return _Pos;
}

//��ȡ����
const char *game_������::GetName()
{
	const char * name = "";
	name = readString(readInteger(object_pointer + __����ƫ��),100);
	return name;
}

// ��ȡ����
DWORD game_������::GetCode()
{
	DWORD code = NULL;
	code = readInteger(object_pointer + __����ƫ��);
	return code;
}

// ��ȡ��Ӫ
DWORD game_������::GetCamp()
{
	DWORD camp = NULL;
	camp = readInteger(object_pointer + __��Ӫƫ��);
	return camp;
}

// ��ȡѪ��
DWORD game_������::GetHP()
{
	DWORD HP = NULL;
	HP = readInteger(object_pointer + __Ѫ��ƫ��);
	return HP;
}

// ��ȡ����
DWORD game_������::GetType()
{
	DWORD type = NULL;
	type = readInteger(object_pointer + __����ƫ��);
	return type;
}