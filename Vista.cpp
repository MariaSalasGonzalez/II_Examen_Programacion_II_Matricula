#include "Vista.h"

Vista::Vista(SistemaMatricula* sisMatriculita): sisMatriculita(sisMatriculita) {}

void Vista::cargaProfesorGuia() {
	return sisMatriculita->agregaProfesorGuia();
}

void Vista::inicia() {
	cout << ".................................................." << endl;
	cout << ". . . . . . .  B I E N V E N I D O . . . . . . . ." << endl;
	cout << ". . . .  S I S T E M A  G E S T O R  D E . . . . ." << endl;
	cout << ". . . . . M A T R I C U L A  S I G M A . . . . . ." << endl;
	cout << ".................................................." << endl;
}

int Vista::menuPrincipal() {
	int opcion;
	system("cls");
	cout << ".................................................." << endl;
	cout << "........... M E N U  P R I N C I P A L ..........." << endl;
	cout << ".................................................." << endl;
	cout << "  1) Carga Profesores                             " << endl;
	cout << "  2) Matricula estudiante                        " << endl;
	cout << "  3) Elimina estudiante por cedula               " << endl;
	cout << "  4) Muestra todos los estudiantes                " << endl;
	cout << "  5) Muestra estudiantes por profesor guia        " << endl;
	cout << "  6) Guarda datos                                " << endl;
	cout << "  7) Recupera datos                              " << endl;
	cout << "  8) Salir                                        " << endl;
	cout << ".................................................." << endl;
	cout << "    Digite una de las opciones: ";
	cin >> opcion;
	cout << ".................................................." << endl;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		system("cls");
		cout << ".................................................." << endl;
		cout << "........... M E N U  P R I N C I P A L ..........." << endl;
		cout << ".................................................." << endl;
		cout << "  1) Carga Profesores                             " << endl;
		cout << "  2) Matricula estudiante                        " << endl;
		cout << "  3) Elimina estudiante por cedula               " << endl;
		cout << "  4) Muestra todos los estudiantes                " << endl;
		cout << "  5) Muestra estudiantes por profesor guia        " << endl;
		cout << "  6) Guarda datos                                " << endl;
		cout << "  7) Recupera datos                              " << endl;
		cout << "  8) Salir                                        " << endl;
		cout << ".................................................." << endl;
		cout << "    Digite una de las opciones: ";
		cin >> opcion;
		cout << ".................................................." << endl;
	}
	system("cls");
	return opcion;
}

void Vista::menuAgregaEstudiante() {
	int opcion = 0, dia = 0, mes = 0, annio = 0, diaMat = 0, mesMat = 0, annioMat = 0;
	string cedulaEstu = "", nombreEstu = "", apellidoEstu = "", cedulaEnca = "",
		   nombreEnca = "", apellidoEnca = "", telefonoEnca = "", direccionEnca = "", codigoMat = "";
	Encargado* encargadito = nullptr;
	Fecha* fechita = nullptr;
	Fecha* fechitaMat = nullptr;
	Matricula* matriculita = nullptr;
	Estudiante* estudiantito = nullptr;
	ProfesorGuia* profesorcito = nullptr;
	bool fechilla = false;
	system("cls");
	cout << " Digite la cedula del estudiante: " << endl;
	cin >> cedulaEstu;
	cout << " Digite el nombre del estudiante:  " << endl;
	cin >> nombreEstu;
	cout << " Digite el apellido del estudiante:  " << endl;
	cin >> apellidoEstu;
	cout << endl;
	cout << " Digite la cedula del encargado: " << endl;
	cin >> cedulaEnca;
	cout << " Digite el nombre del encargado: " << endl;
	cin >> nombreEnca;
	cout << " Digite el apellido del encargado: " << endl;
	cin >> nombreEnca;
	cout << " Digite el telefono del encargado: " << endl;
	cin >> telefonoEnca;
	cout << " Digite el direccion del encargado: " << endl;
	cin >> direccionEnca;
	while (fechilla == false) {
		try {
			cout << " Digite el annio de nacimiento: " << endl;
			cin >> annio;
			cout << " Digite el mes de nacimiento: " << endl;
			cin >> mes;
			if (mes < 1 || mes > 12) {
			throw " El mes que digito NO es correcto\n\n";
			fechilla = 0;
			}else {
			cout << " Digite el dia de nacimiento: " << endl;
			cin >> dia;
			if ((mes == 1 || mes == 3 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) {
			throw " El dia que digito NO es correcto\n";
			fechilla = 0;
			}else {
			if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia < 1 || dia > 31) || (mes == 2 && dia > 28)) {
			throw " El dia que digito NO es valido\n";
			fechilla = 0;
			}else {
			cout << " La fecha de nacimiento es: " << dia << "/" << mes << "/" << annio << endl;
			fechilla = 1;
			}}}
		}
		catch (const char* excepcion) {
			cout << excepcion;
		}
	}
	if (sisMatriculita->getProfesorPpio() != nullptr) {
		cout << sisMatriculita->mostrarProfesor();
		cout << " Digite el numero de la lista de l@s profesores. " << endl;
		cin >> opcion;
		profesorcito = sisMatriculita->buscarProfesor(opcion);
	}else {
		cout << " NO hay profesores en el sistema. " << endl;
	}
	fechita = new Fecha(dia, mes, annio);
	encargadito = new Encargado(cedulaEnca, nombreEnca, apellidoEnca, telefonoEnca, direccionEnca);
	estudiantito = new Estudiante(cedulaEstu, nombreEstu, cedulaEstu, profesorcito, encargadito, fechita);
	sisMatriculita->agregarEstudiante(estudiantito);
	profesorcito->agregarEstudiante(estudiantito);
	fechilla = false;
	while (fechilla == false) {
		try {
			cout << " Digite el annio de la matricula. " << endl;
			cin >> annioMat;
			cout << " Digite el mes de la matricula. " << endl;
			cin >> mesMat;
			if (mesMat < 1 || mesMat > 12) {
			throw " El mes que escribio NO es correcto\n\n";
			fechilla = 0;
			}else {
			cout << " Digite el dia de la matricula. " << endl;
			cin >> diaMat;
			if ((mesMat == 1 || mesMat == 3 || mesMat == 5 || mesMat == 7 || mesMat == 8 || mesMat == 10 || mesMat == 12) && (diaMat < 1 || diaMat > 31)) {
			throw " El dia que escribio NO es valido.\n\n";
			fechilla = 0;
			}else {
			if ((mesMat == 4 || mesMat == 6 || mesMat == 9 || mesMat == 11) && (dia < 1 || dia > 31) || (mesMat == 2 && diaMat > 28)) {
			throw " El dia que escribio NO es valido.\n\n";
			fechilla = 0;
			}else {
			cout << " La fecha de la matricula es: " << diaMat << "/" << mesMat << "/" << annioMat << endl;
			fechilla = 1;
			}}}}
		catch (const char* excepcion) {
			cout << excepcion;
		}
	}
	fechitaMat = new Fecha(diaMat, mesMat, annioMat);

	cout << "Escriba el codigo de la matricula. " << endl;
	cin >> codigoMat;
	matriculita = new Matricula(codigoMat, fechitaMat, "12:12:12", profesorcito, estudiantito, encargadito);
	sisMatriculita->agregarMatricula(matriculita);
	system("pause");
}


