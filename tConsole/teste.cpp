#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "windows.h"

int mainuy(int argc, char** argv)
{
	int n;
	HANDLE	H = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	CONSOLE_SCREEN_BUFFER_INFOEX infoEx;
	n = GetConsoleScreenBufferInfo(H, &info);
	std::cout << "(" << info.dwSize.X << ", " << info.dwSize.Y << ")" << std::endl;
	n = GetConsoleScreenBufferInfoEx(H, &infoEx);
	perror("teste");
	std::cout << "Error: " << n << std::endl;
	std::cout << "(" << infoEx.dwMaximumWindowSize.X << ", " << infoEx.dwMaximumWindowSize.Y << ")" << std::endl;
	std::cout << "cbSize " << infoEx.cbSize << " (" << infoEx.dwSize.X << ", " << infoEx.dwSize.Y << ")" << std::endl;
	return 0;
}	// end main()
