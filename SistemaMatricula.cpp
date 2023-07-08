#include "SistemaMatricula.h"

SistemaMatricula::SistemaMatricula() {
	listaEstudiante = new Lista<Estudiante>(); listaEncargado = new Lista<Encargado>(); listaProfesor = new Lista<ProfesorGuia>();
	listaMatricula = new Lista<Matricula>(); gestor = new GestorArchivos();
}

void SistemaMatricula::guardaDatosBina() {
	gestor->guardaEstudiante(listaEstudiante);
	gestor->guardaEncargado(listaEncargado);
	gestor->guardaMatricula(listaMatricula);
	gestor->guardaProfesorGuia(listaProfesor);
}

void SistemaMatricula::recuperaDatosBina() {
	gestor->leeEstudiante(listaEstudiante);
	gestor->leeEncargado(listaEncargado);
	gestor->leeMatricula(listaMatricula);
	gestor->leeProfesorGuia(listaProfesor);
}

void SistemaMatricula::agregaProfesorGuia() {
	//Para crear los profesores
	ProfesorGuia* prof1 = new ProfesorGuia("22222", "Ivonne", "1.");
	ProfesorGuia* prof2 = new ProfesorGuia("33333", "Maribel", "1.");
	ProfesorGuia* prof3 = new ProfesorGuia("44444", "Maria", "1.");
	ProfesorGuia* prof4 = new ProfesorGuia("55555", "Ricardo", "1.");
	ProfesorGuia* prof5 = new ProfesorGuia("66666", "JeanCarlos", "1.");
	//Los inserta
	listaProfesor->insertarInicio(prof1);
	listaProfesor->insertarInicio(prof2);
	listaProfesor->insertarInicio(prof3);
	listaProfesor->insertarInicio(prof4);
	listaProfesor->insertarInicio(prof5);
}

void SistemaMatricula::agregarMatricula(Matricula* matri) {
	listaMatricula->insertarInicio(matri);
}

void SistemaMatricula::agregarEstudiante(Estudiante* est) {
	listaEstudiante->insertarInicio(est);
}

void SistemaMatricula::agregarProfesor(ProfesorGuia* pro) {
	listaProfesor->insertarInicio(pro);
}

void SistemaMatricula::agregarEncargado(Encargado* enc) {
	listaEncargado->insertarInicio(enc);
}

bool SistemaMatricula::eliminarEstudiante(int lugar){
	return listaEstudiante->eliminarEspecifico(lugar);
}

bool SistemaMatricula::eliminarEncargado(int lugar) {
	return listaEncargado->eliminarEspecifico(lugar);
}

bool SistemaMatricula::eliminarProfesor(int lugar) {
	return listaProfesor->eliminarEspecifico(lugar);
}

bool SistemaMatricula::eliminarMatricula(int lugar) {
	return listaMatricula->eliminarEspecifico(lugar);
}

Nodo<Matricula>* SistemaMatricula::getMatriculaPpio(){
	return listaMatricula->getPrimero();
}

Nodo<ProfesorGuia>* SistemaMatricula::getProfesorPpio(){
	return listaProfesor->getPrimero();
}

Nodo<Estudiante>* SistemaMatricula::getEstudiantePpio(){
	return listaEstudiante->getPrimero();
}

Nodo<Encargado>* SistemaMatricula::getEncargadoPpio(){
	return listaEncargado->getPrimero();
}

int SistemaMatricula::getN_Estu() {
	return listaEstudiante->getSize();
}

int SistemaMatricula::getN_Profe() {
	return listaProfesor->getSize();
}

int SistemaMatricula::getN_Enca() {
	return listaEncargado->getSize();
}

int SistemaMatricula::getN_Matri() {
	return listaMatricula->getSize();
}

Lista<Matricula>* SistemaMatricula::getListaMatricula() {
	return listaMatricula;
}

Lista<Encargado>* SistemaMatricula::geLlistaEncargado() {
	return listaEncargado;
}

Lista<Estudiante>* SistemaMatricula::getListaEstudiante() {
	return listaEstudiante;
}

Lista<ProfesorGuia>* SistemaMatricula::getListaProfesor() {
	return listaProfesor;
}

Matricula* SistemaMatricula::buscarMatricula(int lug) {
	return listaMatricula->buscar(lug);
}

Estudiante* SistemaMatricula::buscarEstudiante(int lug) {
	return listaEstudiante->buscar(lug);
}

ProfesorGuia* SistemaMatricula::buscarProfesor(int lug) {
	return listaProfesor->buscar(lug);
}

Encargado* SistemaMatricula::buscarEncargado(int lug) {
	return listaEncargado->buscar(lug);
}

string SistemaMatricula::mostrarMatricula() {
	return listaMatricula->toString();
}

string SistemaMatricula::mostrarEstudiante() {
	return listaEstudiante->toString();
}

string SistemaMatricula::mostrarProfesor() {
	return listaProfesor->toString();
}

string SistemaMatricula::mostrarEncargados() {
	return listaEncargado->toString();
}

SistemaMatricula::~SistemaMatricula() {
	delete listaMatricula;
	delete listaEstudiante;
	delete listaProfesor;
	delete listaEncargado;
	delete gestor;
}


