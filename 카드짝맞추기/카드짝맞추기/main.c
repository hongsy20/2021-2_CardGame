#pragma once

#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
/* ��� ����  */

/*  define ����  */
#define pause system("pause > nul")   
#define cls system("cls")   


/*  �Լ� ����  */
void SetColor(int color);
void CursorView(char show);
void gotoxy(int x, int y);