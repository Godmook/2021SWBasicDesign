#include "TypingGame.h"
#pragma warning(disable:4996)
const char Element_text[80][60] =
{
    /* Element_Non_text */
    "justice",
    "ultimate",
    "serendipity",
    "requiem",
    "luminous",
    "masquerade",
    "pioneer",
    "actualize",
    "egoist",
    "alchemist",
    "cloudnine",
    "dazzling",
    "surreal",
    "daystar",
    "alvin",
    "baron",
    "delling",
    "adolph",
    "miraculous",
    "sumptuous",
    /* Element_Lv1_text */
    "You only live once",
    "Believe in yourself",
    "Follow your heart",
    "Seize the day",
    "Love yourself",
    "Life is a journey",
    "Life is a choice",
    "The die is cast",
    "Hope springs eternal",
    "Hang in there",
    /**/
    "Think of me",
    "Always be with you",
    "I just want to be with you",
    "There is no limit to my love",
    "Charity begins at home",
    "Blood is thicker than water",
    "Union is strength",
    "In doing we learn",
    "Nurture is above nature",
    "Frist think and speak",
    /* Element_Lv2_text */
    "Live Well, Love Much, Laugh Often",
    "No pain, No gain",
    "Fall seven times, stand up eight",
    "Don't dream it, be it",
    "Just Do it!",
    "This too, shall pass",
    "Experience is the best teacher",
    "Nothing ventured, nothing gained",
    "Another Sunrise, Another New Beginning",
    "United we stand, divided we fall",
    /**/
    "Cuz your eyes make me see things",
    "Nothing can be done without efforts",
    "Love and reason do not go together",
    "Example is better than precept",
    "A friend is known in necessity",
    "Sleep is better than medicine",
    "The language of truth is simple",
    "Promise little, do much",
    "Your capacity to enjoy life",
    "an eventful day, life, journey",
    /* Element_Lv3_text */
    "Let thy speech be short, comprehending much in few words",
    "To be trusted is a greater compliment than to be loved",
    "It is a wise father that knows his own child",
    "All good things which exist are the fruits of originality",
    "Great art is an instant arrested in eternity",
    "Life's greatest happiness is to be convinced we are loved",
    "People find life entirely too time-consuming",
    "Error is the discipline through which we advance",
    "When money speaks, the truth keeps silent",
    "I never think of the future. It comes soon enough",
    /**/
    "Power is dangerous unless you have humility",
    "If you laugh, blessings will come your way",
    "The family is one of nature's masterpieces",
    "A good reader is ar rare as a good writer",
    "Book cannot never teach the use of books",
    "Life's not all gloom and despondency",
    "Happiness and sadness alternate in our lives",
    "There's a fine line between love and hate",
    "A love that endures all things and never fails",
    "It isn't love, it's just a passing infatuation"
};

void TypingGame(int ele, int lv, int* Result_Arr)
{
    int GAME_STR_X = 10;
    int GAME_STR_Y = 42;
    int GAME_IN_X = 10;
    int GAME_IN_Y = 44;
    int k = 0, ota = 0, Nota = 0;
    unsigned char string_now;
    char string_a[60] = "\0", string_b[60] = "\0";
    int i = rand() % 20 + lv * 20;
    TypingClean();
    double tasu = 0.0;
    double time1 = 0, time2 = 0;
    strcpy(string_a, Element_text[i]);
    gotoxy(GAME_STR_X, GAME_STR_Y);
    setcolor(ele, C_BLACK);
    puts(string_a);
    gotoxy(GAME_IN_X, GAME_IN_Y);
    time1 = clock();
    int j = 0;
    int len = strlen(Element_text[i]);
    while (1)
    {
        Dont_GetKey = 1;
        setcolor(C_WHITE, C_BLACK);
        gotoxy(GAME_IN_X + 65, GAME_IN_Y - 2);
        printf("Ÿ�� �ӵ�: %.2lf", tasu);
        gotoxy(GAME_IN_X + j, GAME_IN_Y);
        setcolor(C_WHITE, C_BLACK);
        printf("_");
        gotoxy(GAME_IN_X + j, GAME_IN_Y);
        setcolor(C_WHITE, C_BLACK);
        string_now = _getch();
        time2 = clock();
        if (string_now == ENTER)break;
        tasu = (j - ota) / ((time2 - time1) / 1000 / 60);
        for (k = 0, ota = 0; k < j; k++) {
            if (string_b[k] != string_a[k])
                ota++;
        }
        if (string_now == BACKSPACE) {
            if (j > 0) {
                gotoxy(GAME_IN_X - 1 + j, GAME_IN_Y);
                setcolor(C_WHITE, C_BLACK);
                printf("  ");
                string_b[j] = ' ';
                j--;
            }
        }
        else if (string_now == Element_text[i][j])
        {
            if (j < len) {
                gotoxy(GAME_IN_X + j, GAME_IN_Y);
                setcolor(C_WHITE, C_BLACK);
                putchar(string_now);
                string_b[j] = string_now;
                j++;
            }
        }
        else
        {
            if (j < len) {
                gotoxy(GAME_IN_X + j, GAME_IN_Y);
                if (level < 9) setcolor(C_RED_, C_BLACK);
                else setcolor(C_WHITE, C_BLACK);
                putchar(string_now);
                Nota++;
                j++;
            }
        }
        setcolor(C_WHITE, C_BLACK);
        gotoxy(GAME_IN_X + 65, GAME_IN_Y - 2);
        printf("Ÿ�� �ӵ�: %.2lf", tasu);
    }
    for (k = 0, ota = 0; k < len; k++) {
        if (string_b[k] != string_a[k])
            ota++;
    }
    if (ota) {
        drawNormalBattleSituationLogUpdate("������ �Ϻ��� �Է�����");
        drawNormalBattleSituationLogUpdate("�ʾҽ��ϴ�");
    }
    Result_Arr[0] = (int)tasu;
    Result_Arr[1] = ota;
    Result_Arr[2] = ele;
    Result_Arr[3] = lv;
}
void TypingClean() {
    for (int xx = 5; xx < 95; xx++) {
        for (int yy = 41; yy < 50; yy++) {
            gotoxy(xx, yy);
            printf(" ");
        }
    }
}


