#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

	int opcion;
	Matriz A;
	Matriz B;
	Matriz Resta,Suma,Multi;
	Matriz Determinante;

	do {
		cout << endl;
		cout <<"1.CrearMatriz A" << endl;
		cout <<"2.ImprimirMatriz A" << endl;
		
		cout <<"3.CrearMatriz B" << endl;
		cout <<"4.ImprimirMatriz B" << endl;

		cout << "5.Calcular Suma " << endl;
		cout << "6. Calcular Resta" << endl;

		cout << "7.Calcular Multiplicacion" << endl;

		cout << "8.Calcular Determinante " << endl;
		cout << "9.Salir" << endl;
		cin >> opcion;
		cout << endl;
		system("cls");
		switch (opcion)
		{
		case 1:
			char arch[10];
			cout << "Escriba el Nombre del Alchivo para la Matriz A: ";
			cin >> arch;

			system(arch);
			if (A.VerificarEscritura(arch)) {
				A.CrearMatriz(arch);
				A.LLenarMatriz(arch);

				cout << "Matriz A creada " << endl;
			}
			break;

		case 2:
			cout << endl;
			char ar[10];
			cout << "Escriba el Nombre del Archivo para la Matriz A: ";
			cin >> ar;
			if (A.VerificarEscritura(ar)) {


				A.ImprimirMatriz(ar);
				cout << endl;
			}
			break;

		case 3:
			cout << endl;
			char arvos[10];
			cout << "Escriba el Nombre del Archivo para la Matriz B: ";
			cin >> arvos;
			
			system(arvos);

			if (A.VerificarEscritura(arch)) {
				B.CrearMatriz(arvos);
				B.LLenarMatriz(arvos);

				cout << "Matriz B creada " << endl;
				cout << endl;
			}
			break;

		case 4:
			cout << endl;
			char arivos[10];
			cout << "Escriba el Nombre del Archivo para la Matriz B: ";
			cin >> arivos;

			if (A.VerificarEscritura(arch)) {
				B.ImprimirMatriz(arivos);
				cout << endl;
			}
			break;

		case 5:
			cout << endl;
			char vos[10];
			cout << "Escriba el Nombre del Archivo de Suma: ";
			cin >> vos;
			
			if (A.getColumnas() == B.getColumnas() && A.getFilas() == B.getFilas()) {
				system(vos);
				Suma.SumaMatriz(A, B, "A.dat", "B.dat", vos);
				Suma.CrearMatriz(vos);
				Suma.LLenarMatriz(vos);
				system(vos);
				Suma.ImprimirMatriz(vos);
			}
			else {
				cout << "No tienen la misma dimension"<<endl;
			}
			cout << endl;
			break;

		case 6:
			cout << endl;
			char ivos[10];
			cout << "Escriba el Nombre del Archivo de Resta: ";
			cin >> ivos;
			if (A.getColumnas() == B.getColumnas() && A.getFilas() == B.getFilas()) {
				system(ivos);
				Resta.RestaMatriz(A, B, "A.dat", "B.dat", ivos);
				Resta.CrearMatriz(ivos);
				Resta.LLenarMatriz(ivos);
				system(ivos);
				Resta.ImprimirMatriz(ivos);
			}
			else
			{
				cout << "No tienen la misma dimension" << endl;
			}

			cout << endl;
			break;

		case 7:
			cout << endl;
			char a[10];
			cout << "Escriba el Nombre del Archivo de Multiplicacion: ";
			cin >> a;
			if (A.getFilas() == B.getColumnas()) {
				system(a);
				Multi.MultiplicacionMatriz(A, B, "A.dat", "B.dat", a);
				Multi.CrearMatriz(a);
				Multi.LLenarMatriz(a);
				system(a);
				Multi.ImprimirMatriz(a);
			}
			else
			{
				std::cout << "No se pueden multiplicar ya que debe tener La matriz B el en columnas el mismo numero de fila de la matriz A para la multiplicacion" << std::endl;
			}
			cout << endl;
			break;

		case 8:
			int opc;
			cout << "1.Determinante Matriz A ";
			cout << endl;
			cout << "2.Determinante Matriz B";
			cout << endl;
			cin >> opc;

			switch (opc)
			{
			case 1:
				Determinante.DeterminanteMatriz(A, "Adet.dat");
				system("Adet.dat");
				break;

			case 2:
				Determinante.DeterminanteMatriz(B, "Bdet.dat");
				system("Bdet.dat");
				break;
			default:
				break;
			}
			cout << endl;



		default:
			break;
		}

	} while (opcion!=9);


	



	
}