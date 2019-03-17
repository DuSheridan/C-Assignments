#pragma once
#include "VectorDinamic.h"
#include "tranzactie.h"

class Repository
{
private:
	VectorDinamic tranzactii;
	VectorDinamic tranzactii_vechi;

public:
	void add_tranzactie(const Tranzactie &tr);
	void del(Tranzactie &tr);
	void update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &tr);
	VectorDinamic getAll();
	void undo();
	int get_lungime();
};