#pragma once
#include "Repository.h"
#include "Resurse.h"
#include "ResurseFinanciare.h"
#include "ResurseFizice.h"
#include "Service.h"
class Ui
{
private:

	Service<Resurse> & service;

public:
	Ui(Service<Resurse> &service) : service{ service } {}
	void meniu();

};