#pragma once
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Ŀ�� ����
void RemoveCursor(void);
//���� Ŀ�� ��ġ ���� �ϱ�
void gotoxy(int x, int y);

//���� Ŀ�� ��ġ ������ ����
COORD GetCurrentCursorPos(void);
