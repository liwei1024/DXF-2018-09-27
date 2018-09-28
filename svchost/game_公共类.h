#pragma once

class game_公共类
{
public:
	DWORD object_pointer = NULL;
	Pos pos;
	const char * name;
	DWORD HP;
	DWORD code;
	DWORD camp;
	DWORD type;
	game_公共类(DWORD dwObjectPointer = NULL);
	~game_公共类();
	Pos GetPos();
	const char * GetName();
	DWORD GetCode();
	DWORD GetCamp();
	DWORD GetHP();
	DWORD GetType();
};

