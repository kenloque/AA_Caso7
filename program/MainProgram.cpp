#include <iostream>
#include "../logic/PasswordMaker.cpp"
using namespace std;

int main(){
	PasswordMaker* maker = new PasswordMaker();
	char answr;
	short int contTry = 0;
	while(true){
		contTry++;
		maker->makePassword();
		maker->password.print();
		do{
			cout << endl << "Funciona? (s/n) ";
			cin >> answr;
			switch(answr){
				case 's':	
					cout << "Cantidad de intentos: " << contTry << endl;
					return 0;
				case 'n':	break;
				default: break;
			}
		}while (answr!='n');
	}
}
