#pragma once
class game_������
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_������(LPCWSTR lpClass, LPCWSTR lpName);
	~game_������();
	ProcessInfo Run();
};

