#include "Domain/Headers/nodo.h"
#include <iostream>
#include <stack>
using namespace std;

struct Camion {
  int tara, id;
};

void ordenarCamiones(stack<Camion> *estacionamiento) {
  	stack<Camion> aux1, aux2;
  	int mayor = 0;
  	while (!estacionamiento->empty()) {
    Camion c = estacionamiento->top();

    if (aux1.empty()) {
    	aux1.push(c);
    	mayor = c.tara;
	}else if (c.tara > mayor){
		while (!aux1.empty()){
			aux2.push(aux1.top());
			aux1.pop();
		}
		mayor = c.tara; 
		aux1.push(c);
	}else if (c.tara > aux1.top().tara){
		while(aux1.top().tara < c.tara){
			aux2.push(aux1.top());
			aux1.pop();
		}
		aux1.push(c);
	
	} else if (aux2.empty() || c.tara > aux2.top().tara ) aux1.push(c);
	else aux2.push(c);
	estacionamiento->pop();

	if(estacionamiento->empty()){
		Camion c2;
		while(!aux2.empty()){
			estacionamiento->push(aux2.top());
			c2 = aux2.top();
			aux2.pop();
		}
	}

  	}
	while(!aux1.empty()){
		estacionamiento->push(aux1.top());
		aux1.pop();
	}
}

void rellenarEstacionamiento(stack<Camion> *estacionamiento) {
	int cantidad_camiones;
	int tara;
	int contador = 0;
	
	cout << "Ingrese la cantidad de camiones: " << endl;
	cin >> cantidad_camiones;
	while (contador < cantidad_camiones){
		Camion c;
		cout << "Ingrese tara del camion: " << contador + 1 << endl;
		cin >> tara;
		c.tara = tara;
		c.id = contador+1;
		estacionamiento->push(c);
		contador++;
	} 
}

void printEstacionamiento(stack<Camion> *estacionamiento) {
  int i = 1;
  while (!estacionamiento->empty()) {
    Camion c = estacionamiento->top();
    cout << i << ") id: " << c.id << ", tara: " << c.tara << endl;
    estacionamiento->pop();
    i++;
  }
}

// ------------ Problema 4 --------------

void calcularPromedio(Nodo *head) {
  Nodo *actual = head;
  double sumador = head->getNota();
  int contador = 1;
  actual = actual->getNext();
  while (actual != head) {
    sumador += actual->getNota();
    contador++;
    actual = actual->getNext();
  }
	cout << "Cantidad de notas: " << contador << endl;
  cout << "Promedio = " << sumador / contador << endl;
}

Nodo* insertarNota(Nodo *head, double nota) {
  Nodo* nuevoNodo = new Nodo(nota);
  if (head == nullptr){
	  head = nuevoNodo;
	  head->setNext(nuevoNodo);
  }else {
	  Nodo* current = head;
	  while (current->getNext()!= head){
		  current = current->getNext();
	  }
	  current->setNext(nuevoNodo);
	  nuevoNodo->setNext(head);
	  head = nuevoNodo;
  }
	
  return head;
}

Nodo* rellenarNotas(Nodo* head){
	int cantidad_notas;
	double nota;
	cout << "Ingrese cantidad de notas: " << endl;
	cin >> cantidad_notas;
	for(int i=1; i<=cantidad_notas; i++){
		cout<<"Ingrese nota "<<i<<" (1.0-7.0): "<<endl;
		cin>>nota;
		head = insertarNota(head,nota);
	}
	return head;
}


void Problema4() {
  	Nodo* head = nullptr;
	head = rellenarNotas(head);
  	calcularPromedio(head);
}

void Problema5() {
  	stack<Camion> estacionamiento;
  	rellenarEstacionamiento(&estacionamiento);
  	ordenarCamiones(&estacionamiento);
  	printEstacionamiento(&estacionamiento);
}

int main() {
  	Problema4();
  	Problema5();
}
