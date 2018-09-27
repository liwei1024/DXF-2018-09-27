// svchost.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "base_Util.h"
#include "game_角色类.h"
#include "base_内存读写.h"

game_进程类 _game_进程类;

int main()
{
	try
	{
		删除自身();

		窗口初始化();

		EnableDebugPrivilege(true);

		game_进程类 _game_进程类;

		game_角色类 _game_角色类(readInteger(__人物基址));
		青色打印("%s", _game_角色类.GetName());
		青色打印("%d", _game_角色类.GetCode());
		Pos _Pos = _game_角色类.GetPos();
		青色打印("x %d y %d z %d", _Pos.x, _Pos.y, _Pos.z);
		青色打印("%d", _game_角色类.GetHP());
	}
	catch (const char* exception)
	{
		红色打印("%s\n", exception);
	}
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


