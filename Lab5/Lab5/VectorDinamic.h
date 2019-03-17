#pragma once
#include "tranzactie.h"
class VectorDinamic
{
private:
	Tranzactie* vector;
	int capacitate;
	int lungime;
	void asigura_capacitate();
public:
	VectorDinamic();
	VectorDinamic(const VectorDinamic &other);
	~VectorDinamic();
	int get_lungime();
	void add(const Tranzactie &s);
	void del(Tranzactie &s);
	void update(int ziua, int bani, const char* tip, const char* desc, Tranzactie &s);
	Tranzactie &operator[](int pozitie);
	VectorDinamic &operator=(const VectorDinamic &other);
};