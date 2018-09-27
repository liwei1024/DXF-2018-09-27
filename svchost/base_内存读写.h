#pragma once
// 读内存
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize);
// 读字节
byte readByte(INT address);
// 读短整形
short readShort(INT address);
// 读整形
int readInteger(INT address);
// 读长整形
LONGLONG readLong(INT address);
// 读单浮点型
float readFloat(INT lpBaseAddress);
// 读双浮点型
double readDouble(INT lpBaseAddress);
// 读字节数组
std::vector<byte> readBytes(INT lpBaseAddress, INT len);
// 读字符串
CHAR * readString(INT lpBaseAddress, INT len);
// 写内存
BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize);
// 写字节
BOOL writeByte(INT lpBaseAddress, byte lpBuffer);
// 写短整形
BOOL writeShort(INT lpBaseAddress, short lpBuffer);
// 写整形
BOOL writeInteger(INT lpBaseAddress, int lpBuffer);
// 写长整形
BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer);
// 写单浮点
BOOL writeFloat(INT lpBaseAddress, float lpBuffer);
// 写双浮点
BOOL writeDouble(INT lpBaseAddress, double lpBuffer);
// 写字节数组
BOOL writeBytes(INT lpBaseAddress, std::vector<int> bytes);
// 写字符串
BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer);
