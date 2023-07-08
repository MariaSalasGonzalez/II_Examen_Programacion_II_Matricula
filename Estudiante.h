#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Encargado.h"
#include "ProfesorGuia.h"
#include "Fecha.h"
#include "Persona.h"
using namespace std;

class Estudiante;
class Persona;
class Encargado;
class ProfesorGuia;
class Estudiante : public Persona {
private:
	Fecha* fechita;
	Encargado* encargadito;
	ProfesorGuia* profesorcito;
public:
	Estudiante(string = "", string = "", string = "", ProfesorGuia* = nullptr, Encargado* = nullptr, Fecha* = nullptr);
	void setCedula(string);
	void setNombre(string);
	void setApellido(string);
	void setFecha(Fecha*);
	void setEncargado(Encargado*);
	void setProfesor(ProfesorGuia*);
	string getCedula();
	string getNombre();
	string getApellido();
	Fecha* getFecha();
	Encargado* getEncargado();
	ProfesorGuia* getProfesorGuia();
	virtual string toString();
	virtual ~Estudiante();
	friend ostream& operator <<(ostream&, Estudiante&);
	Estudiante& operator = (Estudiante&);
};
