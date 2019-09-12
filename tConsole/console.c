#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "windows.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int mainxx(int argc, char** argv)
{
	HANDLE	H = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	int n = GetConsoleScreenBufferInfo(H, &info);
	printf("GetConsoleScreenBufferInfo retornou %d\n", n);
	printf("dwSize: (%d,%d)\n", info.dwSize.X, info.dwSize.Y);
	return 0;
}	// end main()