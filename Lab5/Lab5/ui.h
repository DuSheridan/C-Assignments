#pragma once
#include "ctrl.h"
class Ui
{
private:

	Controller & service;

public:

	Ui(Controller &service) : service{ service } {}
	void afis(Tranzactie ceAvem);
	void meniu();
};