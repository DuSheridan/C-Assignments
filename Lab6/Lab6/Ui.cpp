#include "stdafx.h"
#include "Ui.h"
#include "Produs.h"
#include "Repository.h"
#include "Produs.h"
#include <iostream>
#include <vector>
#include "Monede.h"
#include "RepoFile.h"

using namespace std;

void Ui::meniu() {
	vector<Produs> v;
	Monede nrMonede;
	nrMonede = Monede(10, 10, 10, 10);
	int ok = 1, op;
	while (ok) {

		cout << "1.Adaugare element \n";
		cout << "2.Get all \n";
		cout << "3.Cumpara produs \n";
		cout << "4.Save to file \n";
		cout << "5.Load from file \n";
		cout << "0.Iesire \n";


		cin >> op;
		switch (op)
		{
		case 1:
		{
			int cod;
			float pret;
			char nume[20];
			cout << "Cod produs: \n";
			cin >> cod;
			cout << "Nume produs: \n";
			cin >> nume;
			cout << "Pret produs: \n";
			cin >> pret;
			Produs p;
			p = Produs(cod, nume, pret);
			service.add_elem(p);
			break;
		}
		case 2:
		{
			vector <Produs> v;
			v = service.getAll();
			for (int i = 0; i < v.size(); i++)
			{
				cout << "Cod produs: " << v[i].get_cod() << "\nNume produs: " << v[i].get_nume() << "\nPret Produs: " << v[i].get_pret() << "\n";
			}
			break;
		}
		case 3:
		{
			
			cout << "Numele produsului dorit: \n";
			char nume[50];
			cin >> nume;
			cout << "Banii introdusi: \n";
			float bani;
			cin >> bani;
			v = service.getAll();
			for (int i = 0; i < v.size(); i++) {
				if (!strcmp(v[i].get_nume(), nume))
				{
					service.cumpara_produs(bani - v[i].get_pret(), nrMonede);
					break;
				}
			}
			break;
		}

		case 4:
		{
			service.save_to_file();
			break;
		}

		case 5:
		{
			service.load_from_file();
			break;
		}

		case 0:
		{
			ok = 0;
			break;
		}
		default:
		{
			cout << "Optiune invalida";
			break;
		}
		}
	}


}
