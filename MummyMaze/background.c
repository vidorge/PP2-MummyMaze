#include <stdio.h>
#include <windows.h>

#include "colors.h"
#include "position_cursor.h"
#include "background.h"

void backgroundImage (int whichTime) {

	int i;

	switch (whichTime) {
		case WELCOME: {
			changeColor(14);
			system ("CLS");
			changeColor(14);
		
			positionCursor(0,15);
			printf ("                                                                    .o@@8@@@@@.\n"
					"                                                                  oOcooCoO8@@@@O\n"
					"                                                               c@8co    :ccccooCo:\n"
					"                                                             :8o cCOCocCCCCCooCO8Oo:\n"
					"                                                             8o .:oc  .c8@@c.   ::.CC\n"
					"                                                              .@@co      o@      o:\n"
					"                                                               .cc::COO..:@@O@@@8:.C\n"
					"                                                                 Coocc   :CCoO8OCo:.:     c:\n"
					"                                                             c88::..    :. :o8OOo: .@8o@o:.c\n"
					"                                                         c8O88OO.co  .:::.:.::OOCc. Oc888oc::O:\n"
					"                                :. .:         ..:oO8oc.cC88OCCoc: Cc  . .:..  .coCc .ooc.  c@OOOccOo\n"
					"                                 o@cc       O@OO8888COCCo.::c:::. :..:cooCoO@8CCCc. :::..o8OO8OCcC@@OOc\n"
					"                                  c.c    .cO8@8oOCcO8Cc:ccoCoc::. :o .   :Cooc... . .:co:::::oO@@@@8Co:.\n"
					"                                  co   .8@OO@88ooocoo:.:::          :o. :Coooc:...:.. .:oC@@@@@@@@8OCoC:C.\n"
					"                                  c8..C@@8@oOCCO:::ooCo:.   ..::...  ..::ccc:      :cooO888888888Ooc.COco.\n"
					"                                    C@:O@88OO:Co.c:..:coCCooooc::.             .::coCCooccccooO88Ooc:ocooC\n"
					"                                   .oC@O:coc:c..   .. . ......::coocooc:c:c:.:oCOOOOOOOCCoCCoooccocc.cco.\n"
					"                                     .oO8OCC:::.:::.:cCO8888OCoo::::.      .cooooCCOOCCoccCOCoocCCcc.oc :\n"
					"                                  OCcOo: .         .::.::coCCCCCCooccc::::.          ..::...:oOOCo::.  :\n"
					"                         :..ccccc.             .   .. ...::::::.....:.::::ccc::coc:.:ccooc::....       .:::cc:.\n"
					"                           :::ooCCC:             .:     ..   ....::....::::::::cccccc:.....::.       :.   ..::c..\n"
					"                          .:::cccccco:              .:            .    .....:::cooCCoooc::..        ..:c:.cooo::.\n"
					"                        c  ..ccoCc:::.:         c:       .  ......::..::..........:::ccc....        c:.  .:c:.:c.\n"
					"                      ...cc..:coooc::::            :.         .     ...         ......:c.  ..       ::Ccccocccoc.\n"
					"                      .. ccccoOOO8Coc:.              .          ..::::::.::::::ccccc:.  :..:         c::oO88Cc.c.\n"
					"                      ..    .cO@@OO:c                   ....          .    .     ..  :o: .::.        co::cCocc:.\n"
					"                          .oCoCOOCo.              .                         .::. .:::.. :c:          . C8@@8:::\n"
					"                        :.   :Co::c                  ::::::.           ......:....:....o: c.         .CCCCCOo:\n"
					"                       ..cOO:.:oc..                                ...      .::.   :oc..o:          .oOcooo8OC\n"
					"                       c8: :::oCoO8c             .    ..             ..::.    .:c.   :o:..:      :O@OCocoCOOCO\n"
					"              c888:  .O: cCcccoO8OOOO8Oc                 .......         ..      .cc.  . .     :8@Oo.   ..C@@Oc8O\n"
					"                  :CCc  ..:oooCOCccoo:8O                                      .::  : ...:c.    .CO       .coo.O@C\n"
					"                        :.:o: C8c    .:o.       .coc:.                        .   ..:c.coc      C.       O@@co8Oc\n"
					"                          :8c:O:       .C.     . .cc:  .::..                     :co.:Co:..              OC.o88:\n"
					"                         .:o.o8.       .     .    .::coCo.          .           coc.oCCc:c:.               ooo.c:\n"
					"                        ...:o:OC            ..  .::..::::...                .ccc::cCoc::CCc::           oOOC..c:\n"
					"                        :.c::c.oo.             :oOOOOOCCCo. .            .c::c:..c:::cOO::Cc               :Cc...  \n"
					"                             .:.:c.         :OOc..:::cooCCcc:cc::.   .    .:: ...:.:Oco@8C::.            :: .::.  n"
					"                                          :Cc     .coCCococ:::: ...           . .ccc8888OCOoc");
		
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
			break;
		}	//welcome end
		
		case MENU: {
			changeColor(GROUND);
			system ("CLS");
			changeColor(GROUND);

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
			break;
		}	//menu end

		case TEXT: {
			changeColor(GROUND);
			system ("CLS");
			changeColor(GROUND);

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
			changeColor(MENUC);

			for (i=TOP;i<BOTTOM;i++) {
				positionCursor(5,i);
				printf ("                                                                                                                   ");
			}
			break;
		}	//text end
			
	}		//switch end

}