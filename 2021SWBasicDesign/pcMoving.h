#pragma once
#include"data.h"
#include"normalSituation.h"
#include "Town.h"
#include"bossBattle.h"

// 충돌 찾기
int pcDetectCollision(int x,int y);

// 캐릭터 지우기
void pcRemove();
// 캐릭터 그리기
void pcDraw();

// 캐릭터 왼쪽으로 이동
void pcMoveLeft();
// 캐릭터 오른쪽으로 이동
void pcMoveRight();
// 캐릭터 위로 이동
void pcMoveUp();
// 캐릭터 아래로 이동
void pcMoveDown();
