#pragma once
#include"Cursor.h"
#include"data.h"
#include"Color.h"
#include"pcMoving.h"
#include"Key.h"
#include"MonsterData.h"
#include"Monster_Move.h"
#include"MapInfo.h"
#define INVENTORY 105
#define SKILL 107
#define EQUIP 112
// 인게임 화면 시작
void startNormalSituation();

// 인게임 입력 키 처리
void normalSituationProcessKeyInput();

// 인게임 기본 화면 출력(메뉴 default : 인벤토리)
void drawNormalSituation();

// 인게임 맵 출력
void drawNormalSituationMap();
// 인게임 스탯창 출력
void drawNormalSituationStat();
// 인게임 메뉴 출력
void drawNormalSituationMenu();
// 인게임 인벤토리 출력
void drawNormalSituationInventory();
// 인게임 스킬창 출력
void drawNormalSituationSkill();
// 인게임 장비창 출력
void drawNormalSituationEquipment();
// 인게임 인벤토리, 장비, 스킬 창 지우기
void removeNormalSituationMenuWindow();









