#pragma once
#include <iostream>
#include <cstring>
#include "Resurse.h"

using namespace std;


class ResurseFizice: public Resurse {

protected:
	int durataViata;
	int nrExemplare;

public:

	ResurseFizice();
	ResurseFizice(string nume, string data, double valoare, int durataV, int nr);
	~ResurseFizice() { }


	ResurseFizice pseudoConstructor(vector<string> v);

	virtual string getString() {
		string s;
		ostringstream strs;
		double v = this->valoare;
		strs << v;
		string val = strs.str();
		string durata = to_string(this->durataViata);
		string nr = to_string(this->nrExemplare);
		s = "Fizice, " + this->nume + ", " + this->data + ", " + val + ", " + durata + ", " + nr + ", ";

		return s;

	}

	virtual string getTip() {
		return "Fizice";
	}

	int getDurataViata() {
		return durataViata;
	}

	int getNrExemplare() {
		return nrExemplare;
	}

	void setDurataViata(int d) {
		durataViata = d;
	}

	void setNrExemplare(int nrex) {
		nrExemplare = nrex;
	}

};