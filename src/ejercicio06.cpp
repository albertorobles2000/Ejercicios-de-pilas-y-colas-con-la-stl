/*
7. Implementa una funci´on insertar(P, pos, x) que inserte un elemento en una pila P en la posicion pos. 
La pila debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/

#include <iostream>
#include <stack>
using namespace std;

template<typename T>
void insertar(stack<T> &pila,unsigned pos, T x){ // Voy a suponer que la posicion 0, esta el primer elemento que se metio en la pila
	if(pos<pila.size()){								// y en la posicion pila.size()-1 el ultimo que se metio en la pila
		unsigned n = pila.size() - pos;
		stack<T> auxiliar;												
		for (unsigned i=0; i<n; i++){
				auxiliar.push(pila.top());
				pila.pop();
		}
		
		pila.push(x);
		
		for (unsigned i=0; i<n; i++){
				pila.push(auxiliar.top());
				auxiliar.pop();
		}
		
	}
}

int main(){
	stack<int> pila;
	for (int i=0; i<10; i++){
		cout << i << " " ;
		pila.push(i);	
	}
	
	cout << endl;
	
	insertar(pila,3, 7);
	
	while(!pila.empty()){
		cout << pila.top() << " " ;
		pila.pop();	
	}
	
	cout << endl;
}
