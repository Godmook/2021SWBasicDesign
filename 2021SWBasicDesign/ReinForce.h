#pragma once
#pragma warning (disable : 4996)
#include <stdio.h>
#include "Color.h"
#include "data.h"
#include "Cursor.h"
#include "Key.h"
#include"data.h"
#define GOOUT 8
int ReinForceSelectProcessKeyInput();
void Print_ReinForce_Need();
void Print_ReinForce_Got();
int Calculate_Can_ReinForce();
void ShowPercent();
void Print_ReinForce_Need_RANK();
extern int equipReinForce[25][10];
extern int equipRankUpgarde[5][4];
extern int ReinForce_Select;
extern int ReinForce_Select_Before;
extern int Choose_OK;
extern int SELECT_SWITCH;
extern int JangGiBAEK[5];
void Draw_ReinForce_Select_BA(int BEFORE, int AFTER);
//������ ��� �������õ� �Լ�
void startReinForce();
void drawDownCase();
void drawUpCase();
void ReinForce_Before();
void ReinForce_After();
void Print_ReinForce_Item();
void DrawBg(int color, int bgcolor);
void Draw_ReinForce_Select();
void Option();
void SetUp();
void OptionClean();
void DrawLog();
void ShowPercent_RANK_UP();
void ReinForce_RANK();
void ReinForce_After_RANK();
//������ ��ü �׸��� ��
void ReinForceLoading();
void ReinForce();
//���� â
void DrawHat(int color, int bgcolor);
//�κ� â
void DrawRobe(int color, int bgcolor);
//���� â
void DrawWeapon(int color, int bgcolor);
//�Ź� â
void DrawShoe(int color, int bgcolor);
//���� â
void DrawPalZZi(int color, int bgcolor);

void DrawBACK(int color, int bgcolor);

void OptionLeft();

void OptionRight();

void MoveUpDraw();

void MoveDownDraw();

void CleanBg();