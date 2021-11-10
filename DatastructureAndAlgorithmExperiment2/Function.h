#pragma once
#include "struct.h"
#include <graphics.h>
#include<easyx.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
using namespace std;

//从csv文件导入数据库
void ImportDatabase(FILE* fp, plateDatabase* DataBase);
//导出到csv文件
void ExportDatabase(FILE* fp, plateDatabase* DataBase, int* SortResult);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//排序（按照车牌顺序ASCII码排序）(不包含城市位）
void DataBaseInsertSort(plateDatabase* DataBase, int* SortReasult);
//排序（按照车牌顺序ASCII码排序）(包含城市位）
void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult);
//最原始的搜索，顺序匹配字符串（返回下标）
int Search(PlateDatabase* DataBase, char* search);
//顺序查找，根据排序查找
int SearchInOrder(PlateDatabase* DataBase, char* search, int* SortReasult);
//对半查找
int SearchInHalf(PlateDatabase* DataBase, char* search, int* SortReasult);
//对半查找
int SearchInHalf(PlateDatabase* DataBase, char* searchNumber, char searchCity, int* SortReasult, int low, int high);
//索引查找
int SearchInIndex(PlateDatabase* DataBase, char* search, int start, int end, int* SortResult);
//初始化索引列表
void initIndex(PlateDatabase* DataBase, PlateIndex* Index, int* SortReasult);
//和数据库匹配城市名称（输入字符串，输出字符串）
void MatchCarCity(char city, char* CITY);
