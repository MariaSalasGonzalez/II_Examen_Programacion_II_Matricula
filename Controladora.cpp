#include "Controladora.h"

Controladora::Controladora() {
	SistemaMatricula* sistemita = new SistemaMatricula();
	vistita = new Vista(sistemita);
}

Controladora::~Controladora() {
	delete vistita;
}

void Controladora::control() {
	try {
		inicia();
		int opcion;
		do {
			opcion = menu();
			switch (opcion) {
			case 1:
				control1(); 
				break;
			case 2:
				control2(); 
				break;
			case 3:
				control3(); 
				break;
			case 4:
				control4(); 
				break;
			case 5:
				control5(); 
				break;
			case 6:
				control6(); 
				break;
			case 7:
				control7(); 
				break;
			case 8:
				control8(); 
				break;
			default:
				cout << "Debe digitar un numero del 1 al 8" << endl;
			}
		} while (opcion != 8);
	}
	catch (const char* excepcion) {
		cout << excepcion << endl;
	}
	catch (...) {
		cout << "Hubo un problema inesperado. " << endl;
	}
}

void Controladora::inicia() {
	vistita->inicia();
	system("pause");
}

int Controladora::menu() {
	return vistita->menuPrincipal();
	system("pause");
}

void Controladora::control1() {
	vistita->cargaProfesorGuia();
	system("pause");
}

void Controladora::control2() {
	vistita->menuAgregaEstudiante();
	system("pause");
}

void Controladora::control3() {
	vistita->eliminaEstu();
	system("pause");
}

void Controladora::control4() {
	vistita->muestraEstudiante();
	system("pause");
}

void Controladora::control5() {
	vistita->muestraEstudiantePorProfe();
	system("pause");
}

void Controladora::control6() {
	vistita->guardaDatos();
	system("pause");
}

void Controladora::control7() {
	vistita->recuperaDatos();
	system("pause");
}

void Controladora::control8() {
	vistita->adios();
	system("pause");
}
