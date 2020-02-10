/*
12. Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas 
de caracteres mas largas y que en caso de igualdad salgan por orden alfabetico.
*/


#include <iostream>
#include <queue>
#include <string>

using namespace std;

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
			while(!cola1.empty() && cola1.front().size() < s.size()){
				cola2.push(cola1.front());
				cola1.pop();
			}
			
			while(!cola1.empty() && cola1.front().size() == s.size() && s > cola1.front()){
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
