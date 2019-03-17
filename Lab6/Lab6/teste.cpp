#include "stdafx.h"
#include "repository.h"
#include "Produs.h"
#include "assert.h"
#include "Monede.h"
#include "ctrl.h"
#include <cstring>
#include <iostream>

using namespace std;


void teste() {

	Produs p1, p2, p3;

	p1 = Produs(100, "ciocolata", 1.35);
	p2 = Produs(101, "apa", 5);
	p3 = Produs(102, "suc", 15);
	assert(p1.get_cod() == 100 && !strcmp(p2.get_nume(), "apa") && p3.get_pret() == 15);
	
	p1.set_cod(200);
	p1.set_nume("APA");
	p3.set_pret(25);
	assert(p1.get_cod() == 200 && !strcmp(p1.get_nume(), "APA") && p3.get_pret() == 25);
	Repository<Produs> repo;
	Produs suc(11, "suc", 3);
	repo.add_elem(suc);
	vector<Produs> v;
	v = repo.getAll();
	assert(v[0].get_cod() == 11 && !strcmp(v[0].get_nume(), "suc") && v[0].get_pret() == 3);
	Monede nr_monede(10, 10, 10, 10);
	RepoFile<Produs> repo_fisier;

	Controller service(repo_fisier);

	service.cumpara_produs(1.36, nr_monede);
	assert(nr_monede.get_m50() == 8 && nr_monede.get_m10() == 7 && nr_monede.get_m5() == 9 && nr_monede.get_m1() == 9);

	service.cumpara_produs(500, nr_monede);
	assert(nr_monede.get_m50() == 8 && nr_monede.get_m10() == 7 && nr_monede.get_m5() == 9 && nr_monede.get_m1() == 9);

	//Produs testRepoFile(11, "qq", 11);
	//service.add_elem(testRepoFile);
	//service.save_to_file();
	//service.load_from_file();
	//v = service.getAll();
	//assert(v[0].get_cod() == 11);
}