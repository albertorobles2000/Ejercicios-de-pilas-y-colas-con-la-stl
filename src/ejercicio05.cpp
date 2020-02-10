/*
6. Se llama expresion en postfijo a una expresion matematica en la que cada operacion aparece con sus dos operandos seguidos 
por el operador. Por ejemplo: 2 3 + 5 * Escribe un programa que evalue una expresion en postfijo.
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

long opera(string operacion, stack<long> & pila){
		long op2 = pila.top(); 
		pila.pop();
		long op1 = pila.top(); 
		pila.pop();
		long result;
		
		if(operacion == "+")
			result = op1 + op2;
		else{
			if(operacion == "-")
				result = op1 - op2;
			else{
				if(operacion == "*")
					result = op1 * op2;
				else{
					if(operacion == "/")
						result = op1 / op2;
					else{
						if(operacion == "^"){
							result = pow(op1,op2);
						}
					}
				}
			}
		}
		
		return result;
}


long post_fijo(queue<string> &cola){
	stack<long> pila;
	long result;
	
	while(!cola.empty()){
	
		if(cola.front() == "+" || cola.front() == "-" || cola.front() == "*" ||
		   cola.front() == "/" || cola.front() == "^"){
		   
		   pila.push(opera(cola.front(), pila));
		}
		else{
			pila.push(atoi((cola.front()).c_str()));
		}
		cola.pop();
	}
	result = pila.top();
	pila.pop();
	return result;
}

int main(){
	queue<string> cola;
	string cadena;
	cout << "Introduzca cada operando y operadores separados por 'enter' " << endl;
	cout << "Escriba 'fin' para terminar" << endl;
	getline(cin,cadena);
	while(cadena != "fin"){
		cola.push(cadena);
		getline(cin,cadena);	
	}
	
	cout << "Resultado: " << post_fijo(cola);
}
