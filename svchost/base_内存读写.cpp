#include "pch.h"
#include "base_�ڴ��д.h"
#include "base_Util.h"

using namespace std;
//=====================================��======================================//
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize)
{
	SIZE_T lpNumberOfBytesRead;
	//ntReadVirtualMemory(_ProcessInfo.hProcess, (LPCVOID)baseAddress, lpBuffer, (SIZE_T)nSize, &lpNumberOfBytesRead);
	ReadProcessMemory(_ProcessInfo.hProcess, (LPCVOID)baseAddress, lpBuffer, (SIZE_T)nSize, &lpNumberOfBytesRead);
	/*if ( == FALSE) {
		printf("��ȡ %x �ڴ�ʱʧ�ܣ�\n", baseAddress);
		system("pause");
		return false;
	}
	if (lpNumberOfBytesRead != nSize) {
		printf("��ȡ %x �ڴ�ʱʵ�ʶ�ȡ�ĳ�����Ҫ��ȡ�ĳ��Ȳ�һ�£�\n", baseAddress);
		system("pause");
		return false;
	}*/
	return true;
}

byte readByte(INT address)
{
	byte lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

short readShort(INT address)
{
	short lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

int readInteger(INT address)
{
	int lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

LONGLONG readLong(INT address)
{
	LONGLONG lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

float readFloat(INT lpBaseAddress)
{
	float lpBuffer;
	readMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

double readDouble(INT lpBaseAddress)
{
	double lpBuffer;
	readMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

vector<byte> readBytes(INT lpBaseAddress, INT len)
{
	byte * lpBuffer;
	lpBuffer = new byte[len];
	memset(lpBuffer, 0, len);
	readMemory(lpBaseAddress, lpBuffer, len);
	vector<byte>  result;
	result.resize(len);
	for (INT i = 0; i < len; i++)
	{
		result[i] = lpBuffer[i];
	}
	delete[]lpBuffer;
	return result;
}

CHAR* readString(INT lpBaseAddress, INT len)
{
	TCHAR *lpBuffer;
	len = len * 2 + 2;
	lpBuffer = new TCHAR[len];
	readMemory(lpBaseAddress, lpBuffer, len);
	CHAR * str = unicodeToAnsi(lpBuffer);
	return str;
}

//=====================================д======================================//

BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize)
{
	SIZE_T lpNumberOfBytesRead;
	if (!WriteProcessMemory(_ProcessInfo.hProcess, (LPVOID)lpBaseAddress, lpBuffer, (SIZE_T)(nSize), &lpNumberOfBytesRead)) {
		printf("д�� %x �ڴ�ʱʧ�ܣ�\n", lpBaseAddress);
		return false;
	}
	if (lpNumberOfBytesRead != nSize) {
		printf("д�� %x �ڴ�ʱʵ��д��ĳ�����Ҫд��ĳ��Ȳ�һ�£�\n", lpBaseAddress);
		return false;
	}
	return true;
}

BOOL writeByte(INT lpBaseAddress, byte lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeShort(INT lpBaseAddress, short lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeInteger(INT lpBaseAddress, int lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeFloat(INT lpBaseAddress, float lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeDouble(INT lpBaseAddress, double lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeBytes(INT lpBaseAddress, vector<int> bytes)
{
	INT size = bytes.size();
	byte *lpBuffer = new byte[size];
	for (INT i = 0; i < size; i++)
	{
		lpBuffer[i] = bytes[i];
	}
	bool result = writeMemory(lpBaseAddress, lpBuffer, size);
	delete[]lpBuffer;
	return result;
}

BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer)
{
	INT len = wcslen(lpBuffer) * 2 + 2;
	return writeMemory(lpBaseAddress, (LPCVOID)lpBuffer, len);
}
