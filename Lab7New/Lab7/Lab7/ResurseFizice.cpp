#include "stdafx.h"
#include "ResurseFizice.h"
#include <sstream>

ResurseFizice::ResurseFizice(string nume, string data, double valoare, int durataV, int nr)
{
	this->nume = nume;
	this->data = data;
	this->valoare = valoare;
	this->durataViata = durataV;
	this->nrExemplare = nr;
}

ResurseFizice::ResurseFizice()
{
	Resurse();
	this->durataViata = 0;
	this->nrExemplare = 0;
}

ResurseFizice ResurseFizice::pseudoConstructor(vector<string> v) {
	double val;
	val = atof(v[3].c_str());
	int durataV = atof(v[4].c_str());
	int nr = atof(v[5].c_str());
	ResurseFizice R = ResurseFizice(v[1], v[2], val, durataV, nr);
	return R;
}