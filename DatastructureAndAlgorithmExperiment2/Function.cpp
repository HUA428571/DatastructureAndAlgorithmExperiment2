#include "Function.h"

//从csv文件导入数据库
void ImportDatabase(FILE* fp, plateDatabase* DataBase)
{
	DataBase->plateCount = 0;
	int plateCount = 0;
	char c;
	char buffer[8];
	while (!feof(fp))
	{
		int i = 0;//i是用于写入char数组的下标符
		DataBase->plate[plateCount].city = fgetc(fp);
		fgetc(fp);//读取逗号分隔符
		while ((c = fgetc(fp)) != ',')//读取车牌号
		{
			DataBase->plate[plateCount].number[i] = c;
			i++;
		}
		DataBase->plate[plateCount].number[i] = '\0';//字符串结尾
		i = 0;
		while ((c = fgetc(fp)) != ',')//读取车辆信息
		{
			DataBase->plate[plateCount].cartype[i] = c;
			i++;
		}
		DataBase->plate[plateCount].cartype[i] = '\0';//字符串结尾
		i = 0;
		while ((c = fgetc(fp)) != ',')//读取车主信息
		{
			fseek(fp, -1, 1);//移动文件指针就当前位置向前一个
			fgets(buffer, 3, fp);
			DataBase->plate[plateCount].ownerName[i] = buffer[0];
			DataBase->plate[plateCount].ownerName[i + 1] = buffer[1];
			i += 2;
		}
		DataBase->plate[plateCount].ownerName[i] = '\0';//字符串结尾
		i = 0;
		while (i < 11)//读取车主手机号
		{
			c = fgetc(fp);
			DataBase->plate[plateCount].ownerPhone[i] = c;
			i++;
		}
		DataBase->plate[plateCount].ownerPhone[i] = '\0';//字符串结尾
		plateCount++;
		if ((c = fgetc(fp)) == EOF)break;
	}
	DataBase->plateCount = plateCount;
}
//导出到csv文件
void ExportDatabase(FILE* fp, plateDatabase* DataBase, int* SortResult)
{
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		fprintf(fp, "%c,%s,%s,%s,%s\n",
			DataBase->plate[SortResult[i]].city,
			DataBase->plate[SortResult[i]].number,
			DataBase->plate[SortResult[i]].cartype,
			DataBase->plate[SortResult[i]].ownerName,
			DataBase->plate[SortResult[i]].ownerPhone);
	}
}
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default)
{
	clearrectangle(x, y, x + 120, y + 40);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(30, 0, FONT2_EN);
	setlinecolor(BLACK);
	line(x, y + 35, x + 120, y + 35);
	settextcolor(RGB(220, 220, 220));
	outtextxy(x + 1, y+6, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + 160, y + 34);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			{
				if (Length == Limit - 1)
				{
					;
				}
				else
				{
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + 1 + 15 * Length, y + 6, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * 15, y + 35, x + 15 + Length * 15, y + 35);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + 15 * Length, y, x + 15 + 15 * Length, y + 34);
					setlinecolor(BLACK);
					line(x+ Length * 15, y + 35, x + 15 + Length * 15, y + 35);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize + 2, i + 1, y + Hsize + 2);
		//Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		//while (MouseHit())//如果鼠标被按下，则退出输入
		//{
		//	m = GetMouseMsg();
		//	if (m.uMsg == WM_LBUTTONDOWN)
		//	{
		//		strcpy(Input, InputBuf);
		//		return Length;
		//	}
		//}
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + Lsize, y + Hsize);
				settextcolor(RGB(220, 220, 220));
				outtextxy(x, y, Default);
				settextcolor(BLACK);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c == '\\' || c == '/' || c == '_' || c == ':' || c == '-')
			{
				if (Length == Limit)
				{
					;
				}
				else
				{
					if (Length == 0)//第一个字符
					{
						clearrectangle(x, y, x + Lsize, y + Hsize);
					}
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + (Hsize / 2) * Length, y, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * (Hsize / 2), y + Hsize + 2, x + (Length + 1) * (Hsize / 2), y + Hsize + 2);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + Length * (Hsize / 2), y, x + (Length + 1) * (Hsize / 2), y + Hsize);
					setlinecolor(BLACK);
					line(x + Length * (Hsize / 2), y + Hsize + 2, x + (Length + 1) * (Hsize / 2), y + Hsize + 2);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}
