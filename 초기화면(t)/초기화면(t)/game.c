#include "main.h"
#include "windows.h"

void mainPtr(void);

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
};

int main(void) {
    int POS = 2;
    CursorView(0);    //Ŀ���� �������� �����ش�.
    system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
    mainPtr();
    while (1) {
        if (GetAsyncKeyState(VK_DOWN))
            if (POS == 1) POS = 0;
            else POS = 0;
        else if (GetAsyncKeyState(VK_UP))
            if (POS == 0) POS = 1;
            else POS = 1;
        else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
            break;
        switch (POS) {
        case 0:
            gotoxy(60, 17); printf("���� �ϱ�");
            SetColor(11);
            gotoxy(60, 20); printf("���� ����");
            SetColor(14);
            break;

        case 1:
            gotoxy(60, 17); printf("���� �ϱ�");
            SetColor(14);
            gotoxy(60, 20); printf("���� ����");
            SetColor(11);
            break;
        default: break;
        }
        Sleep(10);
    }
    cls;
    if (POS == 1) puts("���� �ϱ⸦ �������ϴ�.");
    else if (POS == 0) puts("���Ḧ �������ϴ�.");

    return 0;
}


void mainPtr(void) {
    system("mode con:cols=150 lines=40");
    system("title ī��¦���߱� - ����");

    textcolor(14);
    puts("    ���������������������������������������������������������������������");
    puts("    ��                                                                                                                                    ��");
    puts("    ��                                                                                                                                    ��");
    puts("    ��                                                                                                                                    ��");
    puts("    ��      #########          ###          #######         ########             #########        ######    ##        ##    ########      ��");
    puts("    ��    ##                ##    ##      ##      ##      ##       ##          ##                ##   ##    ## ##  ## ##   ##             ��");
    puts("    ��   ##               #########      ##     ##       ##       ##          ##      ####      ########    ##   ##   ##   ########       ��");
    puts("    ��   ##             ##      ##      ##    ##        ##       ##           ##        ##     ##     ##    ##        ##  ##              ��");
    puts("    ��    #########   ##      ##      ##        ##     ##########              #########      ##      ##    ##        ##  ########        ��");
    puts("    ��                                                                                                                                    ��");
    puts("    ��                                                                                                                                    ��");
    puts("    ��                                                                                                                                    ��");
    puts("    ���������������������������������������������������������������������");




    gotoxy(60, 17); printf("���� �ϱ�");

    gotoxy(60, 20); printf("���� ����");
    return;
}