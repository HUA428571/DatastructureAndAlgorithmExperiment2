#include"MENU.h"

int startMENU(USER u[10])
{
	initgraph(1280, 720);	//创建绘图窗口，大小为 1280x720 像素
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	// 设置背景色为淡白色
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 30;						// 设置字体高度为30
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT2_EN));	// 设置字体为FONT2_EN
	settextstyle(&format);						// 设置字体样式
	IMAGE BG;
	IMAGE UserNameBox;
	IMAGE PassWordBox;
	IMAGE UserNameWrong;
	IMAGE PassWordWrong;
	loadimage(&BG, _T(".\\IMAGES\\StartMenu.png"), 1280, 720);
	loadimage(&UserNameBox, _T(".\\IMAGES\\UserNameBox.png"), 340, 60);
	loadimage(&PassWordBox, _T(".\\IMAGES\\PasswordBox.png"), 340, 60);
	loadimage(&UserNameWrong, _T(".\\IMAGES\\UserNameWrong.png"), 340, 60);
	loadimage(&PassWordWrong, _T(".\\IMAGES\\PasswordWrong.png"), 340, 60);
	putimage(0, 0, &BG);
	//以上都是常规代码
	char UserName[50];
	char UserNameCheck = 0;
	char PassWord[50];
	int MENUchoice;
	MENUchoice = StartMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 1:
		{
			putimage(0, 0, &BG);
			putimage(470, 280, &UserNameBox);
			CR_InputBox(UserName, 40, 530, 290, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 330, 800, 330);
			UserNameCheck = 1;
			MENUchoice = StartMENU_MENUChoose();
			break;
		}
		case 2:
		{
			putimage(470, 380, &PassWordBox);
			CHR_InputBox(PassWord, 40, 530, 390, 270, 40, "");
			setlinecolor(BLACK);
			line(530, 430, 800, 430);
			if (UserNameCheck == 0)
			{
				MENUchoice = StartMENU_MENUChoose();
			}
			else
			{
				int temp;
				temp = CheckID(UserName, PassWord, u);
				if (temp >= 0)
					return temp;
				else
				{
					putimage(470, 280, &UserNameWrong);
					putimage(470, 380, &PassWordWrong);
					UserNameCheck = 0;
					MENUchoice = StartMENU_MENUChoose();
				}
			}
			break;
		}
		}
	}
}
int CheckID(char* n, char* m, USER u[10])
{
	USER temp;
	int count = 0;
	while (count < 10)
	{
		temp = u[count];
		if (strcmp(temp.id, n) == 0)
		{
			if (strcmp(temp.pwd, m) == 0)
			{
				if (temp.Identity == 1)
					return 1;
				if (temp.Identity == 0)
					return 0;
			}
			else
				return -1;
		}
		else
			count++;
	}
	return -1;
}

int AdminMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	// 设置背景色为淡白色
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// 用背景色清空屏幕
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// 设置字体为FONT
	settextstyle(&format);						// 设置字体样式
	int MENUchoice;
	MENUchoice = AdminMENU_HomeMENU(DataBase, Index);		//先进入主页
	while (true)											//循环
	{
		switch (MENUchoice)
		{
		case 0:
			MENUchoice = AdminMENU_HomeMENU(DataBase, Index);
			break;
		case 1:
			MENUchoice = AdminMENU_SearchMENU(DataBase, Index);
			break;
		case 2:
			MENUchoice = AdminMENU_AddMENU(DataBase, Index);
			break;
		case 3:
			MENUchoice = AdminMENU_DeleteMENU(DataBase, Index);
			break;
		case 4:
			MENUchoice = AdminMENU_ChangeMENU(DataBase, Index);
			break;
		case -1:
			return 0;
		}
	}
}

