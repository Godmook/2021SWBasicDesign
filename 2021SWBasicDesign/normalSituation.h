#pragma once
#include"Cursor.h"
#include"data.h"
#include"Color.h"
#include"pcMoving.h"
#include"Key.h"
#include"MonsterData.h"
#include"Monster_Move.h"
#include"MapInfo.h"
#define INVENTORY 105
#define SKILL 107
#define EQUIP 112
// �ΰ��� ȭ�� ����
void startNormalSituation();

// �ΰ��� �Է� Ű ó��
void normalSituationProcessKeyInput();

// �ΰ��� �⺻ ȭ�� ���(�޴� default : �κ��丮)
void drawNormalSituation();

// �ΰ��� �� ���
void drawNormalSituationMap();
// �ΰ��� ����â ���
void drawNormalSituationStat();
// �ΰ��� �޴� ���
void drawNormalSituationMenu();
// �ΰ��� �κ��丮 ���
void drawNormalSituationInventory();
// �ΰ��� ��ųâ ���
void drawNormalSituationSkill();
// �ΰ��� ���â ���
void drawNormalSituationEquipment();
// �ΰ��� �κ��丮, ���, ��ų â �����
void removeNormalSituationMenuWindow();









