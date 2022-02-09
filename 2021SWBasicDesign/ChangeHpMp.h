#pragma once
#include"MonsterData.h"
#include"Color.h"
#include"data.h"
void drawBattleSituationMonsterHP(Monster* s, int FinalHp);

void drawBattleSituationPCHP(int FinalHp);

void drawBattleSituationPCMP(int FInalMp);

void drawBattleSituationPCMPUp(int FinalMp);

void drawBattleSituationPCHPUp(int FinalHp);
int CalculateFinalHp(int currentHp, int Damage);

void drawBossSituationPCStat();
void drawBossBattleSituationMonsterStat(Monster* s);