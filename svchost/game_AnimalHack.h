#pragma once

struct Pos
{
	int x;
	int y;
};

class game_AnimalHack
{
public:
	DWORD object_pointer = NULL;
	game_AnimalHack(DWORD dwObjectPointer);
	~game_AnimalHack();
	Pos GetPos();
	const char * GetName();
	DWORD GetCode();
	DWORD GetCamp();
	DWORD GetHP();
};

