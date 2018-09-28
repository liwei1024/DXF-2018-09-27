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