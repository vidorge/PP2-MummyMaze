#ifndef _maze_solve_h
#define _maze_solve_h


/* makrooi za proveru statsa clanova glavne matrice */

#define jeZid(char A ) ( A & 0x01)
#define jeHint (char A )	(A & 0x02)
#define jeCovek(char A ) (A & 0x04)

int menhetenDuzina (int kordinataX1, int kordinataY1 , int kordinataX2, int kordinataY2 );
typedef struct{
	elemStablo **nizElem; 
	char status;
	int i,j;
} elemStablo; 

typedef struct{
	int	menDuz;
	elemStablo *info;
	elemPrioRed *sled;


} elemPrioRed;


#endif