#pragma once
class game_ProcessHack
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_ProcessHack(LPCWSTR lpClass = L"���³�����ʿ", LPCWSTR lpName = L"���³�����ʿ");
	~game_ProcessHack();
};

