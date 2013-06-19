#include "pause.h"

void pause () {

	positionCursor (70,25);
	printf ("PAUSE");

	while (1) {
		if (_kbhit())
			break;
	}
}
