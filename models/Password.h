#ifndef PASSWORD_H_
#define PASSWORD_H_

#include "../utils/IConst.h"

/*
	Abstracción de una contraseña
	Es un arreglo de caracteres
*/

class Password {
public:
	void addChar(char pChar);
	void print();
private:
	char value[MAX_CHAR_AMOUNT];
	short int lastChar;
};

#endif
