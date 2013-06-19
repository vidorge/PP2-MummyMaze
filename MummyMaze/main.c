#include "start_animation.h"
#include "main_menu.h"
#include "screen_resolution.h"

void main ()
{

	setConsoleSize(WIDTH,HEIGHT);

	startAnimation ();

	mainMenu();

}