/*
11. Implementa una cola con prioridad de un tipo struct con (apellidos, nombre, prioridad) de forma que
los datos salgan de acuerdo a ese tercer campo prioridad.
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Persona{
	string nombre;
	string apellidos;
	int prioridad;	// prioridad = 0 tiene mas prioridad que prioridad = 0+x
};

class Cola_prioridad{
	private: 
		queue<Persona> cola1;
		queue<Persona> cola2;
	
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
		
		void push(Persona & p)
		{
			while((cola1.front()).prioridad <= p.prioridad && !cola1.empty()){
				cola2.push(cola1.front());
				cola1.pop();
			}
			
			cola2.push(p);
			
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
		
		Persona & front()
		{
			return cola1.front();	
		}
		
		Persona & back()
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
			bool menor = false;
			bool fin = false;
			
			queue<Persona> este = this->cola1;
			queue<Persona> otro = otra.cola1;
			
			while(!este.empty() && !otro.empty() && !fin ){
				if(este.front().prioridad < otro.front().prioridad){
					fin = true;
					menor = true;
				}
				else{
					if(este.front().prioridad > otro.front().prioridad){
						fin = true;
						menor = false;
					}
					else{
						este.pop();
						otro.pop();	
					}
				}
			}
			
			if(!fin){
				if(este.empty() && !otro.empty())
					menor = true;
			}
			
			return menor;
		}
		
		bool operator == (const Cola_prioridad & otra)
		{
			queue<Persona> este = this->cola1;
			queue<Persona> otro = otra.cola1;
			
			bool distintos = false;
			
			while(!este.empty() && !otro.empty() && !distintos){
				if(este.front().prioridad != otro.front().prioridad)
					distintos = true;	
			}
			
			if(!distintos && (!este.empty() || !otro.empty())){
					distintos = true;
			}
			
			return distintos;
		}
	
};

int main(){
	Cola_prioridad cola;
	for (int i=0; i<20; i++){
		Persona p;
		p.prioridad = i%5;
		cola.push(p);	
	}
	
	while(!(cola.empty())){
		cout << cola.front().prioridad << endl;
		cola.pop();	
	}
}
