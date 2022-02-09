#include"normalSituation.h"

void normalSituationProcessKeyInput()
{
    for (int i = 0; i < speed; i++)
    {
        if (_kbhit())
        {
            int key = _getch();
            switch (key)
            {
            case INVENTORY:     drawNormalSituationInventory();     break;  // 'i'
            case SKILL:         drawNormalSituationSkill();         break;  // 'k'
            case EQUIP:         drawNormalSituationEquipment();     break;  // 'p'
            case UP:            pcMoveUp();                         break;  
            case DOWN:          pcMoveDown();                       break;
            case LEFT:          pcMoveLeft();                       break;
            case RIGHT:         pcMoveRight();                      break;
            case SPACE_BAR:     Check_Portal();                     break;  // ��Ż �̵�
            //case 113:   return 0;                           break;  // 'q'  -> �ΰ��� ȭ�� ����
            default:                                        break;
            }
            // ���� �浹 �˻�
            if (battleMosterIdx != -1)
                return;
        }
        Sleep(200/speed); // 200 = ���� �ӵ�
    }
}
void startNormalSituation()
{
    battleMosterIdx = -1;   
    initMonsterList();
    drawNormalSituation();
    while (STATE == START_NOMAL)
    {
        normalSituationProcessKeyInput();
        // ���� �浹 �˻�
        if (battleMosterIdx != -1)
        {
            STATE = START_N_BATTLE;
            break;
        }

        // ���� ������
        for (int i = 0; i < 10; i++)
            monster_move(&monsterList[i]);

        pcDetectCollision(pcX, pcY);

        // ���� �浹 �˻�
        if (battleMosterIdx != -1)
        {
            STATE = START_N_BATTLE;
            break;
        }
    }
}

