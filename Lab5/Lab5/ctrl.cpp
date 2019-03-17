#include "stdafx.h"
#include "ctrl.h"
#include <string.h>
#include <iostream>


using namespace std; 

void Controller::add_tranzactie(int ziua, int bani, const char *tip, const char *desc)
{
	Tranzactie tranzactie(ziua, bani, tip, desc);
	this->repo.add_tranzactie(tranzactie);
}

int Controller::get_lungime()
{
	return this->repo.get_lungime();
}
VectorDinamic Controller::getAll() 
{
	return this->repo.getAll();
}

void Controller::del(Tranzactie &tr) {
	this->repo.del(tr);
}

void Controller::update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &tr)
{
	this->repo.update(ziua,bani, tip,desc,tr);
}

VectorDinamic Controller::afisare_tip(const char* tip) {
	VectorDinamic lista_finala;
	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (!strcmp(lista_initiala[i].get_tip(), tip))
			lista_finala.add(lista_initiala[i]);
	}
	return lista_finala;
}

VectorDinamic Controller::suma_mare(int bani) {
	VectorDinamic lista_finala;
	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (lista_initiala[i].get_bani() >= bani)
			lista_finala.add(lista_initiala[i]);
	}
	return lista_finala;
}

VectorDinamic Controller::suma_egala(int bani) {
	VectorDinamic lista_finala;
	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (lista_initiala[i].get_bani() == bani)
			lista_finala.add(lista_initiala[i]);
	}
	return lista_finala;
}

int Controller::sold(int ziua) {
	int suma=0;
	Tranzactie tranz_init;
	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		tranz_init = lista_initiala[i];
		if (tranz_init.get_ziua() == ziua)
		{
			if (!strcmp(tranz_init.get_tip(), "in"))
				suma = suma + tranz_init.get_bani();
			else
				suma = suma - tranz_init.get_bani();
		}

	}
	return suma;
}

int Controller::suma_in() {

	int s = 0;

	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (!strcmp(lista_initiala[i].get_tip(), "in"))
			s = s + lista_initiala[i].get_bani();
	}

	return s;


}

int Controller::max_out(int ziua) {

	int maxim = -1;

	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (!strcmp(lista_initiala[i].get_tip(), "out") && lista_initiala[i].get_ziua() == ziua)
		{
			if (lista_initiala[i].get_bani() > maxim)
				maxim = lista_initiala[i].get_bani();
		}
	}

	return maxim;


}

void Controller::filtru_tip() {

	VectorDinamic ceAvem = this->getAll();
	for (int i = 0; i < ceAvem.get_lungime(); i++) {
		if (!strcmp(ceAvem[i].get_tip(), "out"))
			del(ceAvem[i]);
	}


}

void Controller::filtru_mai_mic(int bani) {

	VectorDinamic lista_initiala = this->getAll();
	for (int i = 0; i < lista_initiala.get_lungime(); i++) {
		if (!strcmp(lista_initiala[i].get_tip(), "in") && lista_initiala[i].get_bani() > bani)
			del(lista_initiala[i]);
	}

}

void Controller::undo() {

	this->repo.undo();

}