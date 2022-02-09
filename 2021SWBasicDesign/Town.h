#pragma once
#include "normalSituation.h"
#include"MapInfo.h"
extern int TownInfo[39][123];

//마을 맵 상황 시작
void startNormalSituationInTown();

// 마을 맵 인터페이스 
void drawNormalSituationInTown();

void DrawTown(); //마을 맵 그리기

// 마을 맵 + pc 출력
void drawNormalSituationInTownMap();

//포탈 위에 있는지 확인
void Check_Portal();