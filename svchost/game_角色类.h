#pragma once
#include "game_公共类.h"
class game_角色类 :
	public game_公共类
{
public:
	game_角色类(DWORD dwObjectPointer = NULL);
	~game_角色类();
	Pos GetPos();
	int 取角色等级();
	int 取疲劳值();
};

