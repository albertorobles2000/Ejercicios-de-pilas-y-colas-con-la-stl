/*
 Implementa un TDA cola usando como representacion dos pilas.
*/
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Cola{
	private:
		stack<T> pila1;
		stack<T> pila2;
	public:
		Cola(){}
		
		Cola(const Cola& otra)
		{
			pila1 = otra.pila1;
		}
		
		void operator = (const Cola & otra)
		{
			pila1 = otra.pila1;
		}
			
		void push(const T& nuevo)
		{
			pila1.push(nuevo);
		}
		
		void pop()
		{
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}
			
			pila2.pop();
			
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
		}
		
		T& front()
		{
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}
			
			T& ref = pila2.top();
			
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
			
			return ref;
		}
		
		T& back()
		{
			return pila1.top();
		}
		
		bool empty() const
		{
			return pila1.empty();
		}
		
		int size() const
		{
			return pila1.size();
		}
		
		bool operator < (Cola & otra){
			bool menor;
			while(!pila1.empty()){
				pila2.push(pila1.top());
				pila1.pop();
			}
			
			while(!(otra.pila1).empty()){
				(otra.pila2).push(otra.pila1.top());
				(otra.pila1).pop();
			}
			
			menor = pila2 < otra.pila2;
			
			while(!pila2.empty()){
				pila1.push(pila2.top());
				pila2.pop();
			}
			
			while(!(otra.pila2).empty()){
				(otra.pila1).push(otra.pila2.top());
				otra.pila2.pop();
			}
		
			return menor;
		}
		
		bool operator == (const Cola & otra)
		{
			return pila1 == otra.pila1;
		}
		
};

int main(){
	cout << "Utilizamos constructor por defecto" << endl;
	Cola<int> cola;
	for(int i=0; i<10; i++){
		cola.push(i);	
	}
	
	cout << "Utilizamos constructor de copia" << endl;
	Cola<int> otra(cola);
	
	cout << "Primer elemento en la cola: " << cola.front() << endl;
	cout << "Ultimo elemento en la cola: " << cola.back() << endl;
	cout << "size: " << cola.size() << endl;
	cout << "Pop del primer elemento" << endl;
	cola.pop();
	cout << "Primer elemento en la cola: " << cola.front() << endl;
	cout << "Ultimo elemento en la cola: " << cola.back() << endl;
	cout << "size: " << cola.size() << endl;
	if ((cola < otra))
		cout << "cola < otra // primer elemento de cola = 1 // primer elemento de otra = 0"<< endl;
		
	if (!(cola == otra))
			cout << "cola != otra"<< endl;
}
