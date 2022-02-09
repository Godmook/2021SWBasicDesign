#include"ChangeHpMp.h"
void drawBossBattleSituationMonsterStat(Monster* s)
{
	// ü��, ���� ����

	// ü�� ���
	int ratioHp = s->hp / (s->maxHp / 32.0f);

	// ü�� ���
	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 40); printf("����");
	gotoxy(105, 42); printf("ü��");
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
		// ü��, ���� ����
		int ratioMp = mp / (maxMp / 32.0f);
		// ���� ���
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 48); printf("����");
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
			// ü��, ���� ����
			int ratioMp = mp / (maxMp / 32.0f);
			// ���� ���
			setcolor(C_WHITE, C_BLACK);
			gotoxy(105, 48); printf("����");
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
	// ü��, ���� ����
	Dont_GetKey = 1;
	int Sleep_time = abs(FinalHp - s->hp);
	// ü�� ���
	while (1) {
		int ratioHp = s->hp / (s->maxHp / 32.0f);

		// ü�� ���
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 40); printf("����");
		gotoxy(105, 42); printf("ü��");
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
// �Ϲ� ���Ϳ��� ���� ��Ȳ �� PC ü�� �����̸鼭 ���ϰ�
void drawBattleSituationPCHP(int FinalHp)
{
	int Sleep_time = abs(FinalHp - hp);
	Dont_GetKey = 1;
	// ü��, ���� ����
	while (1) {
		int ratioHp = hp / (maxHp / 32.0f);
		int ratioMp = mp / (maxMp / 32.0f);

		// ü�� ���
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 44); printf("�÷��̾�");
		gotoxy(105, 46); printf("ü��");
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
	// ü��, ���� ����
	while (1) {
		int ratioHp = hp / (maxHp / 32.0f);
		// ü�� ���
		setcolor(C_WHITE, C_BLACK);
		gotoxy(105, 44); printf("�÷��̾�");
		gotoxy(105, 46); printf("ü��");
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

	// ü��, ���� ����
	int ratioHp = hp / (maxHp / 32.0f);
	int ratioMp = mp / (maxMp / 32.0f);

	// ü�� ���
	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 44); printf("�÷��̾�");
	gotoxy(105, 46); printf("ü��");
	gotoxy(110, 46);

	setcolor(C_WHITE, C_RED_);
	for (int i = 0; i < ratioHp; i++)
		printf(" ");
	setcolor(C_WHITE, C_RED);
	for (int i = ratioHp; i < 32; i++)
		printf(" ");
	setcolor(C_WHITE, C_BLACK);
	printf(" (%6d/%6d)", hp, maxHp);

	// ���� ���

	setcolor(C_WHITE, C_BLACK);
	gotoxy(105, 48); printf("����");
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