// Lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "tests.h"
#include "ResurseFinanciare.h"
#include "ResurseFizice.h"
#include "Service.h"
#include "RepoFile.h"
#include "Ui.h"


int main()
{
	void tests();
	RepoFile<Resurse> repoFile;
	Service<Resurse> service(repoFile);
	service.loadFromFile(2);
	service.saveToFile(1);

	Ui ui(service);

	ui.meniu();
    return 0;
}

