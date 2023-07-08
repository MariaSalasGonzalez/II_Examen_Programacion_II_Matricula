#include "Estudiante.h"

Estudiante::Estudiante(string ced, string nom, string ape, ProfesorGuia* profe, Encargado* enca, Fecha* fec): 
	                   profesorcito(profe), encargadito(enca), fechita(fec), Persona(ced,nom,ape) {}

void Estudiante::setCedula(string ced) {
	cedula = ced;
}

void Estudiante::setNombre(string nom) {
	nombre = nom;
}

void Estudiante::setApellido(string ape) {
	apellido = ape;
}

void Estudiante::setFecha(Fecha* fec){
	fechita = fec;
}

void Estudiante::setEncargado(Encargado* enc) {
	encargadito = enc;
}

void Estudiante::setProfesor(ProfesorGuia* proG) {
	profesorcito = proG;
}

string Estudiante::getCedula() {
	return cedula;
}

string Estudiante::getNombre() {
	return nombre;
}

string Estudiante::getApellido() {
	return apellido;
}

Fecha* Estudiante::getFecha() {
	return fechita;
}

Encargado* Estudiante::getEncargado() {
	return encargadito;
}

ProfesorGuia* Estudiante::getProfesorGuia() {
	return profesorcito;
}

string Estudiante::toString() {
	stringstream s;
	s << "--- Informacion importante del estudiante ---" << endl << endl;
	s << Persona::toString();
	s << " Fecha Nacimiento: " << fechita->getDia()<< "/"<<fechita->getMes()<< "/" <<fechita->getAnnio() << endl; 
	s << " Encargado: " << encargadito->getNombre() << endl;
	s << " Profesor: " << profesorcito->getNombre() << endl;
	return s.str();
}

Estudiante::~Estudiante() {
	delete profesorcito;
	delete encargadito;
	delete fechita;
}

ostream& operator <<(ostream& out, Estudiante& p) {
	return out << "Cedula..." << p.getCedula() << endl
		       << "Nombre..." << p.getNombre() << endl
		       << "Apellido..." << p.getApellido() << endl
		       << "Fecha: " << *p.getFecha() << endl
	           << "Encargado: " << *p.getEncargado() << endl
	           << "Profesor: " << *p.getProfesorGuia() << endl;
}

Estudiante&  Estudiante::operator = (Estudiante& p) {
	if (this != &p) {
		this->cedula = p.cedula;
		this->nombre = p.nombre;
		this->apellido = p.apellido;
		this->fechita = new Fecha(p.fechita->getDia(), p.fechita->getMes(), p.fechita->getAnnio());
		this->encargadito = new Encargado(p.encargadito->getCedula(), p.encargadito->getNombre(), p.encargadito->getApellido(),
			                              p.encargadito->getDireccion(), p.encargadito->getTelefono());
		this->profesorcito = new ProfesorGuia(p.profesorcito->getCedula(), p.profesorcito->getNombre(), p.profesorcito->getApellido());
	}
	return *this;
}

