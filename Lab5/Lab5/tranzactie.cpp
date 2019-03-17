#include "stdafx.h"
#include "tranzactie.h"
#include <string.h>
#include <iostream>

using namespace std;

Tranzactie::Tranzactie(int ziua, int bani, const char* tip, const char* desc)
{
	this->ziua = ziua;
	this->bani = bani;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1,tip);
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc)+1, desc);
	
}

Tranzactie::Tranzactie()
{
	this->ziua = 0;
	this->bani = 0;
	this->tip = new char[10];
	strcpy_s(this->tip, 10, "n/a");
	this->desc = new char[100];
	strcpy_s(this->desc, 10, "n/a");
}

Tranzactie & Tranzactie::operator=(const Tranzactie &Tranzactie)
{
	if (this != &Tranzactie)
	{
		this->ziua = Tranzactie.ziua;
		this->bani = Tranzactie.bani;
		this->set_tip(Tranzactie.tip);
		this->set_desc(Tranzactie.desc);

	}
	return *this;
}


Tranzactie::Tranzactie(const Tranzactie &Tranzactie)
{
	this->ziua = Tranzactie.ziua;
	this->bani = Tranzactie.bani;
	this->tip = new char[strlen(Tranzactie.tip) + 1];
	strcpy_s(this->tip, strlen(Tranzactie.tip)+1, Tranzactie.tip);
	this->desc = new char[strlen(Tranzactie.desc) + 1];
	strcpy_s(this->desc, strlen(Tranzactie.desc)+1,Tranzactie.desc);
}

int Tranzactie::get_ziua()
{
	return this->ziua;
}

void Tranzactie::set_ziua(int ziua)
{
	this->ziua = ziua;
}

int Tranzactie::get_bani()
{
	return this->bani;
}

void Tranzactie::set_bani(int bani)
{
	this->bani = bani;
}

char* Tranzactie::get_tip()
{
	return this->tip;
}

void Tranzactie::set_tip(const char* tip)
{
	if(this->tip!=NULL)
		delete[] this->tip;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip,strlen(tip) + 1, tip);
}

char* Tranzactie::get_desc()
{
	return this->desc;
}

void Tranzactie::set_desc(const char* desc)
{
	delete[] this->desc;
	this->desc = new char[strlen(desc) + 1];
	strcpy_s(this->desc, strlen(desc)+1, desc);
}
Tranzactie::~Tranzactie()
{
	
}