void drawNormalSituation()
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
    drawNormalSituationMap();
    drawNormalSituationMenu();
    drawNormalSituationStat();
    drawNormalSituationInventory();
    // �ΰ��� ȭ�� �⺻Ʋ ���

}
void drawNormalSituationMap()
{
    //��Ż �׸��� �߰�
    for (int i = 0; i < 39; i++)
    {
        for (int j = 0; j < 123; j++)
        {
            gotoxy(j, i);
            switch (NormalMapInfo[i][j]) {
            case 5: case 6:
                printf("/"); break;
            }
        }
    }

    gotoxy(59, 4);
    printf("Town");
    gotoxy(59, 34);
    printf("Boss");
    

    pcDraw();

    // ���� �׸��� �߰�
    for (int i = 0; i < 10; i++)
        monsterDraw(monsterList[i]);
}
void drawNormalSituationStat()
{
    // ü��, ���� ����
    int ratioHp = hp / (maxHp / 100.0f);
    int ratioMp = mp / (maxMp / 100.0f);
    int ratioExp = pcExp / (maxExp / 100.0f);

    // ü�� ���
    gotoxy(2, 41);
    printf("ü��  ");
    setcolor(C_WHITE, C_RED_);
    for (int i = 0; i < ratioHp; i++)
        printf(" ");
    setcolor(C_WHITE, C_RED);
    for (int i = ratioHp; i < 100; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", hp, maxHp);

    // ���� ���
    gotoxy(2, 43);
    printf("����  ");
    setcolor(C_WHITE, C_BLUE_);
    for (int i = 0; i < ratioMp; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLUE);
    for (int i = ratioMp; i < 100; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", mp, maxMp);

    // ����ġ ���
    gotoxy(2, 45);
    printf("exp   ");
    setcolor(C_WHITE, C_GREEN);
    for (int i = 0; i < ratioExp; i++)
        printf(" ");
    setcolor(C_WHITE, C_GRAY);
    for (int i = ratioExp; i < 100; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", pcExp, maxExp);

    // ���ݷ�, ����, �̼� ���
    gotoxy(20, 47);
    printf("���� : %d \t\t���ݷ� : %d \t\t ���� : %d \t\t �̼� : %.0f", level, atk, def, speed);
}
void drawNormalSituationMenu()
{
    gotoxy(140, 2);
    printf("<�޴�>");
    gotoxy(138, 5);
    printf("i : �κ��丮");
    gotoxy(138, 7);
    printf("k : ��ų â");
    gotoxy(138, 9);
    printf("p : ��� â");
}
void drawNormalSituationInventory()
{
    // ����� â �����
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<�κ��丮>");
    gotoxy(138, 18);
    printf("�� : %d ��", money);
    gotoxy(134, 21);
    printf("�ϱ� ��ȭ�� �� : %d ��", enhancementStone1);
    gotoxy(134, 23);
    printf("�߱� ��ȭ�� �� : %d ��", enhancementStone2);
    gotoxy(134, 25);
    printf("��� ��ȭ�� �� : %d ��", enhancementStone3);
    gotoxy(136, 28);
    printf("ü�� ���� : %d ��", healingPotion);
    gotoxy(136, 30);
    printf("���� ���� : %d ��", manaPotion);
    gotoxy(134, 32);
    printf("ü��/���� ���� : %d ��", allPotion);
    gotoxy(135, 34);
    printf("����ġ ���� : %d ��", expPotion);
}
void drawNormalSituationSkill()
{
    // ����� â �����
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<��ų â>");
    
    // ����� �� �ִ� ��ų ���� ���
    for (int i = 0; i < 3; i++)
    {
        if (takenSkill[i] == -1)
        {
            // ��ų�� �ϳ��� ���� ���� ���
            if (i == 0)
            {
                gotoxy(128, 30);
                printf("����� �� �ִ� ��ų�� �����ϴ�.");
            }
            break;
        }

        int y = 19 + (i * 10);
        gotoxy(130, y);
        printf("�� %s", skillInfo[i][takenSkill[i]].name);

        // �Ӽ����� �۾� �� ����
        switch (takenSkill[i])
        {
        case 0: setcolor(E_ICE, C_BLACK);     break;
        case 1: setcolor(E_FLAME, C_BLACK);   break;
        case 2: setcolor(E_ELECT, C_BLACK);   break;
        }

        gotoxy(128, y + 2);
        printf("���� : %s", skillInfo[i][takenSkill[i]].explantion);
        gotoxy(128, y + 3);
        printf("������ : �⺻������ %d%%", skillInfo[i][takenSkill[i]].damage);
        gotoxy(128, y + 4);
        printf("�Ҹ� ������ : %d", skillInfo[i][takenSkill[i]].mana);

        setcolor(C_WHITE, C_BLACK);
    }
}
void drawNormalSituationEquipment()
{
    // ����� â �����
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<��� â>");

    int y = 18;
    gotoxy(130, y);
    printf("�� HAT");
    gotoxy(132, y + 1);
    switch (equipmentRank[HAT]) {
    case NORMAL: printf("���: �븻"); break;
    case RARE: printf("���: "); setcolor(C_SKYBLUE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("���: "); setcolor(C_PURPLE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("���: "); setcolor(E_ELECT, C_BLACK); printf("����ũ"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("���: "); setcolor(C_GREEN_, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[HAT]);
    gotoxy(132, y + 3);
    printf("ȿ�� : ü�� %.0f%% ����", equipmentEffect[5 * equipmentRank[HAT] + HAT][equipmentLevel[HAT]]);

    y += 6;
    gotoxy(130, y);
    printf("�� ROBE");
    gotoxy(132, y + 1);
    switch (equipmentRank[ROBE]) {
    case NORMAL: printf("���: �븻"); break;
    case RARE: printf("���: "); setcolor(C_SKYBLUE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("���: "); setcolor(C_PURPLE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("���: "); setcolor(E_ELECT, C_BLACK); printf("����ũ"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("���: "); setcolor(C_GREEN_, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[ROBE]);
    gotoxy(132, y + 3);
    printf("ȿ�� : ���� %.0f%% ����", equipmentEffect[5 * equipmentRank[ROBE] + ROBE][equipmentLevel[ROBE]]);

    y += 6;
    gotoxy(130, y);
    printf("�� SHOES");
    gotoxy(132, y + 1);
    switch (equipmentRank[SHOES]) {
    case NORMAL: printf("���: �븻"); break;
    case RARE: printf("���: "); setcolor(C_SKYBLUE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("���: "); setcolor(C_PURPLE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("���: "); setcolor(E_ELECT, C_BLACK); printf("����ũ"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("���: "); setcolor(C_GREEN_, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[SHOES]);
    gotoxy(132, y + 3);
    printf("ȿ�� : �̵��ӵ� %.1f ����", equipmentEffect[5 * equipmentRank[SHOES] + SHOES][equipmentLevel[SHOES]]);

    y += 6;
    gotoxy(130, y);
    printf("�� WEAPON");
    gotoxy(132, y + 1);
    switch (equipmentRank[WEAPON]) {
    case NORMAL: printf("���: �븻"); break;
    case RARE: printf("���: "); setcolor(C_SKYBLUE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("���: "); setcolor(C_PURPLE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("���: "); setcolor(E_ELECT, C_BLACK); printf("����ũ"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("���: "); setcolor(C_GREEN_, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[WEAPON]);
    gotoxy(132, y + 3);
    printf("ȿ�� : ���ݷ� %.0f%% ����", equipmentEffect[5 * equipmentRank[WEAPON] + WEAPON][equipmentLevel[WEAPON]]);

    y += 6;
    gotoxy(130, y);
    printf("�� BRACELET");
    gotoxy(132, y + 1);
    switch (equipmentRank[BRACELET]) {
    case NORMAL: printf("���: �븻"); break;
    case RARE: printf("���: "); setcolor(C_SKYBLUE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("���: "); setcolor(C_PURPLE, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("���: "); setcolor(E_ELECT, C_BLACK); printf("����ũ"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("���: "); setcolor(C_GREEN_, C_BLACK); printf("����"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[BRACELET]);
    gotoxy(132, y + 3);
    printf("ȿ�� : ���� %.0f%% ����", equipmentEffect[5 * equipmentRank[BRACELET] + BRACELET][equipmentLevel[BRACELET]]);
}
void removeNormalSituationMenuWindow()
{
    for (int y = 12; y < 50; y++) 
    {
        gotoxy(127, y);
        for (int x = 127; x < 160; x++)
            printf(" ");
    }

}
