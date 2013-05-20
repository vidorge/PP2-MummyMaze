#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"

void help () {
	
	int input;

	backgroundImage (0);	

	positionCursor(50,11);
	printf ("  _    _ ______ _      _____  ");
	positionCursor(50,12);
	printf (" | |  | |  ____| |    |  __ \\ ");
	positionCursor(50,13);
	printf (" | |__| | |__  | |    | |__) |");
	positionCursor(50,14);
	printf (" |  __  |  __| | |    |  ___/ ");
	positionCursor(50,15);
	printf (" | |  | | |____| |____| |     ");
	positionCursor(50,16);
	printf (" |_|  |_|______|______|_|     ");
	positionCursor(50,17);
	printf ("                              ");

	positionCursor(35,20);
	printf ("CONTROLS");
	positionCursor(10,22);
	printf ("          _______               ||");
	positionCursor(10,23);
	printf ("         ||      ||             ||");
	positionCursor(10,24);
	printf ("         ||  up  ||             || ");
	positionCursor(10,25);
	printf ("         ||      ||             ||");
	positionCursor(10,26);
	printf ("         ||______||             ||");
	positionCursor(10,27);
	printf ("         |/______\\|             ||");
	positionCursor(10,28);
	printf (" _______  _______  _______      ||");
	positionCursor(10,29);
	printf ("||      |||      |||      ||    ||");
	positionCursor(10,30);
	printf ("||      |||      |||      ||    ||");
	positionCursor(10,31);
	printf ("||left  ||| down ||| right||    ||");
	positionCursor(10,32);
	printf ("||______|||______|||______||    ||");
	positionCursor(10,33);
	printf ("|/______\\|/______\\|/______\\|    ||");

	positionCursor(10,34);
	printf ("                                ||");
	positionCursor(10,35);
	printf ("                                ||");

	positionCursor(10,36);
	printf (" ____________________           ||");
	positionCursor(10,37);
	printf ("||                   ||         ||");
	positionCursor(10,38);
	printf ("|| \33---              ||         ||");
	positionCursor(10,39);
	printf ("||                   ||         ||");
	positionCursor(10,40);
	printf ("||___________________||         ||");
	positionCursor(10,41);
	printf ("|/___________________\\|         ||");

	positionCursor(10,42);
	printf ("                                ||");
	positionCursor(10,43);
	printf ("                                ||");

	while (1) {
		input=_getch();
		if ((input==PAUSE)||(input==EXIT)) break;	
	}
}