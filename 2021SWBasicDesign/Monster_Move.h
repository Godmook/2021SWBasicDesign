#pragma once
#include "Cursor.h"
#include "MonsterData.h"
#include "MapInfo.h"

// ���� �̵� �� �ٽ� �׸���
void monster_move(Monster* s);

// ���� �̵� ����
void monsterGetDirection(Monster* s);
// ���� �̵� �˻�
int monsterDetectCollision(int x, int y, Monster *s);

// ���� �׸���
void monsterDraw(Monster s);
// ���� �����
void monsterRemove(Monster s);

// ���� �̵�
void monsterMoveLeft(Monster* s);
void monsterMoveRight(Monster* s);
void monsterMoveDown(Monster* s);
void monsterMoveUp(Monster* s);
void monsterMoveUpLeft(Monster* s);
void monsterMoveUpRight(Monster* s);
void monsterMoveDownLeft(Monster* s);
void monsterMoveDownRight(Monster* s);
