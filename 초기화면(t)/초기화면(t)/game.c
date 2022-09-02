#include "main.h"
#include "windows.h"

void mainPtr(void);

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};

int main(void) {
    int POS = 2;
    CursorView(0);    //커서의 깜빡임을 숨겨준다.
    system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
    mainPtr();
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
    }
    cls;
    if (POS == 1) puts("새로 하기를 눌렀습니다.");
    else if (POS == 0) puts("종료를 눌렀습니다.");

    return 0;
}


void mainPtr(void) {
    system("mode con:cols=150 lines=40");
    system("title 카드짝맞추기 - 메인");

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




    gotoxy(60, 17); printf("새로 하기");

    gotoxy(60, 20); printf("게임 종료");
    return;
}