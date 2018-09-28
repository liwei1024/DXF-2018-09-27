#pragma once
class game_进程类
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_进程类(LPCWSTR lpClass, LPCWSTR lpName);
	~game_进程类();
	ProcessInfo Run();
};

