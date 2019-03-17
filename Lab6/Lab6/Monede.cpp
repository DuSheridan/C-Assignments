#include "stdafx.h"
#include <iostream>
#include "Monede.h"
using namespace std;


Monede::Monede(int v1, int v2, int v3, int v4) {

	monede_1 = v1;
	monede_5 = v2;
	monede_10 = v3;
	monede_50 = v4;

}

Monede::Monede() {
	monede_1 = 0;
	monede_5 = 0;
	monede_10 = 0;
	monede_50 = 0;
}

Monede & Monede::operator=(const Monede &nr) {

	if (this != &nr) {
		monede_1 = nr.monede_1;
		monede_5 = nr.monede_5;
		monede_10 = nr.monede_10;
		monede_50 = nr.monede_50;

	}
	return *this;
}

Monede::Monede(const Monede &nr)
{
	monede_1 = nr.monede_1;
	monede_5 = nr.monede_5;
	monede_10 = nr.monede_10;
	monede_50 = nr.monede_50;
}
int Monede::get_m1() 
{
	return monede_1;
}

int Monede::get_m5()
{
	return monede_5;
}

int Monede::get_m10()
{
	return monede_10;
}

int Monede::get_m50()
{
	return monede_50;
}

void Monede::set_m1(int nr) 
{
	monede_1 = nr;
}

void Monede::set_m5(int nr) 
{
	monede_5 = nr;
}

void Monede::set_m10(int nr) 
{
	monede_10 = nr;
}

void Monede::set_m50(int nr) 
{
	monede_50 = nr;
}