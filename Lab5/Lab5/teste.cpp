#include "stdafx.h"
#include "repository.h"
#include "Tranzactie.h"
#include "ctrl.h"
#include "assert.h"
#include <cstring>
#include <iostream>

using namespace std;




void teste() {
	
	Repository r;
	Controller service(r);
	VectorDinamic lista_initiala;
	Tranzactie tr1, tr2, tr3;

	tr1 = Tranzactie(10, 1000, "in", "PrimaTr");
	tr2 = Tranzactie(20, 2000, "out", "AdouaTr");
	tr3 = Tranzactie(25, 100, "in", "Salar");



	service.add_tranzactie(10, 1000, "in", "PrimaTr");
	service.add_tranzactie(20, 2000, "out", "AdouaTr");
	service.add_tranzactie(25, 100, "in", "Salar");


	lista_initiala = service.getAll();

	assert(lista_initiala[0].get_ziua() == 10);
	assert(lista_initiala[1].get_ziua() == 20);
	assert(!strcmp(lista_initiala[2].get_desc(), "Salar") == 1);

	service.update(5, 500, "in", "Prima", tr1);
	service.del(lista_initiala[2]);

	lista_initiala = service.getAll();

	assert(lista_initiala[0].get_bani() == 500 && lista_initiala[0].get_ziua() == 5 && !strcmp(lista_initiala[0].get_tip(), "in") && !strcmp(lista_initiala[0].get_desc(), "Prima") == 1);
	assert(lista_initiala[1].get_bani() == tr2.get_bani() && lista_initiala[1].get_ziua() == tr2.get_ziua() && !strcmp(lista_initiala[1].get_tip(), tr2.get_tip()) && !strcmp(lista_initiala[1].get_desc(), tr2.get_desc()) == 1);
	assert(service.get_lungime() == 2);
	
	lista_initiala = service.afisare_tip("in");

	assert(lista_initiala[0].get_bani() == 500 && lista_initiala[0].get_ziua() == 5 && !strcmp(lista_initiala[0].get_tip(), "in") && !strcmp(lista_initiala[0].get_desc(), "Prima") == 1);

	lista_initiala = service.suma_egala(500);

	assert(lista_initiala[0].get_bani() == 500 && lista_initiala[0].get_ziua() == 5 && !strcmp(lista_initiala[0].get_tip(), "in") && !strcmp(lista_initiala[0].get_desc(), "Prima") == 1);

	lista_initiala = service.suma_mare(1000);

	assert(lista_initiala[0].get_bani() == 2000 & lista_initiala[0].get_ziua() == 20 && !strcmp(lista_initiala[0].get_tip(), "out") && !strcmp(lista_initiala[0].get_desc(), "AdouaTr"));

	service.add_tranzactie(5, 500, "out", "qqq");

	int sold = service.sold(5);

	assert(sold == 0);

	int suma_in = service.suma_in();

	assert(suma_in == 500);

	int max_out = service.max_out(5);

	assert(max_out == 500);
	
	service.filtru_tip();

	lista_initiala = service.getAll();

	assert(service.get_lungime() == 1 && lista_initiala[0].get_bani() == 500 && lista_initiala[0].get_ziua() == 5 && !strcmp(lista_initiala[0].get_tip(), "in") && !strcmp(lista_initiala[0].get_desc(), "Prima"));

	service.filtru_mai_mic(100);

	lista_initiala = service.getAll();

	assert(service.get_lungime() == 0);

	service.undo();

	lista_initiala = service.getAll();

	assert(service.get_lungime() == 1 && lista_initiala[0].get_bani() == 500 && lista_initiala[0].get_ziua() == 5 && !strcmp(lista_initiala[0].get_tip(), "in") && !strcmp(lista_initiala[0].get_desc(), "Prima"));
	

}
