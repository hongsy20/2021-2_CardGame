#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "main.h"
#include "windows.h"


int mainPtr(void);



void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};
void title(void) {
    int POS = 2;
    int true = 1;
    CursorView(0);    //커서의 깜빡임을 숨겨준다.
    system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
    mainPtr();
    while (true) {
        if (GetAsyncKeyState(VK_DOWN))
            if (POS == 1) POS = 0;
            else POS = 0;
        else if (GetAsyncKeyState(VK_UP))
            if (POS == 0) POS = 1;
            else POS = 1;
        else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
            break;
        switch (POS) {
        case 0:
            gotoxy(60, 17); printf("시작 하기");
            SetColor(11);
            gotoxy(60, 20); printf("게임 종료");
            SetColor(14);
            break;

        case 1:
            gotoxy(60, 17); printf("시작 하기");
            SetColor(14);
            gotoxy(60, 20); printf("게임 종료");
            SetColor(11);
            break;
        default: break;
        }
        Sleep(10);
    }
    cls;
    if (POS == 1) system("cls");

    else if (POS == 0) puts("종료를 눌렀습니다.");

    return 0;
}


int mainPtr(void) {
    system("mode con:cols=150 lines=40");
    system("title 카드짝맞추기 - 메인");

    int POS = 2;
    CursorView(0);    //커서의 깜빡임을 숨겨준다.
    system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.


    textcolor(14);
    puts("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■      #########          ###          #######         ########             #########        ######    ##        ##    ########      ■");
    puts("    ■    ##                ##    ##      ##      ##      ##       ##          ##                ##   ##    ## ##  ## ##   ##             ■");
    puts("    ■   ##               #########      ##     ##       ##       ##          ##      ####      ########    ##   ##   ##   ########       ■");
    puts("    ■   ##             ##      ##      ##    ##        ##       ##           ##        ##     ##     ##    ##        ##  ##              ■");
    puts("    ■    #########   ##      ##      ##        ##     ##########              #########      ##      ##    ##        ##  ########        ■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■                                                                                                                                    ■");
    puts("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");



    while (1) {
        if (GetAsyncKeyState(VK_DOWN))
            if (POS == 1) POS = 0;
            else POS = 0;
        else if (GetAsyncKeyState(VK_UP))
            if (POS == 0) POS = 1;
            else POS = 1;
        else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
            break;
        switch (POS) {
        case 0:
            gotoxy(60, 17); printf("새로 하기");
            SetColor(11);
            gotoxy(60, 20); printf("게임 종료");
            SetColor(14);
            break;

        case 1:
            gotoxy(60, 17); printf("새로 하기");
            SetColor(14);
            gotoxy(60, 20); printf("게임 종료");
            SetColor(11);
            break;
        default: break;
        }
        Sleep(10);
        gotoxy(60, 17); printf("시작 하기");

        gotoxy(60, 20); printf("게임 종료");
    }
    cls;
    if (POS == 1) {
        return 1;
    }

    else if (POS == 0)
    {
        puts("종료를 눌렀습니다.");
        return 0;
    }




}





//int originmap[4][4] = {
//   {1,4,2,3},
//   {3,6,1,5},
//   {7,2,8,6},
//   {5,8,7,4}
//};








int originmap[4][4] = {
   {0,0,0,0},
   {0,0,0,0},
   {0,0,0,0},
   {0,0,0,0}
};

int checkmap[4][4] = {
    {0,0,0,0},
   {0,0,0,0},
   {0,0,0,0},
   {0,0,0,0}
};


struct Pos {
    int x;
    int y;
};
struct Pos player; // 플레이어의 커서 위치
struct Pos flippos[2]; // 뒤집은 카드의 위치

void Gotoxy(int x, int y)
{
    COORD gotopos;
    gotopos.X = x;
    gotopos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gotopos);
}

char questionmap[4][4];
int flipcounter; //뒤집은 카드 수
int matchcardcount; // 맞춘 카드의 개수
int try_count; // 카드 뒤집기 시도 횟수(2번이 1번 )
clock_t start, end;
double result;
void init();
int Getkey();
void Movepos();
void Flipcard();
void Checkcard();
void Drawmap();
void timer();
void gamepan();
void Random();
int checkdata(int i, int j, int num);







