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
            case SPACE_BAR:     Check_Portal();                     break;  // 포탈 이동
            //case 113:   return 0;                           break;  // 'q'  -> 인게임 화면 종료
            default:                                        break;
            }
            // 몬스터 충돌 검사
            if (battleMosterIdx != -1)
                return;
        }
        Sleep(200/speed); // 200 = 몬스터 속도
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
        // 몬스터 충돌 검사
        if (battleMosterIdx != -1)
        {
            STATE = START_N_BATTLE;
            break;
        }

        // 몬스터 움직임
        for (int i = 0; i < 10; i++)
            monster_move(&monsterList[i]);

        pcDetectCollision(pcX, pcY);

        // 몬스터 충돌 검사
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
    drawNormalSituationMap();
    drawNormalSituationMenu();
    drawNormalSituationStat();
    drawNormalSituationInventory();
    // 인게임 화면 기본틀 출력

}
void drawNormalSituationMap()
{
    //포탈 그리기 추가
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

    // 몬스터 그리기 추가
    for (int i = 0; i < 10; i++)
        monsterDraw(monsterList[i]);
}
void drawNormalSituationStat()
{
    // 체력, 마나 비율
    int ratioHp = hp / (maxHp / 100.0f);
    int ratioMp = mp / (maxMp / 100.0f);
    int ratioExp = pcExp / (maxExp / 100.0f);

    // 체력 출력
    gotoxy(2, 41);
    printf("체력  ");
    setcolor(C_WHITE, C_RED_);
    for (int i = 0; i < ratioHp; i++)
        printf(" ");
    setcolor(C_WHITE, C_RED);
    for (int i = ratioHp; i < 100; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", hp, maxHp);

    // 마나 출력
    gotoxy(2, 43);
    printf("마나  ");
    setcolor(C_WHITE, C_BLUE_);
    for (int i = 0; i < ratioMp; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLUE);
    for (int i = ratioMp; i < 100; i++)
        printf(" ");
    setcolor(C_WHITE, C_BLACK);
    printf(" (%6d/%6d)", mp, maxMp);

    // 경험치 출력
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

    // 공격력, 방어력, 이속 출력
    gotoxy(20, 47);
    printf("레벨 : %d \t\t공격력 : %d \t\t 방어력 : %d \t\t 이속 : %.0f", level, atk, def, speed);
}
void drawNormalSituationMenu()
{
    gotoxy(140, 2);
    printf("<메뉴>");
    gotoxy(138, 5);
    printf("i : 인벤토리");
    gotoxy(138, 7);
    printf("k : 스킬 창");
    gotoxy(138, 9);
    printf("p : 장비 창");
}
void drawNormalSituationInventory()
{
    // 출력할 창 지우기
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<인벤토리>");
    gotoxy(138, 18);
    printf("돈 : %d 원", money);
    gotoxy(134, 21);
    printf("하급 강화의 돌 : %d 개", enhancementStone1);
    gotoxy(134, 23);
    printf("중급 강화의 돌 : %d 개", enhancementStone2);
    gotoxy(134, 25);
    printf("상급 강화의 돌 : %d 개", enhancementStone3);
    gotoxy(136, 28);
    printf("체력 포션 : %d 개", healingPotion);
    gotoxy(136, 30);
    printf("마나 포션 : %d 개", manaPotion);
    gotoxy(134, 32);
    printf("체력/마나 포션 : %d 개", allPotion);
    gotoxy(135, 34);
    printf("경험치 포션 : %d 개", expPotion);
}
void drawNormalSituationSkill()
{
    // 출력할 창 지우기
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<스킬 창>");
    
    // 사용할 수 있는 스킬 설명 출력
    for (int i = 0; i < 3; i++)
    {
        if (takenSkill[i] == -1)
        {
            // 스킬을 하나도 찍지 않은 경우
            if (i == 0)
            {
                gotoxy(128, 30);
                printf("사용할 수 있는 스킬이 없습니다.");
            }
            break;
        }

        int y = 19 + (i * 10);
        gotoxy(130, y);
        printf("▼ %s", skillInfo[i][takenSkill[i]].name);

        // 속성별로 글씨 색 변경
        switch (takenSkill[i])
        {
        case 0: setcolor(E_ICE, C_BLACK);     break;
        case 1: setcolor(E_FLAME, C_BLACK);   break;
        case 2: setcolor(E_ELECT, C_BLACK);   break;
        }

        gotoxy(128, y + 2);
        printf("설명 : %s", skillInfo[i][takenSkill[i]].explantion);
        gotoxy(128, y + 3);
        printf("데미지 : 기본공격의 %d%%", skillInfo[i][takenSkill[i]].damage);
        gotoxy(128, y + 4);
        printf("소모 마나양 : %d", skillInfo[i][takenSkill[i]].mana);

        setcolor(C_WHITE, C_BLACK);
    }
}
void drawNormalSituationEquipment()
{
    // 출력할 창 지우기
    removeNormalSituationMenuWindow();

    gotoxy(138, 15);
    printf("<장비 창>");

    int y = 18;
    gotoxy(130, y);
    printf("▶ HAT");
    gotoxy(132, y + 1);
    switch (equipmentRank[HAT]) {
    case NORMAL: printf("등급: 노말"); break;
    case RARE: printf("등급: "); setcolor(C_SKYBLUE, C_BLACK); printf("레어"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("등급: "); setcolor(C_PURPLE, C_BLACK); printf("에픽"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("등급: "); setcolor(E_ELECT, C_BLACK); printf("유니크"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("등급: "); setcolor(C_GREEN_, C_BLACK); printf("전설"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[HAT]);
    gotoxy(132, y + 3);
    printf("효과 : 체력 %.0f%% 증가", equipmentEffect[5 * equipmentRank[HAT] + HAT][equipmentLevel[HAT]]);

    y += 6;
    gotoxy(130, y);
    printf("▶ ROBE");
    gotoxy(132, y + 1);
    switch (equipmentRank[ROBE]) {
    case NORMAL: printf("등급: 노말"); break;
    case RARE: printf("등급: "); setcolor(C_SKYBLUE, C_BLACK); printf("레어"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("등급: "); setcolor(C_PURPLE, C_BLACK); printf("에픽"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("등급: "); setcolor(E_ELECT, C_BLACK); printf("유니크"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("등급: "); setcolor(C_GREEN_, C_BLACK); printf("전설"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[ROBE]);
    gotoxy(132, y + 3);
    printf("효과 : 방어력 %.0f%% 증가", equipmentEffect[5 * equipmentRank[ROBE] + ROBE][equipmentLevel[ROBE]]);

    y += 6;
    gotoxy(130, y);
    printf("▶ SHOES");
    gotoxy(132, y + 1);
    switch (equipmentRank[SHOES]) {
    case NORMAL: printf("등급: 노말"); break;
    case RARE: printf("등급: "); setcolor(C_SKYBLUE, C_BLACK); printf("레어"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("등급: "); setcolor(C_PURPLE, C_BLACK); printf("에픽"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("등급: "); setcolor(E_ELECT, C_BLACK); printf("유니크"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("등급: "); setcolor(C_GREEN_, C_BLACK); printf("전설"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[SHOES]);
    gotoxy(132, y + 3);
    printf("효과 : 이동속도 %.1f 증가", equipmentEffect[5 * equipmentRank[SHOES] + SHOES][equipmentLevel[SHOES]]);

    y += 6;
    gotoxy(130, y);
    printf("▶ WEAPON");
    gotoxy(132, y + 1);
    switch (equipmentRank[WEAPON]) {
    case NORMAL: printf("등급: 노말"); break;
    case RARE: printf("등급: "); setcolor(C_SKYBLUE, C_BLACK); printf("레어"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("등급: "); setcolor(C_PURPLE, C_BLACK); printf("에픽"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("등급: "); setcolor(E_ELECT, C_BLACK); printf("유니크"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("등급: "); setcolor(C_GREEN_, C_BLACK); printf("전설"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[WEAPON]);
    gotoxy(132, y + 3);
    printf("효과 : 공격력 %.0f%% 증가", equipmentEffect[5 * equipmentRank[WEAPON] + WEAPON][equipmentLevel[WEAPON]]);

    y += 6;
    gotoxy(130, y);
    printf("▶ BRACELET");
    gotoxy(132, y + 1);
    switch (equipmentRank[BRACELET]) {
    case NORMAL: printf("등급: 노말"); break;
    case RARE: printf("등급: "); setcolor(C_SKYBLUE, C_BLACK); printf("레어"); setcolor(C_WHITE, C_BLACK); break;
    case EPIC: printf("등급: "); setcolor(C_PURPLE, C_BLACK); printf("에픽"); setcolor(C_WHITE, C_BLACK); break;
    case UNIQUE: printf("등급: "); setcolor(E_ELECT, C_BLACK); printf("유니크"); setcolor(C_WHITE, C_BLACK); break;
    case LEGENDARY: printf("등급: "); setcolor(C_GREEN_, C_BLACK); printf("전설"); setcolor(C_WHITE, C_BLACK); break;
    }
    gotoxy(132, y + 2);
    printf("level : %d Lv", equipmentLevel[BRACELET]);
    gotoxy(132, y + 3);
    printf("효과 : 마나 %.0f%% 증가", equipmentEffect[5 * equipmentRank[BRACELET] + BRACELET][equipmentLevel[BRACELET]]);
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
