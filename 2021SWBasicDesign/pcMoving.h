#pragma once
#include"data.h"
#include"normalSituation.h"
#include "Town.h"
#include"bossBattle.h"

// �浹 ã��
int pcDetectCollision(int x,int y);

// ĳ���� �����
void pcRemove();
// ĳ���� �׸���
void pcDraw();

// ĳ���� �������� �̵�
void pcMoveLeft();
// ĳ���� ���������� �̵�
void pcMoveRight();
// ĳ���� ���� �̵�
void pcMoveUp();
// ĳ���� �Ʒ��� �̵�
void pcMoveDown();
