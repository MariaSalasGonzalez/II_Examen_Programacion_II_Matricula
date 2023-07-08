#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Lista.h"
#include "Matricula.h"
#include "Encargado.h"
#include "ProfesorGuia.h"
#include "Estudiante.h"
#include "GestorArchivos.h"
using namespace std;

class SistemaMatricula;
class SistemaMatricula{
private:
	int N;
	Lista<Matricula>* listaMatricula;
	Lista<Encargado>* listaEncargado;
	Lista<Estudiante>* listaEstudiante;
	Lista<ProfesorGuia>* listaProfesor;
	GestorArchivos* gestor;
public:
	SistemaMatricula();
	void agregaProfesorGuia();
	void agregarMatricula(Matricula*);
	void agregarEstudiante(Estudiante*);
	void agregarProfesor(ProfesorGuia*);
	void agregarEncargado(Encargado*);
	bool eliminarEstudiante(int);
	bool eliminarEncargado(int);
	bool eliminarProfesor(int);
	bool eliminarMatricula(int);
	int getN_Estu();
	int getN_Profe();
	int getN_Enca();
	int getN_Matri();
	Nodo<Matricula>* getMatriculaPpio();
	Nodo<ProfesorGuia>* getProfesorPpio();
	Nodo<Estudiante>* getEstudiantePpio();
	Nodo<Encargado>* getEncargadoPpio();
	Lista<Matricula>* getListaMatricula();
	Lista<Encargado>* geLlistaEncargado();
	Lista<Estudiante>* getListaEstudiante();
	Lista<ProfesorGuia>* getListaProfesor();
	Matricula* buscarMatricula(int);
	Estudiante* buscarEstudiante(int);
	ProfesorGuia* buscarProfesor(int);
	Encargado* buscarEncargado(int);
	string mostrarMatricula();
	string mostrarEstudiante();
	string mostrarProfesor();
	string mostrarEncargados();
	void guardaDatosBina();
	void recuperaDatosBina();
	~SistemaMatricula();
};

