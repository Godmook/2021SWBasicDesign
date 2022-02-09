#include"data.h"
// PC ���� ��ġ
int pcX = 50;
int pcY = 15;
//������ ù ���� ��ġ

int STATE = START_TOWN;
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
	level : ���� ����
	pcStatTable : ĳ���� �⺻ ����(ü��, ����, ���ݷ�, ����, �̵��ӵ�, ����ġ)
*/
int maxHp = 300;
int maxMp = 50;
int maxExp = 10;
int hp = 300;
int mp = 50;
double speed = 3;
int atk = 30;
int def = 5;
int pcExp = 0;
int level = 1;
int Dont_GetKey = 0;
double pcStatTable[6][17] =
{
	{0,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800},
	{0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200},
	{0,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180},
	{0,1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30},
	{0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18},
	{0,10,20,40,80,160,320,640,1280,2560,5120,10240,20480,40960,81920,163840,327680}
};

void pcLevelUp()
{
	if (level == 16) return;   // ����
	level += 1;
	PCSet();
}
void PCSet() {
	double tmp = 0.0;
	tmp = ((pcStatTable[HP][level] + rankEffect[HAT][equipmentRank[HAT]]) * ((100 + equipmentEffect[5 * equipmentRank[HAT] + HAT][equipmentLevel[HAT]]) / 100.0f));
	maxHp = (int)tmp;
	tmp = ((pcStatTable[MP][level] + rankEffect[BRACELET][equipmentRank[BRACELET]]) * ((100 + equipmentEffect[5 * equipmentRank[BRACELET] + BRACELET][equipmentLevel[BRACELET]]) / 100.0f));
	maxMp = tmp;
	maxExp = pcStatTable[EXP][level];
	hp = maxHp;
	mp = maxMp;
	tmp = ((pcStatTable[SPEED][level] + rankEffect[SHOES][equipmentRank[SHOES]]) * ((100 + equipmentEffect[5 * equipmentRank[SHOES] + SHOES][equipmentLevel[SHOES]]) / 100.0f));
	speed = (int)tmp;
	tmp = ((pcStatTable[ATK][level] + rankEffect[WEAPON][equipmentRank[WEAPON]]) * ((100 + equipmentEffect[5 * equipmentRank[WEAPON] + WEAPON][equipmentLevel[WEAPON]]) / 100.0f));
	atk = (int)tmp;
	tmp = ((pcStatTable[DEF][level] + rankEffect[ROBE][equipmentRank[ROBE]]) * ((100 + equipmentEffect[5 * equipmentRank[ROBE] + ROBE][equipmentLevel[ROBE]]) / 100.0f));
	def = (int)tmp;
}
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
int money =0;
int healingPotion = 0;
int manaPotion = 0;
int allPotion = 0;
int expPotion = 0;
int enhancementStone1 = 0;
int enhancementStone2 = 0;
int enhancementStone3 = 0;
int reforce_Material = 0;

/*
	<��ų>
	takenSkill : ���� ��ų ([0] : 5Lv, [1] : 9Lv, [2] : 13Lv)
				(-1 : ���� ��ų�� ����, 0~2 : ����, ȭ��, ���� �Ӽ� ��ų)
	skillInfo : ��ų ����
*/
int takenSkill[3] = { -1,-1,-1 };
Skill skillInfo[3][3] = {
	{
		{"������", "�����̸� ��ȯ�� ������.", 130, 10 },
		{"ȭ����", "ȭ�� ��ü�� ���.", 130, 10 },
		{"������", "�����⸦ ���.", 130, 10 }
	},
	{
		{"����ȭ��", "����ȭ���� ��ȯ�� ���.", 170, 20 },
		{"ȭ��â", "ȭ��â�� ��ȯ�� ������.", 170, 20 },
		{"������", "�������� ��ȯ�Ѵ�.", 170, 20 }
	},
	{
		{"��������", "�������� �ֳ����� �Ѵ�.", 250, 40 },
		{"����", "������ ����߸���.", 250, 40 },
		{"õ�չ���", "������ ��������.", 250, 40 }
	}
};


/*
	<��� ����>
	0. hat : ����(ü��)
	1. robe : �κ�(����)
	2. shoes : �Ź�(�̼�)
	3. weapon : ����(���ݷ�)
	4. bracelet : ����(����)
*/

//���-> ���׷��̵带 �ҋ� ���� ��ȭ ������ �پ��� �븻 4-> ���� 1������ �Ǵ°ž�
//�� ����� ���׷��̵帶�� ȿ���� �ٸ��� ����� �޶�
//�븻1->���� 1����
//�븻1->�������� 1���� ���� ���°ź��� ����ũ 10����->�������� 6���� �Ǵ½�����
int equipmentLevel[5] = { 1,1,1,1,1 };
int equipmentRank[5] = { NORMAL,NORMAL,NORMAL,NORMAL,NORMAL };
double equipmentEffect[25][11] = {
	/*NORMAL*/
	{0,5,10,15,20,25,30,40,45,50,55},
	{0,1,2,3,4,5,6,7,8,9,10},
	{0,3, 5, 7, 9, 11, 13, 15, 17, 20,22},
	{0,5,10,15,20,25,30,40,45,50,55},
	{0,5,10,15,20,25,30,40,45,50,55},
	/*RARE*/
	{0,20,26,32,38,44,50,56,62,68,74},
	{0,4,5.5,7,8.5,10,11.5,13,14.5,16,18.5},
	{0,9, 12, 15,18, 21, 24, 27, 30, 33,36},
	{0,20,26,32,38,44,50,56,62,68,74},
	{0,20,26,32,38,44,50,56,62,68,74},
	/*EPIC*/
	{0,38,45,52,59,66,73,80,87,94,101},
	{0,8.5,10.5,12.5,14.5,16.5,18.5,20.5,22.5,24.5,26.5},
	{0,18, 22, 26,30, 34, 38, 42, 46, 50,54},
	{0,38,45,52,59,66,73,80,87,94,101},
	{0,38,45,52,59,66,73,80,87,94,101},
	/*UNIQUE*/
	{0,59,70,80,90,100,110,120,130,140,150},
	{0,14.5,17,20,23,26,29,32,35,38,41},
	{0,30, 35, 40,45, 50, 55, 60, 65, 70,75},
	{0,59,70,80,90,100,110,120,130,140,150},
	{0,59,70,80,90,100,110,120,130,140,150},
	/*LEGENDARY*/
	{0,90,110,130,150,170,190,210,230,250,270},
	{0,23,28,33,38,43,48,53,58,63,68},
	{0,30, 35, 40,45, 50, 55, 60, 65, 70,75},
	{0,90,110,130,150,170,190,210,230,250,270},
	{0,90,110,130,150,170,190,210,230,250,270},
};

/*
	<��� ����>
	0. hat : ����(ü��)
	1. robe : �κ�(����)
	2. shoes : �Ź�(�̼�)
	3. weapon : ����(���ݷ�)
	4. bracelet : ����(����)
	[i][0]=NORMAL
	[i][1]=RARE
	[i][2]=EPIC
	[i][3]=UNIQUE
	[i][4]=LEGENDARY
*/
double rankEffect[5][5] = {
	{0,200,400,600,800},	//���� ��� �⺻ ȿ��
	{0,5,10,15,20},			//�κ� ��� �⺻ ȿ��
	{0,3,6,9,12},			//�Ź� ��� �⺻ ȿ��
	{0,25,50,200,800},	//���� ��� �⺻ ȿ��
	{0,50,100,150,200}		//���� ��� �⺻ ȿ��
};