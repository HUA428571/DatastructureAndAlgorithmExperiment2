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

//��csv�ļ��������ݿ�
void ImportDatabase(FILE* fp, plateDatabase* DataBase);
//������csv�ļ�
void ExportDatabase(FILE* fp, plateDatabase* DataBase, int* SortResult);
//������������ݣ��������ƣ���������λ�ã����������λ�ã�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, const char* Default);
//������������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int C_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//�����_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int CR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//�����_����ʾ�ַ�_��¼���棨�������ݣ��������ƣ���������λ�ã����������λ�ã�������ܳ��ȣ�����߶ȣ�Ĭ����ʾ�����ݣ�
int CHR_InputBox(char* Input, int Limit, int x, int y, int Lsize, int Hsize, const char* Default);
//���򣨰��ճ���˳��ASCII������(����������λ��
void DataBaseInsertSort(plateDatabase* DataBase, int* SortReasult);
//���򣨰��ճ���˳��ASCII������(��������λ��
void DataBaseInsertSortWithCity(plateDatabase* DataBase, int* SortReasult);
//��ԭʼ��������˳��ƥ���ַ����������±꣩
int Search(PlateDatabase* DataBase, char* search);
//˳����ң������������
int SearchInOrder(PlateDatabase* DataBase, char* search, int* SortReasult);
//�԰����
int SearchInHalf(PlateDatabase* DataBase, char* search, int* SortReasult);
//�԰����
int SearchInHalf(PlateDatabase* DataBase, char* searchNumber, char searchCity, int* SortReasult, int low, int high);
//��������
int SearchInIndex(PlateDatabase* DataBase, char* search, int start, int end, int* SortResult);
//��ʼ�������б�
void initIndex(PlateDatabase* DataBase, PlateIndex* Index, int* SortReasult);
//�����ݿ�ƥ��������ƣ������ַ���������ַ�����
void MatchCarCity(char city, char* CITY);
