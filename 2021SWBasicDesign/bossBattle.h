#pragma once

#include"Cursor.h"
#include"Color.h"
#include"MonsterData.h"
#include"normalBattleSituation.h"
#include"TypingGame.h"

// 보스 시작
void startBossBattle();

// 보스 배틀 선택 메뉴 출력
void printBossBattleMenu();

// 보스 세팅
Monster setBoss();

// 보스 키 입력 처리
void bossBattleKeyInputProcess();

// 보스 패턴
// phase 1 - 단어 
void phase1();	// 얼음 속성 패턴
extern char word[60][5];
typedef struct alphabet {
	int x;
	char ch;
}Alphabet;
extern int alphabetY[15];	// 내려오는 알파벳 y좌표
extern Alphabet alphabet[15][5];	// 내려오는 알파벳 정보 + x좌표
extern int choiceWord;	// 현재 선택된 단어 인덱스
extern int wordChange;	// 단어 변경 여부
extern char acquiredWord[5]; // 현재 획득한 알파벳
void initAlphabetGame();	// 게임 초기화 
void setRandomAlp();	// alphabet 세팅
void setAlphabetY();		// y 초기화
int checkFull();	// 다 완성했는지 검사
int addAlp(char ch);	// 획득한 알파벳에 ch 추가
void detectAlphabetCollision();	//알파벳 충돌 검사
void removeAlphabet();	// 알파벳 지우기
void drawAlphabet();	// 알파벳 그리기
void printWord();		// 획득해야하는 단어 + 획득한 알파벳 출력

// phase 2 - 갤러그
void phase2();	// 불 속성 패턴
extern int missileX1[10][10]; // 미사일 x좌표
extern int missileY[10]; // 미사일 y좌표
void drawmissile(); // 미사일 그리는 함수
void removemissile(); // 그린 미사일 지우는 함수
void InitY(); // 미사일 y좌표 생성
void initMissile(int y);	// 미사일 x좌표 초기화 
void detectMissileCollision();	// 미사일 충돌 검사

// phase 3 - 번개 관련
void phase3();
extern int isThunder;
extern int thunder[10];	// 번개가 떨어질 x좌표 10개
extern int thunderDamage[10];	// 데미지 받았는지 확인
void setThunderPoint();	// 번개 떨어질 좌표 초기화
void detectThunderCollision();	// 번개 충돌 검사

// 발판 관련
extern int footholdInfo[3];	// 발판 속성 순서
extern int footholdStartTime;		// 발판 시작 시간
extern int footholdEndTime;			// 발판 끝나는 시간

// 발판 그리기
void Color_foothold();
// 발판 지우기
void Delete_foothold();
// 발판 검사
void checkFoothold();

// 보스 체력 별 속성 변경
void bossChangeElement();

// pc 죽었을 때 
void dieBoss();
// 보스 클리어
void clearBoss();
void cleardrawArrow();  // 선택 화살표 출력
void clearremoveArrow();  // 선택 화살표 제거
void clearBossDraw();  // 보스 클리어시 출력문
int clearBossProcessKeyInput(); // 보스 클리어시 키 입력 함수