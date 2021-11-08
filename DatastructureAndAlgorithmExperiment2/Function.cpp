#include "Function.h"

//��csv�ļ��������ݿ�
void ImportDatabase(FILE* fp, plateDatabase* DataBase)
{
	DataBase->plateCount = 0;
	int plateCount = 0;
	char c;
	char buffer[8];
	while (!feof(fp))
	{
		int i = 0;//i������д��char������±��
		DataBase->plate[plateCount].city = fgetc(fp);
		fgetc(fp);//��ȡ���ŷָ���
		while ((c = fgetc(fp)) != ',')//��ȡ���ƺ�
		{
			DataBase->plate[plateCount].number[i] = c;
			i++;
		}
		DataBase->plate[plateCount].number[i] = '\0';//�ַ�����β
		i = 0;
		while ((c = fgetc(fp)) != ',')//��ȡ������Ϣ
		{
			DataBase->plate[plateCount].cartype[i] = c;
			i++;
		}
		DataBase->plate[plateCount].cartype[i] = '\0';//�ַ�����β
		i = 0;
		while ((c = fgetc(fp)) != ',')//��ȡ������Ϣ
		{
			fseek(fp, -1, 1);//�ƶ��ļ�ָ��͵�ǰλ����ǰһ��
			fgets(buffer, 3, fp);
			DataBase->plate[plateCount].ownerName[i] = buffer[0];
			DataBase->plate[plateCount].ownerName[i + 1] = buffer[1];
			i += 2;
		}
		DataBase->plate[plateCount].ownerName[i] = '\0';//�ַ�����β
		i = 0;
		while (i < 11)//��ȡ�����ֻ���
		{
			c = fgetc(fp);
			DataBase->plate[plateCount].ownerPhone[i] = c;
			i++;
		}
		DataBase->plate[plateCount].ownerPhone[i] = '\0';//�ַ�����β
		plateCount++;
		if ((c = fgetc(fp)) == EOF)break;
	}
	DataBase->plateCount = plateCount;
}
//������csv�ļ�
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
//������������ݣ��������ƣ���������λ�ã����������λ�ã�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default)
{
	clearrectangle(x, y, x + 120, y + 40);
	fflush(stdin);//��������뻺��
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
		if (c != 13)//�������Ĳ��ǻس�
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
//������������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize);
	fflush(stdin);//��������뻺��
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
		//while (MouseHit())//�����걻���£����˳�����
		//{
		//	m = GetMouseMsg();
		//	if (m.uMsg == WM_LBUTTONDOWN)
		//	{
		//		strcpy(Input, InputBuf);
		//		return Length;
		//	}
		//}
		c = _getch();
		if (c != 13)//�������Ĳ��ǻس�
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
					if (Length == 0)//��һ���ַ�
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
//�����_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//��������뻺��
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
		if (c != 13)//�������Ĳ��ǻس�
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
					if (Length == 0)//��һ���ַ�
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
//�����_����ʾ�ַ�_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default)
{
	clearrectangle(x, y, x + Lsize, y + Hsize + 2);
	fflush(stdin);//��������뻺��
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
		if (c != 13)//�������Ĳ��ǻس�
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
					if (Length == 0)//��һ���ַ�
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
//���򣨰��ճ���˳��ASCII������(����������λ��
//ʹ��ֱ�Ӳ�������
void DataBaseInsertSort(plateDatabase* DataBase, int* SortReasult)
{
	//����Ҫ��ʼ��һ�´洢������������
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		SortReasult[i] = i;
	}
	int i, j;//iΪ������Ԫ���±�
	Plate cmp;//ÿһ�˴�����(������Ԫ��
	int cmpID;
	for (i = 1; i < DataBase->plateCount; i++)//ѭ���ӵڶ���Ԫ�ؿ�ʼ
	{
		cmpID = SortReasult[i];
		cmp = DataBase->plate[SortReasult[i]];
		for (j = i - 1; j >= 0; j--)//�Ӻ���ǰ����
		{
			//�����Ԫ�ش��ڴ�����Ԫ�أ������Ųһ��λ��Ϊ������Ԫ�ؿճ��ռ�
			if (strcmp(cmp.number, DataBase->plate[SortReasult[j]].number) < 0)
				SortReasult[j + 1] = SortReasult[j];
			else break;
		}
		SortReasult[j + 1] = cmpID;//������Ԫ�ط�������������
	}
}
//���򣨰��ճ���˳��ASCII������(��������λ��
//ʹ��ֱ�Ӳ�������
void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult)
{
	//����Ҫ��ʼ��һ�´洢������������
	for (int i = 0; i < DataBase->plateCount; i++)
	{
		SortReasult[i] = i;
	}
	int i, j;//iΪ������Ԫ���±�
	Plate cmp;//ÿһ�˴�����(������Ԫ��
	int cmpID;
	for (i = 1; i < DataBase->plateCount; i++)//ѭ���ӵڶ���Ԫ�ؿ�ʼ
	{
		cmpID = SortReasult[i];
		cmp = DataBase->plate[SortReasult[i]];
		for (j = i - 1; j >= 0; j--)//�Ӻ���ǰ����
		{
			//�����Ԫ�ش��ڴ�����Ԫ�أ������Ųһ��λ��Ϊ������Ԫ�ؿճ��ռ�
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
		SortReasult[j + 1] = cmpID;//������Ԫ�ط�������������
	}
}

//void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult)
//{
//	//����Ҫ��ʼ��һ�´洢������������
//	for (int i = 0; i < DataBase->plateCount; i++)
//	{
//		SortReasult[i] = i;
//	}
//	int i, j;//iΪ������Ԫ���±�
//	int cmpID;
//	char tmpi[8] = { 'X','\0' };
//	char tmpj[8] = { 'X','\0' };
//	for (i = 1; i < DataBase->plateCount; i++)//ѭ���ӵڶ���Ԫ�ؿ�ʼ
//	{
//		cmpID = SortReasult[i];
//		tmpi[1] = '\0';
//		tmpj[1] = '\0';
//		tmpi[0] = DataBase->plate[SortReasult[i]].city;
//		strcat(tmpi, DataBase->plate[SortReasult[i]].number);
//		for (j = i - 1; j >= 0; j--)//�Ӻ���ǰ����
//		{
//			//�����Ԫ�ش��ڴ�����Ԫ�أ������Ųһ��λ��Ϊ������Ԫ�ؿճ��ռ�
//			tmpj[0] = DataBase->plate[SortReasult[j]].city;
//			tmpj[1] = '\0';
//			strcat(tmpj, DataBase->plate[SortReasult[j]].number);
//			if (strcmp(tmpi, tmpj) < 0)
//				SortReasult[j + 1] = SortReasult[j];
//			else break;
//		}
//		SortReasult[j + 1] = cmpID;//������Ԫ�ط�������������
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
//��ԭʼ��������˳��ƥ���ַ����������±꣩
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
//˳����ң������������
int SearchInOrder(PlateDatabase* DataBase, char* search, int* SortReasult)
{
	//����������ȡ������
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
//�԰����
int SearchInHalf(PlateDatabase* DataBase, char* search, int* SortReasult)
{
	char searchNumber[6] = { 'x','x','x','x','x','\0' };
	searchNumber[0] = search[1];
	searchNumber[1] = search[2];
	searchNumber[2] = search[3];
	searchNumber[3] = search[4];
	searchNumber[4] = search[5];
	char searchCity = search[0];
	//�м�ڵ�
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
//��������
int SearchInIndex(PlateDatabase* DataBase, char* search, int start, int end)
{
	//����������ȡ������
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
	char flag = 'A';//��ǰ�ַ�
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
//�����ݿ�ƥ��������ƣ������ַ���������ַ�����
void MatchCarCity(char city, char* CITY)
{
	switch (city)
	{
	case 'A':
		strcpy(CITY, "�Ͼ�");
		return;
	case 'B':
		strcpy(CITY, "����");
		return;
	case 'C':
		strcpy(CITY, "����");
		return;
	case 'D':
		strcpy(CITY, "����");
		return;
	case 'E':
		strcpy(CITY, "����");
		return;
	case 'F':
		strcpy(CITY, "��ͨ");
		return;
	case 'G':
		strcpy(CITY, "���Ƹ�");
		return;
	case 'H':
		strcpy(CITY, "����");
		return;
	case 'J':
		strcpy(CITY, "�γ�");
		return;
	case 'K':
		strcpy(CITY, "����");
		return;
	case 'L':
		strcpy(CITY, "��");
		return;
	case 'M':
		strcpy(CITY, "̩��");
		return;
	case 'N':
		strcpy(CITY, "��Ǩ");
		return;
	}
}
