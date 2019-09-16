#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Matrix.h"

Matriz::Matriz() : f(0), c(0)
{
	inicio = new Nodo;
}
void Matriz::setFilas(int f)
{
	this->f = f;
}
void Matriz::setColumnas(int c)
{
	this->c = c;
}
Nodo *Matriz::getRoot_Nodo()
{
	return this->inicio;
}
int Matriz::getFilas()
{
	return this->f;
}
int Matriz::getColumnas()
{
	return this->c;
}

bool Matriz::checkFormat(const char *nombre)
{

	std::ifstream archivoM(nombre, std::ios::in);
	if (!archivoM)
	{
		std::cout << "Error al abrir archivo";
	}
	std::string line;

	while (std::getline(archivoM, line))
	{
		for (int i = 0; i < line.length(); i = i + 2)
		{
			if (line[i] == ' ')
			{
				archivoM.close();
				return false;
			}
		}
	}
	archivoM.close();
	return true;
}

int Matriz::Columnas(const char *nombre)
{
	std::ifstream archivoM(nombre, std::ios::in);
	if (!archivoM)
	{
		std::cout << "Error al abrir archivo";
	}
	std::string line;
	int i = 0;
	while (std::getline(archivoM, line))
	{
		i++;
	}
	//i = i-2;//reduce lo que se suma en Filas()
	archivoM.close();
	setColumnas(i);
	return i;
}

int Matriz::Filas(const char *nombre)
{
	std::ifstream archivoM(nombre, std::ios::in);
	if (!archivoM)
	{
		std::cout << "Error al abrir archivo";
	}
	std::string line;
	int a = 0;

	while (std::getline(archivoM, line))
	{
		for (int i = 0; i < line.length(); i = i + 2)
		{
			a++;
		}
		archivoM.close();
		setFilas(a);
		return a;
	}
}

void Matriz::CrearMatriz(const char *nombre)
{

	if (checkFormat(nombre))
	{

		Nodo *nuevo;

		Nodo *tmp = this->inicio;
		Nodo *pivote = this->inicio;

		int Col = Columnas(nombre);
		int Fil = Filas(nombre);

		for (int i = 0; i < Col; i++)
		{
			if (i == 0)
			{
			}
			else
			{
				pivote = tmp;
				nuevo = new Nodo;
				pivote->setAba(nuevo);
				pivote = pivote->getAba();
				tmp = tmp->getAba();
			}
			for (int k = 0; k < Fil; k++)
			{
				nuevo = new Nodo;
				pivote->setSig(nuevo);
				pivote = pivote->getSig();
			}
		}
	}
	else
	{
		std::cout << "Error en crear de la Matriz " << std::endl;
	}
}

void Matriz::LLenarMatriz(const char *nombre)
{

	if (checkFormat(nombre))
	{
		
		int Col = Columnas(nombre);
		int Fil = Filas(nombre);

		Nodo *tmp = this->inicio;
		Nodo *pivote = this->inicio;

		std::ifstream archivoM(nombre, std::ios::in);
		if (!archivoM)
		{
			std::cout << "Error al abrir archivo";
		}
		std::string line;
		while (!archivoM.eof())
		{
			for (int i = 0; i < Col; i++)
			{
				std::getline(archivoM, line);

				if (i == 0)
				{
					//No realiza ninguna instruccion
				}
				else
				{
					pivote = tmp;
					pivote = pivote->getAba();
					tmp = tmp->getAba();
				}
				for (int k = 0; k < line.length(); k=k+2)
				{
					//const char *inf = &line[k];
					//int info = atoi(inf); //convert str to int
					char * cline = new char[line.length()+1];
					strcpy(cline,line.c_str());
					char * charInt = strtok(cline," ");
				//	int numeroSacado = atoi(charInt);
					
					while (charInt && pivote->getSig()!=0)
					{
						pivote->setValor(atoi(charInt));
						pivote = pivote->getSig();
						charInt =strtok(NULL," ");
					
					
					}
						

					//pivote->setValor(numeroSacado);
					
				}
			}
		}
	}
	else
	{
		std::cout << "Formato de la matriz incorrecto" << std::endl;
	}
}

