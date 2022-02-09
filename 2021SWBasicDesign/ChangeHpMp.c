#include"ChangeHpMp.h"
void drawBossBattleSituationMonsterStat(Monster* s)
{
	// 체력, 마나 비율

	// 체력 출력
	int ratioHp = s->hp / (s->maxHp / 32.0f);

	// 체력 출력
	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 40); printf("몬스터");
	gotoxy(105, 42); printf("체력");
	gotoxy(110, 42);

	setcolor(C_WHITE, C_RED_);
	for (int i = 0; i < ratioHp; i++)
		printf(" ");
	setcolor(C_WHITE, C_RED);
	for (int i = ratioHp; i < 32; i++)
		printf(" ");
	setcolor(C_WHITE, C_BLACK);
	printf(" (%6d/%6d)", s->hp, s->maxHp);

}
void drawBattleSituationPCMP(int FinalMp)
{
	Dont_GetKey = 1;
	int Sleep_time = abs(FinalMp - mp);
	while (1) {
		// 체력, 마나 비율
		int ratioMp = mp / (maxMp / 32.0f);
		// 마나 출력
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 48); printf("마나");
		gotoxy(110, 48);
		setcolor(C_WHITE, C_BLUE_);

		for (int i = 0; i < ratioMp; i++)
			printf(" ");
		setcolor(C_WHITE, C_BLUE);
		for (int i = ratioMp; i < 32; i++)
			printf(" ");
		setcolor(C_WHITE, C_BLACK);
		printf(" (%6d/%6d)", mp, maxMp);
		Sleep((50 / Sleep_time) / Sleep_time);
		if (mp == FinalMp)break;
		mp--;
	}
	Dont_GetKey = 0;
}
void drawBattleSituationPCMPUp(int FinalMp)
{
	if (mp != FinalMp) {
		Dont_GetKey = 1;
		int Sleep_time = abs(FinalMp - mp);
		while (1) {
			// 체력, 마나 비율
			int ratioMp = mp / (maxMp / 32.0f);
			// 마나 출력
			setcolor(C_WHITE, C_BLACK);
			gotoxy(105, 48); printf("마나");
			gotoxy(110, 48);
			setcolor(C_WHITE, C_BLUE_);

			for (int i = 0; i < ratioMp; i++)
				printf(" ");
			setcolor(C_WHITE, C_BLUE);
			for (int i = ratioMp; i < 32; i++)
				printf(" ");
			setcolor(C_WHITE, C_BLACK);
			printf(" (%6d/%6d)", mp, maxMp);
			Sleep((50 / Sleep_time) / Sleep_time);
			if (mp == FinalMp)break;
			mp++;
		}
		Dont_GetKey = 0;
	}
}
void drawBattleSituationMonsterHP(Monster* s, int FinalHp)
{
	// 체력, 마나 비율
	Dont_GetKey = 1;
	int Sleep_time = abs(FinalHp - s->hp);
	// 체력 출력
	while (1) {
		int ratioHp = s->hp / (s->maxHp / 32.0f);

		// 체력 출력
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 40); printf("몬스터");
		gotoxy(105, 42); printf("체력");
		gotoxy(110, 42);

		setcolor(C_WHITE, C_RED_);
		for (int i = 0; i < ratioHp; i++)
			printf(" ");
		setcolor(C_WHITE, C_RED);
		for (int i = ratioHp; i < 32; i++)
			printf(" ");
		setcolor(C_WHITE, C_BLACK);
		printf(" (%6d/%6d)", s->hp, s->maxHp);
		Sleep((50 / Sleep_time) / Sleep_time);
		if (s->hp == FinalHp)break;
		s->hp--;
	}
	Dont_GetKey = 0;
}
// 일반 몬스터와의 전투 상황 중 PC 체력 움직이면서 변하게
void drawBattleSituationPCHP(int FinalHp)
{
	int Sleep_time = abs(FinalHp - hp);
	Dont_GetKey = 1;
	// 체력, 마나 비율
	while (1) {
		int ratioHp = hp / (maxHp / 32.0f);
		int ratioMp = mp / (maxMp / 32.0f);

		// 체력 출력
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 44); printf("플레이어");
		gotoxy(105, 46); printf("체력");
		gotoxy(110, 46);

		setcolor(C_WHITE, C_RED_);
		for (int i = 0; i < ratioHp; i++)
			printf(" ");
		setcolor(C_WHITE, C_RED);
		for (int i = ratioHp; i < 32; i++)
			printf(" ");
		setcolor(C_WHITE, C_BLACK);
		printf(" (%6d/%6d)", hp, maxHp);
		Sleep((50 / Sleep_time) / Sleep_time);
		if (hp == FinalHp)break;
		hp--;
	}
	Dont_GetKey = 0;
}
void drawBattleSituationPCHPUp(int FinalHp)
{
	int Sleep_time = abs(FinalHp - hp);
	Dont_GetKey = 1;
	// 체력, 마나 비율
	while (1) {
		int ratioHp = hp / (maxHp / 32.0f);
		// 체력 출력
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 44); printf("플레이어");
		gotoxy(105, 46); printf("체력");
		gotoxy(110, 46);

		setcolor(C_WHITE, C_RED_);
		for (int i = 0; i < ratioHp; i++)
			printf(" ");
		setcolor(C_WHITE, C_RED);
		for (int i = ratioHp; i < 32; i++)
			printf(" ");
		setcolor(C_WHITE, C_BLACK);
		printf(" (%6d/%6d)", hp, maxHp);
		Sleep((50 / Sleep_time) / Sleep_time);
		if (hp == FinalHp)break;
		hp++;
	}
	Dont_GetKey = 0;
}
int CalculateFinalHp(int currentHp, int Damage) {
	int tmp = currentHp - Damage;
	if (tmp < 0)tmp = 0;
	return tmp;
}

void drawBossSituationPCStat()
{

	// 체력, 마나 비율
	int ratioHp = hp / (maxHp / 32.0f);
	int ratioMp = mp / (maxMp / 32.0f);

	// 체력 출력
	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 44); printf("플레이어");
	gotoxy(105, 46); printf("체력");
	gotoxy(110, 46);

	setcolor(C_WHITE, C_RED_);
	for (int i = 0; i < ratioHp; i++)
		printf(" ");
	setcolor(C_WHITE, C_RED);
	for (int i = ratioHp; i < 32; i++)
		printf(" ");
	setcolor(C_WHITE, C_BLACK);
	printf(" (%6d/%6d)", hp, maxHp);

	// 마나 출력

	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 48); printf("마나");
	gotoxy(110, 48);
	setcolor(C_WHITE, C_BLUE_);

	for (int i = 0; i < ratioMp; i++)
		printf(" ");
	setcolor(C_WHITE, C_BLUE);
	for (int i = ratioMp; i < 32; i++)
		printf(" ");
	setcolor(C_WHITE, C_BLACK);
	printf(" (%6d/%6d)", mp, maxMp);

}