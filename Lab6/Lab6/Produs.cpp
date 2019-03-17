#include "stdafx.h"
#include "Produs.h"
#include <string.h>
#include <iostream>

using namespace std;

Produs::Produs(int cod,const char* nume, float pret)
{

	this->cod = cod;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->pret = pret;

}

Produs::Produs() 
{
	this->cod = 0;
	this->nume = new char[4];
	strcpy_s(this->nume, 4, "n/a");
	this->pret = 0;

}

Produs & Produs::operator=(const Produs &Produs) 
{

	if (this != &Produs)
	{
		this->cod = Produs.cod;
		this->set_nume(Produs.nume);
		this->pret = Produs.pret;
	}
	return *this;
}

Produs::Produs(const Produs &Produs) 
{

	this->cod = Produs.cod;
	this->set_nume(Produs.nume);
	this->pret = Produs.pret;

}

int Produs::get_cod()
{
	return this->cod;
}

char* Produs::get_nume()
{
	return this->nume;
}

float Produs::get_pret() 
{
	return this->pret;
}

void Produs::set_cod(int cod) 
{
	this->cod = cod;
}

void Produs::set_nume(const char* nume) 
{
	//delete[] this->nume;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Produs::set_pret(float pret)
{
	this->pret = pret;
}

Produs::~Produs()
{

	if (this != NULL)
		delete[] this->nume;
}