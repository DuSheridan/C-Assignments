#include "stdafx.h"
#include "ResurseFinanciare.h"
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>

ResurseFinanciare::ResurseFinanciare(string nume, string data, double valoare, string valuta)
{
	this->nume = nume;
	this->data = data;
	this->valoare = valoare;
	this->valuta = valuta;
}

ResurseFinanciare::ResurseFinanciare()
{
	Resurse();
	this->valuta = "";
}

ResurseFinanciare ResurseFinanciare::pseudoConstructor(vector<string> v) {
	double val;
	val = atof(v[3].c_str());
	ResurseFinanciare R = ResurseFinanciare(v[1], v[2], val, v[4]);
	return R;
}

