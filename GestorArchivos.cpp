#include "GestorArchivos.h"

GestorArchivos::GestorArchivos(){}

GestorArchivos::~GestorArchivos(){}

void GestorArchivos::guardaMatricula(Lista<Matricula>* mat) {
	Matricula* mat1 = nullptr;
	ofstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		for (int i = 0; i < mat->getSize(); i++) {
			mat1 = mat->buscar(i);
			infile.write((char*)&mat1, sizeof(Matricula));
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::guardaEstudiante(Lista<Estudiante>* est) {
	Estudiante* est1 = nullptr;
	ofstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		for (int k = 0; k < est->getSize(); k++) {
			est1 = est->buscar(k);
			infile.write((char*)&est1, sizeof(Estudiante));
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::guardaProfesorGuia(Lista<ProfesorGuia>* pro) {
	ProfesorGuia* pro1 = nullptr;
	ofstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		for (int j = 0; j < pro->getSize(); j++) {
			pro1 = pro->buscar(j);
			infile.write((char*)&pro1, sizeof(ProfesorGuia));
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::guardaEncargado(Lista<Encargado>* enc) {
	Encargado* Carlos = nullptr;
	ofstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		for (int m = 0; m < enc->getSize(); m++) {
			Carlos = enc->buscar(m);
			infile.write((char*)&Carlos, sizeof(Encargado));
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::leeMatricula(Lista<Matricula>* mat) {
	Matricula* mat1 = nullptr;
	ifstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.read((char *)&mat1, sizeof(Matricula));
			mat->insertarInicio(mat1);
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::leeEstudiante(Lista<Estudiante>* est) {
	Estudiante* est1 = nullptr;
	ifstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.read((char *)&est1, sizeof(Estudiante));
			est->insertarInicio(est1);
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::leeProfesorGuia(Lista<ProfesorGuia>* pro) {
	ProfesorGuia* pro1 = nullptr;
	ifstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.read((char *)&pro1, sizeof(ProfesorGuia));
			pro->insertarInicio(pro1);
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

void GestorArchivos::leeEncargado(Lista<Encargado>* n) {
	Encargado* p = nullptr;
	ifstream infile;
	infile.open("archivo.bin", ios::binary);
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile.read((char *)&p, sizeof(Encargado));
			n->insertarInicio(p);
		}
		infile.close();
	}else {
		cout << "Hubo un error al abrir el archivo. " << endl;
	}
}

//void GestorArchivos::guardaDatosJson(Lista<Matricula>* lisMa, Lista<Estudiante>* lisEs, Lista<ProfesorGuia>* lisPro, Lista<Encargado>* lisEnc) {
//	Matricula* m1 = nullptr;
//	Estudiante* e1 = nullptr;
//	ProfesorGuia* p1 = nullptr;
//	Encargado* en1 = nullptr;
//	Fecha* f1 = nullptr;
//	Json::StreamWriterBuilder constructor;
//	constructor["commentStyle"] = "None";
//	constructor["indentation"] = "  ";
//	unique_ptr<Json::StreamWriter> escritor(constructor.newStreamWriter());
//	ofstream archivo("jsonDatos.txt");
//	Json::Value matri;
//	Json::Value estu;
//	Json::Value profe;
//	Json::Value enca;
//	Json::Value fech;
//	Json::Value ListaMa(Json::arrayValue);
//	Json::Value ListaEnc(Json::arrayValue);
//	Json::Value ListaPro(Json::arrayValue);
//	Json::Value ListaEs(Json::arrayValue);
//	//--------Matricula--------
//	for (int i = 0; i < lisMa->getN(); i++) {
//		m1 = lisMa->retornaElemento(i);
//		matri["Codigo: "] = m1->getCodigo();
//		matri["Fecha: "] = fech["Dia "] = f1->getDia(), fech["Mes "] = f1->getMes(), fech["Annio "] = f1->getAnnio();
//		matri["ProfesorGuia: "] = profe["Cedula "] = p1->getCedula(), profe["Nombre "] = p1->getNombre(), profe["Apellido "] = p1->getApellido();
//		matri["Estudiante: "] = estu["Cedula "] = e1->getCedula(), estu["Nombre "] = e1->getNombre(), estu["Apellido "] = e1->getApellido();
//		matri["Encargado: "] = enca["Cedula "] = en1->getCedula(), enca["Nombre "] = en1->getNombre(), enca["Apellido "] = en1->getApellido(),
//			                                     enca["Direccion "] = en1->getDireccion(), enca["Telefono "] = en1->getTelefono();
//		ListaMa.append(matri);
//	}
//	escritor->write(ListaMa, &archivo);
//	archivo.close();
//
//	//--------Estudiante--------
//	for (int j = 0; j < lisEs->getN(); j++) {
//		e1 = lisEs->retornaElemento(j);
//		estu["Cedula: "] = e1->getCedula();
//		estu["Nombre: "] = e1->getNombre();
//		estu["Apellido: "] = e1->getApellido();
//		ListaEs.append(estu);
//	}
//	escritor->write(ListaEs, &archivo);
//	archivo.close();
//
//	//---------Profesor---------
//	for (int k = 0; k < lisPro->getN(); k++) { 
//		p1 = lisPro->retornaElemento(k);
//		profe["Cedula: "] = p1->getCedula();
//		profe["Nombre: "] = p1->getNombre();
//		profe["Apellido: "] = p1->getApellido();
//		ListaPro.append(profe);
//	}
//	escritor->write(ListaPro, &archivo);
//	archivo.close();
//
//	//---------Encargado---------
//	for (int l = 0; l < lisEnc->getN(); l++) { 
//		en1 = lisEnc->retornaElemento(l);
//		profe["Cedula: "] = en1->getCedula();
//		profe["Nombre: "] = en1->getNombre();
//		profe["Apellido: "] = en1->getApellido();
//		profe["Direccion: "] = en1->getDireccion();
//		profe["Telefono: "] = en1->getTelefono();
//		ListaEnc.append(enca);
//	}
//	escritor->write(ListaEnc, &archivo);
//	archivo.close();
//}