void Matriz::ImprimirMatriz(const char *nombre)
{

	if (inicio == 0)
	{
		std::cout << "EMPTY LIST";
		return;
	}
	else
	{

		if (checkFormat(nombre))
		{
			//	std::cout << "EMPTY LIST";
			Nodo *tmp = inicio;
			Nodo *pivote = inicio;

			int Col = Columnas(nombre);
			int Fil = Filas(nombre);

			for (int i = 0; i < Col; i++)
			{
				if (i == 0)
				{
				}
				else
				{
					pivote = tmp;
					pivote = pivote->getAba();
					tmp = tmp->getAba();
					std::cout << "\n";
				}
				for (int k = 0; k < Fil; k++)
				{

					std::cout << pivote->getValor() << " ";
					pivote = pivote->getSig();
				}
			}
		}
		else
		{
			std::cout << "Error En escritura de la Matriz " << std::endl;
		}
	}
}

void Matriz::SumaMatriz(Matriz A, Matriz B, const char *nombreA, const char *nombreB, const char *nombre)
{
	if (checkFormat(nombreA) && checkFormat(nombreB))
	{
		if (Columnas(nombreA) == Columnas(nombreB) && Filas(nombreA) == Filas(nombreB))
		{

			int Col = Columnas(nombreA); // no importa cual archivo debido que ya paso la condicion
			int Fil = Filas(nombreA);	// y presentan as misma dimensiones

			Nodo *pivote1 = A.getRoot_Nodo();
			Nodo *tmp1 = A.getRoot_Nodo();

			Nodo *pivote2 = B.getRoot_Nodo();
			Nodo *tmp2 = B.getRoot_Nodo();

			std::ofstream archivoM(nombre);
			archivoM.clear();
			if (!archivoM)
			{
				std::cout << "Error al abrir archivo";
			}
			std::string linea = "";
			int suma;

			for (int i = 0; i < Col; i++)
			{
				if (i == 0)
				{
					for (int k = 0; k < Fil; k++)
					{

						suma = pivote1->getValor() + pivote2->getValor();
						pivote1 = pivote1->getSig();
						pivote2 = pivote2->getSig();

						linea = linea + std::to_string(suma) + ' ';
						suma = 0;
					}
					archivoM << linea + "\n";
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
					tmp1 = tmp1->getAba();

					pivote2 = pivote2->getAba();
					tmp2 = tmp2->getAba();
					linea = "";
				}
				else
				{
					for (int k = 0; k < Fil; k++)
					{

						suma = pivote1->getValor() + pivote2->getValor();
						pivote1 = pivote1->getSig();
						pivote2 = pivote2->getSig();

						linea = linea + std::to_string(suma) + ' ';
						suma = 0;
					}
					archivoM << linea + "\n";
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
					tmp1 = tmp1->getAba();

					pivote2 = pivote2->getAba();
					tmp2 = tmp2->getAba();
					linea = "";
				}
			}

			archivoM.close();
		}
		else
		{
			std::cout << "No se puede sumar debido a que deben ser de la misma dimension" << std::endl;
		}
	}
	else
	{
		std::cout << "Error en la escritura de alguno de los archivos" << std::endl;
	}
}

