#ifndef NODO_H
#define NODO_H
#include <iostream>

class Nodo{
	private: 
		double nota;
		Nodo* next;

	public:
		Nodo(double nota);
		~Nodo();
		void setNext(Nodo* next);
		Nodo* getNext();
		double getNota();
};
#endif
