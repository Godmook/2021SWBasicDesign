#pragma once
#pragma warning (disable : 4996)
#include <stdio.h>
#include "Color.h"
#include "data.h"
#include "Cursor.h"
#include "Key.h"

extern int price[6];

#define HP 0
#define MP 1
#define ALL 2
#define EXP 3
#define GOLD 4

#define LEAVE 5

int state;

int Choice_Status;
int Choice_Status_Before;

int Select;
int SelectBUY;

int num;
int total;

//구매 가격을 고른 상태에서 구매를 할지 안할지 여부를 출력
extern int Select_Buy_Chioce;
void startBuyItem();// 아이템 창 화면 시작하기

void DrawItmeFirst();//첫 시작 그리기
void drawInventory();

int CheckMoney(int num);

int MoneyGacha();

int DrawChoiceItem();

void DrawSelect(int before, int after);

int DrawUpDown();

void Show_Choice();
int DrawBuyItem();
void OptionClean();
void SelectBUYItem();

void ReturnBUYItem_Choice();
void SelectBUYItem_Choice();
void ReturnSelectItem();

void Buttons();

void SelectDOWN();

void SelectUP();

void UPandDOWN();


void SetZero();

void Calculate();

void drawPlusEXP(double plus);
void UsingEXPPortion();// 경험치 포션 적용
void SetEXP(); //경험치 그림 그리기

void Box(int color, int bgcolor);
void DrawBOX(int color, int bgcolor);//상자 그리기

//설명 작성
void DrawItemInstructions();

//초기화
void RemoveItemInstructions();



void DrawHPPortion(int color, int bgcolor);
void DrawMPPortion(int color, int bgcolor);
void DrawALLPortion(int color, int bgcolor);
void DrawEXPPortion(int color, int bgcolor);
void DrawGOLDBOX(int color, int bgcolor);
void DrawLEAVE(int color, int bgcolor);