int AdminMENU_HomeMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	PrintHomeBG(DataBase);
	char Location[2][100] = { ".\\Data\\DefaultPlateDatabase.txt",".\\Data\\PlateDatabase.txt" };

	int MENUchoice = AdminMENU_HomeMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//导入车牌数据
		case 51:
			MENUchoice = AdminMENU_HomeMENU_Import(DataBase, Index, Location);
			break;
			//导出车牌数据
		case 52:
			MENUchoice = AdminMENU_HomeMENU_Export(DataBase, Index, Location);
			break;
		case 61:
			FILE * fp;
			int SortResult[MAXSIZE];
			if ((fp = fopen(".\\Data\\AutoSave_PlateDatabase.txt", "w")) == NULL)
			{
				clearrectangle(400, 200, 1220, 700);
				outtextxy(400, 200, "文件打开失败");
			}
			DataBaseInsertSortWithCity(DataBase, SortResult);
			ExportDatabase(fp, DataBase, SortResult);
			fclose(fp);
			closegraph();			// 关闭绘图窗口
			return -1;
		case 62:
			closegraph();			// 关闭绘图窗口
			return -1;
		}
	}
}
int AdminMENU_HomeMENU_Import(PlateDatabase* DataBase, PlateIndex* Index, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Home_Import.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	settextcolor(BLACK);
	outtextxy(400, 200, "将从以下目录导入车牌数据库：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 240, Location[0]);
	int MENUchoice = AdminMENU_HomeMENU_Import_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//导入车牌数据
		case 51:
			MENUchoice = AdminMENU_HomeMENU_Import(DataBase, Index, Location);
			break;
			//导出车牌数据
		case 52:
			MENUchoice = AdminMENU_HomeMENU_Export(DataBase, Index, Location);
			break;
		case 57:
			FILE * fp;
			if ((fp = fopen(Location[0], "r")) == NULL)
			{
				clearrectangle(400, 200, 1220, 700);
				outtextxy(400, 200, "文件打开失败");
			}
			ImportDatabase(fp, DataBase);
			fclose(fp);
			clearrectangle(400, 200, 1220, 700);
			settextstyle(25, 0, FONT);
			outtextxy(400, 200, "导入了");
			char count[8];
			_stprintf(count, _T("%d"), DataBase->plateCount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个车牌数据");
			Sleep(500);
			return 0;//返回主页
		case 58:
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			outtextxy(420, 200, "已取消导入");
			Sleep(500);
			return 0;//返回主页
		case 59:
			clearrectangle(400, 240, 1220, 300);
			char LocationTEMP[100] = "\0";
			C_InputBox(LocationTEMP, 99, 400, 280, 600, 20, Location[0]);
			if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
			{
				outtextxy(400, 280, "无效的目录！");
				Sleep(50);
			}
			else
			{
				strcpy(Location[0], LocationTEMP);
			}
			return AdminMENU_HomeMENU_Import(DataBase, Index, Location);
		}
	}
}
int AdminMENU_HomeMENU_Export(PlateDatabase* DataBase, PlateIndex* Index, char Location[][100])
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Home_Export.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	settextcolor(BLACK);
	outtextxy(400, 200, "将导出数据库到以下目录：");
	settextstyle(20, 0, FONT);
	outtextxy(400, 240, Location[1]);
	int MENUchoice = AdminMENU_HomeMENU_Import_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//导入车牌数据
		case 51:
			MENUchoice = AdminMENU_HomeMENU_Import(DataBase, Index, Location);
			break;
			//导出车牌数据
		case 52:
			MENUchoice = AdminMENU_HomeMENU_Export(DataBase, Index, Location);
			break;
		case 57:
			clearrectangle(400, 200, 1220, 700);
			FILE* fp;
			int SortResult[MAXSIZE];
			if ((fp = fopen(Location[1], "w")) == NULL)
			{
				clearrectangle(400, 200, 1220, 700);
				outtextxy(400, 200, "文件打开失败");
			}
			DataBaseInsertSortWithCity(DataBase, SortResult);
			ExportDatabase(fp, DataBase, SortResult);
			fclose(fp);
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			outtextxy(400, 200, "导出了");
			char count[8];
			_stprintf(count, _T("%d"), DataBase->plateCount);
			outtextxy(480, 200, count);
			outtextxy(530, 200, "个车牌数据");
			Sleep(500);
			return 0;//返回主页
		case 58:
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			outtextxy(420, 200, "已取消导出");
			Sleep(500);
			return 0;//返回主页
		case 59:
			clearrectangle(400, 280, 1220, 300);
			char LocationTEMP[100] = "\0";
			C_InputBox(LocationTEMP, 99, 400, 280, 600, 20, Location[0]);
			if (LocationTEMP[1] == 0)//如果输入为空，则返回原有目录
			{
				outtextxy(400, 280, "无效的目录！");
				Sleep(50);
			}
			else
			{
				strcpy(Location[0], LocationTEMP);
			}
			return AdminMENU_HomeMENU_Import(DataBase, Index, Location);
		}
	}
}

