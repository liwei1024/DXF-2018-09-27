#include "pch.h"
#include "base_Util.h"
#include <ctime>
using namespace std;

HWND s_hwnd = NULL;

string FormatString(const char *lpcszFormat, ...)
{
	char *pszStr = NULL;
	if (NULL != lpcszFormat)
	{
		va_list marker = NULL;
		va_start(marker, lpcszFormat); //��ʼ����������
		size_t nLength = _vscprintf(lpcszFormat, marker) + 1; //��ȡ��ʽ���ַ�������
		pszStr = new char[nLength];
		memset(pszStr, '\0', nLength);
		_vsnprintf_s(pszStr, nLength, nLength, lpcszFormat, marker);
		va_end(marker); //���ñ�������
	}
	std::string strResult(pszStr);
	delete[]pszStr;
	return strResult;
}

wstring FormatWstring(const wchar_t *lpcwszFormat, ...)
{
	wchar_t *pszStr = NULL;
	if (NULL != lpcwszFormat)
	{
		va_list marker = NULL;
		va_start(marker, lpcwszFormat); //��ʼ����������
		size_t nLength = _vscwprintf(lpcwszFormat, marker) + 1; //��ȡ��ʽ���ַ�������
		pszStr = new wchar_t[nLength];
		memset(pszStr, L'\0', nLength);
		_vsnwprintf_s(pszStr, nLength, nLength, lpcwszFormat, marker);
		va_end(marker); //���ñ�������
	}
	std::wstring strResult(pszStr);
	delete[]pszStr;
	return strResult;
}



bool ɾ������()
{
	bool result = true;
	char FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//��ȡ�ļ�·��
	GetModuleFileName(NULL, (LPWSTR)FileName, MAX_PATH);
	char *NewFileName;
	NewFileName = new char[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//�����ļ�����
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	//����ֱ��ɾ��
	if (DeleteFile((LPCWSTR)FileName))//��ֱ��ɾ�����
	{
		delete[] NewFileName;
		return false;
	}
	//����APIһ�������ن���
	wsprintf((LPWSTR)NewFileName, L"C:\\Windows\\%C\0", FileName[0]);
	CreateDirectory((LPCWSTR)NewFileName, NULL);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf((LPWSTR)NewFileName, L"C:\\Windows ����������\0", FileName[0], GetTickCount());
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile((LPCWSTR)NewFileName);
	if (!MoveFileEx((LPCWSTR)FileName, (LPCWSTR)NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		//printf("ɾ������ʧ�� Error Code\n");
		return false;//�����˾ͷ���
	}
	MoveFileEx((LPCWSTR)NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	if (result == false)
	{
		printf("ɾ������ʧ�� Error Code\n");
		system("pause");
		exit(0);
	}
	return result;
}

void ��ɫ��ӡ(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ����ɫ���
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void ��ɫ��ӡ(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//���ú�ɫ����ɫ���

	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void ��ɫ��ӡ(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//���ú�ɫ����ɫ���
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void ��ɫ��ӡ(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void ��ɫ��ӡ(const char *����, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, ����);
	vsprintf_s(buffer, ����, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void ���ڳ�ʼ��()
{
	RECT rect;
	int cx, cy;
	int width, height;
	cx = GetSystemMetrics(SM_CXFULLSCREEN);
	cy = GetSystemMetrics(SM_CYFULLSCREEN);
	s_hwnd = GetConsoleWindow();
	GetWindowRect(s_hwnd, &rect);
	MoveWindow(s_hwnd, 0, 0, 800, 600, TRUE);
	GetWindowRect(s_hwnd, &rect);
	width = (rect.right - rect.left);
	height = (rect.bottom - rect.top);
	MoveWindow(s_hwnd, cx - width, cy - height, width, height, TRUE);

	SetConsoleTitle(L"");
	//SetLayeredWindowAttributes(hwnd, 0, 200, 3);//͸��������
}

bool EnableDebugPrivilege(bool bEnable)
{
	//Enabling the debug privilege allows the application to see 
	//information about service application
	BOOL fOK = false;     //Assume function fails
	HANDLE hToken;
	//Try to open this process's acess token
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		//Attempt to modify the "Debug" privilege
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = bEnable ? SE_PRIVILEGE_ENABLED : 0;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
		fOK = (GetLastError() == ERROR_SUCCESS);
		CloseHandle(hToken);
	}
	return fOK;
}

int createRandom(int min, int max)
{
	int ����� = 0;
	if (max > min) {
		srand((unsigned)time(NULL));
		����� = (rand() % (min - max + 1) + max);
	}
	else {
		srand((unsigned)time(NULL));
		����� = (rand() % (max - min + 1) + min);
	}
	return �����;
}

char* unicodeToAnsi(const wchar_t * wstr)
{
	if (!wstr)
		return NULL;
	INT strlen = ::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), NULL, 0, NULL, FALSE);
	char* str = new char[strlen + 1];
	::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), str, strlen, NULL, FALSE);
	str[strlen] = '\0';
	return str;
}

// ��ȡʱ���
INT getTime()
{
	DWORD t_start, t_end;
	t_start = GetTickCount();//�Ӳ���ϵͳ������������elapsed���ĺ����������ķ���ֵ��DWORD��
	Sleep(3000);
	t_end = GetTickCount();
	return  t_end - t_start;
}

POINT getMouseCoord()
{
	POINT Coord;
	if (GetCursorPos(&Coord)) {
		printf("getMouseCoord Erro!\n");
	}
	return Coord;
}

BOOL setMouseCoord(INT x, INT y)
{
	BOOL result;
	result = SetCursorPos(x, y);
	if (result == FALSE) {
		printf("setMouseCoord Erro!\n");
	}
	return result;
}

VOID mouseClick(INT s)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
}

VOID mouseDoubleClick(INT s)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(s + createRandom(0, 10));
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50 + createRandom(0, 10));
}

BOOL getKeyStatus(INT keyCode)
{
	if (GetKeyState(keyCode) < 0) {
		return TRUE;
	}
	return FALSE;
}

INT getSCan(INT keyCode)
{
	INT sCan = MapVirtualKey(keyCode, 0);
	if (
		keyCode == VK_LEFT ||
		keyCode == VK_RIGHT ||
		keyCode == VK_DOWN ||
		keyCode == VK_UP
		)
	{
		sCan += 0x80;
	}
	return sCan;
}

VOID keyDown(INT keyCode)
{
	if (getKeyStatus(keyCode) == FALSE) {
		keybd_event(keyCode, getSCan(keyCode), 0, 0);
	}
}

VOID keyUp(INT keyCode)
{
	if (getKeyStatus(keyCode) == TRUE) {
		keybd_event(keyCode, getSCan(keyCode), KEYEVENTF_KEYUP, 0);
	}
}

VOID doKeyPress(INT keyCode, INT s)
{
	keyDown(keyCode);
	Sleep(s + createRandom(0, 10));
	keyUp(keyCode);
	Sleep(50 + createRandom(0, 10));
}

bool Զ��CALL(int CALL_Address, bool async)
{
	if (async)
	{
		return SendMessage(_ProcessInfo.hWnd, 10024, CALL_Address, 0);
	}
	else {
		return PostMessage(_ProcessInfo.hWnd, 10024, CALL_Address, 0);
	}
}

std::string PosToString(Pos pos)
{
	string str;
	str = std::to_string(pos.x) + "," + std::to_string(pos.y) + "," + std::to_string(pos.z);
	return str;
}


DWORD GetSystemTime()
{
	time_t tt = time(NULL);
	return (DWORD)tt;
}





