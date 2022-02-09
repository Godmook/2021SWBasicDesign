#include"skill.h"

int currentSelect = 0;
int pointX[3] = { 35, 80, 125 };

void drawArrow()
{
	gotoxy(pointX[currentSelect], 32);
	printf("��");
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
				printf("��");
			else if (x == width - 1)
				printf("��");
			else printf("��");

			gotoxy(originX + x, 30);
			if (x == 0)
				printf("��");
			else if (x == width - 1)
				printf("��");
			else printf("��");

		}
		for (int y = 6; y < 30; y++)
		{
			gotoxy(originX, y);
			printf("��");
			gotoxy(originX + width-1, y);
			printf("��");
		}

		// �Ӽ��� ���� ����
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
		printf("���� : %s", s.explantion);
		gotoxy(originX + width / 2 - 13,19);
		printf("������ : �⺻������ %3d%%", s.damage);
		gotoxy(originX + width / 2 - 8, 23);
		printf("�Ҹ� ������ : %3d", s.mana);

		setcolor(C_WHITE, C_BLACK);
	}
	
	gotoxy(58, 40);
	printf("%d ������ �Ǿ� ���ο� ��ų�� ��� �� �ֽ��ϴ�.", level);
	gotoxy(65, 42);
	printf("���� ���� ��ų�� �����ϼ���.");
	

	gotoxy(65, 48);
	printf("(����Ű�� ���� �� SPACE�� ����)");
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