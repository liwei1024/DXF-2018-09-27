#include "pch.h"
#include "base_��Ϣ.h"
#include "base_Util.h"
HHOOK g_hHook;
DWORD g_dwMainThreadId;

VOID ThreadMessage(
	UINT message,
	WPARAM wParam,
	LPARAM lParam
)
{
	��ɫ��ӡ("message %d", message);
	��ɫ��ӡ("wParam %d", wParam);
	��ɫ��ӡ("lParam %d", lParam);
}

LRESULT CALLBACK �ȼ���Ӧ(int nCode, WPARAM wParam, LPARAM lParam)
{
	CWPSTRUCT* p = (CWPSTRUCT*)lParam;
	if (nCode == HC_ACTION)
	{
		switch (wParam) //wParam������ϢID
		{
			// ������Ϣ
		case WM_KEYDOWN:
		{
			switch (p->lParam)
			{
			case VK_HOME:
				//PostThreadMessage(g_dwMainThreadId, 10024, 0, 0);
				break;

				break;
			default:
				break;
			}
		}
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

BOOL WINAPI ConsoleCtrlhandler(DWORD dwCtrlType)
{
	if (dwCtrlType == CTRL_CLOSE_EVENT)//�˳��¼�
	{
		UnhookWindowsHookEx(g_hHook);
		//OutputDebugString(L"exit 1");
		CloseHandle(_ProcessInfo.hProcess);//�رս��̾��
		PostThreadMessage(g_dwMainThreadId, WM_QUIT, 0, 0);
	}
	
	return TRUE;
}

VOID ����ȫ�ּ��̹���()
{
	g_dwMainThreadId = GetCurrentThreadId();
	SetConsoleCtrlHandler(ConsoleCtrlhandler, TRUE);
	g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, �ȼ���Ӧ, GetModuleHandle(NULL), NULL);
	if (g_hHook == NULL)
		printf("hook failure!");
}

VOID ȡ��ȫ�ּ��̹���()
{
	SetConsoleCtrlHandler(ConsoleCtrlhandler, FALSE);
}