int AdminMENU_SearchMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	//int SearchReasult[MAXSIZE];//用于存储搜索结果

	PrintSearchBG(DataBase);

	int MENUchoice = AdminMENU_SearchMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
		case 51:
			MENUchoice = AdminMENU_SearchMENU_SearchInOrder(DataBase, Index);
			break;
		case 52:
			MENUchoice = AdminMENU_SearchMENU_SearchInHalf(DataBase, Index);
			break;
		case 53:
			MENUchoice = AdminMENU_SearchMENU_SearchInIndex(DataBase, Index);
			break;
		}
	}
}
int AdminMENU_SearchMENU_SearchInOrder(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	DataBaseInsertSort(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 300, 300, 340);
	settextstyle(26, 0, FONT);
	outtextxy(140, 308, "苏");
	C_InputBox(search, 8, 165, 300, "GYP343");
	SearchResult = SearchInOrder(DataBase, search, SortResult);
	if (SearchResult >= 0)
	{
		PrintSearchBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintSearchBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchInHalf(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	DataBaseInsertSort(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 350, 300, 390);
	settextstyle(26, 0, FONT);
	outtextxy(140, 358, "苏");
	C_InputBox(search, 8, 165, 350, "GYP343");
	SearchResult = SearchInHalf(DataBase, search, SortResult);
	if (SearchResult >= 0)
	{
		PrintSearchBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintSearchBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return AdminMENU_SearchMENU_MENUChoose();
}
int AdminMENU_SearchMENU_SearchInIndex(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	//对整个车牌包含城市进行排序
	DataBaseInsertSortWithCity(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 400, 300, 440);
	settextstyle(26, 0, FONT);
	outtextxy(140, 408, "苏");
	C_InputBox(search, 8, 165, 400, "GYP343");
	int start, end;
	initIndex(DataBase, Index, SortResult);
	char flag = search[0];
	start = Index->start[flag - 65];
	end = Index->end[flag - 65];
	SearchResult = SearchInIndex(DataBase, search, start, end, SortResult);
	if (SearchResult >= 0)
	{
		PrintSearchBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintSearchBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return AdminMENU_SearchMENU_MENUChoose();
}

int AdminMENU_AddMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Add.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	settextcolor(BLACK);
	Plate PlateTemp;
	char buffer[99];
	InputBox(buffer, 8, "请输入要添加的车牌号\n不需要输入“苏”，eg A10A10");
	PlateTemp.city = buffer[0];
	for (int i = 1; i < 99; i++)
	{
		PlateTemp.number[i - 1] = buffer[i];
		if (buffer[i] == 0)
			break;
	}
	InputBox(PlateTemp.cartype, 99, "请输入添加的车牌的车辆信息\n车架号：");
	InputBox(PlateTemp.ownerName, 99, "请输入添加的车牌的车主信息\n车主姓名：");
	InputBox(PlateTemp.ownerPhone, 99, "请输入添加的车牌的车主信息\n车主手机：");
	PrintPlateDetail(PlateTemp);
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//确认添加
		case 21:
			DataBase->plate[DataBase->plateCount] = PlateTemp;
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			DataBase->plateCount++;
			outtextxy(420, 200, "成功添加！");
			Sleep(500);
			return 0;
			//取消添加
		case 22:
			outtextxy(420, 200, "已取消添加！");
			Sleep(500);
			return 0;
		}
	}

}
int AdminMENU_DeleteMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Delete.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	settextcolor(BLACK);
	char Delete[8];
	InputBox(Delete, 8, "请输入你想删除的车牌\n不需要输入“苏”，eg A10A10");
	int SearchResult = Search(DataBase, Delete);
	if (SearchResult >= 0)
	{
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
		return AdminMENU_MENUChoose();
	}
	int MENUchoice = AdminMENU_AddMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//确认删除
		case 21:
			for (int i = SearchResult; i < DataBase->plateCount - 1; i++)
			{
				DataBase->plate[i] = DataBase->plate[i + 1];
			}
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			DataBase->plateCount--;
			outtextxy(420, 200, "成功删除！");
			Sleep(500);
			return 0;
			//取消删除
		case 22:
			return 0;
		}
	}
}
int AdminMENU_ChangeMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	IMAGE BG;
	LOGFONT format;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	settextcolor(BLACK);
	gettextstyle(&format);						// 获取当前字体设置
	format.lfHeight = 25;						// 设置字体高度为 25
	_tcscpy_s(format.lfFaceName, _T(FONT));	// 设置字体为FONT
	format.lfQuality = PROOF_QUALITY;			// 设置输出效果为最高质量  
	settextstyle(&format);						// 设置字体样式
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	settextcolor(BLACK);
	char Delete[8];
	InputBox(Delete, 8, "请输入你想修改的车牌\n不需要输入“苏”，eg A10A10");
	int SearchResult = Search(DataBase, Delete);
	if (SearchResult < 0)
	{
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
		return AdminMENU_MENUChoose();
	}
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Change.png"), 1280, 720);
	putimage(0, 0, &BG);	// 在另一个位置再次显示背景
	char buffer[99];
	char CITY[16] = "\0";
	Plate PlateTemp = DataBase->plate[SearchResult];
	PrintPlateDetail(DataBase, SearchResult);
	int MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			return MENUchoice;
			//确认删除
		case 101:
			InputBox(buffer, 8, "请输入更改后的车牌号\n不需要输入“苏”，eg A10A10");
			if (Search(DataBase, buffer) >= 0)
			{
				settextstyle(26, 0, FONT);
				outtextxy(400, 200, "已经存在的车牌号！");
				Sleep(500);
				PrintPlateDetail(DataBase, SearchResult);
				MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
				break;
			}
			PlateTemp.city = buffer[0];
			for (int i = 1; i < 99; i++)
			{
				PlateTemp.number[i - 1] = buffer[i];
				if (buffer[i] == 0)
					break;
			}
			clearrectangle(400, 240, 700, 300);
			settextstyle(25, 0, FONT);
			outtextxy(400, 240, "车牌号：");
			outtextxy(500, 240, "苏");
			outtextxy(525, 240, PlateTemp.city);
			outtextxy(540, 240, PlateTemp.number);
			outtextxy(400, 270, "车辆归属地：");
			MatchCarCity(PlateTemp.city, CITY);
			outtextxy(550, 270, CITY);
			MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
			break;
		case 102:
			InputBox(PlateTemp.cartype, 99, "请输入更改后的车辆信息\n车架号：");
			clearrectangle(400, 380, 800, 410);
			settextstyle(25, 0, FONT);
			outtextxy(400, 380, "车架号：");
			outtextxy(500, 380, PlateTemp.cartype);
			MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
			break;
		case 103:
			InputBox(PlateTemp.ownerName, 99, "请输入更改后的车主信息\n车主姓名：");
			clearrectangle(400, 490, 800, 520);
			settextstyle(25, 0, FONT);
			outtextxy(400, 490, "姓名：");
			outtextxy(475, 490, PlateTemp.ownerName);
			MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
			break;
		case 104:
			InputBox(PlateTemp.ownerPhone, 99, "请输入更改后的车主信息\n车主手机：");
			clearrectangle(400, 520, 800, 550);
			settextstyle(25, 0, FONT);
			outtextxy(400, 520, "手机：");
			outtextxy(475, 520, PlateTemp.ownerPhone);
			MENUchoice = AdminMENU_ChangeMENU_MENUChoose();
			break;
			//确认添加
		case 21:
			DataBase->plate[SearchResult] = PlateTemp;
			settextstyle(25, 0, FONT);
			clearrectangle(400, 200, 1220, 700);
			outtextxy(420, 200, "成功更改！");
			Sleep(500);
			return 0;
			//取消添加
		case 22:
			outtextxy(420, 200, "已取消更改！");
			Sleep(500);
			return 0;
		}
	}
}

