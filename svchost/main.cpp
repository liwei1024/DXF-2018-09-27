// svchost.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "base_Util.h"
#include "game_角色类.h"
#include "base_内存读写.h"
#include "game_进程类.h"
#include "base_消息.h"
#include "game_地图类.h"


ProcessInfo _ProcessInfo;

int main()
{
	try
	{
		EnableDebugPrivilege(true);
		
		删除自身();

		窗口初始化();

		

		/*_ProcessInfo = game_进程类().Run();

		game_角色类 _game_角色类;

		青色打印("%s", _game_角色类.GetName());
		青色打印("%d", _game_角色类.GetCode());
		Pos _Pos = _game_角色类.GetPos();
		青色打印("x %d y %d z %d", _Pos.x, _Pos.y, _Pos.z);
		青色打印("%d", _game_角色类.GetHP());

		game_地图类().遍历();*/
		MSG msg;//消息指针
		设置全局键盘钩子();
		while (GetMessage(&msg, NULL, 0, 0))
		{
			ThreadMessage(msg.message,msg.wParam,msg.lParam);//线程消息处理
			TranslateMessage(&msg);//等待信号
			DispatchMessage(&msg);//处理信号
		}
		取消全局键盘钩子();
	}
	catch (const char* exception)
	{
		红色打印("Error Info：%s\n", exception);
		system("pause");
	}
	return 0;
}


