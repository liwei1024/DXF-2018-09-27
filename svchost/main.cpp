// svchost.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "game_ProcessHack.h"
#include "base_Util.h"


int main()
{
	try
	{
		game_ProcessHack _game_ProcessHack;
	}
	catch (const char* exception)
	{
		红色打印("%s\n", exception);
	}
	system("pause");
	return 0;
}


