#include"bossBattle.h"

int footholdInfo[3] = { 0,0,0 };	// 발판 속성 순서
int footholdStartTime = 15;
int footholdTerm = 3;

// 보스 배틀 선택 메뉴 출력
void printBossBattleMenu()
{
	drawNormalBattleSituationChoiceClean();
	gotoxy(10, 42);
	printf("(1) 일반공격\t");
	if (takenSkill[0] != -1)
		printf("(2) %s\t", skillInfo[0][takenSkill[0]].name);
	else
		printf("(2) 사용불가\t");
	if (takenSkill[1] != -1)
		printf("(3) %s\t", skillInfo[1][takenSkill[1]].name);
	else
		printf("(3) 사용불가\t");
	if (takenSkill[2] != -1)
		printf("(4) %s\t", skillInfo[2][takenSkill[2]].name);
	else
		printf("(4) 사용불가\t");

	gotoxy(10, 46);
	printf("(5) 체력 물약:%d개\t", healingPotion);
	printf("(6) 마나 물약:%d개\t", manaPotion);
	printf("(7) 체력/마나 물약:%d개\t", allPotion);
}

// 보스 세팅
Monster setBoss()
{
	Monster m = SetMonster();
	m.maxHp = 15000;
	m.hp = 15000;
	m.atk = 2000;
	return m;
}
void drawBoss()
{
	setcolor(boss.element, C_BLACK);
	gotoxy(58, 2);
	printf("BOSS Lv.??");
	gotoxy(53, 3);
	printf("  ■■■■■■■■  ");
	gotoxy(53, 4);
	printf("■■■  ■■  ■■■");
	gotoxy(53, 5);
	printf("  ■■■■■■■■  ");

	setcolor(C_WHITE, C_BLACK);
}

// 보스 배틀 시작
void startBossBattle()
{
	boss = setBoss();

	// 플레이어 위치 초기화 
	pcY = 35;
	pcX = 65;

	while (STATE == START_BOSS_BATTEL)
	{
		drawNormalBattleSituation(&boss);	// 전투 틀 그리기
		isTypingSelect = 0;
		printBossBattleMenu();	// 보스 배틀 메뉴 그리기
		drawBoss();
		pcDraw(); // 플레이어 그리기
		switch (boss.element)
		{
		case E_ICE:		phase1();	break;
		case E_FLAME:	phase2();	break;
		case E_ELECT:	phase3();	break;
		default:				    break;
		}
	}
}

// 발판 관련 함수
void Color_foothold() {
	int Element[3] = { E_FLAME,E_ICE ,E_ELECT };
	for (int i = 0; i < 3; i++)
		footholdInfo[i] = 0;

	for (int i = 0; i < 3; i++) {
		while (footholdInfo[i] == 0) {
			footholdInfo[i] = rand() % 3;
			switch (footholdInfo[i]) {
			case 0: footholdInfo[i] = Element[0];   Element[0] = 0; break;
			case 1: footholdInfo[i] = Element[1];   Element[1] = 0; break;
			case 2: footholdInfo[i] = Element[2];   Element[2] = 0; break;
			}
		}
	}
	int y = 36;
	setcolor(footholdInfo[0], C_BLACK);
	for (int x = 15; x < 25; x += 2) {
		gotoxy(x, y);
		printf("〓");
	}
	setcolor(C_WHITE, C_BLACK);
	setcolor(footholdInfo[1], C_BLACK);
	for (int x = 55; x < 65; x += 2) {
		gotoxy(x, y);
		printf("〓");
	}
	setcolor(C_WHITE, C_BLACK);
	setcolor(footholdInfo[2], C_BLACK);
	for (int x = 95; x < 105; x += 2) {
		gotoxy(x, y);
		printf("〓");
	}
	setcolor(C_WHITE, C_BLACK);
}
void Delete_foothold() {
	int y = 36;
	setcolor(C_WHITE, C_BLACK);
	for (int x = 15; x < 25; x++) {
		gotoxy(x, y);
		printf("─");
	}
	for (int x = 55; x < 65; x++) {
		gotoxy(x, y);
		printf("─");
	}
	for (int x = 95; x < 105; x++) {
		gotoxy(x, y);
		printf("─");
	}
}
void checkFoothold()
{
	int originalElement = boss.element;
	if (pcX >= 15 && pcX <= 25)
		boss.element = footholdInfo[0];
	if (pcX >= 55 && pcX <= 65)
		boss.element = footholdInfo[1];
	if (pcX >= 95 && pcX <= 105)
		boss.element = footholdInfo[2];

	if (originalElement == boss.element) return;

	switch (boss.element)
	{
	case E_FLAME:	drawNormalBattleSituationLogUpdate("보스의 속성이 화염 속성으로");	drawNormalBattleSituationLogUpdate("변경됩니다.");  break;
	case E_ICE:		drawNormalBattleSituationLogUpdate("보스의 속성이 얼음 속성으로");	drawNormalBattleSituationLogUpdate("변경됩니다.");  break;
	case E_ELECT:	drawNormalBattleSituationLogUpdate("보스의 속성이 전기 속성으로");	drawNormalBattleSituationLogUpdate("변경됩니다.");  break;
	default:																																break;
	}
}

