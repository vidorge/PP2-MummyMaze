#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "position_cursor.h"
#include "colors.h"
#include "background.h"


void startAnimation () {

	//***debug**mode****on/off****
	int DEBUGGING=FALSE;
	//****************************
	
	int blink=0;

	changeColor(ARROW);
	system ("CLS");
	changeColor(ARROW);
	positionCursor(50,20);
	
	printf ("RESIZE WINDOW TO FULL SCREEN                       \n"
			"                                                   \n"
			"    -/++/-`                                       \n"
			"  `syyhhhhho.                                     \n"
			" `/yyyyhhhhhho-                                   \n"
			" :hsoyyyyhhhhhhs:                                 \n"
			" :ddmsoyyhhhhhhhhy/`                              \n"
			"  :hmmmyoshhhhhhhhhh/`                            \n"
			"    :ymmmhoshhhhhhhhdh+.                          \n"
			"      -smmmhoohhhhhhddddo.                        \n"
			"        .odmmdoohhhhhhhddds-                      \n"
			"          `+ddddsoyhhhhhhddhy:                    \n"
			"            `/hdddsoyhhyhhddddh/`        `        \n"
			"               :yddhsoyhhhhdddddh+`   `:sd-       \n"
			"                 -sdhhyoshhhhddddddo/sdmmmy       \n"
			"                   -shhhyoshdddddddddddmmmm:      \n"
			"                    `.+hhhyoohdddddddddmmmmh`     \n"
			"                       `/sooydddddddddmmmmmm+     \n"
			"                      ``/ydddddddddddddmmmmmd`    \n"
			"                      yysosssshddddddddddmmmms    \n"
			"                     -hhhhhhhysosssshdddddmmmm-   \n"
			"                      `-:+oyhhhhhhhhsosssshdmmy   \n"
			"                            `.:/oshhhhhhhhyssss-  \n"
			"                                   .-/+syhhhhhhy` \n"
			"                                         `-:+oy+ ");
	if (!DEBUGGING) Sleep(3200);

	changeColor(ETF);
	system ("CLS");
	changeColor(ETF);
	positionCursor(0,7);
	printf ("                                    ``.-:://+oosssyyyyyyyysso++/:.`                              \n"
			"                                +dmNNNNMMMMMMMNNNmdddhhhyyyyyyyyhhhhyo:.                         \n"
			"                                .NMMMMyo+/:-..``````              ````.-//`                      \n"
			"                                 +MMMMh          .--://++oosssyyyyyys.   -so.                    \n"
			"                                  dMMMM+         :NNMMMMMMMMMMMMMMNNNd-    :do`                  \n"
			"                                  -MMMMN.         odhhyso++oMMMN/-.````     `..                  \n"
			"                                   yMMMMh          ``   `:ohMMMMNNmmho:.                         \n"
			"                                   .NMMMM/            `omNMMdmMMMMyoyhmNh+.    `os-              \n"
			"                                    oMMMMm`          /mMMmo-`-NMMMm. ``-odms-   -mN/             \n"
			"                                    `mMMMMo         +NMMs.    +MMMMh`    `/dNs`  -mN/            \n"
			"                                     +MMMMN.       -NMMo       yMMMMo      `+Nd-  :NN/           \n"
			"                                     `mMMMMy       yMMm`       .mMMMN-``.--:/hMNssyNMN:          \n"
			"                                      +MMMMN-      mMMy     `.--yMMMMNdmmNNMMMMMMMMMMMm.         \n"
			"                                      `mMMMMh      mMMd/oshdmmNNMMMMMMMMMMMMMMMMMNhyomMh`        \n"
			"                                       +MMMMM/:/oshNMMMMMMMMMMMMMMMMMMMNmdhyo+:+MN.  :NM+        \n"
			"                                       `mMMMMMMMMMMMMMMMMMMMMNmmdydMMMMd.`     -MM-   yMN.       \n"
			"                                        +MMMMMMMMMNNNMMMmso/:-.`` .NMMMM:      +MM.   .NMs       \n"
			"                                        `NMMMMNs+:-..dMMm:         sMMMMh     .mMd     oho       \n"
			"                                         oMMMMM-     .hMMNo.       .NMMMM-   -dMN-               \n"
			"                                         .NMMMMy      `omMMmo-`     yMMMMy .omMm/                \n"
			"                                          sMMMMM.       .smMMNhs/-.`:MMMMMhNMNy-        `-+.     \n"
			"                                          .NMMMMs         .+hNMMMNNmdMMMMMMms:          .NM+     \n"
			"                                           yMMMMN.           .:oyhdmmmMMMMh...:+sh+      mMy     \n"
			"                                           -MMMMMo                 ``.dMMMNdmNMMMMh      hMd     \n"
			"                                            hMMMMm`          ``.-/oyhmMMMMMMMMMNmds      yMd     \n"
			"                                            /MMMMM/          smNMMMMMMMMMNmdyo/-`     ``:hMd     \n"
			"                                            `mMMMMh          +MMMMNNmdy+/-`       `./shmMMNy     \n"
			"                                             oMMMMN.         .dyo/:.`       ``-/shmMMMMNds:`     \n"
			"                                             .NMMMMo                  ``.:oydNMMMMMNds/.         \n"
			"                                              yMMMMm            ``-/oydmMMMMMMNmho:.             \n"
			"                                              :MMMMM-    ``.:+shdNMMMMMMNNmyo/.                  \n"
			"                                              `mMMMMy/+shmNMMMMMMMNNmhs/:.                       \n"
			"                                               oMMMMMMMMMMMMNNdyo/-`                             \n"
			"                                               .MMMMMMNdhs+:.`                                   \n"
			"                                                sso/-.                                           \n");
	if (!DEBUGGING) Sleep(2000);

	changeColor(GROUND);
	system ("CLS");
	changeColor(GROUND);
	positionCursor(0,13);
	printf ("                                     ______ _          ______                  _      \n"
			"                                    / _____|_)_       / _____)                (_)_    \n"
			"                                   | /  ___ _| |_    | /      ___  ____  ____  _| |_  \n"
			"                                   | | (___) |  _)   | |     / _ \\|    \\|    \\| |  _) \n"
			"                                   | \\____/| | |__   | \\____| |_| | | | | | | | | |__ \n"
			"                                    \\_____/|_|\\___)   \\______)___/|_|_|_|_|_|_|_|\\___)\n"
			"                                                                                          \n"
			"                                                _______ _______        ______           \n"
			"                                              (_______|_______)  /\\  |  ___ \\          \n"
			"                                               _       _____    /  \\ | | _ | |         \n"
			"                                               | |     |  ___)  / /\\ \\| || || |         \n"
			"                                               | |_____| |_____| |__| | || || |         \n"
			"                                                \\______)_______)______|_||_||_|         \n");
	positionCursor(50,27);
	printf ("---PRESENTS YOU---");
	if (!DEBUGGING) Sleep(2000);

	system ("CLS");

	backgroundImage(1);
	
	if (!DEBUGGING) 
		while (1) {		
			switch (blink) {
				case 0:{positionCursor (50,40);printf ("  -- Press any key --  ");Sleep(500);blink=1;break;}
				case 1:{positionCursor (50,40);printf ("                       ");Sleep(500);blink=0;break;}		
			}

			if(_kbhit()) {
				positionCursor (50,40);
				printf ("                       ");
				break;
			}
		}

	backgroundImage(2);
}