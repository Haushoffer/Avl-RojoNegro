#ifndef FORMATO_H
#define FORMATO_H

#include <windows.h>
#include <iostream>
using namespace std;


inline void gotoxy(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

inline void textcolor(WORD col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}
#endif

void linea(int n)
{
	char c = 205;
	for (int i = 0; i < n; ++i)
	{
		cout << c;
	}
}

static void printLine(int n, int endline = 0)
{
	char c = 205;
	for (int i = 0; i < n; ++i)
	{
		std::cout << c;
	}
	if (endline)
		cout << endl;
}


struct Pos
{
	int x;
	int y;
	bool equals(Pos a)
	{
		if (a.x == x && a.y == y)
			return true;
		return false;
	}
};