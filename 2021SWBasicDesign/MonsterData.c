#include"MonsterData.h"
//앞에서 부터 체력, 공격력, 이동속도 순
//위에서부터 1레벨~ 16레벨

int battleMosterIdx = -1;
double monsterStatTable[17][3] = {
	{0,0,0},		//체력 공격력 이동속도
	{150,15,10},		//Lv.1
	{160,20,10},		//LV.2
	{170,25,10},		//Lv.3
	{180,30,10},		//Lv.4
	{200,40,10},		//Lv.5
	{300,50,10},		//Lv.6
	{400,70,10},		//Lv.7
	{500,80,10},		//Lv.8
	{600,90,10},		//Lv.9
	{700,100,10},		//Lv.10
	{800,110,10},		//Lv.11
	{1000,130,10},		//Lv.12
	{1100,140,10},		//Lv.13
	{1200,150,10},		//Lv.14
	{1300,160,10},		//Lv.15
	{1400,170,10}		//Lv.16
};
//앞에서 부터 하급, 하급+중급, 하급+중급+고급 순
//위에서부터 1레벨~ 16레벨
double monsterDropTable[17][3] = {
	{0,0,0},		//		하급	중급	고급
	{50,0,0},		//Lv.1	50		0		0
	{55,0,0},		//Lv.2	55		0		0
	{60,0,0},		//Lv.3	60		0		0
	{65,0,0},		//Lv.4	65		0		0
	{70,90,0},		//Lv.5	70		20		0
	{75,100,0},		//Lv.6	75		25		0
	{70,100,0},		//Lv.7	70		30		0
	{65,100,0},		//Lv.8	65		35		0
	{59,99,100},	//Lv.9	59		40		1
	{50,95,100},	//Lv.10	50		45		5
	{40,90,100},	//Lv.11	40		50		10
	{30,85,100},	//Lv.12	30		55		15
	{25,80,100},	//Lv.13	25		55		20
	{20,70,100},	//Lv.14	20		50		30
	{15,60,100},	//Lv.15	15		45		40
	{10,55,100}		//Lv.16	10		45		45
};

Monster monsterList[10];
Monster boss;

void initMonsterList()
{
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		monsterList[i] = SetMonster();
		if (monsterList[i].level > level) {
			int cnt = 0;
			for (int j = 0; j < i; j++) {
				if (monsterList[j].level>level)cnt++;
			}
			if (cnt > 2) {
				while (monsterList[i].level>level) {
					monsterList[i] = SetMonster();
				}
			}
		}
	}
}

Monster SetMonster() {
	Monster tmp;

	tmp.level = rand() % 9 - 5 + level;
	if (tmp.level < 1) tmp.level = 1;
	if (tmp.level > 16) tmp.level = 16;

	tmp.shape = rand() % 2;

	tmp.maxHp = monsterStatTable[tmp.level][0];
	if (tmp.shape == 1) tmp.maxHp *= 1.05;
	tmp.hp = tmp.maxHp;

	tmp.atk = monsterStatTable[tmp.level][1];
	if (tmp.shape == 0) tmp.atk *= 1.05;
	tmp.atk *= 2;
	int elem = rand() % 3;
	switch (elem)
	{
	case 0: tmp.element = E_FLAME;	break;
	case 1: tmp.element = E_ICE;	break;
	case 2: tmp.element = E_ELECT;	break;
	default:						break;
	}
	
	int dir = rand() % 2;
	if (tmp.shape == 0)
	{
		if (dir == 0)	tmp.direction = 0;	// 왼
		else if (dir == 1) tmp.direction = 4;	// 오
	}
	else if (tmp.shape == 1)
	{
		if (dir == 0) tmp.direction = 2;	// 위
		else if (dir == 1) tmp.direction = 6;	// 아래 
	}

	tmp.exp = (rand()%5+1) * pow(2, tmp.level - 1);
	int rand_money = rand() % 3 + 2;
	tmp.money = rand_money*tmp.maxHp;
	for (int i = 0; i < tmp.level/2; i++) {
		int stone = rand() % 100 + 1;
		if (stone < monsterDropTable[tmp.level][0]) tmp.Enhance_Stone[i] = STONE1;
		else if (stone < monsterDropTable[tmp.level][1]) tmp.Enhance_Stone[i] = STONE2;
		else if (stone < monsterDropTable[tmp.level][2]) tmp.Enhance_Stone[i] = STONE3;
		else tmp.Enhance_Stone[i] = 0;	// 강화의 돌 드랍 없음
	}
	tmp.m_x = rand() % 124;
	tmp.m_y = rand() % 38;

	while (NormalMapInfo[tmp.m_y][tmp.m_x] != 0)
	{
		tmp.m_x = rand() % 124;
		tmp.m_y = rand() % 38;
	}

	return tmp;
}