void Vista::muestraEstudiante() {
	if (sisMatriculita->getEstudiantePpio() != nullptr) {
	cout << " Mostrando estudiantes..." << endl;
	cout << sisMatriculita->mostrarEstudiante();
	}else {
		cout << " No se encuentra en el sistema SIGMA" << endl;
	}
}

void Vista::muestraEstudiantePorProfe() {
	int opc = 0;
	ProfesorGuia* profe = nullptr;
	cout << sisMatriculita->mostrarProfesor();
	cout << " Digite la posicion del profesor guia" << endl;
	cin >> opc;
	profe = sisMatriculita->buscarProfesor(opc);
	if (profe != nullptr) {
	cout << " Mostrando lista de estudiantes: " << profe->getNombre() << endl;
	cout << profe->mostrarEstudiante();
	}else {
		cout << " NO hay profesores en el sistema " << endl;
	}
}

//bool Vista::poneFecha(int dia, int mes, int annio) {
//	try {
//		cout << " Digite el annio" << endl;
//		cin >> annio;
//		cout << " Digite el mes" << endl;
//		cin >> mes;
//		if (mes < 1 || mes > 12) {
//		throw " El mes que usted digito NO es correcto \n";
//		return 0;
//		}else {
//			cout << " Digite el dia" << endl;
//			cin >> dia;
//			if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && (dia < 1 || dia > 31)) {
//			throw " El dia que usted digito NO es correcto \n";
//			return 0;
//			}
//		}
//	}
//	catch (const char excepcion) {
//		cout << excepcion;
//	}
//}

void Vista::eliminaEstu() {
	Estudiante* est = nullptr;
	Matricula* mat = nullptr;
	string nombreE = "";
	if (sisMatriculita->getEstudiantePpio() != nullptr) {
		cout << sisMatriculita->mostrarEstudiante();
		cout << " Digite el nombre del estudiante que quiere eliminar. " << endl;
		cin >> nombreE;
		for (int i = 0; i < sisMatriculita->getN_Estu(); i++) {
			est = sisMatriculita->buscarEstudiante(i);
			if (est->getNombre() == nombreE) {
				for (int j = 0; j < sisMatriculita->getN_Matri(); j++) {
				mat = sisMatriculita->buscarMatricula(i);
				if (mat->getCodigoEstudiante() == est->getCedula()) {
				sisMatriculita->eliminarMatricula(i);
				}
				}
				sisMatriculita->eliminarEstudiante(i);
			}
		}
	}else {
		cout << "No hay estudiantes en el sistema." << endl;
	}
}

void Vista::mostrarEstudiantes() {
	if (sisMatriculita->getEstudiantePpio() != nullptr) {
	cout << " Mostrando a los estudiantes. " << endl;
	cout << sisMatriculita->mostrarEstudiante();
	}else {
	cout << " No hay ningun estudiante en el sistema." << endl;
	}
	system("pause");
}

void Vista::muestraEstudiantesPorProfeGuia() {
	int opcion = 0;
	ProfesorGuia* pro = nullptr;
	cout << sisMatriculita->mostrarProfesor();
	cout << " Digite la posicion del profesor. " << endl;
	cin >> opcion;
	pro = sisMatriculita->buscarProfesor(opcion);
	if (pro != nullptr) {
	cout << " Mostrando la lista de estudiantes de " << pro->getNombre() << endl;
	cout << pro->mostrarEstudiante();
	}else {
	cout << " Sin profesores guias en el sistema. " << endl;
	}
	system("pause");
}

void Vista::guardaDatos() {
	sisMatriculita->guardaDatosBina();
}

void Vista::recuperaDatos() {
	sisMatriculita->recuperaDatosBina();
}

void Vista::adios() {
	cout << ". . . . . . . . . . . . . . . . . . ." << endl;
	cout << ". . . . . . . G R A C I A S . . . . ." << endl;
	cout << ". . . . . P O R  U S A R  L A . . . ." << endl;
	cout << ". . . . . A P L I C A C I O N . . . ." << endl;
	cout << ". . . . . . . . . . . . . . . . . . ." << endl;
	Sleep(3000);
}


