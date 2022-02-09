#pragma once
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include"Cursor.h"
#include"data.h"
#include"Color.h"
#include"MapInfo.h"

// 전투할 몬스터 인덱스
int battleMosterIdx;

// 몬스터 레벨 별 스탯
double monsterStatTable[17][3];
// 몬스터 드랍 아이템 확률
double monsterDropTable[17][3];
typedef struct _monster
{
	int maxHp;
	int hp;
	int atk;
	int shape;	// 0:스파이웨어, 1: 웜
	int exp;
	int m_x;
	int m_y;
	int level;
	int element;	// 속성 별 색
	int money;	
	int Enhance_Stone[8];
	int direction; //움직일 방향  0: 좌 1: 우 2: 상 3: 하
	int SerialNo;
}Monster;

// 몬스터 정보 리스트 (10마리 유지)
extern Monster monsterList[10];
// 보스 몬스터
extern Monster boss;

// 몬스터 정보 리스트 초기화
void initMonsterList();

// 몬스터 초기화 후 리턴
Monster SetMonster();