void Matriz::RestaMatriz(Matriz A, Matriz B, const char *nombreA, const char *nombreB, const char *nombre)
{
	if (checkFormat(nombreA) && checkFormat(nombreB))
	{
		if (Columnas(nombreA) == Columnas(nombreB) && Filas(nombreA) == Filas(nombreB))
		{

			int Col = Columnas(nombreA); // no importa cual archivo debido que ya paso la condicion
			int Fil = Filas(nombreA);	// y presentan as misma dimensiones

			Nodo *pivote1 = A.getRoot_Nodo();
			Nodo *tmp1 = A.getRoot_Nodo();

			Nodo *pivote2 = B.getRoot_Nodo();
			Nodo *tmp2 = B.getRoot_Nodo();

			std::ofstream archivoM(nombre);
			archivoM.clear();
			if (!archivoM)
			{
				std::cout << "Error al abrir archivo";
			}
			std::string linea = "";
			int resta;

			for (int i = 0; i < Col; i++)
			{
				if (i == 0)
				{
					for (int k = 0; k < Fil; k++)
					{

						resta = pivote2->getValor() - pivote1->getValor();
						resta= resta *(-1);
						pivote1 = pivote1->getSig();
						pivote2 = pivote2->getSig();

						linea = linea + std::to_string(resta) + ' ';
						resta = 0;
					}
					archivoM << linea + "\n";
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
					tmp1 = tmp1->getAba();

					pivote2 = pivote2->getAba();
					tmp2 = tmp2->getAba();
					linea = "";
				}
				else
				{
					for (int k = 0; k < Fil; k++)
					{

						resta = pivote2->getValor() - pivote1->getValor();
						resta = resta * (-1);
						pivote1 = pivote1->getSig();
						pivote2 = pivote2->getSig();

						linea = linea + std::to_string(resta) + ' ';
						resta = 0;
					}
					archivoM << linea + "\n";
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
					tmp1 = tmp1->getAba();

					pivote2 = pivote2->getAba();
					tmp2 = tmp2->getAba();
					linea = "";
				}
			}

			archivoM.close();
		}
		else
		{
			std::cout << "No se puede sumar debido a que deben ser de la misma dimension" << std::endl;
		}
	}
	else
	{
		std::cout << "Error en la escritura de alguno de los archivos" << std::endl;
	}
}

void Matriz::MultiplicacionMatriz(Matriz A, Matriz B, const char *nombreA, const char *nombreB, const char *nombre)
{
	if (checkFormat(nombreA) && checkFormat(nombreB))
	{
		if (Filas(nombreB) == Columnas(nombreA))
		{

			int Col = Columnas(nombreA);
			int Fil = Filas(nombreB);
			int contador = 0;

			Nodo *pivote1 = A.getRoot_Nodo();
			Nodo *tmp1 = A.getRoot_Nodo();

			Nodo *pivote2 = B.getRoot_Nodo();
			Nodo *tmp2 = B.getRoot_Nodo();

			std::ofstream archivoM(nombre);
			archivoM.clear();
			if (!archivoM)
			{
				std::cout << "Error al abrir archivo";
			}
			std::string linea = "";
			int multiplicacion = 0;

			for (int i = 0; i < Col; i++)
			{
				if (i == 0)
				{
					for (int k = 0; k < Fil * 2; k++)
					{
						if (contador == Fil)
						{
							linea = linea + std::to_string(multiplicacion) + ' ';

							pivote1 = tmp1;
							pivote2 = tmp2;

							pivote2 = pivote2->getSig();
						}
						else
						{
							multiplicacion = multiplicacion + (pivote1->getValor() * pivote2->getValor());
							pivote1 = pivote1->getSig();
							pivote2 = pivote2->getAba();

							contador++;
						}
					}
					archivoM << linea + "\n";
					linea = "";
					contador = 0;
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
				}
				else
				{
					multiplicacion = 0;
					for (int k = 0; k < Fil * 2; k++)
					{

						if (contador == Fil)
						{

							linea = linea + std::to_string(multiplicacion) + ' ';

							pivote1 = tmp1;
							pivote2 = tmp2;

							pivote2 = pivote2->getSig();
						}
						else
						{
							multiplicacion = multiplicacion + (pivote1->getValor() * pivote2->getValor());
							pivote1 = pivote1->getSig();
							pivote2 = pivote2->getAba();

							contador++;
						}
					}
					archivoM << linea + "\n";
					linea = "";
					contador = 0;
					pivote1 = tmp1;
					pivote2 = tmp2;

					pivote1 = pivote1->getAba();
				}
			}

			archivoM.close();
		}
		else
		{
			std::cout << "No se pueden multiplicar ya que debe tener La matriz B el en columnas el mismo numero de fila de la matriz A para la multiplicacion" << std::endl;
		}
	}
	else
	{
		std::cout << "Error en la escritura de alguno de los archivos" << std::endl;
	}
}