// 보스 키 입력 처리
void bossBattleKeyInputProcess()
{
	if (STATE != START_BOSS_BATTEL) return;
	for (int i = 0; i < speed; i++)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 224)	// 방향키
			{
				key = _getch();
				switch (key)
				{
				case LEFT:          pcMoveLeft();		  break;
				case RIGHT:         pcMoveRight();		  break;
				default:								  break;
				}

				// phase1 - pc 이동 시 미사일 검사
				if (boss.element == E_FLAME)
					detectMissileCollision();
				// phase3 - pc 이동 시 번개 검사
				else if (boss.element == E_ELECT && isThunder)
					detectThunderCollision();
				else if (boss.element == E_ICE)
					detectAlphabetCollision();
			}
			else
			{
				switch (key)
				{
				case ONE:			bossTypingGame_Start(-1, 0);				break;
				case TWO:			bossTypingGame_Start(takenSkill[0], 1);		break;
				case THREE:			bossTypingGame_Start(takenSkill[1], 2);		break;
				case FOUR:			bossTypingGame_Start(takenSkill[2], 3);		break;
				case FIVE:			UsingHpPortion();	printBossBattleMenu();	break;
				case SIX:			UsingMpPortion();	printBossBattleMenu();	break;
				case SEVEN:			UsingAllPortion();	printBossBattleMenu();  break;
				case ENTER:			bossTypingGameFinish();						break;
				case BACKSPACE:		bossTypingGamePlaying('\0');				break;
				case SPACE_BAR:		bossTypingGamePlaying(' ');					break;
				default:			bossTypingGamePlaying((char)key);			break;
				}
			}
		}
		Sleep(200 / speed); // 200 = 몬스터 속도
	}
}

