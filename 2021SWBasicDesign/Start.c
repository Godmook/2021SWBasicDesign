#include "Start.h"
void introProcessKeyInput()
{
	for (int i = 0; i < 10; i++)
	{
		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case UP:            if (My_select > 1) { prev_select = My_select; My_select--; }                       break;
			case DOWN:          if (My_select < 3) { prev_select = My_select; My_select++; }                       break;
			case ENTER:         EnterProcess *= -1;                       break;
			default:                                        break;
			}
		}
		Sleep(10);
	}
}
int MainView() {
	RemoveCursor();
mainview:
	INTRO_SET
		setcolor(C_BLACK, C_WHITE);
	My_select = 1;
	prev_select = 2;
	EnterProcess = -1;
	system("cls");
	gotoxy(0, 4);
	printf("         S2  LITE \n\n\n\n");
	printf("         게임시작\n");
	printf("         게임방법\n");
	printf("         끝 내 기\n");
	while (1)
	{
		RemoveCursor();
		gotoxy(9, 7 + My_select);
		setcolor(12, 14);
		printf("%s", My_select == 1 ? "게임시작" : My_select == 2 ? "게임방법" : "끝 내 기");
		gotoxy(9, 7 + prev_select);
		setcolor(0, 15);
		printf("%s", prev_select == 1 ? "게임시작" : prev_select == 2 ? "게임방법" : "끝 내 기");
		introProcessKeyInput();
		// enter 입력(메뉴 선택)
		if (EnterProcess > 0) {
			// 게임 시작
			if (My_select == 1)
				return 1;
			// 게임 방법
			else if (My_select == 2)
			{
				setcolor(0, 15);
				WINDOW_SET_PLAY
					system("cls");
				gotoxy(0, 6);
				printf("                              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");//0
				printf("                              ┃    ********이동 방법*******    ┃                              ┃    *******몬스터 종류*******   ┃\n");//1
				printf("                              ┃                                ┃                              ┃      웜           스파이웨어   ┃\n");//6
				printf("                              ┃       기본 이동 : 방향키       ┃                              ┃                                ┃\n");//2
				printf("                              ┃       인벤토리  : i            ┃                              ┃   체력 특화        공격 특화   ┃\n");//3
				printf("                              ┃       스킬 창   : k            ┃                              ┃  위 아래 이동      좌 우 이동  ┃\n");//4
				printf("                              ┃       장비 창   : p            ┃                              ┃    모양:  ●       모양:  ▲   ┃\n");//5
				printf("                              ┃                                ┃                              ┃                                ┃\n");//6
				printf("                              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");//7

				gotoxy(0, 19);
				printf("                               ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");//0
				printf("                               ┃    *********스 토 리********   ┃                              ┃    ********공격 방식*******    ┃\n");//1
				printf("                               ┃                                ┃                              ┃                                ┃\n");//6
				printf("                               ┃    컴퓨터에 침입한 악성코드를  ┃                              ┃                                ┃\n");//2
				printf("                               ┃    퇴치하기 위하여 컴퓨터를    ┃                              ┃ 1. 기본공격 or 스킬공격을 선택 ┃\n");//3
				printf("                               ┃    성장시키면서 악성코드를     ┃                              ┃ 2. 나오는 영어문장 타자 치기   ┃\n");//4
				printf("                               ┃    퇴치하는 게임               ┃                              ┃ 3. 문장이 맞으면 공격          ┃\n");//5
				printf("                               ┃                                ┃                              ┃                                ┃\n");//6
				printf("                               ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");//7

				gotoxy(0, 32);
				printf("                               ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓                              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");//0
				printf("                               ┃    *********속    성********   ┃                              ┃      ********아이템********    ┃\n");//1
				printf("                               ┃                                ┃                              ┃                                ┃\n");//6
				printf("                               ┃           화염 > 얼음          ┃                              ┃     -체력 물약                 ┃\n");//2
				printf("                               ┃           전기 > 화염          ┃                              ┃     -마나 물약                 ┃\n");//3
				printf("                               ┃           얼음 > 전기          ┃                              ┃     -경험치 물약               ┃\n");//4
				printf("                               ┃      우위에 있는 상성은 20%%    ┃                              ┃     -강화의 돌                 ┃\n");//5
				printf("                               ┃           데미지 추가          ┃                              ┃     -돈                        ┃\n");//6
				printf("                               ┃                                ┃                              ┃                                ┃\n");//6
				printf("                               ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛                              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");//7
				_getch();
				goto mainview;
			}
			// 게임 종료 
			else if (My_select == 3)
				return 0;
		}
	}
}