#include <stdio.h>
#include <windows.h>

#include "colors.h"
#include "position_cursor.h"
#include "background.h"
#include "screen_resolution.h"

void header () {
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
}

void backgroundImage (int whichTime) {

	int i, j;

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
		
			header();
			break;
		}	//welcome end
		
		case MENU: {
			changeColor(GROUND);
			system ("CLS");
			changeColor(GROUND);

			positionCursor(0,15);
			printf ("                                                    R##V#=;.# WM # i:#X##X                                                  \n"
					"                                                ;##i    #  ;, ## ;,  #    i##;                                              \n"
					"                                              :#W       # ## ,   .#R #       W#:                                            \n"
					"                                             W#         # :, M  R  = #         ##                                           \n"
					"                                            #B          #    #  #    #          X#                                          \n"
					"                                           WY           M.           #           t#                                         \n"
					"                                          =#             #          M             #+                                        \n"
					"                                          #              #          #              #                                        \n"
					"                                         #W:              #        #              ;M#                                       \n"
					"                                        Y#   =#W+         BR    = =:         t##I.  #R                                      \n"
					"                                        #        ,M#,      #    # R      ,#M:        #                                      \n"
					"                                        #            M#   . #  Y.#     WR            #                                      \n"
					"                                        #              =#  Xt: ##    #,              #                                      \n"
					"                                        W#####R.         YB ## #   +;         .R######                                      \n"
					"                                         ;#Y    .Y#;       # #+B  W       :#V.    X#=                                       \n"
					"                                          #I#  Vi.  VM      ###  #      RR  .==  #+#                                        \n"
					"                                          #, #, B####:Vt     ## M     iV,####B..# #W=,                                      \n"
					"                              i##Bt=;;+YB#  # XI  #####.#    ## R    #.#####. tB #  #BI+;;=IB##+                            \n"
					"                           :##V.         #  .# ,#  #####t#    ##    #i#####  #. #   #          R##.                         \n"
					"                       Y#R:  :MiiVW#t    ##  ;#  RM  ;i:  #   #X   #  :t;  MX  #   X#   .R#WY:tM, .=B#V                     \n"
					"                  iI .##I        XR   #= # #,  #   .###R   I  #   #   R###    #   # # B#   X#        B##. it                \n"
					"                 ;.   , W+#R       .#   R:#,=#I =W:  XM#   Mt #  IW   WWX  :M= V#;,#+B   #Y       R#tW      +               \n"
					"                :#      W#. +#i      .#   # ##WR##:   ;M+# # #Wt# # #=W    ,##IB## #   #B      =#= .#W      #:              \n"
					"               #.#       i#  M t#.     #;  #    W,#  X#W # # :  i # # B#X  #:W    #  :#     .#I R  #i       # #             \n"
					"        #WVV#Bii;# M#t. .X###     ##.   IV  # :    #t   #V #  YI  # V#   X#    + #  Y+   .##     ###X. .I#+ #,iI##VtM#      \n"
					"       R;     B  XM     VW##      # ,R#R:.#  # # t #    ##############    # ; # M  # ,B#R,.#      ##WV     R+  M     .B     \n"
					"       #       #  Vi +W    Y#     #    B :V#MM#WM  #,  #  ##########  #  .#  MM#MB#V: W    I     #i    Wi =B  #       #     \n"
					"      X        I   i#      W #Y   #    M   #    #. R##:   ##########   ;#RB  #    #   W    #   V# B      ##   Y        R    \n"
					"      #        #i   #    ,X  ;#   W    #  ;     Y# ;=    #+  X  B ::#    :; #Y     i  +    W  .#:  Y:    #   =#        #    \n"
					"     Bi  X#####    #;# i#   :+#. #    #   #      #, #  tR  ########  MI  # .#      #   #    # .#;;   #t #=#    #####R  :W   \n"
					"     X#Y      #XY,   #R#i=Y#;#i #    M   #M#:  tX#   B#MI=+W      #+;iM#V   #XM, ,#M#   W    # i#=#Y;I#R#   :VXW      t#X   \n"
					"      #,       #t   #          #   Y:   #+W      #,       .X######X.       .#      ,,W   =X   #:        .#   t#       .#    \n"
					"       #      # #VM+         #+   #    # #       #                          #       # M    #   ;#         =WV# #      #     \n"
					"      #VW    #    #        #i   B:    # ##       M.iW##WXi:       .:iXW##Wi.R       ## #   ..W   ;#.       # .  #    #I#    \n"
					"     #   #  R:  W W     t#.   ;W    iMMM .B     B;                          ;W     B, BMX.    V:   .#V     W #  .B  #   #   \n"
					"    #tWIiR### :X:#,  ,#;   X=#WM#B####,W,,#M#WR#M         :I=::==it:         M#RW#MW,,W,BW##W##W#=X   ;#   .#=t; ###RiYWt#.#\n"
					"    #      .#:.    WI      V#        #Y#=                                            =#Y#        #V      Yt    .,#,,     M#i\n"
					"    I  :B +#X YBV#      I#+#          #B                 ,iB######Bt,                 B#          #+#V     .#VRY +#t M:  =i \n"
					"    #  M   :IW;  ####B ,M#Y           YX             V#M.             X#V             tt          .i#B,.B####. iBW:  .X  #  \n"
					"    #.R    #  :#                       #:         RW,                    .MR         =#                       #=  #    B,#  \n"
					"    t#.   # .  #                        #      ;#                            #:      #                        #.  .#    #;  \n"
					"       Y###,#Y#                         :R   RR              :It.              VR   X=                         #Y#;###V     \n"
					"                                         Bt#=              #B.  ;#W              :#+M                                       \n");

			header();

			break;
		}	//menu end

		case TEXT: {
			changeColor(GROUND);
			system ("CLS");
			changeColor(GROUND);

			header();
			changeColor(MENUC);

			for (i=TOP;i<BOTTOM;i++) {
				positionCursor(5,i);
				printf ("                                                                                                                   ");
			}
			break;
		}	//text end
			
	}		//switch end

}