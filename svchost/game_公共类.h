#pragma once
struct Pos
{
	int x = 0;
	int y = 0;
	int z = 0;
};
class game_公共类
{
public:
	DWORD object_pointer = NULL;
	game_公共类(DWORD dwObjectPointer = NULL);
	~game_公共类();
	Pos GetPos();
	const char * GetName();
	DWORD GetCode();
	DWORD GetCamp();
	DWORD GetHP();
};