// phase1 - 단어
void phase1()
{
	int t = 0;
	initAlphabetGame();

	// 처음 라인 그리기
	for (int x = 0; x < 125; x++)
	{
		gotoxy(x, 36);
		printf("─");
	}

	while (boss.element == E_ICE && STATE == START_BOSS_BATTEL)
	{
		// 발판 생성
		if (t != 0 && t % footholdStartTime == 0)
		{
			Color_foothold();
		}

		// 발판 끝
		if (t / footholdStartTime != 0 && t % footholdStartTime == footholdTerm)
		{
			Delete_foothold();
			checkFoothold();	// 발판 확인
			if (boss.element != E_ICE) {
				Sleep(1000);	// 속성 변경 전 시간
				return;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (boss.element != E_ICE) return;
			// 알파벳 지우기
			removeAlphabet();
			// 알파벳 업데이트
			for (int j = 0; j < 15; j++)
				alphabetY[j]++;
			// 알파벳 그리기
			drawAlphabet();

		// pc 그리기
			drawBoss();
			pcDraw();

			// 충돌 검사
			detectAlphabetCollision();

			// 완성 검사
			if (checkFull() == 1)
				wordChange = 1;

			// 시간 초과
			if (alphabetY[14] > pcY)
			{
				drawNormalBattleSituationLogUpdate("시간초과");
				wordChange = 1;

				// 데미지 
				Boss_Damage(&boss);
				if (hp <= 0)
					dieBoss();
			}

			// 키 입력 처리
			bossBattleKeyInputProcess();

			// 단어 변경
			if (wordChange == 1)
			{
				removeAlphabet();
				initAlphabetGame();
				wordChange = 0;
			}
		}
		t++;
	}
}
char word[60][5] = {
	"act",
   "age",
   "air",
   "bag",
   "best",
   "can",
   "case",
   "day",
   "dog",
   "drug",
   "edge",
   "even",
   "fly",
   "fast",
   "fine",
   "goal",
   "grow",
   "half",
   "help",
   "hit",
   "join",
   "key",
   "know",
   "last",
   "law",
   "lead",
   "mean",
   "mind",
   "move",
   "must",
   "much",
   "new",
   "next",
   "nice",
   "once",
   "only",
   "own",
   "page",
   "part",
   "per",
   "race",
   "real",
   "rest",
   "save",
   "sea",
   "send",
   "tax",
   "top",
   "trip",
   "unit",
   "use",
   "very",
   "view",
   "vote",
   "wait",
   "wear",
   "west",
   "yard",
   "yes",
   "zone"
};
int alphabetY[15] = { 0, };
Alphabet alphabet[15][5] = { 0, };
int choiceWord = 0;	// 현재 선택된 단어 인덱스
char acquiredWord[5] = { 0, };	// 현재 먹은 단어
int wordChange = 0;
void initAlphabetGame()
{
	// 초기화 
	choiceWord = rand() % 60;
	setAlphabetY();
	for (int i = 0; i < 15; i++)
		setRandomAlp(i);
	memset(acquiredWord, '\0', sizeof(char) * 5);
	printWord();
}
void setRandomAlp(int idx)
{
	int flag = 1;
	int x = 0;
	// 알파벳 초기화  
	for (int j = 0; j < 5; j++) {
		alphabet[idx][j].ch = 'a' + rand() % 26;
		// x 중복 방지
		flag = 1;
		while (flag) {
			flag = 0;
			x = rand() % 25 * 5;
			for (int k = 0; k < j; k++) {
				if (alphabet[idx][k].x == x)flag = 1;
			}
		}
		alphabet[idx][j].x = x;
	}
	int i = idx % strlen(word[choiceWord]);
	alphabet[idx][rand() % 5].ch = word[choiceWord][i];
}
void setAlphabetY()
{
	for (int i = 0; i < 15; i++)
		alphabetY[i] = 0 - i * 7;	// test
}
int checkFull()
{
	if (strcmp(word[choiceWord], acquiredWord) == 0)
		return 1;
	else
		return 0;
}
int addAlp(char ch)
{
	int len = strlen(word[choiceWord]);
	for (int i = 0; i < len; i++)
	{
		if (word[choiceWord][i] == ch && acquiredWord[i] == '\0')
		{
			acquiredWord[i] = ch;
			printWord();
			if (checkFull() == 1)
				wordChange = 1;
			return 1;
		}
	}
	return 0;
}
void detectAlphabetCollision()
{
	for (int i = 0; i < 15; i++)
	{
		if (alphabetY[i] == pcY)
		{
			for (int j = 0; j < 5; j++)
			{
				if (alphabet[i][j].x == pcX || alphabet[i][j].x == pcX + 1)
				{
					alphabet[i][j].x = -1;
					if (addAlp(alphabet[i][j].ch) == 0)
					{
						drawNormalBattleSituationLogUpdate("단어 틀림");
						wordChange = 1;

						// 데미지 추가
						Boss_Damage(&boss);
						if (hp <= 0)
							dieBoss();
						return;
					}
					break;
				}
			}
			break;
		}
	}
}
void removeAlphabet()
{
	for (int i = 0; i < 15; i++)
	{
		if (alphabetY[i] < 1 || alphabetY[i] >= 36) continue;
		for (int j = 0; j < 5; j++)
		{
			gotoxy(alphabet[i][j].x, alphabetY[i]);
			printf(" ");
		}
	}
}
void drawAlphabet()
{
	for (int i = 0; i < 15; i++)
	{
		if (alphabetY[i] < 1 || alphabetY[i] > pcY) continue;
		for (int j = 0; j < 5; j++)
		{
			gotoxy(alphabet[i][j].x, alphabetY[i]);
			printf("%c", alphabet[i][j].ch);
		}
	}
}
void printWord() {
	gotoxy(60, 0);
	printf("      ");

	gotoxy(60, 0);
	printf("[");
	for (int i = 0; i < strlen(word[choiceWord]); i++)
	{
		if (acquiredWord[i] != '\0')
			setcolor(C_GREEN, C_BLACK);
		printf("%c", word[choiceWord][i]);
		setcolor(C_WHITE, C_BLACK);
	}
	printf("]");
}

// phase 2 - 갤러그
int missileX1[10][10] = { 0, }; // 미사일 x좌표
int missileY[10]; // 미사일 y좌표
void drawmissile() {   // 미사일 그리기

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++)
		{
			if (missileY[j] < 36 && missileY[j] > 0) {
				gotoxy(missileX1[j][i], missileY[j]);
				printf("│");
			}
		}
	}
}
void removemissile() {  // 그린 미사일 지우기
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++)
		{
			if (missileY[j] < 36 && missileY[j] > 0) {
				gotoxy(missileX1[j][i], missileY[j]);
				printf(" ");
			}
		}
	}
}
void InitY() {  // 미사일 y좌표 생성
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		missileY[i] = -5 * cnt;
		cnt++;
	}
}
void initMissile(int y)
{
	// 미사일 위치 초기화 
	for (int j = 0; j < 10; j++) {
		int x = rand() % 125;
		missileX1[y][j] = x;
	}
}
void detectMissileCollision()
{
	for (int i = 0; i < 10; i++)
	{
		if (missileY[i] == 35)
		{
			for (int j = 0; j < 10; j++)
			{
				if (missileX1[i][j] == pcX || missileX1[i][j] == pcX + 1)
				{
					// 로그 출력
					drawNormalBattleSituationLogUpdate("미사일 충돌");

					// 데미지 추가
					Boss_Damage(&boss);

					if (hp <= 0)
						dieBoss();
					break;
				}
			}
			break;
		}
	}
}
void phase2()
{
	int lineY = 36;
	int t = 0;

	// 처음 라인 그리기
	for (int x = 0; x < 125; x++)
	{
		gotoxy(x, lineY);
		printf("─");
	}

	InitY();
	// 미사일 위치 초기화 
	for (int i = 0; i < 10; i++)
		initMissile(i);

	while (boss.element == E_FLAME && STATE == START_BOSS_BATTEL)
	{
		// 발판 생성
		if (t != 0 && t % footholdStartTime == 0)
		{
			Color_foothold();
		}

		// 발판 끝
		if (t / footholdStartTime != 0 && t % footholdStartTime == footholdTerm)
		{
			Delete_foothold();
			checkFoothold();	// 발판 확인
			if (boss.element != E_FLAME) {
				Sleep(1000);	// 속성 변경 전 시간
				return;
			}
		}


		for (int i = 0; i < 5; i++)
		{
			if (boss.element != E_FLAME) return;
			// 미사일 지우기
			removemissile();
			// 미사일 내려오기
			for (int i = 0; i < 10; i++)
				missileY[i]++;
			// 미사일 그리기
			drawmissile();
			drawBoss();
			pcDraw();

			// 충돌 검사
			detectMissileCollision();

			for (int i = 0; i < 10; i++)
				if (missileY[i] == lineY)
				{
					missileY[i] = -14;
					initMissile(i);
					break;
				}

			// 키 입력 처리
			bossBattleKeyInputProcess();	//0.2s
		}
		t++;
	}
}

