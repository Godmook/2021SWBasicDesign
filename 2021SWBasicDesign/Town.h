#pragma once
#include "normalSituation.h"
#include"MapInfo.h"
extern int TownInfo[39][123];

//���� �� ��Ȳ ����
void startNormalSituationInTown();

// ���� �� �������̽� 
void drawNormalSituationInTown();

void DrawTown(); //���� �� �׸���

// ���� �� + pc ���
void drawNormalSituationInTownMap();

//��Ż ���� �ִ��� Ȯ��
void Check_Portal();