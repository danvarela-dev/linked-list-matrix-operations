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

	Nodo * getNodo();

	bool VerificarEscritura(char *);//F
	int Filas(char *);// F
	int Columnas(char *);// F

	void CrearMatriz(char *); // F
	void LLenarMatriz(char *); //F

	void ImprimirMatriz(char *); // para Motivo de Prueba
 	void SumaMatriz(Matriz, Matriz, char *,char *,char *);
	void RestaMatriz(Matriz, Matriz, char *,char *,char *);
	
	void MultiplicacionMatriz(Matriz, Matriz, char *,char *,char *);

	void DeterminanteMatriz(Matriz,char *);

private:
	Nodo *inicio;
	int f;
	int c;
};


//class MetodosMatrices {
//public:
//	static void añadirNodos(Nodo**);
//	static void crearMatriz(Nodo**, int, int);
//	static void ImprimirMatriz(Nodo**);
//	static int ObtenerFilas(Nodo**);
//	static int ObtenerColumnas(Nodo**);
//};
#endif // !MATRIZ_H