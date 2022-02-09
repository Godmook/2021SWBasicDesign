#pragma once

#include "Cursor.h"
#include "Key.h"
#include "Color.h"
#include "MonsterData.h"
#include "data.h"
#include "Damage.h"
#include"pcMoving.h"
#include"skill.h"
#include"BattleLog.h"
extern char Skill_str[3][30];
extern int Skill_Element[3];
extern int n;
extern int Status;
extern int Run_Flag;
extern int ChangeTheme;
extern int Check_Using_Item;
extern COORD s[4];

// 일반 몬스터와의 전투 상황 화면 시작
void startNormalBattleSituation(Monster* monster);
void dieNormal();
// 일반 몬스터와의 전투 상황 입력 키 처리
void SetPoint(COORD* s, int i);
int DrawPointerForBattleSituation(COORD* s, Monster* p);

// 일반 몬스터와의 전투 상황 기본 화면 출력
void drawNormalBattleSituation(Monster* monster);

// 일반 몬스터와의 전투 상황 중 몬스터 HP 출력
void drawNormalBattleSituationMonsterStat(Monster* s);

// 일반 몬스터와의 전투 상황 중 PC 스탯 출력
void drawNormalBattleSituationPCStat();
// 일반 몬스터와의 전투 상황 인벤토리 출력
void drawNormalBattleSituationInventory();

// 일반 몬스터와의 전투 상황 선택창 출력
void drawNormalBattleSituationChoice(Monster* monster);
//선택창 1
void drawNormalBattleSituationChoice_Page1();
//선택창 2
void drawNormalBattleSituationChoice_Skill();
//아이템 선택창
void drawNormalBattleSituationChoice_Item();
//도망가기
void drawNormalBattleSituationChoice_Run(Monster* s);
//타이핑 게임 하는 곳
void drawNormalBattleSituationChoice_TypeGame(int* arr, Monster* monster);

// 선택창 초기화
void drawNormalBattleSituationChoiceClean();

//사용량 확인 함수
//flag가 1이면 체력 물약
//flag가 2이면 마나 물약
//flag가 3이면 마나 체력 물약
void CalculateUsageOfPortion(int flag, int* arr);
//Hp물약 사용
void UsingHpPortion();
//ALl포션 사용
void UsingAllPortion();
//Mp물약 사용
void UsingMpPortion();
// 스킬 복사
void StrCpy_Skill(int idx);

// 일반 몬스터와의 전투 상황에서 플레이어와 몬스터 출력
void drawNormalBattleSituation_PCandMonster(Monster* monster);
// 별모양 플레이어 출력
void DrawStarplayer();
//플레이어 레벨 출력
void DrawPlayerLv();
// 원모양 웜 출력
void DrawCircleworm();
// 삼각형 모양 스파이웨어 출력
void DrawTrianglespyware();
// 다이아 모양 몬스터 출력
void DrawDia();

void DrawMonsterLv(Monster* monster);