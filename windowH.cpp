#include <windows.h>
#include <conio.h>
#include "backend.h"
#include "display.h"
#include "TestExam.h"
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7	
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15
void renderLoginScreen(tree &t);
void renderTeacher(bool &status, tree &t);
bool setPasswordTeacher(int pass);
void renderQues () {
	char list[_numQues][100] = {
	"1. Enter question list.",
	"2. Enter question list by File.",
	"3. Export question list.",
	"4. Search questions by ID.",
	"5. Update question information by ID.",
	"6. Delete questions.",
	"7. Back to Menu"
	};
	
	
	for (int i = 0; i <_numQues; i+= 1) {
		GoToXY(_left + _pLeft, _top + i*_pTop + 1);
		printf("%s", list[i]);
	}
	
}

void drawHorizontalLine() {
	for (int i = 0; i <= winHeight; i+= _pTop) {
		GoToXY(_left, _top + i);
		for (int j = 0; j<winLength; j+= 1) {
			putchar(205); // 
		}
	}
}

void drawVerticalLine () {
	for (int i = 0; i <= winHeight; i+= 1) {
		GoToXY(_left, _top + i);
			putchar(186);
		GoToXY(_left+ winLength, _top + i);
			putchar(186);
		}
}

void drawCorner () {
	GoToXY(_left, _top);
	putchar(201);
	GoToXY(_left+ winLength, _top);
	putchar(187);
	GoToXY(_left, _top + winHeight);
	putchar(200);
	GoToXY(_left + winLength, _top + winHeight);
	putchar(188);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}




bool renderCurOpt(bool &status, tree &t)
{
	int left1 = 42, top = _top + 1;
	GoToXY(left1, top);
	putchar(62);				//left arrows
	putchar(62);
	int left2 = 87;
	GoToXY(left2, top);
	putchar(60);				//right arrows
	putchar(60);
	int c, slt = 0;
	bool loadMenu = true;
	while (loadMenu) {
		c = getConsoleInput();
		switch (c) {
		case 2:			//move up
			if (slt == 0) break; // limit up
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			top -= 2;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			slt--;
			break;
		case 5:			//move down
			if (slt == 6) break; // limit down
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			top += 2;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			slt++;
			break;
		case 6:		//enter
			loadMenu = false;
			break;
		}
	}
	int key;
	int index=0;
	int dem=0;
	char array_answers[50];
	switch (slt) {
	case 0:// 1. Enter question list.
			system("cls");
			CreateTree(t,index);
			WriteFile(t);
			status = true;
			system("cls");
			renderTeacher(status, t);
		break;
	case 1:// 2. Enter question list by File.
			system("cls");	
			ReadFile(t,array_answers, index);
			NLR(t);
			getch();
			status = true;
			system("cls");
			renderTeacher(status, t);
		break;
	case 2:// 3. Export question list.
			system("cls");
			if(true){
			NLR(t);
				printf ("xxx");
			}else {
				printf("\nPlease enter question list!");
			}
			getch();
			system("cls");
			renderTeacher(status, t);
		break;
	case 3:// 4. Search questions by ID.
			if(status){
				system("cls");
				int IDSearch;
				printf("\nEnter ID to search: "); scanf("%d", &IDSearch);
				tree result = new AVLNODE;
				result = searchNodeByID(t, IDSearch);
				if(result){
					OutputQues(result->key);
				}else{
					printf("\nQuestion not found!");
				}
			}
			system("cls");
			renderTeacher(status, t);
		break;
	case 4:// 5. Update question information by ID.
			if(status){
			system("cls");
			int IDUpdate;
			printf("\nEnter ID to update: "); scanf("%d", &IDUpdate);
			updateNodeByID(t, IDUpdate);
			WriteFile(t);
			} else
				printf("\nPlease enter question list !");
			getch();
			system("cls");
			renderTeacher(status, t);
		break;
	case 5:// 6. Delete questions.
		system("cls");
		xoa(t,array_answers, index);
		WriteFile(t);
		system("cls");
		renderTeacher(status, t);
		break;
	case 6: // 7. Back to Menu
		system("cls");
		renderLoginScreen(t);
		break;
	}
}

void renderTeacher(bool &status, tree &t) {	
	readCharFile("text1.txt",0,26, 5);
	drawHorizontalLine();
	drawVerticalLine();
	drawCorner();
	renderQues(); 
	renderCurOpt(status, t);
}

