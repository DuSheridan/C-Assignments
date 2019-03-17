#include "stdafx.h"
#include <iostream>
#include "Resurse.h"
#include "ResurseFinanciare.h"
#include "ResurseFizice.h"
#include "assert.h"

using namespace std;

void tests() {



	Resurse r = Resurse("res", "01.04.2000", 1);

	ResurseFinanciare rfin = ResurseFinanciare("resfin", "02.04.2000", 2, "EUR");

	ResurseFizice rfiz = ResurseFizice("resfiz", "03.04.2000)", 3, 50, 5);

	assert(r.getNume() == "res" && r.getData() == "01.04.2000" && r.getValoare() == 1);

	assert(rfin.getNume() == "resfin" && rfin.getValuta() == "EUR");

	assert(rfiz.getNume() == "resfiz" && rfiz.getNrExemplare() == 5 && rfiz.getDurataViata() == 50);

	cout << "done";

	ResurseFinanciare rt = ResurseFinanciare("resFIN", "04.04.2000", 10, "EUR");







}








