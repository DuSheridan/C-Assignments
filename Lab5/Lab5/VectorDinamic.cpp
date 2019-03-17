#include "stdafx.h"
#include "VectorDinamic.h"
#include <iostream>

using namespace std;

VectorDinamic::VectorDinamic()
{
	this->capacitate = 10;
	this->lungime = 0;
	this->vector = new Tranzactie[this->capacitate];
}

VectorDinamic::VectorDinamic(const VectorDinamic &other)
{
	this->capacitate = other.capacitate;
	this->lungime = other.lungime;
	this->vector = new Tranzactie[this->capacitate];
	for (int i = 0; i < this->lungime; ++i)
	{
		this->vector[i] = other.vector[i];
	}
}

void VectorDinamic::asigura_capacitate()
{
	if (lungime == capacitate)
	{
		capacitate *= 2;
		Tranzactie *vectorNou = new Tranzactie[capacitate];
		for (int i = 0; i < lungime; ++i)
		{
			vectorNou[i] = vector[i];
		}
		delete[] vector;
		vector = vectorNou;
	}
}

void VectorDinamic::add(const Tranzactie &tr)
{
	asigura_capacitate();
	this->vector[this->lungime++] = tr;
}

void VectorDinamic::del(Tranzactie &tr)
{
	int i=0;
	Tranzactie trc;
	while(i < lungime)
	{
		trc = vector[i];
		if (trc.get_bani() == tr.get_bani() && trc.get_ziua() == tr.get_ziua() && !strcmp(trc.get_tip(), tr.get_tip()) && !strcmp(trc.get_desc(), tr.get_desc()))
		{
			for (int j = i; j < lungime-1; j++)
				vector[j] = vector[j + 1];
			lungime--;
			vector[lungime] = Tranzactie();
		}
		i++;
	}

}

void VectorDinamic::update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &tr) {

	int i = 0;
	Tranzactie trc;
	while (i < lungime)
	{
		trc = vector[i];
		if (trc.get_bani() == tr.get_bani() && trc.get_ziua() == tr.get_ziua() && !strcmp(trc.get_tip(), tr.get_tip()) && !strcmp(trc.get_desc(), tr.get_desc()))
		{
			vector[i].set_ziua(ziua);
			vector[i].set_bani(bani);
			vector[i].set_tip(tip);
			vector[i].set_desc(desc);
		}
		break;
	}


}

int VectorDinamic::get_lungime()
{
	return lungime;
}

VectorDinamic::~VectorDinamic()
{
	if (vector != NULL) {
		delete[] vector;
		vector = NULL;
	}

}

Tranzactie &VectorDinamic::operator[](int pozitie)
{
	return this->vector[pozitie];
}

VectorDinamic &VectorDinamic::operator=(const VectorDinamic &other)
{
	if (this != &other)
	{
		delete[] this->vector;
		this->capacitate = other.capacitate;
		this->lungime = other.lungime;
		this->vector = new Tranzactie[this->capacitate];
		for (int i = 0; i < this->lungime; ++i)
		{
			this->vector[i] = other.vector[i];
		}
	}

	return *this;
}