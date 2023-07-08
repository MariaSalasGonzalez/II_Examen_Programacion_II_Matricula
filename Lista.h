#pragma once;
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Nodo.h"
#include "IteradorLista.h"

template<class T>
class Lista{					
private:			
	Nodo<T> *primero;
	int size;
public:
	Nodo<T>* getPrimero();
	Lista();
	Lista(Lista&);
	bool esVacia();
	void insertarInicio(T*);
	void insertarFinal(T*);
	int getSize();
	string toString();
	T* buscar(int); 
	bool eliminarInicio();
	bool eliminarFinal();
	bool eliminarEspecifico(int);
	Lista& operator=(Lista&);
	~Lista();
	IteradorLista<T>* obtenerIterador();
	string verLista();
	void guardar(ofstream& salida);
	void guardar1(ofstream & salida);
};

//Desarrollo de Metodos
template <class T>
Lista<T>::Lista(Lista &aux) {
	while (!esVacia()){
		eliminarInicio();
	}
	primero = nullptr;
	size = 0;
	Nodo<T>* actual = aux.primero;
	while (actual){
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
}

template<class T>
int Lista<T>::getSize() {
	return size;
}

template <class T>
string Lista<T>::verLista() {
	Nodo<T>* p = primero;
	int cont = 1;
	stringstream s;
	if (p == NULL) {
		s << "No hay elementos en la lista..." << endl;
	}else {
		while (p != NULL){
			s << "No." << cont << endl << (p->getInfo()) << endl;
			p = p->getSig();
			cont++;
		}
	}
	return s.str();
}

template<class T>
bool Lista<T>::esVacia() {
	return (primero == nullptr);
}

template<class T>
inline Nodo<T>* Lista<T>::getPrimero(){
	return primero;
}

template<class T>
Lista<T>::Lista() {
	primero = nullptr;
	size = 0;
}

template<class T>
string Lista<T>::toString(){
	stringstream s;
	Nodo<T> *actual = primero;
	int contador = 1;
	while (actual != nullptr){
		s << "---------------------------------------------------------" << endl;
		s << endl;
		s << contador << ")" << *actual->getInfo();
		contador++;
		actual = actual->getSig();
		s << endl;
	}
	return s.str();
}

template<class T>
void Lista<T>::insertarInicio(T* dato) {
	Nodo<T> *actual;
	actual = new Nodo<T>(dato);
	actual->setSig(primero);
	primero = actual;
	size++;
}

template <class T>
void Lista<T>::insertarFinal(T* dato) {
	Nodo<T>* actual = primero;
	if (esVacia()) {
		insertarInicio(dato);
	}else {
		while (actual->getSig() != nullptr){
			actual = actual->getSig();
		}
		actual->setSig(new Nodo<T>(dato));
		size++;
	}
}

template<class T>
T* Lista<T>::buscar(int lug){
	int cont = 1;
	Nodo<T>* p = primero;
	while (p != nullptr && cont < lug) {
		p = p->getSig();
		cont++;
	}
	if (p == nullptr)
		return nullptr;
	if (cont == lug) {
		return p->getInfo();
	}
	return 0;
}

template<class T>
bool Lista<T>::eliminarInicio() {
	Nodo<T>* p = primero;
	if (primero != nullptr) {
		p = primero->getSig();
		delete primero;
		primero = p;
		return true;
	}
	return false;
}

template<class T>
bool Lista<T>::eliminarFinal() {
	Nodo<T>* actual = primero;
	if (primero == nullptr){
		return false;
	}else{
		if (primero->getSig() == nullptr){
			delete primero;
			size--;
			primero = nullptr;
		}else{
			while (actual->getSig()->getSig() != nullptr){
				actual = actual->getSig();
			}
			delete  actual->getSig();
			size--;
			actual->setSig(nullptr);
		}
		return true;
	}
}

template<class T>
bool Lista<T>::eliminarEspecifico(int position) {
	if (getPrimero() == nullptr) {
		return false;
	}else {
		Nodo<T>* eliminar;
		if (position == 0) {
			eliminar = getPrimero();
			primero = primero->getSig();
			delete eliminar;
			return 1;
		} else {
			Nodo<T>* auxiliar = primero;
			for (int i = 0; auxiliar->getSig() != nullptr && i < position - 1; i++) {
				auxiliar = auxiliar->getSig();
			}
			if (auxiliar->getSig() != nullptr) {
				eliminar = auxiliar->getSig();
				auxiliar->setSig(eliminar->getSig());
				delete eliminar;
				return 1;
			}
		}
		return 0;
	}
	return 0;
}

template <class T>
Lista<T>& Lista<T>::operator=(Lista& aux){
	while (!esVacia()){
		eliminarInicio();
	}
	primero = nullptr;
	size = 0;
	Nodo<T>* actual = aux.primero;
	while (actual){
		insertarFinal(actual->getInfo());
		actual = actual->getSig();
	}
	return *this;
}

template<class T>
Lista<T>::~Lista(){
	while (!esVacia())
		eliminarInicio();
	size = 0;
}

template<class T>
inline IteradorLista<T>* Lista<T>::obtenerIterador(){
	return new IteradorLista<T>(primero);
}

template<class T>
inline void Lista<T>::guardar(ofstream & salida){
	T*_t;
	Nodo<T>* actual = primero;
	while (actual != nullptr) {
		_t = actual->getInfo();
		if (_t != nullptr) {
			_t->autoGuardar(salida);
		}
		actual = actual->getSig();
	}
}

template<class T>
inline void Lista<T>::guardar1(ofstream & salida){
	T*_t;
	Nodo<T>*actual = primero;
	while (actual != nullptr) {
		_t = actual->getInfo();
		if (_t != nullptr) {
			_t->autoGuardar2(salida);
		}
		actual = actual->getSig();
	}
}



