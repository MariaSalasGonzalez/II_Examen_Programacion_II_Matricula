#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Lista.h"
#include "Matricula.h"
#include "Encargado.h"
#include "Estudiante.h"
#include "ProfesorGuia.h"
using namespace std;

class GestorArchivos;
class GestorArchivos{
public:
	GestorArchivos();
	void leeEncargado(Lista<Encargado>*);
	void leeProfesorGuia(Lista<ProfesorGuia>*);
	void leeEstudiante(Lista<Estudiante>*);
	void leeMatricula(Lista<Matricula>*);
	void guardaEncargado(Lista<Encargado>*);
	void guardaProfesorGuia(Lista<ProfesorGuia>*);
	void guardaEstudiante(Lista<Estudiante>*);
	void guardaMatricula(Lista<Matricula>*);
	~GestorArchivos();
};

