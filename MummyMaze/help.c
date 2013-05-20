#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "controls.h"
#include "position_cursor.h"
#include "colors.h"
#include "background.h"

void help () {
	printf ("          _______           \n"
			"         ||      ||          \n"
			"         ||  up  ||          \n"
			"         ||      ||          \n"
			"         ||______||          \n"
			"         |/______\\|          \n"
			" _______  _______  _______\n"
			"||      |||      |||      ||\n"
			"||      |||      |||      ||\n"
			"||left  ||| down ||| right||\n"
			"||______|||______|||______||\n"
			"|/______\\|/______\\|/______\\|");



	_getch();
}