void Matriz::DeterminanteMatriz(Matriz matriz, const char *nombre)
{
	if (matriz.getFilas() == 1 && matriz.getColumnas() == 1)
	{
		std::ofstream archivoM(nombre);
		archivoM.clear();
		if (!archivoM)
		{
			std::cout << "Error al abrir archivo";
		}
		archivoM << "Determinante: " << matriz.getRoot_Nodo()->getValor();
		archivoM.close();
	}
	else if (matriz.getFilas() == 2 && matriz.getColumnas() == 2)
	{
		std::ofstream archivoM(nombre);
		archivoM.clear();
		if (!archivoM)
		{
			std::cout << "Error al abrir archivo";
		}
		Nodo *n1 = matriz.getRoot_Nodo();
		Nodo *n2 = matriz.getRoot_Nodo()->getAba();
		Nodo *n3 = matriz.getRoot_Nodo()->getSig();
		Nodo *n4 = matriz.getRoot_Nodo()->getAba();

		int multiplicacion = (n1->getValor() * n2->getSig()->getValor() - n3->getValor() * n4->getValor());

		archivoM << "Determinante: " << multiplicacion;
		archivoM.close();
	}
	else if (matriz.getFilas() == 3 && matriz.getColumnas() == 3)
	{ // por cofactores

		std::ofstream archivoM(nombre);
		archivoM.clear();
		if (!archivoM)
		{
			std::cout << "Error al abrir archivo";
		}

		int total = 0;

		for (int i = 0; i < 2; i++)
		{
			if (i = 0)
			{
				Nodo *nprin = matriz.getRoot_Nodo();
				Nodo *n2 = matriz.getRoot_Nodo()->getAba()->getSig();
				Nodo *n3 = n2->getSig();
				Nodo *n4 = matriz.getRoot_Nodo()->getAba()->getAba()->getSig();
				Nodo *n5 = n4->getSig();

				total = total + (nprin->getValor() * (n2->getValor() * n5->getValor() - n3->getValor() * n4->getValor()));
			}
			else if (i = 1)
			{
				Nodo *nprin = matriz.getRoot_Nodo()->getSig();
				Nodo *n2 = matriz.getRoot_Nodo()->getAba();
				Nodo *n3 = n2->getSig()->getSig();
				Nodo *n4 = n2->getAba();
				Nodo *n5 = n4->getSig()->getSig();

				total = total - (nprin->getValor() * (n2->getValor() * n5->getValor() - n3->getValor() * n4->getValor()));
			}
			else
			{
				Nodo *nprin = matriz.getRoot_Nodo()->getSig()->getSig();
				Nodo *n2 = matriz.getRoot_Nodo()->getAba();
				Nodo *n3 = n2->getSig();
				Nodo *n4 = n2->getAba();
				Nodo *n5 = n4->getSig();

				total = total + (nprin->getValor() * (n2->getValor() * n5->getValor() - n3->getValor() * n4->getValor()));
			}
		}
		archivoM << "Determinante: " << total;
		archivoM.close();
	}
	else
	{
		std::cout << "No aplica este caso para el proyecto en matrices de orden 4" << std::endl;
	}
}

//void MetodosMatrices::añadirNodos(Nodo**){
//}
//
//void MetodosMatrices::crearMatriz(Nodo **inicio, int filas, int columnas) {
//
//} // horizontal , vertical
//
//void MetodosMatrices::ImprimirMatriz(Nodo**matriz) {
//
//}
//
//int MetodosMatrices::ObtenerFilas(Nodo**matriz) {
//
//}
//
//int MetodosMatrices::ObtenerColumnas(Nodo**matriz) {
//
//}