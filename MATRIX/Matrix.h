#pragma once
#ifndef MATRIZ_H
#define MATRIZ_H
#include "Nodo.h"


class Matriz {
public:
	Matriz();
	void setFilas(int);//F
	void setColumnas(int);//F
	int getFilas();
	int getColumnas();

	Nodo * getRoot_Nodo();

	bool checkFormat(const char *);//Funciona
	
	int Filas(const char *);// Funciona
	int Columnas(const char *);// Funciona

	void CrearMatriz(const char *); // Funciona
	void LLenarMatriz(const char *); // Funciona

	void ImprimirMatriz(const char *); // para ver si se guarda
 	void SumaMatriz(Matriz, Matriz, const char *,const char *,const char *);//F
	void RestaMatriz(Matriz, Matriz, const char *,const char *,const char *);
	void MultiplicacionMatriz(Matriz, Matriz, const char *,const char *,const char *);

	void DeterminanteMatriz(Matriz,const char *);

private:
	Nodo *inicio;
	int f;
	int c;
};


#endif // !MATRIZ_H