// ���� Ÿ���� ����
char atkString[60] = { 0, };		// ���� ���ڿ�
char inputString[100] = { 0, };		// �Է��� ���ڿ�
int typingResult[4] = { 0, };		// Ÿ���� ���� ���(Ÿ��, ��Ÿ, �Ӽ�, ����)
double typingStartTime;				// Ÿ���� ���� �ð�
double typingEndTime;				// Ÿ���� ���� �ð�
int isTypingSelect = 0;				// Ÿ���� Ȱ��ȭ ���� (0 : ��Ȱ��ȭ , ������ : Ȱ��ȭ)

void bossTypingGame_Start(int ele, int lv) {    //ele�� ��ų �Ӽ� //lv �� ��ų ����(-1 : �⺻ ����
    isTypingSelect = -1;	// Ÿ���� ��Ȱ��ȭ
    // ���� ���� ��ų
    if (lv != 0 && ele == -1)
    {
        drawNormalBattleSituationLogUpdate("��� �Ұ� ��ų�Դϴ�.");
        return;
    }
    // ���� ����
    if (lv == 1 && mp < 10 || lv == 2 && mp < 20 || lv == 3 && mp < 40)
    {
        drawNormalBattleSituationLogUpdate("������ �����մϴ�.");
        return;
    }

    drawNormalBattleSituationChoiceClean();
    isTypingSelect = 1;	// Ÿ���� Ȱ��ȭ

    switch (ele)
    {
    case 0:		ele = E_ICE;		break;
    case 1:		ele = E_FLAME;		break;
    case 2:		ele = E_ELECT;		break;
    default:	ele = E_NON;		break;
    }

    int GAME_STR_X = 10;
    int GAME_STR_Y = 42;

    int Current_Text = rand() % 20 + lv * 20;
    strcpy(atkString, Element_text[Current_Text]);  //������ ���ڿ� �տ� �ֱ�

    // ���� ���ڿ� ���
    setcolor(ele, C_BLACK);
    gotoxy(GAME_STR_X, GAME_STR_Y);
    puts(atkString);

    // �Է� ���ڿ� �ʱ�ȭ
    memset(inputString, '\0', 60 * sizeof(char));

    typingStartTime = clock();     //ó�� �ð� ����
    typingResult[2] = ele;
    typingResult[3] = lv;

    setcolor(C_WHITE, C_BLACK);
}
void bossTypingGamePlaying(char ch) {
    if (!isTypingSelect) return;	// Ÿ���� ��Ȱ��ȭ �� �۵� ����
    int GAME_IN_X = 10;
    int GAME_IN_Y = 44;
    typingResult[1] = 0;

    // �齺���̽� �Է��� ���
    if (ch == '\0')
    {
        if (strlen(inputString) != 0)
            inputString[strlen(inputString) - 1] = ch;
    }
    // ���ĺ� �Է�
    else
    {
        inputString[strlen(inputString)] = ch;
        inputString[strlen(inputString)] = '\0';
    }

    int len = strlen(inputString);

    setcolor(C_WHITE, C_BLACK);
    typingEndTime = clock();        //���� �ð� �˱�

    // ������� ��Ÿ ���
    for (int k = 0; k < len; k++) {
        if (inputString[k] != atkString[k])
            typingResult[1]++;
    }

    // Ÿ�� ���
    int n = strlen(inputString) - typingResult[1];
    if (n == 0) n = 1;
    typingResult[0] = n / ((typingEndTime - typingStartTime) / 1000 / 60);
    setcolor(C_WHITE, C_BLACK);
    gotoxy(GAME_IN_X + 65, GAME_IN_Y - 2);
    printf("Ÿ�� �ӵ�: %4d", typingResult[0]);

    // ���� �Է� ���ڿ� �����
    gotoxy(GAME_IN_X, GAME_IN_Y);
    for (int x = 0; x < 65; x++)
        printf(" ");
    // ���� �Է� ���ڿ� ���
    gotoxy(GAME_IN_X, GAME_IN_Y);
    puts(inputString);
}
void bossTypingGameFinish() {
    if (isTypingSelect == 0) return;
    // ��Ÿ or �Է��� ���� ���(�Ϲ� ����)
    if (isTypingSelect == 1 && (typingResult[1] != 0))
    {
        drawNormalBattleSituationLogUpdate("�Է��� �ùٸ��� �ʽ��ϴ�.");
        drawNormalBattleSituationLogUpdate(" ");
    }
    else if (strlen(inputString) == 0 || strlen(inputString) != strlen(atkString))
    {
        drawNormalBattleSituationLogUpdate("�Է��� �ùٸ��� �ʽ��ϴ�.");
        drawNormalBattleSituationLogUpdate(" ");
    }
    else
    {
        PCInBoss_Damage(&boss, typingResult);	// �������� ������ �ֱ�
        bossChangeElement();	// ���� �Ӽ� ���� �˻�
        if (boss.hp == 0)
        {
            clearBoss();
            return;
        }
    }
    isTypingSelect = 0;	// Ÿ���� ��Ȱ��ȭ
    printBossBattleMenu();	// �޴� ���
}