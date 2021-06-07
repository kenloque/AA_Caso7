#ifndef PROBTABLE_H_
#define PROBTABLE_H_
#include "../utils/IConst.h"

/*
	Abstracción de los arcos con sus probabilidades
	Se toman los 9 arcos que poseen el mismo valor como uno solo
*/

class ProbTable {
public:
	ProbTable();
	void use(short int pArk);
	short int get(short int pArk);
private:
	short int arks[MAX_ARKS];
};

#endif
