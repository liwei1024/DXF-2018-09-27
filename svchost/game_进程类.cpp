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
	绿色打印("hWnd			< %d >", hWnd);
	红色打印("hProcess		< %d >", hProcess);
	黄色打印("ProcessId		< %d >", ProcessId);
}


game_进程类::~game_进程类()
{
	红色打印("hProcess		< %d >", hProcess);
	CloseHandle(hProcess);
	OutputDebugString(L"exit");
	system("pause");
}

ProcessInfo game_进程类::Run()
{
	ProcessInfo _ProcessInfo;
	_ProcessInfo.hWnd = hWnd;
	_ProcessInfo.ProcessId = ProcessId;
	_ProcessInfo.hProcess = hProcess;
	return _ProcessInfo;
}

