#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"
#include "options.h"

void options () {
	int choice;

	while(1) {
		choice=controls(_getch());
		if ((choice==EXIT)||(choice==PAUSE)) break;
	}
}