#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Estudiante;
class ProfesorGuia;
class Encargado;
class Persona;

class Persona{
protected:
	string cedula, nombre, apellido;
public:
	Persona(string = "", string = "", string = "");
	virtual ~Persona() = default;
	virtual void setCedula(string) = 0;
	virtual void setNombre(string) = 0;
	virtual void setApellido(string) = 0;
	virtual string getCedula() = 0;
	virtual string getNombre() = 0;
	virtual string getApellido() = 0;
	virtual string toString();
	friend ostream& operator <<(ostream&, Persona&);
	Persona& operator = (Persona&);
};

