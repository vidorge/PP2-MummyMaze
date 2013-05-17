#include <stdio.h>
#include <windows.h>

void setConsoleSize(int width,int height)
{
     HANDLE hOut;	 
     SMALL_RECT DisplayArea = {0, 0, 0, 0};
	 COORD resolution={width,height};
     hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     DisplayArea.Right  = width;
     DisplayArea.Bottom = height;
     SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
	 SetConsoleScreenBufferSize(hOut,resolution);
}