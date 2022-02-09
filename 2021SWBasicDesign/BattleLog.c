#include"BattleLog.h"
// 일반 몬스터와의 전투 상황 로그 출력
void drawNormalBattleSituationLog()
{
    for (int y = 1; y < 38; y++)
    {
        for (int x = 126; x < 160; x++)
        {
            gotoxy(x, y);
            printf(" ");
        }
    }
    gotoxy(130, 5); printf("전투 상황 출력");
    drawNormalBattleSituationLogUpdate(""); // 로그 출력 초기화

}

void drawNormalBattleSituationLogUpdate(char* str)
{
    static int y = 7;
    y++;
    if (y == 37)
    {
        drawNormalBattleSituationLog();
        y = 7;
    }
    if (strcmp(str, "") == 0)
        y = 7;
    gotoxy(130, y);
    printf("%s", str);
}