#pragma once
#include "Repository.h"
#include "Produs.h"
#include "ctrl.h"
class Ui
{
private:
	
	Controller & service;

public:
	Ui(Controller &service) : service{ service } {}
	void meniu();

};