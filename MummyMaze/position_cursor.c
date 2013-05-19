#include <windows.h>

void positionCursor (int column, int line) {
    COORD coord;
	CONSOLE_CURSOR_INFO cursorInfo;

	coord.X = column; coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
	cursorInfo.dwSize = 10;
	cursorInfo.bVisible = FALSE; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	return;
}