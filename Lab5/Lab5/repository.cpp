#include "stdafx.h"
#include "repository.h"
#include "iostream"

using namespace std;

void Repository::add_tranzactie(const Tranzactie &tr)
{
	tranzactii_vechi = tranzactii;
	this->tranzactii.add(tr);
}

void Repository::del(Tranzactie &tr)
{
	tranzactii_vechi = tranzactii;
	this->tranzactii.del(tr);
}

void Repository::update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &tr)
{
	tranzactii_vechi = tranzactii;
	this->tranzactii.update(ziua, bani, tip, desc, tr);

}

void Repository::undo() {

	tranzactii = tranzactii_vechi;

}

VectorDinamic Repository::getAll()
{
	return this->tranzactii;
}

int Repository::get_lungime()
{
	return this->tranzactii.get_lungime();
}