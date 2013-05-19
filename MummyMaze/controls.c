#include <conio.h>
#include "controls.h"
#include <stdio.h>

int controls (int keyboardInput) {
	if (keyboardInput>=224) keyboardInput=_getch();
	switch (keyboardInput) {
		case UP :		return UP; break;
		case DOWN :		return DOWN; break;
		case LEFT :		return LEFT; break;
		case RIGHT :	return RIGHT; break;
		case EXIT :		return EXIT; break;
		case ENTER :	return ENTER;break;
	}
}