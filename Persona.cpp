#include "Persona.h"

Persona::Persona(string ced, string nom, string ape): cedula(ced), nombre(nom), apellido(ape){}

string Persona::toString(){
	stringstream s;
	s << "--- Datos de la Persona ---" << endl;
	s << " Cedula: " << getCedula() << endl;
	s << " Nombre: " << getNombre() << endl;
	s << " Apellido: " << getApellido() << endl;
	return s.str();
}

ostream& operator <<(ostream& out, Persona& p) {
	return out << "Cedula..." << p.getCedula() << endl
		       << "Nombre..." << p.getNombre() << endl
		       << "Apellido....." << p.getApellido() << endl << endl;
}

Persona& Persona::operator = (Persona& p) {
	if (this != &p) {
		this->cedula = p.cedula;
		this->nombre = p.nombre;
		this->apellido = p.apellido;
	}
	return *this;
}