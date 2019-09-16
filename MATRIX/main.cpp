#include <iostream>
#include <cstring>

#include "Matrix.h"
using namespace std;

int main() {

	int opcion;
	Matriz A;
	Matriz B;
	Matriz Resta,Suma,Multi;
	Matriz Determinante;


	// string numerosStr= "3 2 4 1";
	// char * cstr= new char[numerosStr.length()+1];
	// strcpy(cstr,numerosStr.c_str());

	// char * charNumero = strtok(cstr, " ");
    // int num 

	// int cont = 0;
	// while (charNumero && cont <= 4 )
	// {
	// 	charNumero = strtok(NULL, " ");
	// 	cont++;
	// 	cout << cont;	
	// 	}
        
		
		//cout << intSacado++; 



	// A.CrearMatriz("A.dat");
	// A.LLenarMatriz("A.dat");
	// //cout << A.Filas("A.dat") << " X " << A.Columnas("A.dat") << std::endl;
	// cout << " MATRIX A "<<endl;
	
	// A.ImprimirMatriz("A.dat");
	// B.CrearMatriz("B.dat");
	// B.LLenarMatriz("B.dat");
	// cout << " \nMATRIX B "<<endl;
	// B.ImprimirMatriz("B.dat");




	do {
		cout << endl;
		cout <<"1.CrearMatriz A" << endl;
		cout <<"2.ImprimirMatriz Instancia A" << endl;
		
		cout <<"3.CrearMatriz B" << endl;
		cout <<"4.ImprimirMatriz Instancia B" << endl;

		cout << "5.Calcular Suma " << endl;
		cout << "6. Calcular Resta" << endl;

		cout << "7.Calcular Multiplicacion" << endl;

		cout << "8.Calcular Determinante " << endl;
		// cout << "9. Imprimir Lista cualquiera"<<endl;
		cout << "10.Salir" << endl;
		cin >> opcion;
		cout << endl;
				switch (opcion)
		{
		case 1:
			char arch[10];
			cout << "Escriba el Nombre del Archivo para la Matriz A: ";
			cin >> arch;
			cout << A.checkFormat(arch);



			if (A.checkFormat(arch)) {
			//	system("pause");
				A.CrearMatriz(arch);
				A.LLenarMatriz(arch);

				cout << "Matriz A creada " << endl;
				A.ImprimirMatriz(arch);
			}else{
				cout << "Error al crear Matriz A";

			}
			break;

		case 2:
			cout << endl;
			char ar[10];
			cout << "Escriba el Nombre del Archivo para la Matriz A: ";
			cin >> ar;
			if (A.checkFormat(ar)) {


				A.ImprimirMatriz(ar);

				cout << endl;
			}
			break;

		case 3:
			cout << endl;
			char arvos[10];
			cout << "Escriba el Nombre del Archivo para la Matriz B: ";
			cin >> arvos;
			

			if (A.checkFormat(arch)) {
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

			if (A.checkFormat(arch)) {
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
				Suma.SumaMatriz(A, B, "A.dat", "B.dat", vos);
				Suma.CrearMatriz(vos);
				Suma.LLenarMatriz(vos);
	
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
				// system(ivos);
				Resta.RestaMatriz(A, B, "A.dat", "B.dat", ivos);
				Resta.CrearMatriz(ivos);
				Resta.LLenarMatriz(ivos);
				//system(ivos);
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
			
				Multi.MultiplicacionMatriz(A, B, "A.dat", "B.dat", a);
				Multi.CrearMatriz(a);
				Multi.LLenarMatriz(a);
			
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
		
				break;

			case 2:
				Determinante.DeterminanteMatriz(B, "Bdet.dat");
			
				break;
			default:
				break;
			}
			cout << endl;
break;
			// case 9:
			// 	cout << "Introducir nombre de archivo de lista a imprimir";
			// 	char na[10];
			// 	cin >> na;
			// 	A.ImprimirMatriz(na);
			// 	cout <<endl;
			// break;

		default:
		cout << "Opcion Invalida, trate de nuevo";
			break;
		}

	} while (opcion!=9);


	



	
}