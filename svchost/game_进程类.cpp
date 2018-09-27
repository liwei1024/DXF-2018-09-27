#include "pch.h"
#include "game_进程类.h"
#include "base_Util.h"


game_进程类::game_进程类(LPCWSTR lpClass, LPCWSTR lpName)
{
	if (hWnd == NULL)
	{
		hWnd = FindWindow(lpClass, lpName);
		if (hWnd == NULL)
		{
			throw "窗口未找到";
		}
	}

	if (ProcessId == NULL)
	{
		GetWindowThreadProcessId(hWnd, &ProcessId);
		if (ProcessId == NULL)
		{
			throw FormatString("获取进程ID失败 Error Code - < %d >", GetLastError());
		}
	}

	if (hProcess == NULL)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
		if (hProcess == NULL)
		{
			throw FormatString("打开失败 Error Code - < %d >", GetLastError());
		}
	}
}


game_进程类::~game_进程类()
{
	CloseHandle(hProcess);
}

