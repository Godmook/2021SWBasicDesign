#pragma once
#include"Cursor.h"
#include"Color.h"
#include "Key.h"
#include<stdio.h>
#include<windows.h>
#define INTRO_SET  system("mode con: lines=16 cols=26");
#define WINDOW_SET_PLAY system("mode con: lines=50 cols=160");
// ���� ���� ȭ�� (1 ��ȯ : ���� ����, 0 ��ȯ : ���� ����)
int MainView();
// ���� ���� ȭ�� Ű �Է� ó��
void introProcessKeyInput();

// ���� ���õǾ� �ִ� �޴�
int My_select = 2;
// ���� ���� �޴�
int prev_select = 3;
// ���� �Է� ����(1 : ���� �Է�O, -1 : ���� �Է�X)
int EnterProcess = -1;