#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Lista.h"
#include "Estudiante.h"
#include "Persona.h"
using namespace std;

class ProfesorGuia;
class Estudiante;
class ProfesorGuia : public Persona {
private:
	Lista<Estudiante>* listaEstudiante;
public:
	ProfesorGuia(string = "", string = "", string = "");
	void setCedula(string);
	void setNombre(string);
	void setApellido(string);
	void agregarEstudiante(Estudiante*);
	void mostrarProfeXEstudiante();
	Estudiante* buscarEstudiante(int);
	string mostrarEstudiante();
	string getCedula();
	string getNombre();
	string getApellido();
	bool eliminarEstudiante(int);
	Lista<Estudiante>* getListaEstudiante();
	virtual string toString();
	virtual ~ProfesorGuia();
	friend ostream& operator <<(ostream&, ProfesorGuia&);
	ProfesorGuia& operator = (ProfesorGuia&);
};



