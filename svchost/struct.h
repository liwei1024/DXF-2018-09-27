#pragma once
struct ProcessInfo
{
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
};
struct Pos
{
	int x = 0;
	int y = 0;
	int z = 0;
};
struct Coordinate {
	int x, y, z;
};

struct RoomInfo {
	Coordinate coordinate;
	Coordinate parent_coordinate;
	int weight;
	int numbering;
	bool up;
	bool bottom;
	bool left;
	bool right;
};

struct MapInfo {
	int width;
	int height;
	const char * name;
	std::vector<int> channel;
	Coordinate start_coordinate;
	Coordinate end_coordinate;
};