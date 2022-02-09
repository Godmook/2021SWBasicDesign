#include"Town.h"

void Check_Portal() {
    if (pcDetectCollision(pcX, pcY) == 2)// ������ ���ŷ� �̵�
    {
        STATE = BUY_ITEM;
    }
    if (pcDetectCollision(pcX, pcY) == 3)// ��� ��ȭ�� �̵�
    {
        STATE = UPGRADE_EQUIP;
    }

    if (pcDetectCollision(pcX, pcY) == 4)// �Ĺ� ������ �̵�
    {
        STATE = START_NOMAL;
    }
    if (pcDetectCollision(pcX, pcY) == 5)// ���� ������ �̵�
    {
        STATE = START_BOSS_BATTEL;
    }
    if (pcDetectCollision(pcX, pcY) == 6)// �Ĺ� ������ �̵�
    {
        STATE = START_TOWN;
    }
}
void startNormalSituationInTown()
{
    PCSet();
    pcX = 60;
    pcY = 15;
    drawNormalSituationInTown();
    while (1)
    {
        normalSituationProcessKeyInput();
        if (STATE != START_TOWN)break;
    }
}

void drawNormalSituationInTown()
{
    system("cls");
    for (int x = 0; x < 125; x++) {
        gotoxy(x, 39);
        printf("��");
    }
    for (int y = 0; y < 50; y++) {
        gotoxy(125, y);
        printf("��");
    }
    for (int x = 126; x < 160; x++) {
        gotoxy(x, 11);
        printf("��");
    }
    drawNormalSituationInTownMap();
    drawNormalSituationMenu();
    drawNormalSituationStat();
    drawNormalSituationInventory();
    // �ΰ��� ȭ�� �⺻Ʋ ���

}

void DrawTown()
{
    int i, j;
    for (i = 0; i < 39; i++)
    {
        for (j = 0; j < 123; j++)
        {
            gotoxy(j, i);
            switch (TownInfo[i][j]) {
            case 1: printf("*"); break;
            case 2: case 3: case 4:
                printf("/"); break;
            }
        }
    }

    gotoxy(20, 8); printf("< ������ ���� >");
    gotoxy(90, 8); printf("< ��� ��ȭ >");
    gotoxy(56, 34); printf("< �Ĺ� �� >");


}

void drawNormalSituationInTownMap()
{
    // �� �׸��� �߰�

    DrawTown();
    pcDraw();

}