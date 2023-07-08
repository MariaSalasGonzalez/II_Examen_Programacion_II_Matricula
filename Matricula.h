#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include "Lista.h"
#include "Estudiante.h"
#include "ProfesorGuia.h"
#include "Encargado.h"
#include "Fecha.h"
using namespace std;

class Matricula;
class Fecha;
class Estudiante;
class ProfesorGuia;

class Matricula {
private:
	string codigo;
	string hora;
	Fecha* fechita;
	ProfesorGuia* profesorcito;
	Estudiante* estudiantito;
	Encargado* encargadito;
public:
	Matricula(string = "", Fecha* = nullptr, string = "",
		     ProfesorGuia* = nullptr, Estudiante* = nullptr, Encargado* = nullptr);
	void setCodigo(string);
	void setFecha(Fecha*);
	void setHora(string);
	void setProfesor(ProfesorGuia*);
	void setEstudiante(Estudiante*);
	void setEncargado(Encargado*);
	string getCodigoEstudiante();
	string getCodigo();
	Fecha* getFecha();
	string getHora();
	ProfesorGuia* getProfesor();
	Estudiante* getEstudiante();
	Encargado* getEncargado();
	string toString();
	~Matricula();
	friend ostream& operator <<(ostream&, Matricula&);
	Matricula& operator = (Matricula&);
};