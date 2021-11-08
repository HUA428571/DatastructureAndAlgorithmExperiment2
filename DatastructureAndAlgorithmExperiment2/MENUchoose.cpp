#include"MENUchoose.h"

int StartMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 280 && m.y < 340 && m.x>470 && m.x < 810)//鼠标按在输入账号区域
				return 1;
			if (m.y > 380 && m.y < 440 && m.x>470 && m.x < 810)//鼠标按在输入密码区域
				return 2;
		}
	}
}

int AdminMENU_HomeMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入车牌数据区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导出车牌数据区域
				return 52;
			if (m.x > 100 && m.y > 550 && m.x < 300 && m.y < 590)//鼠标按在退出并保存区域
				return 61;
			if (m.x > 100 && m.y > 600 && m.x < 300 && m.y < 640)//鼠标按在直接退出区域
				return 62;
		}
	}
}
int AdminMENU_HomeMENU_Import_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在主页区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在查找区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在添加区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在删除区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在更改区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在导入车牌数据区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在导出车牌数据区域
				return 52;
			if (m.x > 400 && m.y > 300 && m.x < 550 && m.y < 390)//鼠标按在确认导入区域
				return 57;
			if (m.x > 550 && m.y > 300 && m.x < 700 && m.y < 390)//鼠标按在取消导入区域
				return 58;
			if (m.x > 700 && m.y > 300 && m.x < 850 && m.y < 390)//鼠标按在修改路径区域
				return 59;
		}
	}
}


int AdminMENU_SearchMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在查找区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在添加区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在删除区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在更改区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在退出区域
				return 4;
			if (m.x > 100 && m.y > 300 && m.x < 300 && m.y < 340)//鼠标按在顺序查找区域
				return 51;
			if (m.x > 100 && m.y > 350 && m.x < 300 && m.y < 390)//鼠标按在对半查找区域
				return 52;
			if (m.x > 100 && m.y > 400 && m.x < 300 && m.y < 440)//鼠标按在分块索引查找区域
				return 53;
		}
	}
}





int AdminMENU_DeleteMENU_MENUChoose()
{
	FlushMouseMsgBuffer();
	while (true)
	{
		MOUSEMSG m;
		// 获取一条鼠标消息
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键被按下
		{
			if (m.y > 90 && m.y < 135 && m.x>190 && m.x < 290)//鼠标按在查找区域
				return 0;
			if (m.y > 90 && m.y < 135 && m.x>390 && m.x < 490)//鼠标按在添加区域
				return 1;
			if (m.y > 90 && m.y < 135 && m.x>590 && m.x < 690)//鼠标按在删除区域
				return 2;
			if (m.y > 90 && m.y < 135 && m.x>790 && m.x < 890)//鼠标按在更改区域
				return 3;
			if (m.y > 90 && m.y < 135 && m.x>990 && m.x < 1090)//鼠标按在退出区域
				return 4;
		}
	}
}