#pragma once

#include"MonsterData.h"
#include"skill.h"
#define STONE1 997
#define STONE2 998
#define STONE3 999

//������ ���� ��ġ

#define START_TOWN 0
#define BUY_ITEM 1
#define UPGRADE_EQUIP 2
#define START_NOMAL 3
#define START_N_BATTLE 4
#define START_BOSS_BATTEL 5
#define GAME_OVER 6

extern int STATE;
// PC ���� ��ġ
extern int pcX;
extern int pcY;
/*
	<PC �⺻ ����>
	maxHp :�ִ� ü��
	maxMp : �ִ� ����
	maxExp : �ִ� ����ġ
	hp : ���� ü��
	mp : ���� ����
	speed : �̼�
	atk : ���ݷ�
	def : ����(%)
	exp : ���� ����ġ
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
//Ű ���� ������ �ȵǴ� ��Ȳ�̸� 1 �޾Ƶ� �Ǵ� ��Ȳ�̸� 0
extern int Dont_GetKey;
//PC ���� ��
void pcLevelUp();
//PC ����
void PCSet();

/*
	<������>
	money : ��
	healingPotion : ü�� ����
	manaPotion : ���� ����
	allPotion : ü��/���� ���� ȸ�� ����
	expPotion : ����ġ ����
	enhancementStone1 : �ϱ� ��ȭ�� ��
	enhancementStone2 : �߱� ��ȭ�� ��
	enhancementStone3 : ��� ��ȭ�� ��
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
	<��ų>
	takenSkill : ���� ��ų ([0] : 5Lv, [1] : 9Lv, [2] : 13Lv)
				(-1 : ���� ��ų�� ����, 0~2 : ����, ȭ��, ���� �Ӽ� ��ų)
	skillInfo : ��ų ����
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
	<��� ����>
	hat : ����(ü��)
	robe : �κ�(����)
	shoes : �Ź�(�̼�)
	weapon : ����(���ݷ�)
	bracelet : ����(����)
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
