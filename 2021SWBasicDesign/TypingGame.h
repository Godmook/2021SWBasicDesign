#pragma once
#include <time.h>
#include"data.h"
#include "Color.h"
#include "Key.h"
#include"BattleLog.h"
#include"bossBattle.h"
#include"normalBattleSituation.h"

extern const char Element_text[80][60];
//타자 게임 나오는 곳 ele= 속성 lv= 스킬 레벨
void TypingGame(int ele, int lv,int *Result_Arr);
//타이핑 하는 화면 초기화
void TypingClean();

// 보스 타이핑 게임
extern char atkString[60];		// 공격 문자열
extern char inputString[100];	// 입력한 문자열
extern int typingResult[4];		// 타이핑 게임 결과(타수, 오타, 속성, 레벨)
extern double typingStartTime;				// 타이핑 시작 시간
extern double typingEndTime;				// 타이핑 종료 시간
extern int isTypingSelect;				// 타이핑 활성화 여부 (0 : 비활성화 , 나머지 : 활성화)

// 타이핑 게임 시작
void bossTypingGame_Start(int ele, int lv);
// 타이핑 게임 업데이트
void bossTypingGamePlaying(char ch);
// 타이핑 게임 끝(엔터 입력)
void bossTypingGameFinish();