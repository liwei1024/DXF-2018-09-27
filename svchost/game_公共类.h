#pragma once
struct Pos
{
	int x = 0;
	int y = 0;
	int z = 0;
};
class game_������
{
public:
	DWORD object_pointer = NULL;
	game_������(DWORD dwObjectPointer = NULL);
	~game_������();
	Pos GetPos();
	const char * GetName();
	DWORD GetCode();
	DWORD GetCamp();
	DWORD GetHP();
};

