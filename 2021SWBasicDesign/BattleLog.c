#include"BattleLog.h"
// �Ϲ� ���Ϳ��� ���� ��Ȳ �α� ���
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
    gotoxy(130, 5); printf("���� ��Ȳ ���");
    drawNormalBattleSituationLogUpdate(""); // �α� ��� �ʱ�ȭ

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