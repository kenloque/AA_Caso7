#ifndef POSITION_H_
#define POSITION_H_

/*
	Abstracción del movimiento por los nodos
	Se basa en posiciones de los 3 ejes
*/

class Position {
public:
	void reset();
	void chgValue(short int pValue);
	short int getX();
	short int getY();
	short int getZ();
private:
	short int x;
	short int y;
	short int z;
};

#endif
