#pragma once
#include "Nodo.h"

template<class T>
class IteradorLista{
private:
	Nodo<T>* cursor;
public:
	IteradorLista(Nodo<T>*);
	virtual bool masElementos();
	virtual T* proximoElemento();
	~IteradorLista();
};

//Desarrollo de Metodos
template<class T>
inline IteradorLista<T>::IteradorLista(Nodo<T>* elNod){
	cursor = elNod;
}

template<class T>
inline bool IteradorLista<T>::masElementos(){
	if (cursor != nullptr) {
		return true;
	}else
		return false;
}

template<class T>
inline T* IteradorLista<T>::proximoElemento(){
	T* aux;
	if (masElementos() == true) {
		aux = cursor->getInfo();
		cursor = cursor->getSig();
		return aux;
	}
	return nullptr;
}

template<class T>
inline IteradorLista<T>::~IteradorLista(){}
