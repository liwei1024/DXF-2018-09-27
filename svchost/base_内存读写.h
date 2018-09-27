#pragma once
// ���ڴ�
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize);
// ���ֽ�
byte readByte(INT address);
// ��������
short readShort(INT address);
// ������
int readInteger(INT address);
// ��������
LONGLONG readLong(INT address);
// ����������
float readFloat(INT lpBaseAddress);
// ��˫������
double readDouble(INT lpBaseAddress);
// ���ֽ�����
std::vector<byte> readBytes(INT lpBaseAddress, INT len);
// ���ַ���
CHAR * readString(INT lpBaseAddress, INT len);
// д�ڴ�
BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize);
// д�ֽ�
BOOL writeByte(INT lpBaseAddress, byte lpBuffer);
// д������
BOOL writeShort(INT lpBaseAddress, short lpBuffer);
// д����
BOOL writeInteger(INT lpBaseAddress, int lpBuffer);
// д������
BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer);
// д������
BOOL writeFloat(INT lpBaseAddress, float lpBuffer);
// д˫����
BOOL writeDouble(INT lpBaseAddress, double lpBuffer);
// д�ֽ�����
BOOL writeBytes(INT lpBaseAddress, std::vector<int> bytes);
// д�ַ���
BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer);
