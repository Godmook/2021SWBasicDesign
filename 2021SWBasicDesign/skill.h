#pragma once
#include"Cursor.h"
#include"Color.h"
#include"data.h"
#include"Key.h"
#include<stdio.h>
#include<string.h>

void drawArrow();
void removeArrow();

void selectSkill();
void selectSkillDraw(int idx);
int selectSkillProcessKeyInput();