// phase3 - 번개
int thunder[10] = { 0, };	// 번개 떨어질 곳 x 좌표 (10개)
int thunderDamage[10] = { 0, };	// 데미지 여부
int isThunder = 0;
void setThunderPoint()
{
	// 랜덤 10곳 지정
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 125;
		thunder[i] = x;
		thunderDamage[i] = 0;
	}
}
void detectThunderCollision()
{
	// 충돌 검사(데미지)
	for (int i = 0; i < 10; i++)
		if (thunder[i] == pcX || thunder[i] - 1 == pcX && thunderDamage[i] == 0)
		{
			// 로그 출력
			drawNormalBattleSituationLogUpdate("번개 맞음");

			// 데미지 
			Boss_Damage(&boss);
			thunderDamage[i] = 1;

			if (hp <= 0)
				dieBoss();
		}
}
void phase3()
{
	int lineY = 36;
	isThunder = 0;

	// 처음 라인 그리기
	for (int x = 0; x < 125; x++)
	{
		gotoxy(x, lineY);
		printf("─");
	}

	int t = 0;

	// 반복
	while (boss.element == E_ELECT && STATE == START_BOSS_BATTEL)
	{
		// 번개 떨어질 곳 보여주기
		if (t % 5 == 0)
		{
			setThunderPoint(&thunder);
			setcolor(E_ELECT, C_BLACK);
			for (int i = 0; i < 10; i++)
			{
				gotoxy(thunder[i], lineY + 1);
				printf("─");
			}
			setcolor(C_WHITE, C_BLACK);
		}

		// 번개 떨어지기 
		if (t % 5 == 2)
		{
			isThunder = 1;
			for (int i = 0; i < 10; i++)
			{
				int x = thunder[i];
				setcolor(C_WHITE, E_ELECT);
				for (int y = 0; y < lineY; y++)
				{
					gotoxy(x, y);
					printf(" ");
				}
				setcolor(C_WHITE, C_BLACK);
			}

			// 충돌 검사(데미지)
			detectThunderCollision();
			drawBoss();
			pcDraw();
		}

		if (t % 5 == 3)
		{
			// 번개 지우기
			for (int i = 0; i < 10; i++)
			{
				gotoxy(thunder[i], lineY + 1);
				printf(" ");
			}
			for (int i = 0; i < 10; i++)
			{
				int x = thunder[i];
				for (int y = 0; y < lineY; y++)
				{
					gotoxy(x, y);
					printf(" ");
				}
			}
			isThunder = 0;
			drawBoss();
		}

		// 발판 생성
		if (t != 0 && t % footholdStartTime == 0)
		{
			Color_foothold();
		}

		// 발판 끝
		if (t / footholdStartTime != 0 && t % footholdStartTime == footholdTerm)
		{
			Delete_foothold();
			checkFoothold();	// 발판 확인
			if (boss.element != E_ELECT) {
				Sleep(1000);	// 속성 변경 전 시간
				return;
			}
		}

		// 키 입력 처리 (1s)
		for (int i = 0; i < 5; i++)
			bossBattleKeyInputProcess();
		t++;
	}
}

