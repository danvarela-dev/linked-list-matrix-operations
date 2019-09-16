#include "Matrix.h"

Nodo::Nodo() :valor(-1), sig(0), aba(0)
{}
Nodo::Nodo(int num):valor(num){}

void Nodo::setValor(int Valor) {
	this->valor = Valor;
}

int Nodo::getValor() 
{
	return this->valor;
}

Nodo* Nodo::getSig() {
	return this->sig;
}
void Nodo::setSig(Nodo* sig) {
	this->sig = sig;
}

void Nodo::setAba(Nodo*aba) {
	this->aba = aba;
}

Nodo* Nodo::getAba() {
	return this->aba;
}