int main(void)
{
    int key = 0;
    int game_result = 0;
    game_result = mainPtr();


    if (game_result)
    {
        init();
        Drawmap();
        CursorView(1);
        Gotoxy(player.x * 3 + 2, player.y * 3 + 1);
        start = clock();

        while (1)
        {
            key = Getkey();
            if (key == 224)
                Movepos();
            if (key == 32)
                Flipcard();
            if (matchcardcount >= 8)
            {
                end = clock();
                result = (double)(end - start) / CLOCKS_PER_SEC;
                cls;
                Gotoxy(20, 20);

                printf("성공하셨습니다.");
                Gotoxy(20, 21);
                printf("걸린 시간은 %0.1lf초입니다.", result);
                //Gotoxy(20, 22);
                //printf("다시 하기");
                //Gotoxy(20, 23);
                //printf("처음 으로");

                break;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
    //다시 리턴
   // randomize();
  //  setcursortype(SOLIDCURSOR);




}

void Drawmap()
{
    system("cls");
    system("mode con:cols=50 lines=40");

    int i, k;



    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    int x, y;


    Gotoxy(20, 0); printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    Gotoxy(20, 1); printf("┃    카드짝 맞추기 게임    ┃");
    Gotoxy(20, 2); printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛");


    Gotoxy(20, 4); printf("             UP");
    Gotoxy(20, 6); printf("             ↑");
    Gotoxy(20, 8); printf("   LEFT   ←    →    RIGHT");
    Gotoxy(20, 10); printf("             ↓");
    Gotoxy(20, 12); printf("            DOWN");


    Gotoxy(20, 14); printf("     찾기 : 스페이스바");

    //Gotoxy(20, 21); printf("     시도 횟수 : %d", try_count);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Gotoxy(20, 23); printf("시도횟수   : %d", try_count);
    Gotoxy(20, 25); printf("정답  : %d", matchcardcount);

    for (i = 0; i < 4; i++)
    {
        for (k = 0; k < 4; k++)
        {
            questionmap[i][k] = '?';

        }
    }

    for (i = 0; i < 4; i++)
    {
        for (k = 0; k < 4; k++)
        {
            Gotoxy(i * 3, k * 3);
            printf("┏━━┓");
            Gotoxy(i * 3, k * 3 + 1);
            printf("┃");
            printf(" %c", questionmap[i][k]);
            printf("┃");
            Gotoxy(i * 3, k * 3 + 2);
            printf("┗━━┛");

        }
        /*printf("%c ", questionmap[i][k]);*/
    //printf("\n");




    }


}


void init()
{
    int flipcounter = 0;
    int spacecount = 0;
    int matchcardcount = 0;
    try_count = 0;
    srand(time(NULL));

    Random();


}

void Random()  //카드 랜덤 함수
{
    int i = 0, j = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            int randomdata = rand() % 8 + 1;

            if (checkdata(i, j, randomdata) == 1)
            {
                originmap[i][j] = randomdata;
                j++;
            }
        }
        i++;
    }
}
int checkdata(int i, int j, int num)
{
    int counter = 0;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (originmap[x][y] == 0)
                break;
            if (originmap[x][y] == num)
                counter++;
            if (counter > 1)
                return 0;

        }
    }
    return 1;
}

int Getkey()
{
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}

void Movepos()
{
    switch (_getch())
    {
    case 72:
        --player.y;
        if (player.y <= 0)
            player.y = 0;
        Gotoxy(player.x * 3 + 2, player.y * 3 + 1);
        break;
    case 75:
        --player.x;
        if (player.x <= 0)
            player.x = 0;
        Gotoxy(player.x * 3 + 2, player.y * 3 + 1);
        break;
    case 77:
        ++player.x;
        if (player.x >= 3)
            player.x = 3;
        Gotoxy(player.x * 3 + 2, player.y * 3 + 1);
        break;
    case 80:
        ++player.y;
        if (player.y >= 3)
            player.y = 3;
        Gotoxy(player.x * 3 + 2, player.y * 3 + 1);
        break;
    }
}

void Flipcard()
{
    int count = 0;
    if (checkmap[player.x][player.y] == 0)
    {
        if (flipcounter < 2)
        {
            questionmap[player.x][player.y] = originmap[player.x][player.y];
            printf("%d", questionmap[player.x][player.y]);
            flippos[flipcounter].x = player.x;
            flippos[flipcounter].y = player.y;
            ++flipcounter;
            Gotoxy(player.x * 3 + 2, player.y * 3 + 1);



        }
        if (flipcounter == 2)
        {
            Checkcard();
            try_count++;
            Gotoxy(20, 23); printf("시도횟수   : %d", try_count);
            Gotoxy(flippos[1].x * 3 + 2, flippos[1].y * 3 + 1);
        }
    }
}

void Checkcard()
{

    if (questionmap[flippos[0].x][flippos[0].y] == questionmap[flippos[1].x][flippos[1].y])
    {
        matchcardcount++;


        Sleep(1000);
        Gotoxy(flippos[0].x * 3 + 2, flippos[0].y * 3 + 1);
        questionmap[flippos[0].x][flippos[0].y] = ' ';
        printf("%c", questionmap[flippos[0].x][flippos[0].y]);

        Gotoxy(flippos[1].x * 3 + 2, flippos[1].y * 3 + 1);
        questionmap[flippos[1].x][flippos[1].y] = ' ';
        printf("%c", questionmap[flippos[1].x][flippos[1].y]);

        Gotoxy(flippos[1].x * 3 + 2, flippos[1].y * 3 + 1); // 커서가 옆으로 넘어가서 다시 옮겨준거.
        checkmap[flippos[0].x][flippos[0].y] = 1;
        checkmap[flippos[1].x][flippos[1].y] = 1;




    }
    else
    {
        Sleep(1000);

        Gotoxy(flippos[0].x * 3 + 2, flippos[0].y * 3 + 1);
        questionmap[flippos[0].x][flippos[0].y] = '?';
        printf("%c", questionmap[flippos[0].x][flippos[0].y]);

        Gotoxy(flippos[1].x * 3 + 2, flippos[1].y * 3 + 1);
        questionmap[flippos[1].x][flippos[1].y] = '?';
        printf("%c", questionmap[flippos[1].x][flippos[1].y]);

        Gotoxy(flippos[1].x * 3 + 2, flippos[1].y * 3 + 1);


    }

    Gotoxy(20, 25); printf("정답  : %d", matchcardcount);


    //questionmap[flippos[0].x][flippos[0].y] = '?';
    //questionmap[flippos[1].x][flippos[1].y] = '?';
    flipcounter = 0;
}