// 보스 체력 변화에 따른 속성 변화
void bossChangeElement()
{
	static int previousHp = 15000;	// 속성 바뀐 횟수
	if (boss.maxHp == boss.hp) previousHp = boss.maxHp;
	int d = boss.maxHp / 10;	// 속성 바꾸는 체력 기준

	if (boss.hp < previousHp - d)
	{
		previousHp = boss.hp;
		// 보스 속성 바꾸기
		int r = rand() % 2;
		if (boss.element == E_ICE)
			switch (r)
			{
			case 0:	boss.element = E_FLAME;	break;
			case 1:	boss.element = E_ELECT;	break;
			default:						break;
			}
		else if (boss.element == E_FLAME)
			switch (r)
			{
			case 0:	boss.element = E_ICE;	break;
			case 1:	boss.element = E_ELECT;	break;
			default:						break;
			}
		else if (boss.element == E_ELECT)
			switch (r)
			{
			case 0:	boss.element = E_ICE;	break;
			case 1:	boss.element = E_FLAME;	break;
			default:						break;
			}
		drawNormalBattleSituationLogUpdate("보스의 속성이 변경됩니다.");
		Sleep(1000);
	}
}

// 죽었을 때
void dieBoss()
{
	Sleep(500);
	system("cls");
	//능력치 초기화
	level = 1;
	PCSet();
	pcExp = 0;

	//소지품 초기화
	money = 0;
	healingPotion = 0;
	manaPotion = 0;
	allPotion = 0;
	expPotion = 0;
	enhancementStone1 = 0;
	enhancementStone2 = 0;
	enhancementStone3 = 0;

	//장비 초기화
	for (int i = 0; i < 5; i++)
	{
		equipmentLevel[i] = 1;
		equipmentRank[i] = NORMAL;
	}

	// 스킬 초기화
	for(int i=0; i<3; i++)
		takenSkill[i] = -1;

	gotoxy(65, 17); printf(" 당신은 보스 몬스터한테 죽었습니다");
	gotoxy(67, 22); printf(" 마을에서 다시 살아나게 됩니다.");
	gotoxy(65, 27); printf(" (모든 스텟 및 아이템, 장비 리셋)");
	Sleep(3000);

	STATE = START_TOWN;
}

