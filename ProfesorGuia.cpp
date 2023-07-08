#include "ProfesorGuia.h"

ProfesorGuia::ProfesorGuia(string cedula, string nombre, string apellido) : Persona(cedula, nombre, apellido) {
	                       listaEstudiante = new Lista<Estudiante>();
}

void ProfesorGuia::setCedula(string ced){
	cedula = ced;
}

void ProfesorGuia::setNombre(string nom) {
	nombre = nom;
}

void ProfesorGuia::setApellido(string ape) {
	apellido = ape;
}

void ProfesorGuia::agregarEstudiante(Estudiante* est){
	listaEstudiante->insertarInicio(est);
}

void ProfesorGuia::mostrarProfeXEstudiante() {
}

bool ProfesorGuia::eliminarEstudiante(int lugar) {
	return listaEstudiante->eliminarEspecifico(lugar);
}

Estudiante* ProfesorGuia::buscarEstudiante(int lugar) {
	return listaEstudiante->buscar(lugar);
}

string ProfesorGuia::mostrarEstudiante() {
	return listaEstudiante->toString();
}

string ProfesorGuia::getCedula() {
	return cedula;
}

string ProfesorGuia::getNombre() {
	return nombre;
}

string ProfesorGuia::getApellido() {
	return apellido;
}

Lista<Estudiante>* ProfesorGuia::getListaEstudiante() {
	return listaEstudiante;
}

string ProfesorGuia::toString() {
	stringstream s;
	s << "--- Informacion Importante del Profesor Guia ---" << endl << endl;
	s << Persona::toString();
	s << " Lista Estudiante: "<< getListaEstudiante() << endl;
	return s.str();
}

ProfesorGuia::~ProfesorGuia() {
	delete listaEstudiante;
}

ostream& operator << (ostream& out, ProfesorGuia& p) {
	return out << "Cedula..." << p.cedula << endl
		<< "Nombre..." << p.nombre << endl
		<< "Apellido..." << p.apellido << endl
		<< "Lista Estudiante..."<< p.listaEstudiante << endl;
		if (p.getListaEstudiante() != NULL)
		out << p.getListaEstudiante()->verLista() << endl;
}

ProfesorGuia& ProfesorGuia::operator = (ProfesorGuia& p) {
	if (this != &p) {
		this->cedula = p.cedula;
		this->nombre = p.nombre;
		this->apellido = p.apellido;
		this->listaEstudiante = p.listaEstudiante;
	}
	return *this;
}
