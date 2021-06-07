#include <iostream>
#include "Password.h"
using namespace std;

void Password::addChar(char pChar){
	value[lastChar] = pChar;
	lastChar++;
}

void Password::print(){
	cout << "Password: ";
	for(int contChar = 0; contChar < lastChar; contChar++){
		cout << value[contChar];
	}
	cout << endl;
}
