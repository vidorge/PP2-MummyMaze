#include "pause.h"

void pause () {

	positionCursor (0,0);
	printf ("PAUSE");

	while (1) {
		if (_kbhit())
			break;
	}
}