int CustomMENU(PlateDatabase* DataBase, PlateIndex* Index)
{
	PrintCustomBG(DataBase);

	int MENUchoice = CustomMENU_MENUChoose();
	while (true)
	{
		switch (MENUchoice)
		{
		case 51:
			MENUchoice = CustomMENU_SearchMENU_SearchInOrder(DataBase, Index);
			break;
		case 52:
			MENUchoice = CustomMENU_SearchMENU_SearchInHalf(DataBase, Index);
			break;
		case 53:
			MENUchoice = CustomMENU_SearchMENU_SearchInIndex(DataBase, Index);
			break;
		case 62:
			closegraph();			// 关闭绘图窗口
			return 0;
		}
	}
}
int CustomMENU_SearchMENU_SearchInOrder(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	DataBaseInsertSort(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 300, 300, 340);
	settextstyle(26, 0, FONT);
	outtextxy(140, 308, "苏");
	C_InputBox(search, 8, 165, 300, "GYP343");
	SearchResult = SearchInOrder(DataBase, search, SortResult);
	if (SearchResult >= 0)
	{
		PrintCustomBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintCustomBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return CustomMENU_MENUChoose();
}
int CustomMENU_SearchMENU_SearchInHalf(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	DataBaseInsertSort(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 350, 300, 390);
	settextstyle(26, 0, FONT);
	outtextxy(140, 358, "苏");
	C_InputBox(search, 8, 165, 350, "GYP343");
	SearchResult = SearchInHalf(DataBase, search, SortResult);
	if (SearchResult >= 0)
	{
		PrintCustomBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintCustomBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return CustomMENU_MENUChoose();
}
int CustomMENU_SearchMENU_SearchInIndex(PlateDatabase* DataBase, PlateIndex* Index)
{
	//对数据库进行排序
	int SortResult[MAXSIZE];
	//对整个车牌包含城市进行排序
	DataBaseInsertSortWithCity(DataBase, SortResult);
	char search[8];
	int SearchResult;
	clearrectangle(135, 400, 300, 440);
	settextstyle(26, 0, FONT);
	outtextxy(140, 408, "苏");
	C_InputBox(search, 8, 165, 400, "GYP343");
	int start, end;
	initIndex(DataBase, Index, SortResult);
	char flag = search[0];
	start = Index->start[flag - 65];
	end = Index->end[flag - 65];
	SearchResult = SearchInIndex(DataBase, search, start, end, SortResult);
	if (SearchResult >= 0)
	{
		PrintCustomBG(DataBase);
		PrintPlateDetail(DataBase, SearchResult);
	}
	else
	{
		PrintCustomBG(DataBase);
		settextstyle(25, 0, FONT);
		outtextxy(380, 200, "没有找到符合要求的车牌信息！");
	}
	return CustomMENU_MENUChoose();
}