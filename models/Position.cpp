#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Position.h"
#include "../utils/IConst.h"

using namespace std;

void Position::reset(){
	srand(time(NULL));
	this->x = (rand() % POSS_A_NODES);
	srand(time(NULL));
	this->y = (rand() % ALL_NODES);
	srand(time(NULL));
	this->z = (rand() % ALL_NODES);
}

// Recibe el arco que se utilizo en el movimiento
// Dependiendo del arco y del valor del atributo se cambia el valor
void Position::chgValue(short int pValue){
	switch(pValue){
		case ARK_X1:
			if(this->x == NODE_X0){
				this->x = NODE_X1;
				break;
			}
			this->x = NODE_X0;
			break;
		case ARK_X2:
			if(this->x == NODE_X1){
				this->x = NODE_X2;
				break;
			}
			this->x = NODE_X1;
			break;
		case ARK_Y1:
			if(this->y == NODE_Y0){
				this->y = NODE_Y1;
				break;
			}
			this->x = NODE_Y0;
			break;
		case ARK_Y2:
			if(this->y == NODE_Y1){
				this->y = NODE_Y2;
				break;
			}
			this->y = NODE_Y1;
			break;
		case ARK_Z1:
			if(this->z == NODE_Z0){
				this->z = NODE_Z1;
				break;
			}
			this->z = NODE_Z0;
			break;
		case ARK_Z2:
			if(this->z == NODE_Z1){
				this->z = NODE_Z2;
				break;
			}
			this->z = NODE_Z1;
			break;
	}
}

short int Position::getX(){
	return this->x;
}

short int Position::getY(){
	return this->y;
}

short int Position::getZ(){
	return this->z;
}
