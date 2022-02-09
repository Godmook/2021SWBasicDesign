#pragma once
#pragma warning(disable:4996)
#include "MonsterData.h"
#include "data.h"
#include "Color.h"
#include "BattleLog.h"
#include "Cursor.h"
#include"ChangeHpMp.h"
//���Ͱ� �÷��̾����� ������ �ִ� Ȯ�� ǥ
const int Monster_To_PC_Damage[3][3];

//���Ͱ� �÷��̾�� �ִ� ������
void Monster_Damage(Monster* s, int* TypingInfo);

//PC�� ���Ϳ��� �ִ� ������
void PC_Damage(Monster* s, int* TypingInfo);

//�� ���
int Calculate_Upper_OR_Lower(Monster s, int* TypingInfo, int flag);

//�ϻ��� ���Ͱ� ������ �ִ°�
void Monster_Damage_Turn(Monster* s);

void PCInBoss_Damage(Monster* s, int* TypingInfo);

void Boss_Damage(Monster* s);