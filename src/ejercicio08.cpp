/*
10. Usando una pila y una cola, implementa una funcion que compruebe si un string es un palindromo.
*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool es_palindromo(string n){
	int mitad = n.size()/2;
	queue<char> cola;
	stack<char> pila;
	
	for(int i=0; i<mitad; i++){
		cola.push(n[i]);
	}
	cout << endl;
	for(unsigned i=mitad; i<n.size(); i++){
		pila.push(n[i]);
	}
	cout << endl;
	bool es_palindromo = true;
	while(!cola.empty() && !pila.empty() && es_palindromo){
		if(cola.front() == pila.top()){
			cola.pop();
			pila.pop();
		}
		else
			es_palindromo = false;
	}
	
	return es_palindromo;
}

int main(){
	
	string s="ABCECBA";
	string c="ABFECBA";
  	
  	if(es_palindromo(s))
  		cout << s << " es palindromo" << endl;
	else
		cout << s << " no es palindromo" << endl;
		
	if(es_palindromo(c))
  		cout << c << " es palindromo" << endl;
	else
		cout << c << " no es palindromo" << endl;
	
	
	
}
