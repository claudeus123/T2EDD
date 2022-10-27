#include "Headers/nodo.h"

Nodo::Nodo(double nota){
	this->nota = nota;
	next = nullptr;
}
Nodo::~Nodo(){}
void Nodo::setNext(Nodo* next){
	this->next = next;
}
Nodo* Nodo::getNext(){
	return next;
}
double Nodo::getNota(){
	return nota;
}

