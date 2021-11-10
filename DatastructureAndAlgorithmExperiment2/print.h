#pragma once
//本文件存储显示内容的函数
#include"MENUchoose.h"
#include"Struct.h"
#include"Function.h"
#include<time.h>
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<string>
#include <synchapi.h> 
#include<stdlib.h>
#include<Windows.h>
using namespace std;

void PrintHomeBG(PlateDatabase* DataBase);

void PrintSearchBG(PlateDatabase* DataBase);

void PrintPlateDetail(PlateDatabase* DataBase, int ID);

void PrintPlateDetail(Plate Plate);

void PrintCustomBG(PlateDatabase* DataBase);
