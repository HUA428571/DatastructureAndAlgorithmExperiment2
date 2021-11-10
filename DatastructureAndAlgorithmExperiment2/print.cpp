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
	clearrectangle(400, 200, 1220, 700);
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
	outtextxy(400, 450, "������Ϣ��");
	settextstyle(25, 0, FONT);
	outtextxy(400, 490, "������");
	outtextxy(475, 490, DataBase->plate[ID].ownerName);
	outtextxy(400, 520, "�ֻ���");
	outtextxy(475, 520, DataBase->plate[ID].ownerPhone);
}

void PrintPlateDetail(Plate Plate)
{
	clearrectangle(400, 200, 1220, 700);
	char CITY[16] = "\0";
	MatchCarCity(Plate.city, CITY);
	settextstyle(25, 0, FONT);
	outtextxy(400, 240, "���ƺţ�");
	outtextxy(500, 240, "��");
	outtextxy(525, 240, Plate.city);
	outtextxy(540, 240, Plate.number);
	outtextxy(400, 270, "���������أ�");
	outtextxy(550, 270, CITY);
	settextstyle(26, 0, FONT);
	outtextxy(400, 340, "������Ϣ:");
	settextstyle(25, 0, FONT);
	outtextxy(400, 380, "���ܺţ�");
	outtextxy(500, 380, Plate.cartype);
	settextstyle(26, 0, FONT);
	outtextxy(400, 450, "������Ϣ��");
	settextstyle(25, 0, FONT);
	outtextxy(400, 490, "������");
	outtextxy(475, 490, Plate.ownerName);
	outtextxy(400, 520, "�ֻ���");
	outtextxy(475, 520, Plate.ownerPhone);
}

void PrintCustomBG(PlateDatabase* DataBase)
{
	// ���ñ���ɫΪ����ɫ
	setbkcolor(RGB(255, 255, 253));
	setbkmode(TRANSPARENT);
	// �ñ���ɫ�����Ļ
	cleardevice();
	settextcolor(BLACK);
	LOGFONT format;
	gettextstyle(&format);						// ��ȡ��ǰ��������
	format.lfHeight = 25;						// ��������߶�Ϊ 25
	format.lfQuality = PROOF_QUALITY;			// �������Ч��Ϊ�������  
	format.lfPitchAndFamily = FIXED_PITCH;
	_tcscpy_s(format.lfFaceName, _T(FONT));		// ��������ΪFONT
	settextstyle(&format);						// ����������ʽ
	IMAGE BG;
	loadimage(&BG, _T(".\\IMAGES\\CustomMenu.png"), 1280, 720);
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