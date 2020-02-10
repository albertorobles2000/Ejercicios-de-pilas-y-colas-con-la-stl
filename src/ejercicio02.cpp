/*
2. Implementa un funcion para determinar si una expresion contenida en un string tiene 
una configuracion de parentesis correcta. Debe tener un orden lineal
*/

#include <iostream>
#include <queue>
using namespace std;

bool Parentesis_Correctos(string mensaje){
	queue<char> parentesis;
	for(unsigned i=0; i<mensaje.size(); i++){
		if(mensaje[i] == '(' || mensaje[i] == ')')
				parentesis.push(mensaje[i]);
	}
	
	int contador = 0;
	while(!parentesis.empty() && contador >= 0){
		if(parentesis.front() == '(')
			contador++;
		else
			contador--;
		parentesis.pop();	
	}
	
	return contador == 0;
}

int main(){
	string correcto = "(12+(2-3)*(5/4))/(12*3)";
	string incorrecto = "(12*3))(-12)";
	string incorrecto2 = "(1+2)+(3";
	
	if (Parentesis_Correctos(correcto)){
		cout << "El string " << correcto << " tiene una configuracion de parentesis correcta" <<endl;	
	}
	else
		cout << "El string " << correcto << " tiene una configuracion de parentesis incorrecta" <<endl;
		
	if (Parentesis_Correctos(incorrecto)){
		cout << "El string " << incorrecto << " tiene una configuracion de parentesis correcta" <<endl;	
	}
	else
		cout << "El string " << incorrecto << " tiene una configuracion de parentesis incorrecta" <<endl;
		
	if (Parentesis_Correctos(incorrecto2)){
		cout << "El string " << incorrecto2 << " tiene una configuracion de parentesis correcta" <<endl;	
	}
	else
		cout << "El string " << incorrecto2 << " tiene una configuracion de parentesis incorrecta" <<endl;
}
