#include <windows.h>
#include <conio.h>
#include <stdio.h>
HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwStyle = GetWindowLong(consoleWindow, GWL_STYLE);
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);	
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void MaximizeWindow(){
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

// vo hieu hoa cac nut close, phong to , thu nho

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void GoToXY(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void setAndCenterWindow () {
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1152;
	int height = 648;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);
}


void hideScrollBars()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);

	// get handle to the console window
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// retrieve screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	// current screen buffer size
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	// to remove the scrollbar, make sure the window height matches the screen buffer height
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// set the new screen buffer dimensions
	int Status = SetConsoleScreenBufferSize(hOut, newSize);
}

void disableMaximize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void FontSize(int FontWeight, int dwFontSize_X,int dwFontSize_Y){
	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = FontWeight;
    fontex.dwFontSize.X = dwFontSize_X;
    fontex.dwFontSize.Y = dwFontSize_Y;
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}


void setFontInfo(int sizeX, int sizeY)
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = sizeX;
	info.dwFontSize.Y = sizeY;
//	wcscpy_s(info.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
}

void clearConsole()
{
	system("cls");
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(consoleOutput, &cursorInfo);
	cursorInfo.bVisible = 0; // set the cursor visibility
	SetConsoleCursorInfo(consoleOutput, &cursorInfo);
}

void disableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

int getConsoleInput()
{
	int c = -1;
	c = _getch();
		switch (c)
		{
		case 72:				// len
			return 2;
		case 75:				// trai
			return 3;
		case 77:				// phai
			return 4;
		case 80:				// xuong
			return 5;
		case 13:
			return 6;
		case 98:
			return 8;	
		default:				// nut khac
			return 1;
		}

		if (c == 27)                  //esc
			return 0;
		else if (c == 87 || c == 119) //W, w
			return 2;
		else if (c == 65 || c == 97)  //A, a
			return 3;
		else if (c == 68 || c == 100) //D, d
			return 4;
		else if (c == 83 || c == 115) //S, s
			return 5;
		else if (c == 13)             //Enter
			return 6;
		else if (c == 74 || c == 106) //J, j
			return 7;
//		else if (c == 66 || c == 98) //B, b
//			return 8;
		else if (c == 76 || c == 108) //K, k
			return 9;
		else
			return 0;                 //nút khác
}

void readCharFile (const char *filename, int top, int left, int color) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		exit(1);
	}

	int i = 0;
	char arr[128];
	SetColor(0, color);
	while (fgets(arr, 128, fp) != NULL)
    {
        GoToXY(left, top+i);
        printf("%s", arr);
        i++;
    }
	SetColor(0,7);
	fclose(fp);
}
