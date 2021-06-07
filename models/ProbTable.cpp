#include "ProbTable.h"

ProbTable::ProbTable(){
	this->arks[ARK_X1] = FULL_PROB;
	this->arks[ARK_X2] = FULL_PROB;
	this->arks[ARK_Y1] = FULL_PROB;
	this->arks[ARK_Y2] = FULL_PROB;
	this->arks[ARK_Z1] = FULL_PROB;
	this->arks[ARK_Z2] = FULL_PROB;
}

// Navega por un arco afectando todas las probabilidades
void ProbTable::use(short int pArk){\
	this->arks[pArk] -= USE_PENALIZATION;
	for(int contArks = 0 ; contArks < MAX_ARKS ; contArks++){
		this->arks[contArks] += USE_CONSOLATION;
	}
	// Se repasa la lista para corregir numeros negativos
	// Es mas efectivo que solo ignorarlos
	for(int contArks = 0 ; contArks < MAX_ARKS ; contArks++){
		if(this->arks[contArks] < 0){
			this->arks[contArks] = 0;
		}
	}
}

short int ProbTable::get(short int pArk){\
	return this->arks[pArk];
}