void renderStudent (tree t, char *studentName, bool status) {
	readCharFile("table.txt",5, 30, 6);
	GoToXY(118, 2);
	printf ("Excercise: ");
	if (status) {
		SetColor(0, 2);
		printf ("Access");
	} else {
		SetColor(0, 4);
		printf ("Denied");
	}
	SetColor(0,7);
	GoToXY(0,0);
	printf ("B: back to menu\n");
	printf ("C: continue input name");
	
	char c;
	do {
		if (kbhit()) {
			c = getch();
		} else {
			c = '0';
		}
		
		switch(c) {
			case 'b':
			case 'B':
				system("cls");
				renderLoginScreen(t);
			break;
			case 'C':
			case 'c':
				GoToXY(47, 8);
				fflush(stdin);
				gets(studentName);
				SetColor(0,2);
				GoToXY(47, 9);
				printf ("Enter name succesful!");
				getch();
				SetColor(0,7);
				system("cls");
			break;
			default: break;
		}
	} while (!(c == 'c' || c == 'C' || c == 'b' || c == 'B'));
}

bool setPasswordTeacher(tree &t, const char pass[]) {
	readCharFile("teacher.txt", 5, 20, 5);
	GoToXY(0,0);
	printf ("B: back to menu\n");
	printf ("C: continue to login");
	GoToXY(30, 15);
	printf ("Password: ");
	bool flag = true;
	char c;
	do {
		if (kbhit()) {
			c = getch();
		} else {
			c = '0';
		}
		
		switch (c) {
			case 'b':
			case 'B':
				system("cls");
				renderLoginScreen(t);
				flag = false;
			break;
			case 'C':
			case 'c':
					int check;
					do {
						char inputPass[100] = "";						
						char ch;
						check = -1;
						readCharFile("teacher.txt", 5, 20, 5);
						GoToXY(0,0);
						printf ("B: back to menu\n");
						printf ("C: continue to login");
						GoToXY(30, 15);
						printf ("Enter the password <any 8 character>: ");
						int i = 0;
						while (i<9) {
							ch = getch();
							if (ch == 8) {
								GoToXY(67 + i, 15);
								if (i > 0) i--;
								printf(" ");
							} else if (ch == 13) {
								check = strcmp(inputPass, pass);
								if (check != 0) {
									GoToXY(67, 16);
									SetColor(0, 4);
									printf ("Wrong password!");
									SetColor(0, 7);
								} else {
									GoToXY(67, 16);
									SetColor(0, 2);
									printf ("Login success!");
									SetColor(0, 7);
								}
								getch(); 
								break;
							} else {
								if (i < 8) {
									inputPass[i] = ch;
									ch = '*';
									GoToXY(68 + i, 15);
									printf ("%c", ch);
									i++;
								}
							}		
						}
						system("cls");
					} while (check != 0);
			break;
		}
	} while (!(c == 'c' || c == 'C' || c == 'b' || c == 'B'));
	return flag;
}

// excercise status
bool _status = false;

void renderLoginScreen (tree &t) {
	char studentName[100];
	ShowScrollbar(false);
	setFontInfo(24,24);
	disableMouseInput();
	hidecursor();
	readCharFile("login.txt", 5, 32, 8);
	readCharFile("bear.txt",13,34, 3);
	char choice = '0'; 
	do {
		// getche : nhan ki tu -> hien thi
		// getch: nhan ki tu -> 0 hien thi
		if (kbhit()) {
			choice = getch();
		} else {
			choice = '0';
		}
		int itest = 0;
		switch(choice) {
		case '1':
			system("cls");
			renderStudent(t, studentName, _status);
			system("cls");
			if (_status) {
				setFontInfo(18,18);
				fe_renderTestExam(t, studentName);
			} else {
				system("cls");
				SetColor(0,4);
				GoToXY(10,10);
				printf ("You don't have permision to do the test, Please tell to teacher!");
				SetColor(0,7);
				getch();
				system("cls");
				renderLoginScreen(t);
			}
//			drawTestExam(t); 
			break;
		case '2':		
			system("cls");
			if (setPasswordTeacher(t, "123"))
				renderTeacher(_status, t);
			break;
		case '3': 
			system("cls");
			readCharFile("goodbye.txt", 5,5,10);
			getch();
			system("cls");
			readCharFile("team.txt", 0,15, 5);
			break;
		default:
			break;
		}
	} while (!(choice == '1' || choice == '2' || choice == '3'));
}

int main () {
	tree t;
	Init(t);
	// Tieu de cua teminal
	disableMaximize();
	SetConsoleTitle("English App");
	DisableCtrButton(false, true, true);
//	setFontInfo(18, 18);
	MaximizeWindow();
	renderLoginScreen(t);
//	drawTestExam(t);
//	printf ("cc");
//	fe_renderTestExam();
//	system("cls");
//	getch();
//	fe_renderTestExam();
	return 0;

}
