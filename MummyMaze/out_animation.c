#include <stdio.h>
#include <windows.h>

#include "position_cursor.h"
#include "colors.h"
#include "screen_resolution.h"

void outAnimation () {
	int i,j;
	
	for (i=0;i<HEIGHT;i++) {
		positionCursor(0,i);
		changeColor(255);
		printf ("                                                                                                                             ");
	
	}
	
	for (i=0,j=HEIGHT-1;i<HEIGHT+3;Sleep(3), i++,j--) {

		if (i<HEIGHT/2) {
			positionCursor(0,j);
			changeColor(119);
			printf ("                                                                                                                             ");

			positionCursor(0,i);
			changeColor(119);
			printf ("                                                                                                                             ");
		}		
		
		if ((i>1)&&(i<((HEIGHT/2)-1))) {
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