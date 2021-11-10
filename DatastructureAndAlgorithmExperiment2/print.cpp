#include"print.h"

void PrintHomeBG(PlateDatabase* DataBase)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Home.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}

void PrintSearchBG(PlateDatabase* DataBase)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Search.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}

void PrintPlateDetail(PlateDatabase* DataBase, int ID)
{
	clearrectangle(400, 200, 1220, 700);
	char CITY[16] = "\0";
	MatchCarCity(DataBase->plate[ID].city, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 200, "找到以下车牌信息：");
	settextstyle(25, 0, FONT);
	outtextxy(400, 240, "车牌号：");
	outtextxy(500, 240, "苏");
	outtextxy(525, 240, DataBase->plate[ID].city);
	outtextxy(540, 240, DataBase->plate[ID].number);
	outtextxy(400, 270, "车辆归属地：");
	outtextxy(550, 270, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 340, "车辆信息:");
	settextstyle(25, 0, FONT);
	outtextxy(400, 380, "车架号：");
	outtextxy(500, 380, DataBase->plate[ID].cartype);
	settextstyle(26, 0, FONT);
	outtextxy(400, 450, "车主信息：");
	settextstyle(25, 0, FONT);
	outtextxy(400, 490, "姓名：");
	outtextxy(475, 490, DataBase->plate[ID].ownerName);
	outtextxy(400, 520, "手机：");
	outtextxy(475, 520, DataBase->plate[ID].ownerPhone);
}

void PrintPlateDetail(Plate Plate)
{
	clearrectangle(400, 200, 1220, 700);
	char CITY[16] = "\0";
	MatchCarCity(Plate.city, CITY);
	settextstyle(25, 0, FONT);
	outtextxy(400, 240, "车牌号：");
	outtextxy(500, 240, "苏");
	outtextxy(525, 240, Plate.city);
	outtextxy(540, 240, Plate.number);
	outtextxy(400, 270, "车辆归属地：");
	outtextxy(550, 270, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 340, "车辆信息:");
	settextstyle(25, 0, FONT);
	outtextxy(400, 380, "车架号：");
	outtextxy(500, 380, Plate.cartype);
	settextstyle(26, 0, FONT);
	outtextxy(400, 450, "车主信息：");
	settextstyle(25, 0, FONT);
	outtextxy(400, 490, "姓名：");
	outtextxy(475, 490, Plate.ownerName);
	outtextxy(400, 520, "手机：");
	outtextxy(475, 520, Plate.ownerPhone);
}

void PrintCustomBG(PlateDatabase* DataBase)
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
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\CustomMenu.png"), 1280, 720);
	putimage(0, 0, &BG);						// 更新背景
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "当前数据库中有");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "个车牌数据");
	//显示日期
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "年");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "月");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "日");
}