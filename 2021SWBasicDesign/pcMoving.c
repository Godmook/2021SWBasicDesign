#include"pcMoving.h"

int pcDetectCollision(int x, int y)
{
	if (x < 0) return 1;	// 벽과 충돌
	if (x > 123) return 1;
	if (y < 0) return 1;
	if (y > 38) return 1;

	if (STATE == START_NOMAL)
	{
		for (int i = 0; i < 10; i++)
			if (monsterList[i].m_x - 1 <= x && monsterList[i].m_x + 1 >= x && monsterList[i].m_y == y)
			{
				battleMosterIdx = i;
				return 2;	// 몬스터와 충돌
			}
		if (NormalMapInfo[y][x] == 5 || NormalMapInfo[y][x + 1] == 5)return 5;
		if (NormalMapInfo[y][x] == 6 || NormalMapInfo[y][x + 1] == 6)return 6;
	}
	else if (STATE == START_TOWN) {
		if (TownInfo[y][x] == 1 || TownInfo[y][x + 1] == 1)
			return 1;   // 별표 충돌      

		if (TownInfo[y][x] == 2 || TownInfo[y][x+1] == 2)
			return 2;   // 아이템 충돌      

		if (TownInfo[y][x] == 3 || TownInfo[y][x + 1] == 3)
			return 3;   // 건물 충돌      

		if (TownInfo[y][x] == 4 || TownInfo[y][x + 1] == 4)
			return 4;   // 건물 충돌
	}
	return 0;	// 충돌 없음
}

void pcRemove()
{
	gotoxy(pcX, pcY);
	if (STATE == START_TOWN) {
		switch (TownInfo[pcY][pcX]) {
		case 0: printf(" "); break;
		case 1: printf("*"); break;
		case 2: case 3: case 4:
			printf("/"); break;
		}
		gotoxy(pcX+1, pcY);
		switch (TownInfo[pcY][pcX+1]) {
		case 0: printf(" "); break;
		case 1: printf("*"); break;
		case 2: case 3: case 4:
			printf("/"); break;
		}
	}
	if(STATE== START_NOMAL){
		switch (NormalMapInfo[pcY][pcX]) {
		case 0: printf(" "); break;
		case 5: case 6: printf("/"); break;
		}
		gotoxy(pcX + 1, pcY);
		switch (NormalMapInfo[pcY][pcX + 1]) {
		case 0: printf(" "); break;
		case 5: case 6: 
			printf("/"); break;
		}
		gotoxy(59, 4);
		printf("Town");
		gotoxy(59, 34);
		printf("Boss");
	}
	if (STATE == START_BOSS_BATTEL)
	{
		gotoxy(pcX, pcY);
		printf("  ");

		// phase3 - 번개 그리기
		if (boss.element == E_ELECT)
		{
			// 번개 지나가는 경우
			if (isThunder == 1)
			{
				for (int i = 0; i < 10; i++)
				{
					if (pcX == thunder[i])
					{
						gotoxy(pcX, pcY);
						setcolor(E_ELECT, E_ELECT);
						printf(" ");
						setcolor(C_WHITE, C_BLACK);
					}
					if (pcX+1 == thunder[i])
					{
						gotoxy(pcX+1, pcY);
						setcolor(E_ELECT, E_ELECT);
						printf(" ");
						setcolor(C_WHITE, C_BLACK);
					}
				}
			}
		}
	}
}
void pcDraw()
{
	gotoxy(pcX, pcY);
	//setcolor(C_PINK, C_BLACK);
	//printf("★");
	printf("■");
	setcolor(C_WHITE, C_BLACK);
}

void pcMoveLeft()
{
	if (pcDetectCollision(pcX - 1, pcY) == 1) return;
	pcRemove();
	pcX--;
	pcDraw();
}
void pcMoveRight()
{
	if (pcDetectCollision(pcX + 1, pcY) == 1) return;
	pcRemove();
	pcX++;
	pcDraw();
}
void pcMoveUp()
{
	if (pcDetectCollision(pcX, pcY-1) == 1) return;
	pcRemove();
	pcY--;
	pcDraw();
}
void pcMoveDown()
{
	if (pcDetectCollision(pcX, pcY+1) == 1) return;
	pcRemove();
	pcY++;
	pcDraw();
}