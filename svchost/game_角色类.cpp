#include "pch.h"
#include "game_��ɫ��.h"
#include "base_�ڴ��д.h"
#include "game_Util.h"


game_��ɫ��::game_��ɫ��(DWORD dwObjectPointer):game_������(dwObjectPointer)
{

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

int game_��ɫ��::ȡ��ɫ�ȼ�()
{
	int Retn = readInteger(__��ɫ�ȼ�);
	return Retn;
}

int  game_��ɫ��::ȡƣ��ֵ()
{
	int ����ֵ;
	int ��С = ����(__��ǰƣ��);
	int ��� = ����(__���ƣ��);
	����ֵ = ��� - ��С;
	return ����ֵ;
}

