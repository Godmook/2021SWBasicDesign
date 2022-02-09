#pragma once
#include "Cursor.h"
#include "MonsterData.h"
#include "MapInfo.h"

// 몬스터 이동 후 다시 그리기
void monster_move(Monster* s);

// 몬스터 이동 방향
void monsterGetDirection(Monster* s);
// 몬스터 이동 검사
int monsterDetectCollision(int x, int y, Monster *s);

// 몬스터 그리기
void monsterDraw(Monster s);
// 몬스터 지우기
void monsterRemove(Monster s);

// 몬스터 이동
void monsterMoveLeft(Monster* s);
void monsterMoveRight(Monster* s);
void monsterMoveDown(Monster* s);
void monsterMoveUp(Monster* s);
void monsterMoveUpLeft(Monster* s);
void monsterMoveUpRight(Monster* s);
void monsterMoveDownLeft(Monster* s);
void monsterMoveDownRight(Monster* s);
