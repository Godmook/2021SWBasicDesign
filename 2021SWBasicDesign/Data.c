#include"data.h"
// PC 현재 위치
int pcX = 50;
int pcY = 15;
//게임의 첫 시작 위치

int STATE = START_TOWN;
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
	level : 현재 레벨
	pcStatTable : 캐릭터 기본 스텟(체력, 마나, 공격력, 방어력, 이동속도, 경험치)
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
	if (level == 16) return;   // 만렙
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
	<스킬>
	takenSkill : 찍은 스킬 ([0] : 5Lv, [1] : 9Lv, [2] : 13Lv)
				(-1 : 찍은 스킬이 없음, 0~2 : 얼음, 화염, 전기 속성 스킬)
	skillInfo : 스킬 정보
*/
int takenSkill[3] = { -1,-1,-1 };
Skill skillInfo[3][3] = {
	{
		{"눈덩이", "눈덩이를 소환해 던진다.", 130, 10 },
		{"화염구", "화염 구체를 쏜다.", 130, 10 },
		{"정전기", "정전기를 쏜다.", 130, 10 }
	},
	{
		{"얼음화살", "얼음화살을 소환해 쏜다.", 170, 20 },
		{"화염창", "화염창을 소환해 던진다.", 170, 20 },
		{"전기장", "전기장을 소환한다.", 170, 20 }
	},
	{
		{"진눈깨비", "진눈깨비가 휘날리게 한다.", 250, 40 },
		{"유성", "유성을 떨어뜨린다.", 250, 40 },
		{"천둥번개", "번개가 떨어진다.", 250, 40 }
	}
};


/*
	<장비 레벨>
	0. hat : 모자(체력)
	1. robe : 로브(방어력)
	2. shoes : 신발(이속)
	3. weapon : 무기(공격력)
	4. bracelet : 팔찌(마나)
*/

//등급-> 업그레이드를 할떄 일정 강화 레벨이 줄어들어 노말 4-> 레어 1레벨이 되는거야
//각 등급의 업그레이드마다 효과가 다르고 비용이 달라
//노말1->레어 1레벨
//노말1->레전더리 1레벨 까지 가는거보다 유니크 10레벨->레젠더리 6레벨 되는식으로
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
	<장비 레벨>
	0. hat : 모자(체력)
	1. robe : 로브(방어력)
	2. shoes : 신발(이속)
	3. weapon : 무기(공격력)
	4. bracelet : 팔찌(마나)
	[i][0]=NORMAL
	[i][1]=RARE
	[i][2]=EPIC
	[i][3]=UNIQUE
	[i][4]=LEGENDARY
*/
double rankEffect[5][5] = {
	{0,200,400,600,800},	//모자 등급 기본 효과
	{0,5,10,15,20},			//로브 등급 기본 효과
	{0,3,6,9,12},			//신발 등급 기본 효과
	{0,25,50,200,800},	//무기 등급 기본 효과
	{0,50,100,150,200}		//팔찌 등급 기본 효과
};