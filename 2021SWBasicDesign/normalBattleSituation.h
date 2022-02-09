#pragma once

#include "Cursor.h"
#include "Key.h"
#include "Color.h"
#include "MonsterData.h"
#include "data.h"
#include "Damage.h"
#include"pcMoving.h"
#include"skill.h"
#include"BattleLog.h"
extern char Skill_str[3][30];
extern int Skill_Element[3];
extern int n;
extern int Status;
extern int Run_Flag;
extern int ChangeTheme;
extern int Check_Using_Item;
extern COORD s[4];

// �Ϲ� ���Ϳ��� ���� ��Ȳ ȭ�� ����
void startNormalBattleSituation(Monster* monster);
void dieNormal();
// �Ϲ� ���Ϳ��� ���� ��Ȳ �Է� Ű ó��
void SetPoint(COORD* s, int i);
int DrawPointerForBattleSituation(COORD* s, Monster* p);

// �Ϲ� ���Ϳ��� ���� ��Ȳ �⺻ ȭ�� ���
void drawNormalBattleSituation(Monster* monster);

// �Ϲ� ���Ϳ��� ���� ��Ȳ �� ���� HP ���
void drawNormalBattleSituationMonsterStat(Monster* s);

// �Ϲ� ���Ϳ��� ���� ��Ȳ �� PC ���� ���
void drawNormalBattleSituationPCStat();
// �Ϲ� ���Ϳ��� ���� ��Ȳ �κ��丮 ���
void drawNormalBattleSituationInventory();

// �Ϲ� ���Ϳ��� ���� ��Ȳ ����â ���
void drawNormalBattleSituationChoice(Monster* monster);
//����â 1
void drawNormalBattleSituationChoice_Page1();
//����â 2
void drawNormalBattleSituationChoice_Skill();
//������ ����â
void drawNormalBattleSituationChoice_Item();
//��������
void drawNormalBattleSituationChoice_Run(Monster* s);
//Ÿ���� ���� �ϴ� ��
void drawNormalBattleSituationChoice_TypeGame(int* arr, Monster* monster);

// ����â �ʱ�ȭ
void drawNormalBattleSituationChoiceClean();

//��뷮 Ȯ�� �Լ�
//flag�� 1�̸� ü�� ����
//flag�� 2�̸� ���� ����
//flag�� 3�̸� ���� ü�� ����
void CalculateUsageOfPortion(int flag, int* arr);
//Hp���� ���
void UsingHpPortion();
//ALl���� ���
void UsingAllPortion();
//Mp���� ���
void UsingMpPortion();
// ��ų ����
void StrCpy_Skill(int idx);

// �Ϲ� ���Ϳ��� ���� ��Ȳ���� �÷��̾�� ���� ���
void drawNormalBattleSituation_PCandMonster(Monster* monster);
// ����� �÷��̾� ���
void DrawStarplayer();
//�÷��̾� ���� ���
void DrawPlayerLv();
// ����� �� ���
void DrawCircleworm();
// �ﰢ�� ��� �����̿��� ���
void DrawTrianglespyware();
// ���̾� ��� ���� ���
void DrawDia();

void DrawMonsterLv(Monster* monster);