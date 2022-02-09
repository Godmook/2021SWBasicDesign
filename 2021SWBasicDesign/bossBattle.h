#pragma once

#include"Cursor.h"
#include"Color.h"
#include"MonsterData.h"
#include"normalBattleSituation.h"
#include"TypingGame.h"

// ���� ����
void startBossBattle();

// ���� ��Ʋ ���� �޴� ���
void printBossBattleMenu();

// ���� ����
Monster setBoss();

// ���� Ű �Է� ó��
void bossBattleKeyInputProcess();

// ���� ����
// phase 1 - �ܾ� 
void phase1();	// ���� �Ӽ� ����
extern char word[60][5];
typedef struct alphabet {
	int x;
	char ch;
}Alphabet;
extern int alphabetY[15];	// �������� ���ĺ� y��ǥ
extern Alphabet alphabet[15][5];	// �������� ���ĺ� ���� + x��ǥ
extern int choiceWord;	// ���� ���õ� �ܾ� �ε���
extern int wordChange;	// �ܾ� ���� ����
extern char acquiredWord[5]; // ���� ȹ���� ���ĺ�
void initAlphabetGame();	// ���� �ʱ�ȭ 
void setRandomAlp();	// alphabet ����
void setAlphabetY();		// y �ʱ�ȭ
int checkFull();	// �� �ϼ��ߴ��� �˻�
int addAlp(char ch);	// ȹ���� ���ĺ��� ch �߰�
void detectAlphabetCollision();	//���ĺ� �浹 �˻�
void removeAlphabet();	// ���ĺ� �����
void drawAlphabet();	// ���ĺ� �׸���
void printWord();		// ȹ���ؾ��ϴ� �ܾ� + ȹ���� ���ĺ� ���

// phase 2 - ������
void phase2();	// �� �Ӽ� ����
extern int missileX1[10][10]; // �̻��� x��ǥ
extern int missileY[10]; // �̻��� y��ǥ
void drawmissile(); // �̻��� �׸��� �Լ�
void removemissile(); // �׸� �̻��� ����� �Լ�
void InitY(); // �̻��� y��ǥ ����
void initMissile(int y);	// �̻��� x��ǥ �ʱ�ȭ 
void detectMissileCollision();	// �̻��� �浹 �˻�

// phase 3 - ���� ����
void phase3();
extern int isThunder;
extern int thunder[10];	// ������ ������ x��ǥ 10��
extern int thunderDamage[10];	// ������ �޾Ҵ��� Ȯ��
void setThunderPoint();	// ���� ������ ��ǥ �ʱ�ȭ
void detectThunderCollision();	// ���� �浹 �˻�

// ���� ����
extern int footholdInfo[3];	// ���� �Ӽ� ����
extern int footholdStartTime;		// ���� ���� �ð�
extern int footholdEndTime;			// ���� ������ �ð�

// ���� �׸���
void Color_foothold();
// ���� �����
void Delete_foothold();
// ���� �˻�
void checkFoothold();

// ���� ü�� �� �Ӽ� ����
void bossChangeElement();

// pc �׾��� �� 
void dieBoss();
// ���� Ŭ����
void clearBoss();
void cleardrawArrow();  // ���� ȭ��ǥ ���
void clearremoveArrow();  // ���� ȭ��ǥ ����
void clearBossDraw();  // ���� Ŭ����� ��¹�
int clearBossProcessKeyInput(); // ���� Ŭ����� Ű �Է� �Լ