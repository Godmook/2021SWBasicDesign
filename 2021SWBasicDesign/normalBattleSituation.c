#include "normalBattleSituation.h"
#pragma warning(disable:4996)

char Skill_str[3][30] = { 0, };
int Skill_Element[3] = { 0, };
int n = 0;
int Status = 0;
int Run_Flag = 0;
int ChangeTheme = 1;
int Check_Using_Item = 0;
COORD s[4] = { {19,42},{59,42},{19,47},{59,47} };
void dieNormal()
{
    if (hp <= 0)
    {
        system("cls");
        gotoxy(65, 17); printf(" ����� �Ϲ� �������� �׾����ϴ�");
        gotoxy(67, 22); printf("�������� �ٽ� ��Ƴ��� �˴ϴ�.");
        gotoxy(65, 27); printf(" (��� ��� ���� -1)");
        Sleep(2000);
        for (int i = 0; i < 5; i++)
            if (equipmentLevel[i] > 1) equipmentLevel[i]--;
     
        PCSet();
        hp = maxHp;
        mp = maxMp;

        STATE = START_TOWN;
    }
}
// �Ϲ� ���Ϳ��� ���� ��Ȳ ȭ�� ����
void startNormalBattleSituation(Monster* monster)
{
    n = 0;
    Status = 0;
    Run_Flag = 0;
    ChangeTheme = 1;
    Check_Using_Item = 0;
    drawNormalBattleSituation(monster);
    drawNormalBattleSituation_PCandMonster(monster);
    while (DrawPointerForBattleSituation(s, monster)) {
        if (STATE == START_TOWN) break;
        // enter �Է�
        if (ChangeTheme == -1) {
            drawNormalBattleSituationChoice(monster);
            //drawNormalBattleSituationPCStat();
            ChangeTheme = 1;
        }
        // ���� ����
        if (monster->hp == 0) {
            char str[50];
            sprintf(str, "����ġ %d�� ������ϴ�.", monster->exp);
            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            sprintf(str, "���� %d ������ϴ�.", monster->money);
            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            for (int i = 0; i < monster->level/2; i++) {
                switch (monster->Enhance_Stone[i]) {
                case STONE1:
                    drawNormalBattleSituationLogUpdate("�ϱ� ��ȭ�� ����");
                    drawNormalBattleSituationLogUpdate("������ϴ�.");
                    drawNormalBattleSituationLogUpdate(" ");
                    enhancementStone1 += 1;
                    break;
                case STONE2:
                    drawNormalBattleSituationLogUpdate("�߱� ��ȭ�� ����");
                    drawNormalBattleSituationLogUpdate("������ϴ�.");
                    drawNormalBattleSituationLogUpdate(" ");
                    enhancementStone2 += 1;
                    break;
                case STONE3:
                    drawNormalBattleSituationLogUpdate("��� ��ȭ�� ����");
                    drawNormalBattleSituationLogUpdate("������ϴ�.");
                    drawNormalBattleSituationLogUpdate(" ");
                    enhancementStone3 += 1;
                    break;
                default:
                    break;
                }
            }
            money += monster->money;
            if (level < 16) {
                pcExp += monster->exp;
            }
            if (pcStatTable[5][level] > pcExp) {
                if (hp == 0)dieNormal();
            }
            while (pcStatTable[5][level] <= pcExp) {
                pcExp -= pcStatTable[5][level];
                pcLevelUp();
                if (level == 5 || level == 9 || level == 13)
                    selectSkill();
            }
            if (level >= 16)pcExp = 0;
            _getch();
            break;
        }
        if (Run_Flag) {
            //*monster = SetMonster();
            STATE = START_NOMAL;
            break;
        }
    }
}

// �Ϲ� ���Ϳ��� ���� ��Ȳ �Է� Ű ó��
void SetPoint(COORD* s, int i) {
    if (!Dont_GetKey) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                setcolor(C_PINK, C_BLACK);
                gotoxy(s[j].X, s[j].Y);
                printf(">");
                setcolor(C_WHITE, C_BLACK);
            }
            else {
                gotoxy(s[j].X, s[j].Y);
                printf(" ");
            }
        }
    }
}

