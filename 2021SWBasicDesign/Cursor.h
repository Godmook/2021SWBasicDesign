#pragma once
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//커서 삭제
void RemoveCursor(void);
//헌재 커서 위치 세팅 하기
void gotoxy(int x, int y);

//현재 커서 위치 가지고 오기
COORD GetCurrentCursorPos(void);
