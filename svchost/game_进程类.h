#pragma once
class game_������
{
public:
	HWND hWnd = NULL;
	DWORD ProcessId = NULL;
	HANDLE hProcess = NULL;
	game_������(LPCWSTR lpClass = L"���³�����ʿ", LPCWSTR lpName = L"���³�����ʿ");
	~game_������();
};

