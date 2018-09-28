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
		va_start(marker, lpcszFormat); //初始化变量参数
		size_t nLength = _vscprintf(lpcszFormat, marker) + 1; //获取格式化字符串长度
		pszStr = new char[nLength];
		memset(pszStr, '\0', nLength);
		_vsnprintf_s(pszStr, nLength, nLength, lpcszFormat, marker);
		va_end(marker); //重置变量参数
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
		va_start(marker, lpcwszFormat); //初始化变量参数
		size_t nLength = _vscwprintf(lpcwszFormat, marker) + 1; //获取格式化字符串长度
		pszStr = new wchar_t[nLength];
		memset(pszStr, L'\0', nLength);
		_vsnwprintf_s(pszStr, nLength, nLength, lpcwszFormat, marker);
		va_end(marker); //重置变量参数
	}
	std::wstring strResult(pszStr);
	delete[]pszStr;
	return strResult;
}



bool 删除自身()
{
	bool result = true;
	char FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//获取文件路径
	GetModuleFileName(NULL, (LPWSTR)FileName, MAX_PATH);
	char *NewFileName;
	NewFileName = new char[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//设置文件属性
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	//尝试直接删除
	if (DeleteFile((LPCWSTR)FileName))//能直接删掉最好
	{
		delete[] NewFileName;
		return false;
	}
	//以下API一样，不再啰嗦
	wsprintf((LPWSTR)NewFileName, L"C:\\Windows\\%C\0", FileName[0]);
	CreateDirectory((LPCWSTR)NewFileName, NULL);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf((LPWSTR)NewFileName, L"C:\\Windows 服务主进程\0", FileName[0], GetTickCount());
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile((LPCWSTR)NewFileName);
	if (!MoveFileEx((LPCWSTR)FileName, (LPCWSTR)NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		//printf("删除自身失败 Error Code\n");
		return false;//动不了就放弃
	}
	MoveFileEx((LPCWSTR)NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	if (result == false)
	{
		printf("删除自身失败 Error Code\n");
		system("pause");
		exit(0);
	}
	return result;
}

void 青色打印(const char *内容, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置绿色和蓝色相加
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, 内容);
	vsprintf_s(buffer, 内容, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void 黄色打印(const char *内容, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//设置红色和绿色相加

	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, 内容);
	vsprintf_s(buffer, 内容, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void 粉色打印(const char *内容, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//设置红色和蓝色相加
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, 内容);
	vsprintf_s(buffer, 内容, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void 红色打印(const char *内容, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, 内容);
	vsprintf_s(buffer, 内容, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void 绿色打印(const char *内容, ...)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
	va_list argList;
	char buffer[0x500];
	char szBuffer_Game[0x500] = "Game:";
	va_start(argList, 内容);
	vsprintf_s(buffer, 内容, argList);
	printf("%s\n", buffer);
	va_end(argList);
}

void 窗口初始化()
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
	//SetLayeredWindowAttributes(hwnd, 0, 200, 3);//透明度设置
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
	int 随机数 = 0;
	if (max > min) {
		srand((unsigned)time(NULL));
		随机数 = (rand() % (min - max + 1) + max);
	}
	else {
		srand((unsigned)time(NULL));
		随机数 = (rand() % (max - min + 1) + min);
	}
	return 随机数;
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

// 获取时间戳
INT getTime()
{
	DWORD t_start, t_end;
	t_start = GetTickCount();//从操作系统启动所经过（elapsed）的毫秒数，它的返回值是DWORD。
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

bool 远程CALL(int CALL_Address, bool async)
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





