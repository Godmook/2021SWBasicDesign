#pragma once

#include"MonsterData.h"
#include"skill.h"
#define STONE1 997
#define STONE2 998
#define STONE3 999

//게임의 현재 위치

#define START_TOWN 0
#define BUY_ITEM 1
#define UPGRADE_EQUIP 2
#define START_NOMAL 3
#define START_N_BATTLE 4
#define START_BOSS_BATTEL 5
#define GAME_OVER 6

extern int STATE;
// PC 현재 위치
extern int pcX;
extern int pcY;
/*
	<PC 기본 스탯>
	maxHp :최대 체력
	maxMp : 최대 마나
	maxExp : 최대 경험치
	hp : 현재 체력
	mp : 현재 마나
	speed : 이속
	atk : 공격력
	def : 방어력(%)
	exp : 현재 경험치
*/
extern int maxHp;
extern int maxMp;
extern int maxExp;
extern int hp;
extern int mp;
extern double speed;
extern int atk;
extern int def;
extern int pcExp;
extern int level;
#define HP 0
#define MP 1
#define ATK 2
#define DEF 3
#define SPEED 4
#define EXP 5
extern double pcStatTable[6][17];
//키 값을 받으면 안되는 상황이면 1 받아도 되는 상황이면 0
extern int Dont_GetKey;
//PC 레벨 업
void pcLevelUp();
//PC 세팅
void PCSet();

/*
	<아이템>
	money : 돈
	healingPotion : 체력 포션
	manaPotion : 마나 포션
	allPotion : 체력/마나 동시 회복 포션
	expPotion : 경험치 포션
	enhancementStone1 : 하급 강화의 돌
	enhancementStone2 : 중급 강화의 돌
	enhancementStone3 : 상급 강화의 돌
*/
extern int money;
extern int healingPotion;
extern int manaPotion;
extern int allPotion;
extern int expPotion;
extern int enhancementStone1;
extern int enhancementStone2;
extern int enhancementStone3;
extern int reforce_Material;


/*
	<스킬>
	takenSkill : 찍은 스킬 ([0] : 5Lv, [1] : 9Lv, [2] : 13Lv)
				(-1 : 찍은 스킬이 없음, 0~2 : 얼음, 화염, 전기 속성 스킬)
	skillInfo : 스킬 정보
*/
typedef struct _skill
{
	char *name;
	char *explantion;
	int damage;
	int mana;
}Skill;
extern int takenSkill[3];
extern Skill skillInfo[3][3];

/*
	<장비 레벨>
	hat : 모자(체력)
	robe : 로브(방어력)
	shoes : 신발(이속)
	weapon : 무기(공격력)
	bracelet : 팔찌(마나)
*/
#define HAT 0
#define ROBE 1
#define SHOES 2
#define WEAPON 3
#define BRACELET 4

extern int equipmentLevel[5];
extern double equipmentEffect[25][11];
extern int equipmentRank[5];
extern enum INVENTORY_RANK { NORMAL, RARE, EPIC, UNIQUE, LEGENDARY };
extern double rankEffect[5][5];
