#include "Matricula.h"

Matricula::Matricula(string cod, Fecha* fec, string ho, ProfesorGuia* proG, Estudiante* est, Encargado* enc) :
	      codigo(cod), fechita(fec), hora(ho), profesorcito(proG), estudiantito(est), encargadito(enc) {}

void Matricula::setCodigo(string cod) {
	codigo = cod;
}

void Matricula::setFecha(Fecha* fec) {
	fechita = fec;
}

void Matricula::setHora(string ho) {
	hora = ho;
}

void Matricula::setProfesor(ProfesorGuia* proG) {
	profesorcito = proG;
}

void Matricula::setEstudiante(Estudiante* est) {
	estudiantito = est;
}

void Matricula::setEncargado(Encargado* enc) {
	encargadito = enc;
}

string Matricula::getCodigo() {
	return codigo;
}

Fecha* Matricula::getFecha() {
	return fechita;
}

string Matricula::getHora() {
	return hora;
}

string Matricula::getCodigoEstudiante() {
	return estudiantito->getCedula();
}

ProfesorGuia* Matricula::getProfesor() {
	return profesorcito;
}
Estudiante* Matricula::getEstudiante() {
	return estudiantito;
}

Encargado*Matricula::getEncargado() {
	return encargadito;
}

string Matricula::toString() {
	stringstream s;
	s << "--- Informacion Importante de la Matricula ---" << endl << endl;
	s << " Codigo: " << getCodigo() << endl;
	s << " Fecha: " << getFecha() << endl;
	s << " Hora: " << getHora() << endl;
	s << " Profesor: " << getProfesor() << endl;
	s << " Estudiante: " << getEstudiante() << endl;
	s << " Encargado: " << getEncargado() << endl;
	return s.str();
}

Matricula::~Matricula() {
	delete fechita;
	delete profesorcito;
	delete estudiantito;
	delete encargadito;
}

ostream& operator <<(ostream& out, Matricula& p) {
	return out << "Codigo..." << p.getCodigo() << endl
		       << "Hora..." << p.getHora() << endl
		       << "Fecha: " << *p.getFecha() << endl
	           << "Profesor: " << *p.getProfesor() << endl
	           << "Estudiante: " << *p.getEstudiante() << endl
			   << "Encargado: " << *p.getEncargado() << endl;
}

Matricula& Matricula::operator = (Matricula& p) {
	if (this != &p) {
		this->codigo = p.codigo;
		this->fechita = new Fecha(p.fechita->getDia(), p.fechita->getMes(), p.fechita->getAnnio());
		this->hora = p.hora;
		this->profesorcito = new ProfesorGuia(p.profesorcito->getCedula(), p.profesorcito->getNombre(), p.profesorcito->getApellido());

		this->estudiantito = new Estudiante(p.estudiantito->getCedula(), p.estudiantito->getNombre(), p.estudiantito->getApellido(),
			new ProfesorGuia(p.profesorcito->getCedula(), p.profesorcito->getNombre(), p.profesorcito->getApellido()),
			                                 new Encargado(p.encargadito->getCedula(), p.encargadito->getNombre(), p.encargadito->getApellido(),
			                                p.encargadito->getDireccion(), p.encargadito->getTelefono()), new Fecha(p.fechita->getDia(),
			                                p.fechita->getMes(), p.fechita->getAnnio()));
		this->encargadito = new Encargado(p.encargadito->getCedula(), p.encargadito->getNombre(), p.encargadito->getApellido(),
			                              p.encargadito->getDireccion(), p.encargadito->getTelefono());
	
	}
	return *this;
}

