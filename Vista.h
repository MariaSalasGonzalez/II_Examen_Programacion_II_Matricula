#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "GestorArchivos.h"
#include "Estudiante.h"
#include "Fecha.h"
#include "ProfesorGuia.h"
#include "Encargado.h"
#include "Matricula.h"
#include "SistemaMatricula.h"
using namespace std;

class Vista;
class Controladora;
class Encargado;
class Estudiante;
class Fecha;
class ProfesorGuia;
class Matricula;
class SistemaMatricula;

class Vista {
private:
	SistemaMatricula* sisMatriculita;
public:
	Vista(SistemaMatricula* = nullptr);
	void inicia();
	void cargaProfesorGuia();
	int menuPrincipal();
	void menuAgregaEstudiante();
	void muestraEstudiante();
	void muestraEstudiantePorProfe();
	void mostrarEstudiantes();
	void muestraEstudiantesPorProfeGuia();
	void eliminaEstu();
	void guardaDatos();
	void recuperaDatos();
	void adios();
};
