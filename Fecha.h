#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Fecha;
class Fecha {
private:
	int annio;
	int mes;
	int dia;
public:
	Fecha(int = 0, int = 0, int = 0);
	Fecha();
	void setAnnio(int);
	void setMes(int);
	void setDia(int);
	int getAnnio();
	int getMes();
	int getDia();
	string toString();
	~Fecha();
	friend ostream& operator <<(ostream&, Fecha&);
	Fecha& operator = (Fecha&);
};



