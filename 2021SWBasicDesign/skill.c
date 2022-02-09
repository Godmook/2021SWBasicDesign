#include"skill.h"

int currentSelect = 0;
int pointX[3] = { 35, 80, 125 };

void drawArrow()
{
	gotoxy(pointX[currentSelect], 32);
	printf("▲");
}

void removeArrow()
{
	gotoxy(pointX[currentSelect], 32);
	printf("  ");
}

void selectSkill()
{
	rewind(stdin);
	int skillIndex = 0;
	if (level == 5) skillIndex = 0;
	else if (level == 9) skillIndex = 1;
	else if (level == 13) skillIndex = 2;
	currentSelect = 0;

	selectSkillDraw(skillIndex);
	drawArrow();
	while (!selectSkillProcessKeyInput());
	takenSkill[skillIndex] = currentSelect;
}
void selectSkillDraw(int idx)
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		int width = 40;
		int height = 25;
		int originX = 15 + width * i + 5 * i;
		for (int x = 0; x < width; x++)
		{
			gotoxy(originX + x, 5);
			if (x == 0)
				printf("┌");
			else if (x == width - 1)
				printf("┐");
			else printf("─");

			gotoxy(originX + x, 30);
			if (x == 0)
				printf("└");
			else if (x == width - 1)
				printf("┘");
			else printf("─");

		}
		for (int y = 6; y < 30; y++)
		{
			gotoxy(originX, y);
			printf("│");
			gotoxy(originX + width-1, y);
			printf("│");
		}

		// 속성별 색상 변경
		switch (i)
		{
		case 0: setcolor(E_ICE, C_BLACK);     break;
		case 1: setcolor(E_FLAME, C_BLACK);   break;
		case 2: setcolor(E_ELECT, C_BLACK);   break;
		}
		
		Skill s = skillInfo[idx][i];
		
		gotoxy(originX +width/2 - strlen(s.name)/2, 10);
		printf("<%s>", s.name);
		gotoxy(originX + width / 2 - (strlen(s.explantion)+8) / 2, 15);
		printf("설명 : %s", s.explantion);
		gotoxy(originX + width / 2 - 13,19);
		printf("데미지 : 기본공격의 %3d%%", s.damage);
		gotoxy(originX + width / 2 - 8, 23);
		printf("소모 마나양 : %3d", s.mana);

		setcolor(C_WHITE, C_BLACK);
	}
	
	gotoxy(58, 40);
	printf("%d 레벨이 되어 새로운 스킬을 배울 수 있습니다.", level);
	gotoxy(65, 42);
	printf("배우고 싶은 스킬을 선택하세요.");
	

	gotoxy(65, 48);
	printf("(방향키로 선택 후 SPACE로 결정)");
}
int selectSkillProcessKeyInput()
{
	for (int i = 0; i < 100; i++)
	{
		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case LEFT:          if (currentSelect != 0) { removeArrow();  currentSelect--; }	break;
			case RIGHT:         if (currentSelect != 2) { removeArrow();  currentSelect++; }    break;
			case SPACE_BAR:			return 1;														break;
			default:																			break;
			}
			drawArrow();
		}
		Sleep(10);
	}
	return 0;
}