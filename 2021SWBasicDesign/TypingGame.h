#pragma once
#include <time.h>
#include"data.h"
#include "Color.h"
#include "Key.h"
#include"BattleLog.h"
#include"bossBattle.h"
#include"normalBattleSituation.h"

extern const char Element_text[80][60];
//Ÿ�� ���� ������ �� ele= �Ӽ� lv= ��ų ����
void TypingGame(int ele, int lv,int *Result_Arr);
//Ÿ���� �ϴ� ȭ�� �ʱ�ȭ
void TypingClean();

// ���� Ÿ���� ����
extern char atkString[60];		// ���� ���ڿ�
extern char inputString[100];	// �Է��� ���ڿ�
extern int typingResult[4];		// Ÿ���� ���� ���(Ÿ��, ��Ÿ, �Ӽ�, ����)
extern double typingStartTime;				// Ÿ���� ���� �ð�
extern double typingEndTime;				// Ÿ���� ���� �ð�
extern int isTypingSelect;				// Ÿ���� Ȱ��ȭ ���� (0 : ��Ȱ��ȭ , ������ : Ȱ��ȭ)

// Ÿ���� ���� ����
void bossTypingGame_Start(int ele, int lv);
// Ÿ���� ���� ������Ʈ
void bossTypingGamePlaying(char ch);
// Ÿ���� ���� ��(���� �Է�)
void bossTypingGameFinish();