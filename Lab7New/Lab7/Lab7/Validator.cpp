#include "stdafx.h"
#include "validator.h"
#include "ResurseFizice.h"
#include "ResurseFinanciare.h"
#include <string>

using namespace std;

void Validator::validate(ResurseFizice & resfiz)
{
	this->mesaj = string("");
	if (resfiz.getDurataViata() < 1)
	{
		this->mesaj += string("Durata de viata invalida \n");
	}
	if (resfiz.getNrExemplare() < 0)
	{
		this->mesaj += string("Numar de exemplare invalid \n");
	}
	if (!this->mesaj.empty())
	{
		throw exception(this->mesaj.c_str());
	}
}

void Validator::validate(ResurseFinanciare & resfin)
{
	this->mesaj = string("");
	if (resfin.getValoare() < 1)
	{
		this->mesaj += string("Valoare invalida \n");
	}
	if (resfin.getValuta().empty())
	{
		this->mesaj += string("Trebuie sa fie o valuta \n");
	}
	if (!this->mesaj.empty())
	{
		throw exception(this->mesaj.c_str());
	}
}