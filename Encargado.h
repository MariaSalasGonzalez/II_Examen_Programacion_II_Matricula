#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Persona.h"
using namespace std;

class Encargado;
class Persona;

class Encargado: public Persona {
private:
	string direccion, telefono;
public:
	Encargado(string = "", string = "", string = "", string = "", string = "");
	void setCedula(string);
	void setNombre(string);
	void setApellido(string);
	void setDireccion(string);
	void setTelefono(string);
	string getCedula();
	string getNombre();
	string getApellido();
	string getDireccion();
	string getTelefono();
	virtual string toString();
	virtual ~Encargado();
	friend ostream& operator <<(ostream&, Encargado&);
	Encargado& operator = (Encargado&);
};