//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize, i + 1, y + Hsize);
		//Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + Lsize, y + Hsize);
				settextcolor(RGB(220, 220, 220));
				outtextxy(x, y, Default);
				settextcolor(BLACK);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c == '\\' || c == '/' || c == '_' || c == ':' || c == '-')
			{
				if (Length == Limit)
				{
					;
				}
				else
				{
					if (Length == 0)//第一个字符
					{
						clearrectangle(x, y, x + Lsize, y + Hsize);
					}
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + (Hsize / 2) * Length, y, c);
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * (Hsize / 2), y + Hsize, x + (Length + 1) * (Hsize / 2), y + Hsize);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + Length * (Hsize / 2), y, x + (Length + 1) * (Hsize / 2), y + Hsize);
					setlinecolor(BLACK);
					line(x + Length * (Hsize / 2), y + Hsize, x + (Length + 1) * (Hsize / 2), y + Hsize);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}
//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//先清空输入缓存
	char c;
	int Length = 0;
	char InputBuf[100] = { '\0' };
	//MOUSEMSG m;
	settextstyle(Hsize, 0, FONT);
	setlinecolor(BLACK);
	for (int i = x; i < x + Lsize; i++)
	{
		line(i, y + Hsize, i + 1, y + Hsize);
		//Sleep(1);
	}
	settextcolor(RGB(220, 220, 220));
	outtextxy(x, y, Default);
	settextcolor(BLACK);
	FlushMouseMsgBuffer();
	while (true)
	{
		c = _getch();
		if (c != 13)//如果输入的不是回车
		{
			if (Length == 0)
			{
				clearrectangle(x, y, x + Lsize, y + Hsize);
				settextcolor(RGB(220, 220, 220));
				outtextxy(x, y, Default);
				settextcolor(BLACK);
			}
			if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '.' || c == '\\' || c == '/' || c == '_' || c == ':' || c == '-')
			{
				if (Length == Limit)
				{
					;
				}
				else
				{
					if (Length == 0)//第一个字符
					{
						clearrectangle(x, y, x + Lsize, y + Hsize);
					}
					InputBuf[Length] = c;
					InputBuf[Length + 1] = '\0';
					outtextxy(x + (Hsize / 2) * Length, y, '*');
					setlinecolor(RGB(0, 191, 255));
					line(x + Length * (Hsize / 2), y + Hsize, x + (Length + 1) * (Hsize / 2), y + Hsize);
					Length++;
				}
			}
			if (c == 8)
			{
				if (Length != 0)
				{
					InputBuf[Length] = '\0';
					Length--;
					clearrectangle(x + Length * (Hsize / 2), y, x + (Length + 1) * (Hsize / 2), y + Hsize);
					setlinecolor(BLACK);
					line(x + Length * (Hsize / 2), y + Hsize, x + (Length + 1) * (Hsize / 2), y + Hsize);
				}
			}
		}
		else
		{
			strcpy(Input, InputBuf);
			return Length;
		}
	}
}
//排序（按照车牌顺序ASCII码排序）(不包含城市位）
//使用直接插入排序
void DataBaseInsertSort(plateDatabase* DataBase, int* SortReasult)
{
	//首先要初始化一下存储排序结果的数组
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		SortReasult[i] = i;
	}
	int i, j;//i为待插入元素下标
	Plate cmp;//每一趟待插入(待排序）元素
	int cmpID;
	for (i = 1; i < DataBase->plateCount; i++)//循环从第二个元素开始
	{
		cmpID = SortReasult[i];
		cmp = DataBase->plate[SortReasult[i]];
		for (j = i - 1; j >= 0; j--)//从后向前遍历
		{
			//如果该元素大于待插入元素，则向后挪一个位置为待插入元素空出空间
			if (strcmp(cmp.number, DataBase->plate[SortReasult[j]].number) < 0)
				SortReasult[j + 1] = SortReasult[j];
			else break;
		}
		SortReasult[j + 1] = cmpID;//待插入元素放入有序序列中
	}
}
//排序（按照车牌顺序ASCII码排序）(包含城市位）
//使用直接插入排序
void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult)
{
	//首先要初始化一下存储排序结果的数组
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		SortReasult[i] = i;
	}
	int i, j;//i为待插入元素下标
	Plate cmp;//每一趟待插入(待排序）元素
	int cmpID;
	for (i = 1; i < DataBase->plateCount; i++)//循环从第二个元素开始
	{
		cmpID = SortReasult[i];
		cmp = DataBase->plate[SortReasult[i]];
		for (j = i - 1; j >= 0; j--)//从后向前遍历
		{
			//如果该元素大于待插入元素，则向后挪一个位置为待插入元素空出空间
			if (cmp.city < DataBase->plate[SortReasult[j]].city)
			{
				if (strcmp(cmp.number, DataBase->plate[SortReasult[j]].number) < 0)
					SortReasult[j + 1] = SortReasult[j];
				else
					break;
			}
			else
				break;
		}
		SortReasult[j + 1] = cmpID;//待插入元素放入有序序列中
	}
}

