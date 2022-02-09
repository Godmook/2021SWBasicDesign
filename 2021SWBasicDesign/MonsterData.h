#pragma once
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include"Cursor.h"
#include"data.h"
#include"Color.h"
#include"MapInfo.h"

// ������ ���� �ε���
int battleMosterIdx;

// ���� ���� �� ����
double monsterStatTable[17][3];
// ���� ��� ������ Ȯ��
double monsterDropTable[17][3];
typedef struct _monster
{
	int maxHp;
	int hp;
	int atk;
	int shape;	// 0:�����̿���, 1: ��
	int exp;
	int m_x;
	int m_y;
	int level;
	int element;	// �Ӽ� �� ��
	int money;	
	int Enhance_Stone[8];
	int direction; //������ ����  0: �� 1: �� 2: �� 3: ��
	int SerialNo;
}Monster;

// ���� ���� ����Ʈ (10���� ����)
extern Monster monsterList[10];
// ���� ����
extern Monster boss;

// ���� ���� ����Ʈ �ʱ�ȭ
void initMonsterList();

// ���� �ʱ�ȭ �� ����
Monster SetMonster();
