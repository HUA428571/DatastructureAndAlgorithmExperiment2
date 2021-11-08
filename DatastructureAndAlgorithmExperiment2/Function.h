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

void ImportDatabase(FILE* fp, plateDatabase* DataBase);
void ExportDatabase(FILE* fp, plateDatabase* DataBase, int* SortResult);
void DataBaseInsertSort(plateDatabase* DataBase, int* SortReasult);
void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//输入框（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//输入框_不显示字符_登录界面（输入内容，长度限制，输入框横轴位置，输入框纵轴位置，输入框总长度，字体高度，默认显示的内容）
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);

int Search(PlateDatabase* DataBase, char* search);

int SearchInOrder(PlateDatabase* DataBase, char* search, int* SortReasult);

int SearchInHalf(PlateDatabase* DataBase, char* search, int* SortReasult);

int SearchInHalf(PlateDatabase* DataBase, char* searchNumber, char searchCity, int* SortReasult, int low, int high);

int SearchInIndex(PlateDatabase* DataBase, char* search, int start, int end);

void initIndex(PlateDatabase* DataBase, PlateIndex* Index, int* SortReasult);
//和数据库匹配城市名称（输入字符串，输出字符串）
void MatchCarCity(char city, char* CITY);
