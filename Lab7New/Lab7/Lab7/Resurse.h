#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;


class Resurse {

protected:

	string nume;
	string data;
	double valoare;


public:

	Resurse();
	Resurse(string nume, string data, double valoare);
	virtual ~Resurse() { }

	virtual string getString() {
		ostringstream strs;
		strs << valoare;
		string val = strs.str();
		string atribute = "Resurse, " + nume + ", " + data + ", " + val + ", ";
		return atribute;
	}

	virtual string getTip()
	{
		return "Resursa";
	}

	virtual string getNume() {
		return nume;
	}

	virtual string getData() {
		return data;
	}

	virtual double getValoare() {
		return valoare;
	}

	virtual void setNume(string n) {
		this->nume = n;
	}

	virtual void setData(string d) {
		this->data = d;
	}

	virtual void setValoare(double v) {
		this->valoare = v;
	}

};