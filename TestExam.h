#pragma once
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "display.h"
#include "TestExam.cpp"
#include "backend.h"
#include <stdio.h>
using namespace std;
void readCharFile (const char *filename, int top, int left, int color);
void txtColor(int color);
void drawLeaderBoard(char studentName[]);
void QuesList_drawCorner(int left, int top , int length, int height);
void drawQuestion();
void drawAnswer();
void drawQuestionList();
void fe_unColorFrame (int length, int height, int left, int top);
void fe_colorFrame (int length, int height, int left, int top);
void moveAnswers(tree t, int iQues, int *Answered, int count, char studentName[]);
void toMauBingChilling(int left, int top, int iQues);
void un_toMauBingChilling (int left, int top, int iQues);
void drawTestExam(tree t, int *Answered, int count, char studentName[]);
int fe_renderTestExam(tree t, char studentName[]);
void renderDataExam(tree t, int iQues);
void colorQuesAnswered(int left, int top, int iQues);

