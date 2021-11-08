#include"print.h"

void PrintHomeBG(PlateDatabase* DataBase)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Home.png"), 1280, 720);
	putimage(0, 0, &BG);						// ���±���
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	//��ʾ����
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "��");
}

void PrintSearchBG(PlateDatabase* DataBase)
{
	cleardevice();
	setbkcolor(RGB(255, 255, 253));
	settextcolor(BLACK);
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\AdminMenu_Search.png"), 1280, 720);
	putimage(0, 0, &BG);						// ���±���
	settextstyle(25, 0, FONT);
	char count[8];
	_stprintf(count, _T("%d"), DataBase->plateCount);
	outtextxy(110, 200, "��ǰ���ݿ�����");
	outtextxy(110, 230, count);
	outtextxy(162, 230, "����������");
	//��ʾ����
	settextstyle(20, 0, FONT);
	time_t NOW;
	tm* Local;
	NOW = time(NULL);
	Local = localtime(&NOW);
	_stprintf(count, _T("%d"), Local->tm_year + 1900);
	outtextxy(1073, 55, count);
	outtextxy(1113, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mon + 1);
	outtextxy(1133, 55, count);
	outtextxy(1153, 55, "��");
	_stprintf(count, _T("%2d"), Local->tm_mday);
	outtextxy(1173, 55, count);
	outtextxy(1193, 55, "��");
}

void PrintPlateDetail(PlateDatabase* DataBase, int ID)
{
	char CITY[16] = "\0";
	MatchCarCity(DataBase->plate[ID].city, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 200, "�ҵ����³�����Ϣ��");
	settextstyle(25, 0, FONT);
	outtextxy(400, 240, "���ƺţ�");
	outtextxy(500, 240, "��");
	outtextxy(525, 240, DataBase->plate[ID].city);
	outtextxy(540, 240, DataBase->plate[ID].number);
	outtextxy(400, 270, "���������أ�");
	outtextxy(550, 270, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 340, "������Ϣ:");
	settextstyle(25, 0, FONT);
	outtextxy(400, 380, "���ܺţ�");
	outtextxy(500, 380, DataBase->plate[ID].cartype);
	settextstyle(26, 0, FONT);
	outtextxy(400, 440, "������Ϣ��");
	settextstyle(25, 0, FONT);
	outtextxy(400, 480, "������");
	outtextxy(475, 480, DataBase->plate[ID].ownerName);
	outtextxy(400, 510, "�ֻ���");
	outtextxy(475, 510, DataBase->plate[ID].ownerPhone);
}