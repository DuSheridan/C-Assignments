#pragma once
#include "Resurse.h"
#include <sstream>

class ResurseFinanciare :public Resurse {

protected:
	string valuta;

public:
	ResurseFinanciare();
	ResurseFinanciare(string nume, string data, double valoare, string valuta);
	~ResurseFinanciare() { }
	
	ResurseFinanciare pseudoConstructor(vector<string> v);

	virtual string getString()
	{
		string s;
		ostringstream strs;
		double v = this->valoare;
		strs << v;
		string val = strs.str();
		s = "Financiare, " + this->nume + ", " + this->data + ", " + val + ", " + this->valuta + ", ";
		
		return s;
	}

	virtual string getTip() {
		return "Financiare";
	}


	string getValuta() {
		return valuta;
	}

	void setValuta(string val) {
		this->valuta = val;
	}

};