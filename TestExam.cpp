#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 
#include"backend.h"
#include"display.h"
using namespace std;



void drawTestExam(tree t, int *Answered, int count, char studentName[]);

void txtColor(int color){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawLeaderBoard(char studentName[]){
	int x = winList;
	int y = CELL_HEIGHT * _height / 4;
	
	for (int i = 0; i <= 16; i += CELL_HEIGHT + 2){
		GoToXY(winList - 5, i + 5);
		for (int j = 0; j <= 40; j++) {
			putchar(45);
		}
	}
	
	for (int i = 0; i <= 40; i += 40) {
		for (int j = 0; j <= 16 ; j++) {
			GoToXY(winList - 5 + i, j + 5);
			putchar(186);
		}
	}
	
	txtColor(14);
	GoToXY(winList - 5, 5); 
	putchar(201);

	GoToXY(winList + 35, 5); 
	putchar(187);

	GoToXY(winList - 5, 21); 
	putchar(200);

	GoToXY(winList + 35, 21);
	putchar(188);
	
	SetColor(0, 14);
	GoToXY(winList + 7, 7); printf("> SCORE BOARD <");
	GoToXY(winList - 3, 11); printf("Full Name: ");
	SetColor(0, 4);
	printf ("%s", studentName); 
	SetColor(0, 14);
	GoToXY(winList - 3, 15); printf("Score: ");
	GoToXY(winList - 3, 19); printf("Time Remaining: ");
}

void QuesList_drawCorner(int left, int top , int length, int height) {

	GoToXY(left, top +15); //  tren ben trai
	putchar(201);

	GoToXY(left + length, top + 15); // tren ben phai
	putchar(187);

	GoToXY(left, top + height + 16); // duoi ben trai
	putchar(200);

	GoToXY(left + length, top + height + 16); // duoi ben phai
	putchar(188);
}

void drawQuestion(){
	txtColor(2);
	for (int i = 0; i <= 8; i  +=8 ){
		GoToXY(_pLeft + 5, i + 9);
		for (int j = 0; j <= 110; j++) {
			putchar(45);
		}
	}
	
	for (int i = 0; i <= 210; i += 110) {
		for (int j = 0; j <= 8 ; j++) {
			GoToXY(_pLeft + 5 + i, j + 9);
			putchar(186);
		}
	}
	
	txtColor(14);
	GoToXY(_pLeft + 5, 9); 
	putchar(201);

	GoToXY(_pLeft + 115, 9); 
	putchar(187);

	GoToXY(_pLeft + 5, 17); 
	putchar(200);

	GoToXY(_pLeft + 115, 17);
	putchar(188);
}

void drawAnswer(){
	txtColor(14); 
	for (int i = 0; i <= 15; i += 5 ){
		GoToXY(_pLeft + 10, i + 22);
		for (int j = 0; j <= 40; j++) {
			putchar(205);
		}
	}
	
	for (int i = 0; i <= 15; i += 5 ){
		GoToXY(winList - 60, i + 22);
		for (int j = 0; j <= 40; j++) {
			putchar(205);
		}
	}
	
	for (int i = 0; i < 80; i += 40) {
		for (int j = 0; j <= 5 ; j++) {
			GoToXY(_pLeft + 10 + i, j + 22);
			putchar(186);
		}
	}
	
	for (int i = 0; i < 80; i += 40) {
		for (int j = 0; j <= 5 ; j++) {
			GoToXY(winList - 60 + i, j + 22);
			putchar(186);
		}
	}
	
	for (int i = 0; i < 80; i += 40) {
		for (int j = 0; j <= 5 ; j++) {
			GoToXY(_pLeft + 10 + i, j + 32);
			putchar(186);
		}
	}
	
	for (int i = 0; i < 80; i += 40) {
		for (int j = 0; j <= 5 ; j++) {
			GoToXY(winList - 60 + i, j + 32);
			putchar(186);
		}
	}
	txtColor(2);
	// A
	GoToXY(_pLeft + 10 , 22); 
	putchar(201);
	GoToXY(_pLeft + 10 + 40, 22); // tren ben phai
	putchar(187);
	GoToXY(_pLeft + 10, 22 + 5); // duoi ben trai
	putchar(200);
	GoToXY(_pLeft + 10 + 40, 22 + 5); // duoi ben phai
	putchar(188);
	// B
	GoToXY(_pLeft + 10, 22 + 10); //  tren ben trai
	putchar(201);
	GoToXY(_pLeft + 10 + 40, 22 + 10); // tren ben phai
	putchar(187);
	GoToXY(_pLeft + 10, 22 + 10 + 5); // duoi ben trai
	putchar(200);
	GoToXY(_pLeft + 10 + 40, 22 + 10 + 5); // duoi ben phai
	putchar(188);
	//C
	GoToXY(winList - 60, 22); //  tren ben trai
	putchar(201);
	GoToXY(winList - 60 + 40, 22); // tren ben phai
	putchar(187);
	GoToXY(winList - 60, 22 + 5); // duoi ben trai
	putchar(200);
	GoToXY(winList - 60 + 40,  22 + 5); // duoi ben phai
	putchar(188);
	//D
	GoToXY(winList - 60, 22 + 10); //  tren ben trai
	putchar(201);
	GoToXY(winList - 60 + 40, 22 + 10); // tren ben phai
	putchar(187);
	GoToXY(winList - 60, 22 + 10 + 5); // duoi ben trai
	putchar(200);
	GoToXY(winList - 60 + 40, 22 + 10 + 5); // duoi ben phai
	putchar(188);
}


void drawQuestionList(){
	txtColor(2);
	for (int i = 0; i <= CELL_HEIGHT * _height; i += CELL_HEIGHT) {
		GoToXY(winList, _top + 15 + i);
		for (int j = 0; j <= CELL_LENGTH * _length; j++) {
			putchar(205);
		}
	}
	
	txtColor(10);
	for (int i = 0; i <= CELL_LENGTH * _length; i+=CELL_LENGTH) {
		for (int j = 0; j <= CELL_HEIGHT * _height ; j++) {
			GoToXY(winList + i, _top + 15 + j);
			putchar(186);
		}
	}
	
	SetColor(0, 14);
	int left = winList + 2, top = _top + 16;
	GoToXY(winList + 6, top - 3); printf("> CHOOSE QUESTION <");
	int iQues = 1;
	for (int i = 0; i < _height * CELL_HEIGHT; i += CELL_HEIGHT) {
		for (int j = 0; j < _length * CELL_LENGTH; j += CELL_LENGTH) {
			GoToXY(left + j, top + i);
			if(iQues < 10)
				printf("0%d", iQues);
			else
				printf("%d", iQues);
			iQues++;
		}
	}
	
	int length = CELL_LENGTH * _length;
	int height = CELL_HEIGHT * _height;
	for (int i = CELL_LENGTH; i < length; i += CELL_LENGTH) {
		GoToXY(winList + i, _top + 15);
		putchar(203);
		GoToXY(winList + i, _top + 15 + height);
		putchar(202);
	}

	for (int i = CELL_HEIGHT; i < height; i += CELL_HEIGHT) {
		GoToXY(winList, _top + 15 + i);
		putchar(204);
		GoToXY(winList + length, _top + 15 + i);
		putchar(185);
	}

	for (int i = CELL_LENGTH; i < length; i += CELL_LENGTH) {
		for (int j = CELL_HEIGHT; j < height; j += CELL_HEIGHT) {
			GoToXY(winList + i, _top + 15 + j);
			putchar(206);
		}
	}
	
	QuesList_drawCorner(winList, _top, CELL_LENGTH * _length, CELL_HEIGHT * _height - 1);
}

void renderSubmit(){
	SetColor(0, 2);
	system("cls");
	readCharFile("Submitted.txt", 15, 30, 2);
	GoToXY(20, 35);
	int t;
	srand(time(NULL));
	t = rand()%30+1; 
	cout << "Your score: " << t <<"/30" << endl;
	getch();
}

void fe_unColorFrame (int length, int height, int left, int top) {
	SetColor(0,7);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			GoToXY(left + j, top + i);
			putchar(' ');
		}
	}
}

