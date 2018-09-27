#pragma once
struct 宽高
{
	DWORD 宽 = 0;
	DWORD 高 = 0;
};
class game_地图类
{
public:
	game_地图类(DWORD dwObjectPointer = NULL);
	~game_地图类();
	const char * GetName();
	std::vector<int> 地图通道();
	宽高 获取宽高();
	bool 是否已开门();
	bool 是否BOSS房间();
	bool 是否已通关();
	std::vector<int> 取怪物列表();
};

