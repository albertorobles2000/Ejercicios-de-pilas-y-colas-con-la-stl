/*
5. Implementa el TDA pila usando dos colas. ¿Que orden de e?ciencia tienen las operaciones push y pop?
*/

#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Pila{
	private:
		queue<T> cola1;
		queue<T> cola2;
	public:	
		Pila(){}
		
		Pila(const Pila & p)
		{
			cola1 = p.cola1;	
		}
		
		void operator = (const Pila & otra)
		{
			cola1 = otra.cola1;
		}
		
		void push(T x) //Orden push con eficiencia O 1
		{
			cola1.push(x);
		}
		
		void pop()
		{
			while(cola1.size() > 1){
				cola2.push(cola1.front());
				cola1.pop();
			}
			
			cola1.pop();
			
			while(!cola2.empty()){
				cola1.push(cola2.front());
				cola2.pop();
			}
		}
		
		T & top()
		{
			return cola1.back();
		}
		
		bool empty()
		{
			return cola1.empty();
		}
		
		int size()
		{
			return cola1.size();	
		}
		
		bool operator < (Pila & otra){
			bool menor = false;
			bool fin = false;
			
			while(!this->empty() && !otra.empty() && !fin ){
				if(this->top() < otra.top()){
					fin = true;
					menor = true;
				}
				else{
					if(this->top() > otra.top()){
						fin = true;
						menor = false;
					}
					else{
						this->pop();
						otra.pop();	
					}
				}
			}
			
			if(!fin){
				if(this->empty() && !otra.empty())
					menor = true;
			}
			
			return menor;
		}
		
		bool operator == (const Pila & otra)
		{
			return cola1 == otra.cola1;
		}
	
};

int main(){
	Pila<int> pila1;
	Pila<int> pila2;
	
	for(int i=0; i<10; i++)
		pila1.push(i);
	
	cout << "pila1 = pila2" << endl;
	pila2 = pila1;
	
	if(pila1 == pila2)
		cout << "pila1 == pila2" << endl;
	else
		cout << "pila1 == pila2" << endl;
		
	cout << "Pila2.top(): " << pila2.top() << endl;
	cout << "Pila2.pop()" << endl;
	
		if(pila1 < pila2)
		cout << "pila1 < pila2" << endl;
	else
		cout << "pila1 > pila2" << endl;
	
	
}
