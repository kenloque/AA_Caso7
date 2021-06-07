#include "PasswordMaker.h"
#include <utility>
#include <deque>

PasswordMaker::PasswordMaker(){
	probTable  = ProbTable();
}

void PasswordMaker::makePassword(){
/*
	Se reinicia la posicion y la contrasenia cada vez que se llama la funcion
	La posicion restringe quienes son tomados en cuenta para el random
	Dependiendo del ultimo elegido solo se toman en cuenta los mayores
	Se suman las posibilidades de los restantes
	Se elige uno de manera aleatoria
	Se encuentra el char de este
	Se agrega a la contraseña
	Se actualiza el ultimo usado y la posicion
	Se repite hasta que ya no hayan mas
*/
	position.reset();
	password = Password();
	int lastChar = LAST_CHAR_USE;
	while(true){
		deque<pair<int, int>> probList;
		switch(position.getX()){
			case NODE_X0:
				if(lastChar<ARK_X1) probList.push_back(pair<int, int> (ARK_X1, probTable.get(ARK_X1)));
				break;
			case NODE_X1:
				if(lastChar<ARK_X1) probList.push_back(pair<int, int>(ARK_X1, probTable.get(ARK_X1)));
				if(lastChar<ARK_X2) probList.push_back(pair<int, int>(ARK_X2, probTable.get(ARK_X2)));
				break;
			case NODE_X2:
				if(lastChar<ARK_X2) probList.push_back(pair<int, int>(ARK_X2, probTable.get(ARK_X2)));
				break;
		}
		switch(position.getY()){
			case NODE_Y0:
				if(lastChar<ARK_Y1) probList.push_back(pair<int, int>(ARK_Y1, probTable.get(ARK_Y1)));
				break;
			case NODE_Y1:
				if(lastChar<ARK_Y1) probList.push_back(pair<int, int>(ARK_Y1, probTable.get(ARK_Y1)));
				if(lastChar<ARK_Y2) probList.push_back(pair<int, int>(ARK_Y2, probTable.get(ARK_Y2)));
				break;
			case NODE_Y2:
				if(lastChar<ARK_Y2) probList.push_back(pair<int, int>(ARK_Y2, probTable.get(ARK_Y2)));
				break;
		}
		switch(position.getZ()){
			case NODE_Z0:
				if(lastChar<ARK_Z1) probList.push_back(pair<int, int>(ARK_Z1, probTable.get(ARK_Z1)));
				break;
			case NODE_Z1:
				if(lastChar<ARK_Z1) probList.push_back(pair<int, int>(ARK_Z1, probTable.get(ARK_Z1)));
				if(lastChar<ARK_Z2) probList.push_back(pair<int, int>(ARK_Z2, probTable.get(ARK_Z2)));
				break;
			case NODE_Z2:
				if(lastChar<ARK_Z2) probList.push_back(pair<int, int>(ARK_Z2, probTable.get(ARK_Z2)));
				break;
		}
		if(probList.size()==0) return;
		
		int sumProb = 0;
		for(int contArks = 0 ; contArks < probList.size() ; contArks++){
			sumProb += probList.at(contArks).second;

		}
		srand(time(NULL));	// Semilla aleatoria
		int selection = rand() % sumProb + 1;	// Seleccionar una probabilidad
	
		// Buscar el char usado
		sumProb = 0;
		for(int contArks = 0 ; contArks < probList.size() ; contArks++){
			sumProb += probList.at(contArks).second;
			// Ver si esta en las probabilidades correctas
			if(selection<=sumProb){
				short int arkUsed = probList.at(contArks).first;
				probTable.use(arkUsed);
				password.addChar(possChars[arkUsed]);
				lastChar = arkUsed;
				position.chgValue(arkUsed);
				break;
			}
		}
	}
}
