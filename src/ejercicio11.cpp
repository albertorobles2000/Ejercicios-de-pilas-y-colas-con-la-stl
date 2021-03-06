/*
13. Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de caracteres 
que tengan mas vocales y que en caso de igualdad salgan por orden alfabetico.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int num_vocales(string s)
{
	int contador = 0;
	char letra;
	for (unsigned i=0; i<s.size(); i++){
		letra = s[i];
		if ( letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || 
			  letra == 'o' || letra == 'O' || letra == 'a' || letra == 'U' )
		{
			contador++;	  
		}
	}
	return contador;
};

class Cola_prioridad{
	private: 
		queue<string> cola1;
		queue<string> cola2;
	
	public:
		
		Cola_prioridad(){}
		
		Cola_prioridad(const Cola_prioridad & cola)
		{
			cola1 = cola.cola1;	
		}
		
		void operator = (const Cola_prioridad & otra)
		{
			cola1 = otra.cola1;
		}
		
		void push(string s)
		{
			int num_vocal = num_vocales(s);
			while(!cola1.empty() && num_vocales(cola1.front()) > num_vocal){
				cola2.push(cola1.front());
				cola1.pop();
			}
			
			while(!cola1.empty() && num_vocales(cola1.front()) == num_vocal && s > cola1.front()){
				cola2.push(cola1.front());
				cola1.pop();	
			}
			
			cola2.push(s);
			
			while(!cola1.empty()){
					cola2.push(cola1.front());
					cola1.pop();
			}
			
			while(!cola2.empty()){
					cola1.push(cola2.front());
					cola2.pop();
			} 
		}
		
		void pop()
		{
			cola1.pop();
		}
		
		string & front()
		{
			return cola1.front();	
		}
		
		string & back()
		{
			return cola1.back();	
		}
		
		bool empty() const
		{
			return cola1.empty();	
		}
		
		int size() const
		{
			return cola1.size();
		}
		
		bool operator < (const Cola_prioridad & otra)
		{
			return cola1 < otra.cola1;
		}
		
		bool operator == (const Cola_prioridad & otra)
		{
			return cola1 == otra.cola1;
		}
	
};

int main(){
	Cola_prioridad cola;
	string cadena;
	cout << "Introduce string separados por enter" << endl;
	cout << "Estribe 'fin' para terminar" << endl;
	getline(cin,cadena);
	while(cadena != "fin"){
		cola.push(cadena);
		getline(cin,cadena);	
	}
	
	cout << "\n\nSalida ordenada: " << endl;
	while(!cola.empty()){
		cout << cola.front() << endl;
		cola.pop();	
	}
}
