#ifndef PASSWORDMAKER_H_
#define PASSWORDMAKER_H_
#include "../utils/IConst.h"
#include "../models/Password.cpp"
#include "../models/Position.cpp"
#include "../models/ProbTable.cpp"

/*
	Abstracción de la clase creadora de contraseñas
	Utiliza una secuencia de chars
	Estos deben ir en orden de prioridad, en el caso de la tarea:
		1-2-A-B-F-K
*/

class PasswordMaker {
public:
	Password password;

	PasswordMaker();
	void makePassword();
private:
	Position position;
	ProbTable probTable;
	char possChars[MAX_CHAR_AMOUNT] = HW_CHAR_USE;
};

#endif
