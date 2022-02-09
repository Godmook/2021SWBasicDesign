#pragma once
#include"Cursor.h"
#include"Color.h"
#include "Key.h"
#include<stdio.h>
#include<windows.h>
#define INTRO_SET  system("mode con: lines=16 cols=26");
#define WINDOW_SET_PLAY system("mode con: lines=50 cols=160");
// 게임 시작 화면 (1 반환 : 게임 시작, 0 반환 : 게임 종료)
int MainView();
// 게임 시작 화면 키 입력 처리
void introProcessKeyInput();

// 현재 선택되어 있는 메뉴
int My_select = 2;
// 이전 선택 메뉴
int prev_select = 3;
// 엔터 입력 여부(1 : 엔터 입력O, -1 : 엔터 입력X)
int EnterProcess = -1;