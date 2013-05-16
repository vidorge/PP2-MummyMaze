#ifndef _maze_create_h
#define _maze_create_h







#endif


/*

Depth-First Search:

1. Izabrati ćeliju i označiti je kao izlaz,
2. Označiti trenutnu ćeliju kao „posećena“,
3. Ako ćelija ima neposećenih komšija:
	1) Slučajno odabrati jednog od komšija,
	2) Staviti trenutnu ćeliju na stek,
	3) Skloniti zid između trenutne ćelije i izabrane ćelije,
	4) Izabranu ćeliju napraviti trenutnom ćelijom,
	5) Rekurzivno pozivati ovu funkciju, 

4. Ako nema:
	1) Skinuti poslednju ćeliju sa steka,
	2) Vratiti se na prethodno pozivanje ove funkcije. 

*/