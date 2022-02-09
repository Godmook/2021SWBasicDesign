#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Key.h"
#include"Color.h"
#include"Cursor.h"
#include"data.h"
#include"normalSituation.h"
#include"MonsterData.h"
#include "Town.h"
#include "BuyItem.h"
#include"ReinForce.h"
#include"bossBattle.h"

int main()
{
   
    int tmp = 0;
    if (MainView() == 1) {
        system("mode con: lines=50 cols=160");
        RemoveCursor();
        srand(time(NULL));
        setcolor(C_WHITE, C_BLACK);

        PCSet();    // 1 Lv
                
        initMonsterList();  // ���� ����
        while (1)
        {
            switch (STATE)
            {
            case START_TOWN:     startNormalSituationInTown();                  break;// ���� ����
            case BUY_ITEM:        startBuyItem();                               break;
            case UPGRADE_EQUIP:   startReinForce();                             break;
            case START_NOMAL:     startNormalSituation();                       break;// �Ĺ� ��
            case START_N_BATTLE:     startNormalBattleSituation(&monsterList[battleMosterIdx]);            break;//�Ϲ� ���� ����
            case START_BOSS_BATTEL:  startBossBattle();             break;
            case GAME_OVER:    return 0;            break;
            default:
                break;
            }
        }
        getchar();
    }
    return 0;
}