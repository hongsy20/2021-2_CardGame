#pragma once

#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
/* 헤더 선언  */

/*  define 선언  */
#define pause system("pause > nul")   
#define cls system("cls")   


/*  함수 선언  */
void SetColor(int color);
void CursorView(char show);
void gotoxy(int x, int y);