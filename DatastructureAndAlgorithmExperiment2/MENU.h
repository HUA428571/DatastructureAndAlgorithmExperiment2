#pragma once
#include"Function.h"
#include"Struct.h"
#include"MENUchoose.h"
#include"print.h"
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<time.h>

int startMENU(USER u[10]);

int CheckID(char* n, char* m, USER u[10]);

int AdminMENU(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_HomeMENU(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_HomeMENU_Import(PlateDatabase* DataBase, PlateIndex* Index, char Location[][100]);

int AdminMENU_HomeMENU_Export(PlateDatabase* DataBase, PlateIndex* Index, char Location[][100]);

int AdminMENU_SearchMENU(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_SearchMENU_SearchInOrder(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_SearchMENU_SearchInHalf(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_SearchMENU_SearchInIndex(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_AddMENU(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_DeleteMENU(PlateDatabase* DataBase, PlateIndex* Index);

int AdminMENU_ChangeMENU(PlateDatabase* DataBase, PlateIndex* Index);

int CustomMENU(PlateDatabase* DataBase, PlateIndex* Index);

int CustomMENU_SearchMENU_SearchInOrder(PlateDatabase* DataBase, PlateIndex* Index);

int CustomMENU_SearchMENU_SearchInHalf(PlateDatabase* DataBase, PlateIndex* Index);

int CustomMENU_SearchMENU_SearchInIndex(PlateDatabase* DataBase, PlateIndex* Index);