int clearSelect = 0;   // 보스 클리어 시 선택 체크 변수
int coordinates[3] = { 35, 80, 125 };  // 보스 클리어 시 선택 화살표 나올 x 좌표 설정
// 보스 클리어
void clearBoss()
{
	clearSelect = 0;
	clearBossDraw();
	cleardrawArrow();
	while (!clearBossProcessKeyInput());
	if (clearSelect == 0) {  // 계속 하기
		STATE = START_TOWN;
	}
	else if (clearSelect == 1) { // 다시 하기
		//능력치 초기화
		level = 1;
		PCSet();
		pcExp = 0;

		//소지품 초기화
		money = 0;
		healingPotion = 0;
		manaPotion = 0;
		allPotion = 0;
		expPotion = 0;
		enhancementStone1 = 0;
		enhancementStone2 = 0;
		enhancementStone3 = 0;

		//장비 초기화
		for (int i = 0; i < 5; i++)
		{
			equipmentLevel[i] = 1;
			equipmentRank[i] = NORMAL;
		}

		// 스킬 초기화
		for (int i = 0; i < 3; i++)
			takenSkill[i] = -1;
		STATE = START_TOWN;
	}
	else {                          // 게임 끝내기
		if (clearSelect == 2)
			STATE = GAME_OVER;
	}

}

void cleardrawArrow()   // 선택 화살표 출력
{
	gotoxy(coordinates[clearSelect], 32);
	printf("▲");
}

void clearremoveArrow()  // 선택 화살표 제거
{
	gotoxy(coordinates[clearSelect], 32);
	printf("  ");
}

void clearBossDraw() // 보스 클리어시 출력문
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		int width = 40;
		int height = 25;
		int originX = 15 + width * i + 5 * i;
		for (int x = 0; x < width; x++)
		{
			gotoxy(originX + x, 5);
			if (x == 0)
				printf("┌");
			else if (x == width - 1)
				printf("┐");
			else printf("─");

			gotoxy(originX + x, 30);
			if (x == 0)
				printf("└");
			else if (x == width - 1)
				printf("┘");
			else printf("─");

		}
		for (int y = 6; y < 30; y++)
		{
			gotoxy(originX, y);
			printf("│");
			gotoxy(originX + width - 1, y);
			printf("│");
		}

		gotoxy(30, 10);
		printf("<계속 하기>");
		gotoxy(75, 10);
		printf("<다시 시작>");
		gotoxy(120, 10);
		printf("<게임 종료>");
		gotoxy(28, 15);
		printf("기존의 캐릭터로");
		gotoxy(23, 16);
		printf("계속 플레이 할 수 있습니다.");
		gotoxy(73, 15);
		printf("새로운 캐릭터로");
		gotoxy(65, 16);
		printf("처음부터 플레이 할 수 있습니다.");
		gotoxy(116, 15);
		printf("게임을 종료합니다.");

		gotoxy(75, 38);
		printf("축하합니다!");
		gotoxy(68, 40);
		printf("게임을 클리어 하셨습니다.");

		gotoxy(65, 48);
		printf("(방향키로 선택 후 SPACE로 결정)");
	}
}
int clearBossProcessKeyInput()  // 보스 클리어시 키 입력 함수
{
	for (int i = 0; i < 100; i++)
	{
		if (_kbhit())
		{
			int key = _getch();
			switch (key)
			{
			case LEFT:          if (clearSelect != 0) { clearremoveArrow();  clearSelect--; }	break;
			case RIGHT:         if (clearSelect != 2) { clearremoveArrow();  clearSelect++; }    break;
			case SPACE_BAR:			return 1;													break;
			default:																			break;
			}
			cleardrawArrow();
		}
		Sleep(10);
	}
	return 0;
}