//void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult)
//{
//	//首先要初始化一下存储排序结果的数组
//	for (int i = 0; i < DataBase->plateCount; i++)
//	{
//		SortReasult[i] = i;
//	}
//	int i, j;//i为待插入元素下标
//	int cmpID;
//	char tmpi[8] = { 'X','\0' };
//	char tmpj[8] = { 'X','\0' };
//	for (i = 1; i < DataBase->plateCount; i++)//循环从第二个元素开始
//	{
//		cmpID = SortReasult[i];
//		tmpi[1] = '\0';
//		tmpj[1] = '\0';
//		tmpi[0] = DataBase->plate[SortReasult[i]].city;
//		strcat(tmpi, DataBase->plate[SortReasult[i]].number);
//		for (j = i - 1; j >= 0; j--)//从后向前遍历
//		{
//			//如果该元素大于待插入元素，则向后挪一个位置为待插入元素空出空间
//			tmpj[0] = DataBase->plate[SortReasult[j]].city;
//			tmpj[1] = '\0';
//			strcat(tmpj, DataBase->plate[SortReasult[j]].number);
//			if (strcmp(tmpi, tmpj) < 0)
//				SortReasult[j + 1] = SortReasult[j];
//			else break;
//		}
//		SortReasult[j + 1] = cmpID;//待插入元素放入有序序列中
//#ifdef DEBUG
//		if (i = 426)
//		{
//			FILE* fp;
//
//			for (int a = 0; a < 500; a++)
//			{
//				printf("%d\t", SortReasult[a]);
//			}
//		}
//#endif // DEBUG
//	}
//}
//最原始的搜索，顺序匹配字符串（返回下标）
int Search(PlateDatabase* DataBase, char* search)
{
	char tmp[8];
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		tmp[1] = '\0';
		if (search[0] != DataBase->plate[i].city)
			continue;
		tmp[0] = DataBase->plate[i].city;
		strcat(tmp, DataBase->plate[i].number);
		if (!strcmp(tmp, search))
			return i;
	}
	return -1;
}
//顺序查找，根据排序查找
int SearchInOrder(PlateDatabase* DataBase, char* search, int* SortReasult)
{
	//首先我们先取出车牌
	char tmp[6] = { 'x','x','x','x','x','\0' };
	tmp[0]=search[1];
	tmp[1]=search[2];
	tmp[2]=search[3];
	tmp[3]=search[4];
	tmp[4]=search[5];
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		if (search[0] != DataBase->plate[SortReasult[i]].city)
			continue;
		if (!strcmp(tmp, DataBase->plate[SortReasult[i]].number))
			return SortReasult[i];
	}
	return -1;
}
//对半查找
int SearchInHalf(PlateDatabase* DataBase, char* search, int* SortReasult)
{
	char searchNumber[6] = { 'x','x','x','x','x','\0' };
	searchNumber[0] = search[1];
	searchNumber[1] = search[2];
	searchNumber[2] = search[3];
	searchNumber[3] = search[4];
	searchNumber[4] = search[5];
	char searchCity = search[0];
	//中间节点
	int low = 0;
	int high = DataBase->plateCount-1;
	int mid = (low + high) / 2;
	int Result = strcmp(searchNumber,DataBase->plate[SortReasult[mid]].number);
	if (Result == 0)
	{
		if (searchCity == DataBase->plate[SortReasult[mid]].city)
			return SortReasult[mid];
	}
	if (Result < 0)
	{
		SearchInHalf(DataBase, searchNumber, searchCity, SortReasult, low, mid-1);
	}
	else
	{
		SearchInHalf(DataBase, searchNumber, searchCity, SortReasult, mid+1, high);
	}
}
int SearchInHalf(PlateDatabase* DataBase, char* searchNumber, char searchCity,int* SortReasult, int low, int high)
{
	if (high < low)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	int Result = strcmp(searchNumber, DataBase->plate[SortReasult[mid]].number);
	if (Result == 0)
	{
		if (searchCity == DataBase->plate[SortReasult[mid]].city)
			return SortReasult[mid];
	}
	if (Result < 0)
	{
		SearchInHalf(DataBase, searchNumber, searchCity, SortReasult, low, mid - 1);
	}
	else
	{
		SearchInHalf(DataBase, searchNumber, searchCity, SortReasult, mid + 1, high);
	}
}
//索引查找
int SearchInIndex(PlateDatabase* DataBase, char* search, int start, int end)
{
	//首先我们先取出车牌
	char tmp[6] = { 'x','x','x','x','x','\0' };
	tmp[0] = search[1];
	tmp[1] = search[2];
	tmp[2] = search[3];
	tmp[3] = search[4];
	tmp[4] = search[5];
	for (int i = start; i <= end; i++)
	{
		if (!strcmp(tmp, DataBase->plate[i].number))
			return i;
	}
	return -1;
}
void initIndex(PlateDatabase* DataBase, PlateIndex* Index, int* SortReasult)
{
	char flag = 'A';//当前字符
	Index->start[flag - 65] = 0;
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		if (DataBase->plate[SortReasult[i]].city > flag)
		{
			Index->end[flag - 65] = i - 1;
			flag = DataBase->plate[SortReasult[i]].city;
			Index->start[flag - 65] = i;
		}
	}
}
//和数据库匹配城市名称（输入字符串，输出字符串）
void MatchCarCity(char city, char* CITY)
{
	switch (city)
	{
	case 'A':
		strcpy(CITY, "南京");
		return;
	case 'B':
		strcpy(CITY, "无锡");
		return;
	case 'C':
		strcpy(CITY, "徐州");
		return;
	case 'D':
		strcpy(CITY, "常州");
		return;
	case 'E':
		strcpy(CITY, "苏州");
		return;
	case 'F':
		strcpy(CITY, "南通");
		return;
	case 'G':
		strcpy(CITY, "连云港");
		return;
	case 'H':
		strcpy(CITY, "淮安");
		return;
	case 'J':
		strcpy(CITY, "盐城");
		return;
	case 'K':
		strcpy(CITY, "扬州");
		return;
	case 'L':
		strcpy(CITY, "镇江");
		return;
	case 'M':
		strcpy(CITY, "泰州");
		return;
	case 'N':
		strcpy(CITY, "宿迁");
		return;
	}
}
