/*1. Construye una funcion a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo T 
	   y que modifique la pila de forma que todas las veces que aparezca x se substituya por y 
		(quedando la pila en el mismo estado en el que estaba anteriormente). 
		Para este ejercicio no se podran utilizar iteradores.
*/

#include <iostream>
#include <stack>
using namespace std;

template<typename T>

void sustituye (stack<T> &pila, T x, T y){
	stack<T> aux;
	while(!pila.empty()){
		if(pila.top() == x){
			aux.push(y);
		}
		else{
			aux.push(pila.top());	
		}
		pila.pop();
	}

	
	while(!aux.empty()){
		pila.push(aux.top());
		aux.pop();
	}
}

int main(){
	stack<int> una;
	for(int i=0; i<20; i++){
		cout << i%2 << " ";
		una.push(i%2);
	}
	
	sustituye<int>(una,0,1);
	
	cout << endl;
	for(int i=0; i<20; i++){
		cout << una.top() << " ";
		una.pop();
	}
}
