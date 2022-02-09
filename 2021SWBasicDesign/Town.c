#include"Town.h"

void Check_Portal() {
    if (pcDetectCollision(pcX, pcY) == 2)// 아이템 구매로 이동
    {
        STATE = BUY_ITEM;
    }
    if (pcDetectCollision(pcX, pcY) == 3)// 장비 강화로 이동
    {
        STATE = UPGRADE_EQUIP;
    }

    if (pcDetectCollision(pcX, pcY) == 4)// 파밍 맵으로 이동
    {
        STATE = START_NOMAL;
    }
    if (pcDetectCollision(pcX, pcY) == 5)// 보스 맵으로 이동
    {
        STATE = START_BOSS_BATTEL;
    }
    if (pcDetectCollision(pcX, pcY) == 6)// 파밍 맵으로 이동
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
        printf("─");
    }
    for (int y = 0; y < 50; y++) {
        gotoxy(125, y);
        printf("│");
    }
    for (int x = 126; x < 160; x++) {
        gotoxy(x, 11);
        printf("─");
    }
    drawNormalSituationInTownMap();
    drawNormalSituationMenu();
    drawNormalSituationStat();
    drawNormalSituationInventory();
    // 인게임 화면 기본틀 출력

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

    gotoxy(20, 8); printf("< 아이템 상점 >");
    gotoxy(90, 8); printf("< 장비 강화 >");
    gotoxy(56, 34); printf("< 파밍 맵 >");


}

void drawNormalSituationInTownMap()
{
    // 맵 그리기 추가

    DrawTown();
    pcDraw();

}