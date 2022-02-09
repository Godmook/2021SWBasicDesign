#include"Monster_Move.h"

// 몬스터 이동 후 다시 그리기
void monster_move(Monster* s)
{
	monsterGetDirection(s);
	switch (s->direction)
	{
	case 0: monsterMoveLeft(s);			break;
	case 1: monsterMoveUpLeft(s);		break;
	case 2: monsterMoveUp(s);			break;
	case 3: monsterMoveUpRight(s);		break;
	case 4: monsterMoveRight(s);		break;
	case 5: monsterMoveDownRight(s);	break;
	case 6: monsterMoveDown(s);			break;
	case 7: monsterMoveDownLeft(s);		break;
	default:							break;
	}
}

// 몬스터 이동 방향
void monsterGetDirection(Monster* s)
{
	double dist = sqrt(pow((pcX - s->m_x), 2) + pow(((pcY - s->m_y) * 2), 2));
	if (s->level > level && dist < 20)
	{
		int dx = pcX - s->m_x;

		int dy = pcY - s->m_y;

		if (dy == 0 && dx < 0)	s->direction = 0;
		else if (dy < 0 && dx < 0)	s->direction = 1;
		else if (dy < 0 && dx == 0)	s->direction = 2;
		else if (dy < 0 && dx > 0)	s->direction = 3;
		else if (dy == 0 && dx > 0)	s->direction = 4;
		else if (dy > 0 && dx > 0)	s->direction = 5;
		else if (dy > 0 && dx == 0)	s->direction = 6;
		else if (dy > 0 && dx < 0)	s->direction = 7;

		for (int i = 0; i < 5; i++)
		{
			int d1 = (s->direction + i) % 8;
			int d2 = (s->direction + (8 - i)) % 8;

			switch (d1)
			{
			case 0:	if (monsterDetectCollision(s->m_x - 1, s->m_y, s) == 0) { s->direction = d1; return; }		break;
			case 1:	if (monsterDetectCollision(s->m_x - 1, s->m_y - 1, s) == 0) { s->direction = d1; return; }	break;
			case 2:	if (monsterDetectCollision(s->m_x, s->m_y - 1, s) == 0) { s->direction = d1; return; }		break;
			case 3:	if (monsterDetectCollision(s->m_x + 1, s->m_y - 1, s) == 0) { s->direction = d1; return; }	break;
			case 4:	if (monsterDetectCollision(s->m_x + 1, s->m_y, s) == 0) { s->direction = d1; return; }		break;
			case 5:	if (monsterDetectCollision(s->m_x + 1, s->m_y + 1, s) == 0) { s->direction = d1; return; }	break;
			case 6:	if (monsterDetectCollision(s->m_x, s->m_y + 1, s) == 0) { s->direction = d1; return; }		break;
			case 7:	if (monsterDetectCollision(s->m_x - 1, s->m_y + 1, s) == 0) { s->direction = d1; return; }	break;
			default:																							break;
			}

			switch (d2)
			{
			case 0:	if (monsterDetectCollision(s->m_x - 1, s->m_y, s) == 0) { s->direction = d2; return; }		break;
			case 1:	if (monsterDetectCollision(s->m_x - 1, s->m_y - 1, s) == 0) { s->direction = d2; return; }	break;
			case 2:	if (monsterDetectCollision(s->m_x, s->m_y - 1, s) == 0) { s->direction = d2; return; }		break;
			case 3:	if (monsterDetectCollision(s->m_x + 1, s->m_y - 1, s) == 0) { s->direction = d2; return; }	break;
			case 4:	if (monsterDetectCollision(s->m_x + 1, s->m_y, s) == 0) { s->direction = d2; return; }		break;
			case 5:	if (monsterDetectCollision(s->m_x + 1, s->m_y + 1, s) == 0) { s->direction = d2; return; }	break;
			case 6:	if (monsterDetectCollision(s->m_x, s->m_y + 1, s) == 0) { s->direction = d2; return; }		break;
			case 7:	if (monsterDetectCollision(s->m_x - 1, s->m_y + 1, s) == 0) { s->direction = d2; return; }	break;
			default:																							break;
			}
		}

		s->direction = 8; // 이동 불가

	}
	else if (s->level > level) {
		s->direction = 8;
	}
	else
	{
		if (s->direction == 0)
		{
			if (monsterDetectCollision(s->m_x - 1, s->m_y, s) != 0)
				s->direction = 4;
		}
		else if (s->direction == 4)
		{
			if (monsterDetectCollision(s->m_x + 1, s->m_y, s) != 0)
				s->direction = 0;
		}
		else if (s->direction == 2)
		{
			if (monsterDetectCollision(s->m_x, s->m_y - 1, s) != 0)
				s->direction = 6;
		}
		else if (s->direction == 6)
		{
			if (monsterDetectCollision(s->m_x, s->m_y + 1, s) != 0)
				s->direction = 2;
		}
	}
}
// 몬스터 이동 검사
int monsterDetectCollision(int x, int y, Monster* s)
{
	if (x < 0) return 1;	// 벽과 충돌
	if (x > 123) return 1;
	if (y < 0) return 1;
	if (y > 38) return 1;

	if (NormalMapInfo[y][x] != 0 || NormalMapInfo[y][x + 1] != 0)
		return 2;	// 포탈 충돌

	for (int i = 0; i < 10; i++)
	{
		if (&monsterList[i] == s) continue;
		if (monsterList[i].m_x - 1 <= x && monsterList[i].m_x + 1 >= x && monsterList[i].m_y == y)
			return 3;	// 다른 몬스터와 충돌
	}

	return 0;
}

// 몬스터 그리기
void monsterDraw(Monster s)
{
	gotoxy(s.m_x, s.m_y);
	if (s.level > level)
	{
		printf("◆");
	}
	else
	{
		setcolor(s.element, C_BLACK);
		switch (s.shape)
		{
		case 0:	printf("●");	break;
		case 1:	printf("▲");	break;
		default:				break;
		}
		setcolor(C_WHITE, C_BLACK);
	}
}
// 몬스터 지우기
void monsterRemove(Monster s)
{
	gotoxy(s.m_x, s.m_y);
	printf("  ");
}

// 몬스터 이동
void monsterMoveLeft(Monster* s)
{
	monsterRemove(*s);
	s->m_x--;
	monsterDraw(*s);
}
void monsterMoveRight(Monster* s)
{
	monsterRemove(*s);
	s->m_x++;
	monsterDraw(*s);
}
void monsterMoveDown(Monster* s)
{
	monsterRemove(*s);
	s->m_y++;
	monsterDraw(*s);
}
void monsterMoveUp(Monster* s)
{
	monsterRemove(*s);
	s->m_y--;
	monsterDraw(*s);
}
void monsterMoveUpLeft(Monster* s)
{
	monsterRemove(*s);
	s->m_x--;
	s->m_y--;
	monsterDraw(*s);
}
void monsterMoveUpRight(Monster* s)
{
	monsterRemove(*s);
	s->m_x++;
	s->m_y--;
	monsterDraw(*s);
}
void monsterMoveDownLeft(Monster* s)
{
	monsterRemove(*s);
	s->m_x--;
	s->m_y++;
	monsterDraw(*s);
}
void monsterMoveDownRight(Monster* s)
{
	monsterRemove(*s);
	s->m_x++;
	s->m_y++;
	monsterDraw(*s);
}