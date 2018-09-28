#include "pch.h"
#include "game_������.h"
#include "base_Util.h"


game_������::game_������(LPCWSTR lpClass, LPCWSTR lpName)
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
	��ɫ��ӡ("hWnd			< %d >", hWnd);
	��ɫ��ӡ("hProcess		< %d >", hProcess);
	��ɫ��ӡ("ProcessId		< %d >", ProcessId);
}


game_������::~game_������()
{
	��ɫ��ӡ("hProcess		< %d >", hProcess);
	CloseHandle(hProcess);
	OutputDebugString(L"exit");
	system("pause");
}

ProcessInfo game_������::Run()
{
	ProcessInfo _ProcessInfo;
	_ProcessInfo.hWnd = hWnd;
	_ProcessInfo.ProcessId = ProcessId;
	_ProcessInfo.hProcess = hProcess;
	return _ProcessInfo;
}

