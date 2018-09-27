#include "pch.h"
#include "base_Util.h"

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
	MoveWindow(s_hwnd, 0, 0, 400, 600, TRUE);
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