#include <stdio.h>
#include <windows.h>

#include "position_cursor.h"
#include "colors.h"

void outAnimation () {
	int i,j;
	
	for (i=0;i<50;i++) {
		positionCursor(0,i);
		changeColor(255);
		printf ("                                                                                                                             ");
	
	}
	
	for (i=0,j=49;i<28;Sleep(3), i++,j--) {

		if (i<25) {
			positionCursor(0,j);
			changeColor(119);
			printf ("                                                                                                                             ");

			positionCursor(0,i);
			changeColor(119);
			printf ("                                                                                                                             ");
		}		
		
		if ((i>1)&&(i<24)) {
			positionCursor(0,j+2);
			changeColor(136);
			printf ("                                                                                                                             ");

			positionCursor(0,i-2);
			changeColor(136);
			printf ("                                                                                                                             ");
		}

		if (i>2) {
			positionCursor(0,j+3);
			changeColor(0);
			printf ("                                                                                                                             ");

			positionCursor(0,i-3);
			changeColor(0);
			printf ("                                                                                                                             ");		
		}

	}

	Sleep (250);
}