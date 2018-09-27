#include "pch.h"
#include "game_ProcessHack.h"
#include "base_Util.h"


game_ProcessHack::game_ProcessHack(LPCWSTR lpClass, LPCWSTR lpName)
{
	if (hWnd == NULL)
	{
		hWnd = FindWindow(lpClass, lpName);
		if (hWnd == NULL)
		{
			throw "����δ�ҵ�";
		}
	}

	if (ProcessId == NULL)
	{
		GetWindowThreadProcessId(hWnd, &ProcessId);
		if (ProcessId == NULL)
		{
			throw FormatString("��ȡ����IDʧ�� Error Code - < %d >", GetLastError());
		}
	}

	if (hProcess == NULL)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessId);
		if (hProcess == NULL)
		{
			throw FormatString("��ʧ�� Error Code - < %d >", GetLastError());
		}
	}
}


game_ProcessHack::~game_ProcessHack()
{
	CloseHandle(hProcess);
}

