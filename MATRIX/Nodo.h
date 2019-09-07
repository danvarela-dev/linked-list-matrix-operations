#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo {
public:
	Nodo();
	void setValor(int);
	int getValor();
	void setSig(Nodo*);
	Nodo* getSig();

	void setAba(Nodo *);
	Nodo *getAba();

private:
	int valor;
	Nodo *sig;
	Nodo *aba;
};

#endif // !1