#pragma once
#include <stdio.h>

#define MAXSIZE 999
//ȫ�������ʽ
#define FONT "����"
#define FONT2_ZH "����"
#define FONT2_EN "Consolas"

#define DEBUG

//������Ϣ�ṹ��
//���ǲ���������Դ���ƣ�����˵���Ƴ�ȥ��������5λ
typedef struct plate
{
	char city;						//����
	char number[8]="\0";			//���ƺ�
	char cartype[64]="\0";			//������Ϣ
	char ownerName[64] = "\0";		//������Ϣ-����
	char ownerPhone[16] = "\0";		//������Ϣ-�ֻ�
}Plate;

typedef struct plateDatabase
{
	Plate plate[MAXSIZE];
	int plateCount=0;
}PlateDatabase;

typedef struct plateIndex
{
	//int StartA;//�Ͼ�
	//int EndA;
	//int StartB;//����
	//int EndB;
	//int StartC;//����
	//int EndC;
	//int StartD;//����
	//int EndD;
	//int StartE;//����
	//int EndE;
	//int StartF;//��ͨ
	//int EndF;
	//int StartG;//���Ƹ�
	//int EndG;
	//int StartH;//����
	//int EndH;
	//int StartJ;//�γ�
	//int EndJ;
	//int StartK;//����
	//int EndK;
	//int StartL;//��
	//int EndL;
	//int StartM;//̩��
	//int EndM;
	//int StartN;//��Ǩ
	//int EndN;
	int start[26];
	int end[26];
}PlateIndex;

typedef struct USER//�û�
{
	char id[21] = "\0";			//�˺� 
	char pwd[21] = "\0";		//���� 
	char Identity = -1;			//���Ϊ�����ַ���0Ϊ�û���1Ϊ����Ա��
}USER;