void fe_colorFrame (int length, int height, int left, int top) {
	SetColor(6,6);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			GoToXY(left + j, top + i);
			putchar(' ');
		}
	}
	SetColor(0,7);
}

void renderDataExam(tree t, int iQues){
		tree p = new AVLNODE;
		p = searchNodeByID(t, iQues);
		
		if (p->key.id == iQues) {
			GoToXY(12,12);
			printf ("%s", p->key.content);
			
			// A
			GoToXY(22,24);
			printf ("%s", p->key.answerData[0]);
			
			// B
			GoToXY(22,24 + 10);
			printf ("%s", p->key.answerData[1]);
			
			// C
			GoToXY(22 + 58, 24);
			printf ("%s", p->key.answerData[2]);
			// D
			
			GoToXY(22 + 58, 24 + 10);
			printf ("%s", p->key.answerData[3]);
			return;
		}
}

void moveAnswers(tree t, int iQues, int *Answered, int count, char studentName[])
{
	
	renderDataExam(t, iQues);
	int left1 = 9, top = 24;
	GoToXY(left1, top);
	putchar(62);				//left arrows
	putchar(62);
	int left2 = 54;
	GoToXY(left2, top);
	putchar(60);				//right arrows
	putchar(60);
	int c;
	int upDown = 0, rightLeft = 0, jumpY = 10, jumpX = 58;
	int frameWidth = 39;
	int frameLength = 4;
	bool loadMenu = true;
	while (loadMenu) {
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
//			fe_colorFrame(frameWidth,frameLength, left1 + 4, top - 1);
		c = getConsoleInput();
		switch (c) {
		case 2: //move up
			if (upDown == 0) break; // limit up
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			top -= jumpY;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			upDown--;
//			fe_unColorFrame(frameWidth,frameLength, left1 + 4, top - 1 + jumpY);
//			fe_colorFrame(frameWidth,frameLength, left1 + 4, top - 1);
			break;
		case 3: // move left
			if (rightLeft == 0) break;
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			left1 -= jumpX;
			left2 -= jumpX;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			rightLeft--;
//			fe_unColorFrame(frameWidth,frameLength, left1 + 4 + jumpX , top - 1);
//			fe_colorFrame(frameWidth,frameLength, left1 + 4, top - 1);
			break;
		case 4: // move right
			if (rightLeft == 1) break;
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			left1 += jumpX;
			left2 += jumpX;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			rightLeft++;
//			fe_unColorFrame(frameWidth,frameLength, left1 + 4 - jumpX , top - 1);
//			fe_colorFrame(frameWidth,frameLength, left1 + 4, top - 1);
			break;
		case 5:			//move down
			if (upDown == 1) break; // limit down
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			top += jumpY;
			GoToXY(left1, top);
			putchar(62);
			putchar(62);
			GoToXY(left2, top);
			putchar(60);
			putchar(60);
			upDown++;
//			fe_unColorFrame(frameWidth,frameLength, left1 + 4, top - 1 - jumpY);
//			fe_colorFrame(frameWidth,frameLength, left1 + 4, top - 1);
			break;
		case 6: //enter
//			fe_unColorFrame(frameWidth,frameLength, left1 + 4, top - 1);
			GoToXY(left1, top);
			putchar(' ');
			putchar(' ');
			GoToXY(left2, top);
			putchar(' ');
			putchar(' ');
			Answered[count] = iQues;
			count++;		
			drawTestExam(t, Answered, count, studentName);
			break;
		}
	}
}



