#include "Fecha.h"

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), annio(a){}

Fecha::Fecha() : dia(0), mes(0), annio(0) {}

void Fecha::setAnnio(int a) {
	annio = a;
}

void Fecha::setDia(int d) {
	dia = d;
}

void Fecha::setMes(int m) {
	mes = m;
}

int Fecha::getAnnio() {
	return annio;
}

int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

string Fecha::toString() {
	stringstream s;
	s << "--- Informacion Importante de la Fecha ---" << endl << endl;
	s << dia << '/' << mes << '/' << annio << endl;
	return s.str();
}

ostream& operator <<(ostream& out, Fecha& p) {
	return out << "Dia..." << p.getDia() << endl
		<< "Mes..." << p.getMes() << endl
		<< "Annio..." << p.getAnnio() << endl << endl;
}

Fecha& Fecha::operator = (Fecha& p) {
	if (this != &p) {
		this->dia = p.dia;
		this->mes = p.mes;
		this->annio = p.annio;
	}
	return *this;
}

Fecha::~Fecha(){}

