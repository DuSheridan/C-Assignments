#pragma once
#include "Repository.h"
#include "Produs.h"
#include "vector"
#include "Monede.h"
#include "RepoFile.h"

class Controller {
private:
	
	RepoFile<Produs> & repo;

public:

	Controller(RepoFile<Produs> &repo) : repo{ repo } {}

	void add_elem(Produs &p);
	vector<Produs> getAll();
	void cumpara_produs(float pret, Monede &nr);
	void save_to_file();
	void load_from_file();

};


