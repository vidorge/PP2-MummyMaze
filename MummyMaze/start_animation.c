#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "controls.h"
#include "position_cursor.h"
#include "colors.h"


void startAnimation () {
	
	int DEBUGGING=FALSE;

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
	printf ("---PRESENT YOU---");
	if (!DEBUGGING) Sleep(2000);

	system ("CLS");		

	positionCursor(0,1);
			printf ("           __    __    __    __    __    __     __    __    __  __      __    __     _____    _____       _____  \n"
			"          /_/\\  /\\_\\  /\\_\\  /_/\\  /_/\\  /\\_\\   /_/\\  /\\_\\ /\\  /\\  /\\   /_/\\  /\\_\\   /\\___/\\  /\\____\\     /\\_____\\ \n"
			"          ) ) \\/ ( ( ( ( (  ) ) ) ) ) \\/ ( (   ) ) \\/ ( ( \\ \\ \\/ / /   ) ) \\/ ( (  / / _ \\ \\ \\/_ ( (    ( (_____/ \n"
			"         /_/ \\  / \\_\\ \\ \\ \\/ / / /_/ \\  / \\_\\ /_/ \\  / \\_\\ \\ \\__/ /   /_/ \\  / \\_\\ \\ \\(_)/ /    \\ \\_\\    \\ \\__\\   \n"
			"         \\ \\ \\\\// / /  \\ \\  / /  \\ \\ \\\\// / / \\ \\ \\\\// / /  \\__/ /    \\ \\ \\\\// / / / / _ \\ \\    / / /__  / /__/_  \n"
			"          )_) )( (_(   ( (__) )   )_) )( (_(   )_) )( (_(   / / /      )_) )( (_( ( (_( )_) )  ( (____( ( (_____\\ \n"
			"          \\_\\/  \\/_/    \\/__\\/    \\_\\/  \\/_/   \\_\\/  \\/_/   \\/_/       \\_\\/  \\/_/  \\/_/ \\_\\/    \\/____/  \\/_____/ \n");
	
	positionCursor(0,9);
	changeColor(MENUC);
	printf(":/++++///////:::::::/::::::::-------:---:--::::::--------....-----.--:---:------::/-----------------::/::::-----.:---:-:::://\n");
	
	changeColor(GROUND);
	positionCursor(0,11);
	printf ("                                                                   G.                                                  \n"
			"                                                                1L G G                                                 \n"
			"                                                             .G    C   G                                               \n"
			"                                                           L.     ,;    .G                                             \n"
			"                                                        ,i        i.      .G                                           \n"
			"                                                    i. f          C         .G                                         \n"
			"                                                 t.      ;        G           .G                                       \n"
			"                                              f.         t        G             .G:,                                   \n"
			"                                           L             C        G     .itfCGGGG   .1                                 \n"
			"                                        C               tfGG:     f    G         1.    L                               \n"
			"                                     L                 G        L :  i             f     C                             \n"
			"                                 .L                 .;           GGC               L  t.   C                           \n"
			"                              .L               ;.                G                 L      t  f.                        \n"
			"                           ,f             ,fL         i          f                 L           1:                      \n"
			"                        ,t                 i           .        .,                 ;            .,t                    \n"
			"                     ;1                                1        t                              Cf.,.L                  \n"
			"                  ii                                  1         C                            .. ;  C  G                \n"
			"               t:                                    1          G                            .  .       G              \n"
			"             ;f                                     1i          C                t..,        .  .   .     G.           \n"
			"                G.                                L   :         ;               . .  C       .  .   :       f:         \n"
			"                  .C                            L              ,.                     ,      ,  .   ;         it       \n"
			"                     t:                                        t               .      ;      ,  .   1           :L     \n"
			"                        G                                      G               .      t      ,  .   t             .G   \n"
			"                          :1                                   G               .      f      :  .   L               .G \n"
			"                             L.                                t               ,      GC:    :  .   L             1Gi  \n"
			"                               .f                              .               :      f  :.:,:  .   f         CG.      \n"
			"                                  1,                          .                i      i L :.  t .   f    iGi           \n"
			"                                     C                        f                t      :: :   . L.   1LC.               \n"
			"                                       :;                     G                f      ,        L    ;                  \n"
			"                                          f           .       G                L      .        C    :                  \n"
			"                                            .t       .        ;                C            1C.,t;C.                   \n"
			"                                               i.     ,       . ,      t       G       .Lf                             \n"
			"                                                  f.,        ,  f1            ,G       i                               \n"
			"                                                    ,:  1    L            1L.    i;:G;                                 \n"
			"                                                       f  ;  C ,     .Ci                                               \n"
			"                                                          iL.t:  ;C.                                                   \n"
			"                                                            ;Gi                                                        \n");
	if (!DEBUGGING) 
		while (1) {		
			switch (blink) {
				case 0:{positionCursor (50,40);printf ("  -- Press any key --  ");Sleep(500);blink=1;break;}
				case 1:{positionCursor (50,40);printf ("                       ");Sleep(500);blink=0;break;}		
			}

			if (_getch()!=NULL) positionCursor (50,40);printf ("                       ");break;
		}
}