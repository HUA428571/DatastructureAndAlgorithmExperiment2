#pragma once
#include <stdio.h>

#define MAXSIZE 999
//全局字体格式
#define FONT "黑体"
#define FONT2_ZH "宋体"
#define FONT2_EN "Consolas"

#define DEBUG

//车牌信息结构体
//我们不考虑新能源车牌，所以说车牌除去地区还有5位
typedef struct plate
{
	char city;						//城市
	char number[8]="\0";			//车牌号
	char cartype[64]="\0";			//车辆信息
	char ownerName[64] = "\0";		//车主信息-姓名
	char ownerPhone[16] = "\0";		//车主信息-手机
}Plate;

typedef struct plateDatabase
{
	Plate plate[MAXSIZE];
	int plateCount=0;
}PlateDatabase;

typedef struct plateIndex
{
	//int StartA;//南京
	//int EndA;
	//int StartB;//无锡
	//int EndB;
	//int StartC;//徐州
	//int EndC;
	//int StartD;//常州
	//int EndD;
	//int StartE;//苏州
	//int EndE;
	//int StartF;//南通
	//int EndF;
	//int StartG;//连云港
	//int EndG;
	//int StartH;//淮安
	//int EndH;
	//int StartJ;//盐城
	//int EndJ;
	//int StartK;//扬州
	//int EndK;
	//int StartL;//镇江
	//int EndL;
	//int StartM;//泰州
	//int EndM;
	//int StartN;//宿迁
	//int EndN;
	int start[26];
	int end[26];
}PlateIndex;

typedef struct USER//用户
{
	char id[21] = "\0";			//账号 
	char pwd[21] = "\0";		//密码 
	char Identity = -1;			//身份为单个字符（0为用户，1为管理员）
}USER;