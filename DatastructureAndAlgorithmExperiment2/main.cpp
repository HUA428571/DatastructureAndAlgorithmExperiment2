#include <stdio.h>
#include "struct.h"
#include "Function.h"
#include "MENU.h"
#include <stdlib.h>
#include <Windows.h>


int main()
{
	USER u[10];
	strcpy(u[0].id, "Admin");
	strcpy(u[0].pwd, "Admin");
	u[0].Identity=1;//管理员
	strcpy(u[1].id, "B19030314");
	strcpy(u[1].pwd, "B19030314");
	u[1].Identity = 0;//普通用户

	PlateDatabase* DataBase = (PlateDatabase*)malloc(sizeof(PlateDatabase));
	PlateIndex* Index = (PlateIndex*)malloc(sizeof(PlateIndex));
	memset(Index->start, -1, sizeof(Index->start));
	memset(Index->end, -1, sizeof(Index->end));
	//FILE* fp;
	//if ((fp = fopen(".\\plateDatabase.txt", "r")) == NULL)
	//{
	//	return -1;
	//}
	//ImportDatabase(fp, DataBase);
	//fclose(fp);

	DataBase->plateCount = 0;
	//int Choice = startMENU(u);
	int Choice = 1;
	//创建绘图窗口，大小为1280x720像素
	initgraph(1280, 720);
	if (Choice == 1)
		AdminMENU(DataBase, Index);
	if (Choice == 0)
	//	CustomMenu(DataBase, Index);
	return 0;
}
