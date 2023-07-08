#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include "Controladora.h"
#include "Vista.h"
#include "SistemaMatricula.h"
using namespace std;

class Controladora;
class Vista;
class Controladora {
private:
	Vista* vistita;
public:
	Controladora();
	void inicia();
	int menu();
	void control();
	void control1();
	void control2();
	void control3();
	void control4();
	void control5();
	void control6();
	void control7();
	void control8();
	virtual ~Controladora();
};

