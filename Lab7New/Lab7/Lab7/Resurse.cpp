#include "stdafx.h"
#include "Resurse.h"


Resurse::Resurse(string nume, string data, double valoare)
{
	this->nume = nume;
	this->data = data;
	this->valoare = valoare;
}

Resurse::Resurse()
{
	this->nume = "";
	this->data = "00.00.0000";
	this->valoare = 0.0;
}
