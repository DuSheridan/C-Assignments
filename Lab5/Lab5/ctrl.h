#pragma once
#include "tranzactie.h"
#include "VectorDinamic.h"
#include "repository.h"

class Controller
{
private:
	Repository & repo;

public:

	Controller(Repository &repo) : repo{ repo } {}
	void add_tranzactie(int ziua, int bani, const char* tip, const char* desc);
	void del(Tranzactie &tr);
	void update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &tr);
	VectorDinamic afisare_tip(const char* tip);
	VectorDinamic suma_mare(int bani);
	VectorDinamic suma_egala(int bani);
	void undo();
	int sold(int ziua);
	int suma_in();
	int max_out(int ziua);
	void filtru_tip();
	void filtru_mai_mic(int bani);
	int get_lungime();
	VectorDinamic getAll();
};