int DrawPointerForBattleSituation(COORD* s, Monster* p) {
    for (int i = 0; i < 100; i++) {
        if (_kbhit() != 0) {
            int key = _getch();
            if (!Dont_GetKey) {
                switch (key) {
                case UP:
                    if (Status == 2 || Status == 3) {
                        if (n != 2) {
                            if (Status == 2) {
                                SetPoint(s, 0);
                                Status = 0;
                            }
                            else {
                                SetPoint(s, 1);
                                Status = 1;
                            }
                        }
                    }
                    break;
                case DOWN:
                    if (Status == 0 || Status == 1) {
                        if (n != 2) {
                            if (Status == 0) {
                                SetPoint(s, 2);
                                Status = 2;
                            }
                            else {
                                SetPoint(s, 3);
                                Status = 3;
                            }
                        }
                    }
                    break;
                case RIGHT:
                    if (Status == 2 || Status == 0) {
                        if (n != 2) {
                            if (Status == 0) {
                                SetPoint(s, 1);
                                Status = 1;
                            }
                            else {
                                SetPoint(s, 3);
                                Status = 3;
                            }
                        }
                    }
                    break;
                case LEFT:
                    if (Status == 1 || Status == 3) {
                        if (n != 2) {
                            if (Status == 1) {
                                SetPoint(s, 0);
                                Status = 0;
                            }
                            else {
                                SetPoint(s, 2);
                                Status = 2;
                            }
                        }
                    }
                    break;
                case ONE:
                    if (n != 2) {
                        SetPoint(s, 0);
                        Status = 0;
                    }
                    break;
                case TWO:
                    if (n != 2) {
                        SetPoint(s, 1);
                        Status = 1;
                    }
                    break;
                case THREE:
                    if (n != 2) {
                        SetPoint(s, 2);
                        Status = 2;
                    }
                    break;
                case FOUR:
                    if (n != 2) {
                        SetPoint(s, 3);
                        Status = 3;
                    }
                    break;
                case ENTER:
                    if (n == 0 && Status == 0)n = 2;
                    //�������� ������� ��
                    else if (n == 0 && Status == 1)n = 1;     // ��ų
                    else if (n == 0 && Status == 2)n = 3;
                    else if (n == 0 && Status == 3)n = 4;
                    else if (n == 1 && Status == 0)n = 0;
                    else if (n == 1 && !Skill_Element[Status - 1]) {
                        drawNormalBattleSituationLogUpdate("����� �� ���� ��ų�Դϴ�.");
                        drawNormalBattleSituationLogUpdate(" ");
                    }
                    else if (n == 1 && Status == 1 && mp < 10)
                    {
                        n = 1;        //1���� ��ų �����
                        drawNormalBattleSituationLogUpdate("������ �����մϴ�.");
                        drawNormalBattleSituationLogUpdate(" ");
                    }
                    else if (n == 1 && Status == 2 && mp < 20)
                    {
                        n = 1;        //2���� ��ų �����
                        drawNormalBattleSituationLogUpdate("������ �����մϴ�.");
                        drawNormalBattleSituationLogUpdate(" ");
                    }
                    else if (n == 1 && Status == 3 && mp < 40)
                    {
                        n = 1;        //3���� ��ų �����
                        drawNormalBattleSituationLogUpdate("������ �����մϴ�.");
                        drawNormalBattleSituationLogUpdate(" ");
                    }
                    else if (n == -1)n = 0;
                    else if (n == 1 && Status != 0)n = 2;
                    else if (n == 2)n = 0;
                    else if (n == 3 && Status == 1) { // ü�������� ����Ҷ�
                        UsingHpPortion();
                        Status = 0;
                        if (Check_Using_Item) {
                            Check_Using_Item = 0;
                            n = 0;
                            Sleep(10);
                            Monster_Damage_Turn(p);
                            if (p->hp > 0) {
                                dieNormal();
                            }
                        }
                    }
                    else if (n == 3 && Status == 2) {
                        UsingMpPortion();
                        Status = 0;
                        if (Check_Using_Item) {
                            Check_Using_Item = 0;
                            n = 0;
                            Sleep(10);
                            Monster_Damage_Turn(p);
                            if (p->hp > 0) {
                                dieNormal();
                            }
                        }
                    }
                    else if (n == 3 && Status == 3) { // ü��/���� ������ ����Ҷ� 
                        UsingAllPortion();
                        Status = 0;
                        if (Check_Using_Item) {
                            Check_Using_Item = 0;
                            n = 0;
                            Sleep(10);
                            Monster_Damage_Turn(p);
                            if (p->hp > 0) {
                                dieNormal();
                            }
                        }
                    }
                    else if (n == 3)n = 0;
                    else if (n == 4)n = 0;
                    ChangeTheme *= -1;
                    break;
                }
            }
        }
    }
    return 1;
}
void CalculateUsageOfPortion(int flag, int* arr) {
    int tmp = 0;
    if (flag == 1 || flag == 3) {
        tmp = 0.3 * maxHp;
        if (tmp > (maxHp - hp)) {
            tmp = maxHp - hp;
        }
        arr[0] = tmp;
    }
    if (flag == 2 || flag == 3) {
        tmp = 0.3 * maxMp;
        if (tmp > (maxMp - mp)) {
            tmp = maxMp - mp;
        }
        arr[1] = tmp;
    }
}
void UsingHpPortion() {
    int HpArr[2];
    if (healingPotion == 0) {
        drawNormalBattleSituationLogUpdate("ü�� ������ �����ϴ�.");
        drawNormalBattleSituationLogUpdate(" ");
    }
    else {
        if (hp < maxHp && hp>0) {
            drawNormalBattleSituationLogUpdate("ü�� ������ ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
            char str[50];
            CalculateUsageOfPortion(1, HpArr);
            sprintf(str, "ü�� %d�� ȸ���մϴ�.", (int)HpArr[0]);
            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            healingPotion--;
            int tmp = hp + (int)HpArr[0];
            drawBattleSituationPCHPUp(tmp);
            Check_Using_Item = 1;
        }
        else if (hp == maxHp) {
            drawNormalBattleSituationLogUpdate("ü���� ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
        }
    }
    Dont_GetKey = 0;
}
void UsingAllPortion() {
    int MpArr[2];
    if (allPotion == 0) {
        drawNormalBattleSituationLogUpdate("ü��/���� ������ �����ϴ�.");
        drawNormalBattleSituationLogUpdate(" ");
    }
    else {
        if ((mp < maxMp) || (hp < maxHp && hp>0)) {
            drawNormalBattleSituationLogUpdate("ü��/���� ������ ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
            char str[50];
            CalculateUsageOfPortion(3, MpArr);
            sprintf(str, "ü�� %d�� ȸ���մϴ�.", (int)MpArr[0]);
            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            int tmp = hp + (int)MpArr[0];
            drawBattleSituationPCHPUp(tmp);

            sprintf(str, "���� %d�� ȸ���մϴ�.", (int)MpArr[1]);
            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            tmp = mp + (int)MpArr[1];
            drawBattleSituationPCMPUp(tmp);

            allPotion--;
            Check_Using_Item = 1;
        }
        else if (mp == maxMp && hp == maxHp) {
            drawNormalBattleSituationLogUpdate("ü��/������ ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
        }
    }
    Dont_GetKey = 0;
}
void UsingMpPortion() {
    int MpArr[2];
    if (manaPotion == 0) {
        drawNormalBattleSituationLogUpdate("���� ������ �����ϴ�.");
        drawNormalBattleSituationLogUpdate(" ");
    }
    else {
        if (mp < maxMp) {
            drawNormalBattleSituationLogUpdate("���� ������ ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
            char str[50];
            CalculateUsageOfPortion(2, MpArr);
            sprintf(str, "���� %d�� ȸ���մϴ�.", (int)MpArr[1]);

            drawNormalBattleSituationLogUpdate(str);
            drawNormalBattleSituationLogUpdate(" ");
            manaPotion--;
            int tmp = mp + (int)MpArr[1];
            drawBattleSituationPCMPUp(tmp);
            Check_Using_Item = 1;
        }
        else if (mp == maxMp) {
            drawNormalBattleSituationLogUpdate("������ ����մϴ�.");
            drawNormalBattleSituationLogUpdate(" ");
        }
    }
    Dont_GetKey = 0;
}
// �Ϲ� ���Ϳ��� ���� ��Ȳ �⺻ ȭ�� ���
void drawNormalBattleSituation(Monster* monster)
{
    system("cls");
    RemoveCursor();
    for (int x = 0; x < 160; x++) {
        gotoxy(x, 39);
        printf("��");
    }
    for (int y = 0; y < 39; y++) {
        gotoxy(125, y);
        printf("��");
    }
    for (int y = 40; y < 50; y++) {
        gotoxy(100, y);
        printf("��");
    }
    drawNormalBattleSituationMonsterStat(monster);  // ���� ü��
    drawNormalBattleSituationPCStat();  // pc ü��, ����
    drawNormalBattleSituationLog(); // �α�â
    drawNormalBattleSituationInventory();
    if (STATE == START_N_BATTLE)
        drawNormalBattleSituationChoice(monster);
}

// �Ϲ� ���Ϳ��� ���� ��Ȳ �� ���� HP ���
void drawNormalBattleSituationMonsterStat(Monster* s)
{
    // ü��, ���� ����

    // ü�� ���
    int ratioHp = s->hp / (s->maxHp / 32.0f);

    // ü�� ���
    setcolor(C_WHITE, C_BLACK);
    gotoxy(105, 40); printf("����");
    gotoxy(105, 42); printf("ü��");
    gotoxy(110, 42);

    setcolor(C_WHITE, C_RED_);
    for (int i = 0; i < ratioHp; i++)
        printf(" ");
    setcolor(C_WHITE, C_RED);
    for (int i = ratioHp; i < 32; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", s->hp, s->maxHp);

}
// �Ϲ� ���Ϳ��� ���� ��Ȳ �� PC ���� ���
void drawNormalBattleSituationPCStat()
{

    // ü��, ���� ����
    int ratioHp = hp / (maxHp / 32.0f);
    int ratioMp = mp / (maxMp / 32.0f);

    // ü�� ���
    setcolor(C_WHITE, C_BLACK);
    gotoxy(105, 44); printf("�÷��̾�");
    gotoxy(105, 46); printf("ü��");
    gotoxy(110, 46);

    setcolor(C_WHITE, C_RED_);
    for (int i = 0; i < ratioHp; i++)
        printf(" ");
    setcolor(C_WHITE, C_RED);
    for (int i = ratioHp; i < 32; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", hp, maxHp);

    // ���� ���

    setcolor(C_WHITE, C_BLACK);
    gotoxy(105, 48); printf("����");
    gotoxy(110, 48);
    setcolor(C_WHITE, C_BLUE_);

    for (int i = 0; i < ratioMp; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLUE);
    for (int i = ratioMp; i < 32; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", mp, maxMp);

}


// �Ϲ� ���Ϳ��� ���� ��Ȳ �κ��丮 ���
void drawNormalBattleSituationInventory()
{

}
void drawNormalBattleSituationChoiceClean() {
    for (int xx = 10; xx < 95; xx++) {
        for (int yy = 40; yy < 50; yy++) {
            gotoxy(xx, yy);
            printf(" ");
        }
    }
}
void drawNormalBattleSituationChoice_Page1() {
    drawNormalBattleSituationChoiceClean();
    SetPoint(s, Status);
    gotoxy(20, 42); printf("�⺻���� (1)");
    gotoxy(60, 42); printf("��ų���� (2)");
    gotoxy(20, 47); printf("������ ���(3)");
    gotoxy(60, 47); printf("���� ����(4)");
}
void StrCpy_Skill(int idx) {        //�� ȭ ��
    char tmp1[30] = { 0, };
    switch (takenSkill[idx]) {
    case -1: strcpy(Skill_str[idx], "��ų�� ����� ���� (");
        strcat(Skill_str[idx], itoa((int)(idx + 2), tmp1, 10));
        strcat(Skill_str[idx], ")");
        Skill_Element[idx] = 0;
        break;
    case 0: strcpy(Skill_str[idx], skillInfo[idx][0].name);
        strcat(Skill_str[idx], "   (");
        strcat(Skill_str[idx], itoa((int)(idx + 2), tmp1, 10));
        strcat(Skill_str[idx], ")");
        Skill_Element[idx] = E_ICE;
        break;
    case 1: strcpy(Skill_str[idx], skillInfo[idx][1].name);
        strcat(Skill_str[idx], "   (");
        strcat(Skill_str[idx], itoa((int)(idx + 2), tmp1, 10));
        strcat(Skill_str[idx], ")");
        Skill_Element[idx] = E_FLAME;
        break;
    case 2: strcpy(Skill_str[idx], skillInfo[idx][2].name);
        strcat(Skill_str[idx], "   (");
        strcat(Skill_str[idx], itoa((int)(idx + 2), tmp1, 10));
        strcat(Skill_str[idx], ")");
        Skill_Element[idx] = E_ELECT;
        break;
    }
}
void drawNormalBattleSituationChoice_Skill() {
    drawNormalBattleSituationChoiceClean();
    SetPoint(s, Status);
    gotoxy(20, 42); printf("�ڷΰ��� (1)");
    gotoxy(60, 42); StrCpy_Skill(0);    printf("%s", Skill_str[0]);
    gotoxy(20, 47); StrCpy_Skill(1);    printf("%s", Skill_str[1]);
    gotoxy(60, 47); StrCpy_Skill(2);    printf("%s", Skill_str[2]);
}
void drawNormalBattleSituationChoice_Item() {
    drawNormalBattleSituationChoiceClean();
    SetPoint(s, Status);
    gotoxy(20, 42); printf("�ڷΰ��� (1)");
    gotoxy(60, 42); printf("ü������ : %d (2)", healingPotion);
    gotoxy(20, 47); printf("�������� : %d (3)", manaPotion);
    gotoxy(60, 47); printf("ü��/���� ���� : %d (4)", allPotion);
}
void drawNormalBattleSituationChoice_Run(Monster* s) {
    drawNormalBattleSituationChoiceClean();
    int ps = s->level - level;
    if (ps < 0) {
        ps = 70;
    }
    else if (ps < 2)ps = 50;
    else ps = 30;
    int random_var = rand() % 100;
    if (random_var < ps) {
        gotoxy(20, 42);
        printf("�����ƽ��ϴ�!");
        Sleep(1000);
        Run_Flag = 1;
    }
    else {
        gotoxy(20, 42);
        printf("����ġ�� ���߽��ϴ�...");
        Monster_Damage_Turn(s);
        if (s->hp > 0) {
            dieNormal();
        }
        Sleep(1000);
        n = 0;
        Status = 0;
    }
    drawNormalBattleSituationChoice_Page1();
}
void drawNormalBattleSituationChoice_TypeGame(int* arr, Monster* monster) {
    switch (Status) {
    case 0:       TypingGame(E_NON, 0, arr);  PC_Damage(monster, arr); Monster_Damage(monster, arr);           if (monster->hp > 0) {
        dieNormal();
    }    break;
    case 1:       TypingGame(Skill_Element[0], 1, arr);  PC_Damage(monster, arr); Monster_Damage(monster, arr);            if (monster->hp > 0) {
        dieNormal();
    }   break;
    case 2:       TypingGame(Skill_Element[1], 2, arr);       PC_Damage(monster, arr); Monster_Damage(monster, arr);         if (monster->hp > 0) {
        dieNormal();
    }      break;
    case 3:       TypingGame(Skill_Element[2], 3, arr);       PC_Damage(monster, arr); Monster_Damage(monster, arr);            if (monster->hp > 0) {
        dieNormal();
    }   break;
    }
    Status = 0;
    Dont_GetKey = 0;
    drawNormalBattleSituationMonsterStat(monster);
    if (!monster->hp) {
        STATE = START_NOMAL;
    }
}
// �Ϲ� ���Ϳ��� ���� ��Ȳ ����â ���
void drawNormalBattleSituationChoice(Monster* monster)
{
    int arr[4] = { 0, };
    switch (n) {
    case 0: drawNormalBattleSituationChoice_Page1();                   break;
    case 1: drawNormalBattleSituationChoice_Skill();                   break;
    case 2: drawNormalBattleSituationChoice_TypeGame(arr, monster);    break;
    case 3: drawNormalBattleSituationChoice_Item();                    break;
    case 4: drawNormalBattleSituationChoice_Run(monster);                     break;
    }
}

// �Ϲ� ���Ϳ��� ���� ��Ȳ���� �÷��̾�� ���� ���
void drawNormalBattleSituation_PCandMonster(Monster* monster) {

    int c;

    c = monster->element;

    DrawStarplayer();
    DrawPlayerLv();

    setcolor(c, C_BLACK);

    if (monster->shape == 0)
        DrawCircleworm();

    else if (monster->shape == 1)
        DrawTrianglespyware();

    else DrawDia();

    setcolor(C_WHITE, C_BLACK);
    DrawMonsterLv(monster);
}

void DrawPlayerLv() {
    /*
    gotoxy(30, 33); printf("������������������������������������������������");//0
    gotoxy(30, 34); printf("��                      ��");//1
    gotoxy(30, 35); printf("��    �÷��̾�          ��");//1
    gotoxy(30, 36); printf("��    ����: %2d          ��", level);//1
    gotoxy(30, 37); printf("��                      ��");//1
    gotoxy(30, 38); printf("������������������������������������������������");
    */
    gotoxy(18, 23); printf("Lv.%2d", level);
}

void DrawMonsterLv(Monster* monster) {
    gotoxy(108, 13); printf("Lv.%2d", monster->level);
}
void DrawStarplayer() {

    gotoxy(20, 25);
    printf("*");
    gotoxy(20, 26);
    printf("*");
    gotoxy(19, 27);
    printf("***");
    gotoxy(19, 28);
    printf("***");
    gotoxy(18, 29);
    printf("*****");
    gotoxy(10, 30);
    printf("*********************");
    gotoxy(12, 31);
    printf("*****************");
    gotoxy(14, 32);
    printf("*************");
    gotoxy(15, 33);
    printf("***********");
    gotoxy(16, 34);
    printf("**** ****");
    gotoxy(16, 35);
    printf("***   ***");
    gotoxy(15, 36);
    printf("***     ***");
    gotoxy(15, 37);
    printf("**       **");
    gotoxy(14, 38);
    printf("*           *");

}
void DrawCircleworm() {

    gotoxy(110, 2);
    printf("*");
    gotoxy(104, 3);
    printf("*************");
    gotoxy(102, 4);
    printf("*****************");
    gotoxy(101, 5);
    printf("*******************");
    gotoxy(101, 6);
    printf("*******************");
    gotoxy(100, 7);
    printf("*********************");
    gotoxy(101, 8);
    printf("*******************");
    gotoxy(101, 9);
    printf("*******************");
    gotoxy(102, 10);
    printf("*****************");
    gotoxy(104, 11);
    printf("*************");
    gotoxy(110, 12);
    printf("*");

}
void DrawTrianglespyware() {

    gotoxy(110, 2);
    printf("*");
    gotoxy(109, 3);
    printf("***");
    gotoxy(108, 4);
    printf("*****");
    gotoxy(107, 5);
    printf("*******");
    gotoxy(106, 6);
    printf("*********");
    gotoxy(105, 7);
    printf("***********");
    gotoxy(104, 8);
    printf("*************");
    gotoxy(103, 9);
    printf("***************");
    gotoxy(102, 10);
    printf("*****************");
    gotoxy(101, 11);
    printf("*******************");

}
void DrawDia() {

    gotoxy(100, 8);
    printf("*");
    gotoxy(99, 9);
    printf("***");
    gotoxy(98, 10);
    printf("*****");
    gotoxy(97, 11);
    printf("*******");
    gotoxy(96, 12);
    printf("*********");
    gotoxy(95, 13);
    printf("***********");
    gotoxy(94, 14);
    printf("*************");
    gotoxy(95, 15);
    printf("***********");
    gotoxy(96, 16);
    printf("*********");
    gotoxy(97, 17);
    printf("*******");
    gotoxy(98, 18);
    printf("*****");
    gotoxy(99, 19);
    printf("***");
    gotoxy(100, 20);
    printf("*");

}
