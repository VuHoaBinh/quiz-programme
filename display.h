#pragma once
#include <windows.h>
#include <conio.h>
#include "display.cpp"
int winLength = 40;
int winHeight = 14; 
int _left = 45, _top = 12;
int _pLeft = 2, _pTop = 2;
int _numQues = 7;
int winList = 130;
int CELL_HEIGHT = 2;
int CELL_LENGTH = 5;
int _length = 6;
int _height = 5;
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void MaximizeWindow();
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void ShowScrollbar(BOOL Show);
void GoToXY(SHORT posX, SHORT posY);
void SetColor(int backgound_color, int text_color);
void setAndCenterWindow ();
void hideScrollBars();
void disableMaximize();
void FontSize(int FontWeight, int dwFontSize_X,int dwFontSize_Y);
void setFontInfo(int sizeX, int sizeY);
void clearConsole();
void hideCursor();
void disableMouseInput();
int getConsoleInput();
void readCharFile (const char *filename, int top, int left, int color);