void toMauBingChilling(int left, int top, int iQues){
	SetColor(14, 2);
	GoToXY(left, top);
	if(iQues < 10)
				printf("0%d", iQues);
			else
				printf("%d", iQues);
}

void un_toMauBingChilling (int left, int top, int iQues) {
	SetColor(0, 14);
	GoToXY(left, top);
	if(iQues < 10)
				printf("0%d", iQues);
			else
				printf("%d", iQues);
}

void colorQuesAnswered(int left, int top, int iQues){
	SetColor(8, 0);
	GoToXY(left, top);
	if(iQues < 10)
				printf("0%d", iQues);
			else
				printf("%d", iQues);
}

void drawTestExam(tree t, int *Answered, int count, char studentName[]){
//	
	int left1 =winList + 2, top1 =_top + 16;
//	int j = 0;
//	for(int i = 0; i < 30; i++){
//		if(i == Answered[j] && j < 3){
//		colorQuesAnswered(left1 + (5 * i / 7) , top1, Answered[j]);
//			j++;
//		}
//	}
//	int k = 0;
//	int col = 0;
//	int row = 0;
//		for (int i = 0; i < _height * CELL_HEIGHT; i += CELL_HEIGHT) {
//			for (int j = 0; j < _length * CELL_LENGTH; j += CELL_LENGTH) {
//				GoToXY(left + j, top + i);
//				if()
//		}
//	}
	
	readCharFile("TextExam.txt", 1, 35, 14);
	GoToXY(22, 7);
	printf("%c: Move Up   ",30);
	printf("%c: Move Down   ",31);
	printf("%c: Left    ",17);
	printf("%c: Right   ",16);
	printf("B: Submit   ");
	printf("ENTER: Choose");
	drawQuestion();
	drawAnswer();
	drawLeaderBoard(studentName);
	drawQuestionList();
	GoToXY(left1, top1);
	
	
	

	int c, upDown = 0, rightLeft = 0, jumpX = 5, jumpY = 2, iQues = 1;
	bool loadMenu = true;
	char test;
	while (loadMenu) {
		toMauBingChilling(left1, top1, iQues);	
		c = getConsoleInput();
		GoToXY(10, 0); cout<< c;
		switch (c) {
		case 2:			//move up
			if (upDown == 0) break; // limit up
			top1 -= jumpY;
			GoToXY(left1, top1);
			iQues -=6;
			upDown--;
			un_toMauBingChilling(left1, top1 + jumpY, iQues + 6);
			toMauBingChilling(left1, top1, iQues);	
			break;
		case 5:			//move down
			if (upDown == _height - 1) break; // limit down
			top1 += jumpY;
			GoToXY(left1, top1);
			upDown++;
			iQues += 6;
			un_toMauBingChilling(left1, top1 - jumpY, iQues - 6);
			toMauBingChilling(left1, top1, iQues);
			break;
		case 3: 
			if (rightLeft == 0) break; // left
			left1 -= jumpX;
			GoToXY(left1, top1);
			rightLeft--;
			iQues-= 1;
			un_toMauBingChilling(left1 + jumpX, top1, iQues + 1);
			toMauBingChilling(left1, top1, iQues);
			break;
		case 4: 
			if(rightLeft == _length - 1) break; //right
			left1 += jumpX;
			GoToXY(left1, top1);
			rightLeft++;
			iQues += 1;
			un_toMauBingChilling(left1 - jumpX, top1, iQues - 1);
			toMauBingChilling(left1, top1, iQues);
			break; 
		case 6:	
			un_toMauBingChilling(9, 24, 1);
			moveAnswers(t, iQues, Answered, count, studentName); //enter
			break;
		case 8:
			renderSubmit();
			loadMenu = false;
			exit(0);
			break;	
		}	
	}

}

/*void play(tree t,char *array_answers,int index){
	for( int i=1;i<=index;i++){
		cout <<"Question " << i << endl;
	}
	int choice;
	cout <<"CHOICE question: ";
	cin >> choice; 
	tree p = new AVLNODE;
	p = searchNodeByID(t,choice+48); 
	if(p == NULL){
		printf("Not found");
	}else
	{
		OutputQues(p->key);
		char user;
		cout <<"answer correct: "; 
		fflush(stdin);
		scanf("%c",&user);
		for( int i=1;i<=index;i++){
			if(i+48==p->key.id){
				cout << array_answers[i-1] <<endl;
				char letter = array_answers[i-1];
				if(letter==user){
					cout <<"Correct" <<endl;
				
				}else
					cout <<"Incorrect" <<endl;
				break;
			}
		}
	}
		
}

*/

	

int fe_renderTestExam(tree t, char studentName[]){
	int *Answered = new int;
	int count = 0;
	drawTestExam(t, Answered, count, studentName);
//	renderDataExam(t, 1);
	return 0;
//	tree t;
//	Init(t);
//	int index=0;
//	char array_answers[50];
//	renderDataExam(t, 1,array_answers,index);

}
