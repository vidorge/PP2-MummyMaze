#ifndef _colors_h
#define _colors_h

//*****************
//Predefined Colors
//*****************

//Background color for menu
#define GROUND	224

//Color of unactive menu cell
#define MENUC	96

//Color of active menu cell
#define MENUA	14

//Start animation colors
#define ETF		79
#define ARROW	14

//Options
#define DROPUNACTIVE 126

//Wall colors

	//light
	#define LIGHTWALL	120
	#define LIGHTBLANK	102
	#define LIGHTPLAYER	111
	#define LIGHTMUMMY	110

	//dark
	#define DARKWALL	3
	#define DARKBLANK	51
	#define DARKPLAYER	63
	#define DARKMUMMY	62


void changeColor (int color);

#endif