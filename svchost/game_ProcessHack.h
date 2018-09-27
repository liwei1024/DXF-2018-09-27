#pragma once
class game_ProcessHack
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_ProcessHack(LPCWSTR lpClass = L"地下城与勇士", LPCWSTR lpName = L"地下城与勇士");
	~game_ProcessHack();
};

