#pragma once

class game_������
{
public:
	DWORD object_pointer = NULL;
	Pos pos;
	const char * name;
	DWORD HP;
	DWORD code;
	DWORD camp;
	DWORD type;
	game_������(DWORD dwObjectPointer = NULL);
	~game_������();
	Pos GetPos();
	const char * GetName();
	DWORD GetCode();
	DWORD GetCamp();
	DWORD GetHP();
	DWORD GetType();
};

