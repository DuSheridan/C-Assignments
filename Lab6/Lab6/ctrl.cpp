#include "stdafx.h"
#include "ctrl.h"
#include "Produs.h"
#include <iostream>
#include "Monede.h"

using namespace std;

void Controller::add_elem(Produs &p) 
{
	this->repo.add_elem(p);
}

vector<Produs> Controller::getAll() 
{
	return this->repo.getAll();
}

void Controller::save_to_file() 
{
	this->repo.save_to_file();
}

void Controller::load_from_file() 
{
	this->repo.load_from_file();
}

void Controller::cumpara_produs(float pret, Monede &nr_monede)
{
	int m_init50 = nr_monede.get_m50(), m_init10 = nr_monede.get_m10(), m_init5 = nr_monede.get_m5(), m_init1 = nr_monede.get_m1();
	int m50 = nr_monede.get_m50();
	while (pret >= 0.5 && m50 > 0) 
	{
		pret = pret - 0.5;
		m50--;
		if (pret - 0.5 <0.009 && pret - 0.5>0)
		{
			cout << "Rest dat: " << m_init50 - m50 + 1 << " monede de 50 de bani \n";
			nr_monede.set_m50(m50);
			return;
		}
	}
	int m10 = nr_monede.get_m10();
	while (pret >= 0.1 && m10 > 0) 
	{
		pret = pret - 0.1;
		m10--;
		if (pret - 0.1 < 0.009 && pret - 0.1 > 0)
		{
			cout << "Rest dat: " << m_init50 - m50 << " monede de 50 de bani si " << m_init10 - m10 + 1 << " de 10 bani \n";
			nr_monede.set_m50(m50);
			nr_monede.set_m10(m10);
			return;
		}
	}
	int m5 = nr_monede.get_m5();
	while (pret >= 0.05 && m5 > 0) 
	{
		pret = pret - 0.05;
		m5--;
		if (pret - 0.05 < 0.009 && pret - 0.05>0)
		{
			cout << "Rest dat: " << m_init50 - m50 << " monede de 50 de bani, " << m_init10 - m10 << " de 10 bani si" << m_init5 - m5 + 1 << " de 5 bani \n";
			nr_monede.set_m50(m50);
			nr_monede.set_m10(m10);
			nr_monede.set_m5(m5);
			return;
		}

	}
	int m1 = nr_monede.get_m1();
	while (pret >= 0.01 && m1 > 0) 
	{
		pret = pret - 0.01;
		m1--;
		if (pret - 0.01 < 0.009)
		{
			cout << "Rest dat: " << m_init50 - m50 << " monede de 50 de bani, " << m_init10 - m10 << " de 10 bani, " << m_init5 - m5 << " de 5 bani si " << m_init1 - m1 << " de un ban \n";
			nr_monede.set_m50(m50);
			nr_monede.set_m10(m10);
			nr_monede.set_m5(m5);
			nr_monede.set_m1(m1);
			return;
		}
	}
	if (pret != 0) 
	{
		cout << "Nu se poate da rest \n";
		return;
	}
}