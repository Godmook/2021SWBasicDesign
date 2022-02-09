#pragma once
#include "Damage.h"

const int Monster_To_PC_Damage[3][3] =
{						//				데미지 안들어갈 확률		크리티컬 데미지 확률		일반 데미지 확률
	{5, 20, 100},		//상성 좋으면  :		5							15						   80
	{10, 20 , 100},		//일반 상성    :		10							10						   80
	{15,20,100}			//상성 안좋으면:		15							5						   80
};
//턴상황일때 몬스터가 데미지 넣는거
void Monster_Damage_Turn(Monster* s) {
	int random_var = rand() % 100;
	int dmg = 0;
	if (random_var < Monster_To_PC_Damage[1][0])	drawNormalBattleSituationLogUpdate("공격을 피했습니다.");
	else if (random_var < Monster_To_PC_Damage[1][1])
	{
		drawNormalBattleSituationLogUpdate("<치명타>");
		dmg = (int)(1.5 * (s->atk) * (1 - (double)def / 100));
		char str[50];
		sprintf(str, "%d의 공격을 받았습니다.", dmg);
		drawNormalBattleSituationLogUpdate(str);
		int tmp = CalculateFinalHp(hp, dmg);
		drawBattleSituationPCHP(tmp);
		Sleep(10);
	}
	else
	{
		dmg = (int)((s->atk) * (1 - (double)def / 100));
		char str[50];
		sprintf(str, "%d의 공격을 받았습니다.", dmg);
		drawNormalBattleSituationLogUpdate(str);
		int tmp = CalculateFinalHp(hp, dmg);
		drawBattleSituationPCHP(tmp);
		Sleep(10);
	}
}
//몬->플
void Monster_Damage(Monster *s,int *TypingInfo) {
	int random_var = rand() % 100;
	double dmg = 0;
	switch (Calculate_Upper_OR_Lower(*s, TypingInfo, 1)) {
	case 0:		if (random_var < Monster_To_PC_Damage[1][0])	drawNormalBattleSituationLogUpdate("공격을 피했습니다.");
				else if (random_var < Monster_To_PC_Damage[1][1]) 
				{
					drawNormalBattleSituationLogUpdate("<치명타>");
					dmg = 1.5 * (s->atk) * (1 - (double)def / 100);
					dmg = (int)dmg;
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				else
				{
					dmg = (s->atk) * (1 - (double)def / 100);
					dmg = (int)dmg;
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				break;
	case 1:		if (random_var < Monster_To_PC_Damage[0][0]) drawNormalBattleSituationLogUpdate("공격을 피했습니다.");
				else if (random_var < Monster_To_PC_Damage[0][1])
				{
					drawNormalBattleSituationLogUpdate("<치명타>");
					dmg = 1.5 * (s->atk) * (1 - (double)def / 100) * 1.2;
					dmg = (int)dmg;
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				else
				{
					dmg = (s->atk) * (1 - (double)def / 100) * 1.2;
					dmg = (int)dmg;
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				break;
	case -1:	if (random_var < Monster_To_PC_Damage[2][0]) {
		drawNormalBattleSituationLogUpdate("공격을 피했습니다.");
		drawNormalBattleSituationLogUpdate(" ");
	}
				 else if (random_var < Monster_To_PC_Damage[2][1])
				{
					drawNormalBattleSituationLogUpdate("<치명타>");
					dmg = 1.5 * (s->atk) * (1 - (double)def / 100) * 0.8;
					dmg = (int)dmg;
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					drawNormalBattleSituationLogUpdate(" ");
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				 else
				{
					dmg = (int)((s->atk) * (1 - (double)def / 100) * 0.8);
					char str[50];
					sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
					drawNormalBattleSituationLogUpdate(str);
					drawNormalBattleSituationLogUpdate(" ");
					int tmp = CalculateFinalHp(hp, dmg);
					drawBattleSituationPCHP(tmp);
					Sleep(10);
				}
				break;
	}
	if (hp < 0)hp = 0;
}
void PC_Damage(Monster* s,int *TypingInfo) {
	char str[50];
	if (TypingInfo[1]){
		switch (TypingInfo[3]) {
		case 0:
			break;
		case 1:
				sprintf(str, "스킬 [%s]를 사용하지", skillInfo[0][takenSkill[0]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" 못했습니다.");
				drawNormalBattleSituationLogUpdate(" ");
			break;
		case 2:
				sprintf(str, "스킬 [%s]를 사용하지", skillInfo[1][takenSkill[1]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" 못했습니다.");
			break;
		case 3:
				sprintf(str, "스킬 [%s]를 사용하지", skillInfo[2][takenSkill[2]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" 못했습니다.");
				drawNormalBattleSituationLogUpdate(" ");
			break;
		default:
			break;
		}
		switch (TypingInfo[3]) {
			int tmp = 0;
		case 1:
			drawNormalBattleSituationLogUpdate("마나 10을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 10);
			drawBattleSituationPCMP(tmp);
			break;
		case 2:
			drawNormalBattleSituationLogUpdate("마나 20을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 20);
			drawBattleSituationPCMP(tmp);
			break;
		case 3:
			drawNormalBattleSituationLogUpdate("마나 40을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 40);
			drawBattleSituationPCMP(tmp);
			break;
		}
	}
	if (!TypingInfo[1]) {
		int random_var = rand() % 100;
		double dmg;
		double Critical_Calculate = (double)TypingInfo[0] / 10;
		double plusDamage = 0;

		switch (TypingInfo[3]) {
		case 0:		plusDamage = 1.0;	break;
		case 1:		plusDamage = 1.3;	break;
		case 2:		plusDamage = 1.7;	break;
		case 3:		plusDamage = 2.5;	break;
		}
		double m;
		switch (TypingInfo[3]) {
		case 0:
			break;
		case 1:
				sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[0][takenSkill[0]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" ");
			break;
		case 2:
				sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[1][takenSkill[1]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" ");
			break;
		case 3:
				sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[2][takenSkill[2]].name);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" ");
			break;
		default:
			break;
		}
		switch(TypingInfo[3]) {
			int tmp = 0;
		case 1:
			drawNormalBattleSituationLogUpdate("마나 10을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 10);
			drawBattleSituationPCMP(tmp);
			break;
		case 2:
			drawNormalBattleSituationLogUpdate("마나 20을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 20);
			drawBattleSituationPCMP(tmp);
			break;
		case 3:
			drawNormalBattleSituationLogUpdate("마나 40을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			tmp = CalculateFinalHp(mp, 40);
			drawBattleSituationPCMP(tmp);
			break;
		}
		switch (Calculate_Upper_OR_Lower(*s, TypingInfo, 0)) {
		case 0:		if (random_var < Critical_Calculate)	
					{ 
						setcolor(C_YELLOW, C_BLACK);
						drawNormalBattleSituationLogUpdate("critical");
						setcolor(C_WHITE, C_BLACK);
						dmg = 1.5 * atk * plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s,tmp);
						Sleep(10);
					}
					else
					{
						dmg = atk*plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s, tmp);
						Sleep(10);
					}
					break;
		case 1:		if (random_var < Critical_Calculate)
					{
					setcolor(C_YELLOW, C_BLACK);
						drawNormalBattleSituationLogUpdate("critical");
						setcolor(C_WHITE, C_BLACK);
						dmg = 1.5 * atk * 1.2 * plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s, tmp);
						Sleep(10);
					}
					else
					{
						dmg = atk * 1.2 * plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s, tmp);
						Sleep(10);
					}
					break;
		case -1:	if (random_var < Critical_Calculate)
					{
			setcolor(C_YELLOW, C_BLACK);
						drawNormalBattleSituationLogUpdate("critical");
						setcolor(C_WHITE, C_BLACK);
						dmg = 1.5 * atk * 0.8 * plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s, tmp);
						Sleep(10);
					}
					else	
					{
						dmg = atk * 0.8 * plusDamage;
						dmg = (int)dmg;
						sprintf(str, "%.lf의 공격을 합니다.", dmg);
						drawNormalBattleSituationLogUpdate(str);
						drawNormalBattleSituationLogUpdate(" ");
						int tmp = CalculateFinalHp(s->hp, dmg);
						drawBattleSituationMonsterHP(s, tmp);
						Sleep(10);
					}
					break;
		}
		switch (TypingInfo[3]) {
		case 0:
			if (!TypingInfo[1]) {
				m = maxMp * 0.1;
				if (mp + m > maxMp)m = maxMp - mp;
				m = (int)m;
				sprintf(str, "%.lf의 마나를 회복합니다.", m);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" ");
				int tmp = mp + m;
				drawBattleSituationPCMPUp(tmp);
			}
			break;
		default:
			break;
		}
		if (s->hp < 0)s->hp = 0;
	}
}
//s는 현재 상대하고 있는 몬스터 정보, TypingInfo는 현재 친 타자에 대한 정보
int Calculate_Upper_OR_Lower(Monster s,int *TypingInfo,int flag) {		// flag 1번 몬스터가 플레이어 공격
	int tmp = 0;														// flag 0번 플레이어가 몬스터 공격
	if (flag == 1) {
		switch (s.element) {
		case E_FLAME:	if (TypingInfo[2] == E_FLAME || TypingInfo[2] == E_NON)   return 0;
						if (TypingInfo[2] == E_ELECT)							  return 1;
						if (TypingInfo[2] == E_ICE)                               return -1;
		case E_ICE:		if (TypingInfo[2] == E_ICE || TypingInfo[2] == E_NON)     return 0;
						if (TypingInfo[2] == E_ELECT)					          return 1;
						if (TypingInfo[2] == E_FLAME)                             return -1;
		case E_ELECT:	if (TypingInfo[2] == E_ELECT || TypingInfo[2] == E_NON)   return 0;
						if (TypingInfo[2] == E_ICE)					              return 1;
						if (TypingInfo[2] == E_FLAME)							  return -1;
		}
	}
	else {
		switch (TypingInfo[2]) {
		case E_NON:															  return 0;
		case E_FLAME:	if (s.element == E_FLAME)							  return 0;
						if (s.element == E_ELECT)							  return 1;
						if (s.element == E_ICE)                               return -1;
		case E_ICE:		if (s.element == E_ICE)								  return 0;
						if (s.element == E_ELECT)					          return 1;
						if (s.element == E_FLAME)                             return -1;
		case E_ELECT:	if (s.element == E_ELECT)							  return 0;
						if (s.element == E_ICE)					              return 1;
						if (s.element == E_FLAME)							  return -1;
		}
	}
}

void PCInBoss_Damage(Monster* s, int* TypingInfo) {
	char str[50];
	if (TypingInfo[1]) {
		switch (TypingInfo[3]) {
		case 0:
			break;
		case 1:
			sprintf(str, "스킬 [%s]를 사용하지", skillInfo[0][takenSkill[0]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" 못했습니다.");
			drawNormalBattleSituationLogUpdate(" ");
			break;
		case 2:
			sprintf(str, "스킬 [%s]를 사용하지", skillInfo[1][takenSkill[1]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" 못했습니다.");
			break;
		case 3:
			sprintf(str, "스킬 [%s]를 사용하지", skillInfo[2][takenSkill[2]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" 못했습니다.");
			drawNormalBattleSituationLogUpdate(" ");
			break;
		default:
			break;
		}
		switch (TypingInfo[3]) {
			int tmp = 0;
		case 1:
			drawNormalBattleSituationLogUpdate("마나 10을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp = CalculateFinalHp(mp, 10);
			drawBossSituationPCStat();
			break;
		case 2:
			drawNormalBattleSituationLogUpdate("마나 20을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp = CalculateFinalHp(mp, 20);
			drawBossSituationPCStat();
			break;
		case 3:
			drawNormalBattleSituationLogUpdate("마나 40을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp = CalculateFinalHp(mp, 40);
			drawBossSituationPCStat();
			break;
		}
	}
	if (!TypingInfo[1]) {
		int random_var = rand() % 100;
		double dmg;
		double Critical_Calculate = (double)TypingInfo[0] / 10;
		double plusDamage = 0;

		switch (TypingInfo[3]) {
		case 0:      plusDamage = 1.0;   break;
		case 1:      plusDamage = 1.3;   break;
		case 2:      plusDamage = 1.7;   break;
		case 3:      plusDamage = 2.5;   break;
		}
		double m;
		switch (TypingInfo[3]) {
		case 0:
			break;
		case 1:
			sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[0][takenSkill[0]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			break;
		case 2:
			sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[1][takenSkill[1]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			break;
		case 3:
			sprintf(str, "스킬 [%s]를 사용합니다.", skillInfo[2][takenSkill[2]].name);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			break;
		default:
			break;
		}
		switch (TypingInfo[3]) {
			int tmp = 0;
		case 1:
			drawNormalBattleSituationLogUpdate("마나 10을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp = CalculateFinalHp(mp, 10);
			drawBossSituationPCStat();
			break;
		case 2:
			drawNormalBattleSituationLogUpdate("마나 20을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp = CalculateFinalHp(mp, 20);
			drawBossSituationPCStat();
			break;
		case 3:
			drawNormalBattleSituationLogUpdate("마나 40을 사용합니다.");
			drawNormalBattleSituationLogUpdate(" ");
			mp =CalculateFinalHp(mp, 40);
			drawBossSituationPCStat();
			break;
		}
		switch (Calculate_Upper_OR_Lower(*s, TypingInfo, 0)) {
		case 0:      if (random_var < Critical_Calculate)
		{
			setcolor(C_YELLOW, C_BLACK);
			drawNormalBattleSituationLogUpdate("critical");
			setcolor(C_WHITE, C_BLACK);
			dmg = 1.5 * atk * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			  else
		{
			dmg = atk * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			  break;
		case 1:      if (random_var < Critical_Calculate)
		{
			setcolor(C_YELLOW, C_BLACK);
			drawNormalBattleSituationLogUpdate("critical");
			setcolor(C_WHITE, C_BLACK);
			dmg = 1.5 * atk * 1.2 * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			  else
		{
			dmg = atk * 1.2 * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			  break;
		case -1:   if (random_var < Critical_Calculate)
		{
			setcolor(C_YELLOW, C_BLACK);
			drawNormalBattleSituationLogUpdate("critical");
			setcolor(C_WHITE, C_BLACK);
			dmg = 1.5 * atk * 0.8 * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			   else
		{
			dmg = atk * 0.8 * plusDamage;
			dmg = (int)dmg;
			sprintf(str, "%.lf의 공격을 합니다.", dmg);
			drawNormalBattleSituationLogUpdate(str);
			drawNormalBattleSituationLogUpdate(" ");
			s->hp = CalculateFinalHp(s->hp, dmg);
			drawBossBattleSituationMonsterStat(s);
			Sleep(10);
		}
			   break;
		}
		switch (TypingInfo[3]) {
		case 0:
			if (!TypingInfo[1]) {
				m = maxMp * 0.1;
				if (mp + m > maxMp)m = maxMp - mp;
				m = (int)m;
				sprintf(str, "%.lf의 마나를 회복합니다.", m);
				drawNormalBattleSituationLogUpdate(str);
				drawNormalBattleSituationLogUpdate(" ");
				mp += m;
				drawBossSituationPCStat();
			}
			break;
		default:
			break;
		}
		if (s->hp < 0)s->hp = 0;
	}
}

void Boss_Damage(Monster* s) {      //보스가 플레이어한테 넣는 데미지 코드
	int random_var = rand() % 100;
	double dmg = 0;
	if (random_var < 20) {
		drawNormalBattleSituationLogUpdate("<치명타>");
		dmg = 1.5 * (s->atk) * (1 - (double)def / 100);
		dmg = (int)dmg;
		char str[50];
		sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
		drawNormalBattleSituationLogUpdate(str);
		hp = CalculateFinalHp(hp, dmg);
		drawBossSituationPCStat();
		Sleep(10);
	}
	else {
		dmg = (s->atk) * (1 - (double)def / 100);
		dmg = (int)dmg;
		char str[50];
		sprintf(str, "%.lf의 공격을 받았습니다.", dmg);
		drawNormalBattleSituationLogUpdate(str);
		hp = CalculateFinalHp(hp, dmg);
		drawBossSituationPCStat();
		Sleep(10);
	}
	if (hp < 0)hp = 0;
}