#include "pch.h"
#include "game_��ͼ��.h"
#include "game_Util.h"
#include "base_�ڴ��д.h"
#include "game_������.h"
#include "game_��Ʒ��.h"
#include "base_Util.h"

using namespace std;

game_��ͼ��::game_��ͼ��(DWORD dwObjectPointer)
{
	�׵�ַ = readInteger(readInteger(readInteger(__�����ַ) + __��ͼƫ��) + __�׵�ַ);
	β��ַ = readInteger(readInteger(readInteger(__�����ַ) + __��ͼƫ��) + __β��ַ);
	���� = (β��ַ - �׵�ַ) / 4;
}


game_��ͼ��::~game_��ͼ��()
{
}

const char *game_��ͼ��::GetName()
{

}

vector<int> game_��ͼ��::��ͼͨ��()
{

}

��� game_��ͼ��::��ȡ���()
{

}

bool game_��ͼ��::�Ƿ��ѿ���()
{

}

bool game_��ͼ��::�Ƿ�BOSS����()
{

}

bool game_��ͼ��::�Ƿ���ͨ��()
{

}

void game_��ͼ��::����()
{
	DWORD object_pointer;
	string str;
	for (size_t i = ����; i >= 0; i--)
	{
		object_pointer = readInteger(�׵�ַ + 4 * i);
		game_������ _game_������(object_pointer);
		str += "��ַ:" + IntToHex(object_pointer);
		str += "����:" + IntToHex(_game_������.code);
		str += "��Ӫ:" + IntToHex(_game_������.camp);
		str += "Ѫ��:" + IntToHex(_game_������.HP);
		str += "λ��:" + PosToString(_game_������.pos);
		str += "\n";
		��ɫ��ӡ("%s", str.c_str());
	}
}

vector<DWORD> game_��ͼ��::ȡ�����б�()
{
	vector<DWORD> �����б�;
	DWORD object_pointer;
	for (size_t i = ����; i >= 0; i--)
	{
		object_pointer = readInteger(�׵�ַ + 4 * i);
		game_������ _game_������(object_pointer);
		if (_game_������.HP > 0 || _game_������.camp > 0)
		{
			if (_game_������.type == 529 || _game_������.type == 273 || _game_������.type == 545)
			{
				�����б�.insert(�����б�.end(), object_pointer);
			}
		}
	}
	return �����б�;
}

bool game_��ͼ��::�Ƿ��й���()
{
	DWORD object_pointer;
	for (size_t i = ����; i >= 0; i--)
	{
		object_pointer = readInteger(�׵�ַ + 4 * i);
		game_������ _game_������(object_pointer);
		if (_game_������.camp > 0)
		{
			if (_game_������.type == 529 || _game_������.type == 273 || _game_������.type == 545)
			{
				if (_game_������.HP > 0 || _game_������.code == 8104 || _game_������.code == 817)
				{
					return true;
				}
			}
		}
	}
	return false;
}

