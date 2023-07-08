#include "Encargado.h"

Encargado::Encargado(string ced, string nom, string ape, string dire, string tel): direccion(dire), telefono(tel), Persona(ced, nom, ape) {}

void Encargado::setCedula(string ce) {
	cedula = ce;
}

void Encargado::setNombre(string nom) {
	nombre = nom;
}

void Encargado::setApellido(string ape) {
	apellido = ape;
}

void Encargado::setDireccion(string dire) {
	direccion = dire;
}

void Encargado::setTelefono(string tel) {
	telefono = tel;
}

string Encargado::getCedula() {
	return cedula;
}

string Encargado::getNombre() {
	return nombre;
}

string Encargado::getApellido() {
	return apellido;
}

string Encargado::getDireccion() {
	return direccion;
}

string Encargado::getTelefono() {
	return telefono;
}

string Encargado::toString() {
	stringstream s;
	s << "--- Informacion Importante del Encargado ---" << endl << endl;
	s << Persona::toString();
	s << " Direccion: "<< getDireccion() << endl;
	s << " Telefono: "<< getTelefono() << endl;
	return s.str();
}

ostream& operator <<(ostream& out, Encargado& p) {
	return out << "Cedula..." << p.cedula << endl
		<< "Nombre..." << p.nombre << endl
		<< "Apellido....." << p.apellido << endl
		<< "Direccion..."<< p.direccion << endl
		<< "Telefono..."<< p.telefono<<endl;
}

Encargado& Encargado::operator = (Encargado& p) {
	this->cedula = p.cedula;
	this->nombre = p.nombre;
	this->apellido = p.apellido;
	this->direccion = p.direccion;
	this->telefono = p.telefono;
	return *this;
}

Encargado::~Encargado() {}
