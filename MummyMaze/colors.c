#include <windows.h>

void changeColor (int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
	return;
}