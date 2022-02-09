#pragma once
#pragma warning(disable:4996)
#include "MonsterData.h"
#include "data.h"
#include "Color.h"
#include "BattleLog.h"
#include "Cursor.h"
#include"ChangeHpMp.h"
//몬스터가 플레이어한테 데미지 넣는 확률 표
const int Monster_To_PC_Damage[3][3];

//몬스터가 플레이어에게 넣는 데미지
void Monster_Damage(Monster* s, int* TypingInfo);

//PC가 몬스터에게 넣는 데미지
void PC_Damage(Monster* s, int* TypingInfo);

//상성 계산
int Calculate_Upper_OR_Lower(Monster s, int* TypingInfo, int flag);

//턴사용시 몬스터가 데미지 넣는것
void Monster_Damage_Turn(Monster* s);

void PCInBoss_Damage(Monster* s, int* TypingInfo);

void Boss_Damage(Monster* s);