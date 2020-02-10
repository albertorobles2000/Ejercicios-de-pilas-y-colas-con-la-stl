/*
8. Implementa una funcion insertar(Q, pos, x) que inserte un elemento en una cola Q en la posicion pos. 
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)
*/

#include <iostream>
#include <queue>

using namespace std;

template<typename T>

void insertar(queue<T> &cola, unsigned pos, T x){
	queue<T> aux;
	for(unsigned i=0; i<pos; i++){
		aux.push(cola.front());
		cola.pop();
	}
	
	aux.push(x);
	
	for(unsigned i=0; !cola.empty(); i++){
		aux.push(cola.front());
		cola.pop();
	}
	
	cola = aux;
}

int main(){
	queue<int> cola;
	for (int i=0; i<10; i++){
		cout << i << " " ;
		cola.push(i);	
	}
	
	cout << endl;
	
	insertar(cola,3, 7);
	
	while( !cola.empty() ){
		cout << cola.front() << " " ;
		cola.pop();	
	}
	
	cout << endl;
}
