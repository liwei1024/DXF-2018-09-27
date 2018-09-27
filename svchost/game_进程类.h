#pragma once
class game_进程类
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_进程类(LPCWSTR lpClass = L"地下城与勇士", LPCWSTR lpName = L"地下城与勇士");
	~game_进程类();
};

