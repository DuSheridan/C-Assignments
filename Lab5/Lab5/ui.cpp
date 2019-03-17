#include "stdafx.h"
#include "ui.h"
#include "VectorDinamic.h"
#include "tranzactie.h"
#include "repository.h"
#include "ctrl.h"
#include <iostream>

using namespace std;


void Ui::afis(Tranzactie ceAvem)
{
	cout << ceAvem.get_ziua() << " " << ceAvem.get_bani() << " " << endl;
	for (int j = 0; j < strlen(ceAvem.get_tip()); j++) {
		cout << ceAvem.get_tip()[j];
	}
	cout << endl;
	for (int j = 0; j < strlen(ceAvem.get_desc()); j++) {
		cout << ceAvem.get_desc()[j];		}
	cout << endl;
	
}

void Ui::meniu() {

	int ok = 1, op, ziua, bani, i;
	char desc[100], tip[100];
	VectorDinamic lista_initiala;

	while (ok) {

		cout << "1.Adaugare Tranzactie" << endl;
		cout << "2.Eliminare dupa zi" << endl;
		cout << "3.Eliminare dupa o perioada" << endl;
		cout << "4.Eliminare dupa tip" << endl;
		cout << "5.Inlocuire suma de bani dupa zi, tip si descriere " << endl;
		cout << "6.Afisare" << endl;
		cout << "7.Afisare de tip in " << endl;
		cout << "8.Afisare cu suma = 60" << endl;
		cout << "9.Afisare cu suma >100" << endl;
		cout << "10.Sold dintr-o zi " << endl;
		cout << "11.Sum in" << endl;
		cout << "12.Max out " << endl;
		cout << "13.Filtru in" << endl;
		cout << "14.Filtru < 100" << endl;
		cout << "15.Undo" << endl;
		cout << "0. Iesire" << endl;

		cout << "Dati optiunea:" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
		{

			cout << "Dati ziua Tranzactiei: " << endl;
			cin >> ziua;
			if (ziua < 1 || ziua > 31) {
				cout << "Ziua trebuie sa fie un intreg intre 1 si 31: " << endl;
				cin >> ziua;
			}
			cout << "Dati suma de bani: " << endl;
			cin >> bani;
			if (bani < 0) {
				cout << "Trebuie pozitiv " << endl;
				cin >> bani;
			}
			cout << "Dati tipul: in/out: " << endl;
			cin >> tip;

			cout << "Dati o descriere: " << endl;
			cin >> desc;

			service.add_tranzactie(ziua, bani, tip, desc);
			break;
		}
		case 2:
		{
			cout << "Dati ziua: " << endl;
			int zi;
			cin >> zi;
			lista_initiala = service.getAll();
			for (int i = 0; i < lista_initiala.get_lungime(); i++)
				if (lista_initiala[i].get_ziua() == zi)
					service.del(lista_initiala[i]);
			break;
		}
		case 3:
		{
			cout << "Dati ziua 1: " << endl;
			int zi;
			cin >> zi;
			cout << "Dati ziua 2: " << endl;
			int zii;
			cin >> zii;
			lista_initiala = service.getAll();
			for (int j = zi; j <= zii; j++)
			{
				for (int i = 0; i < lista_initiala.get_lungime(); i++)
					if (lista_initiala[i].get_ziua() == j)
						service.del(lista_initiala[i]);
			}
			break;
		}
		case 4:
		{
			char tip[3];
			cout << "Dati tipul: " << endl;
			cin >> tip;
			lista_initiala = service.getAll();
			for (int j = 0; j < service.get_lungime(); j++)
				if (strcmp(lista_initiala[j].get_tip(), tip))
					service.del(lista_initiala[j]);
			break;
		}
		case 5: 
		{
			int bani;
			cout << "Dati noua suma: " << endl;
			cin >> bani;
			int zi;
			cout << "Ziua: \n";
			cin >> zi;
			char tip[3];
			cout << "Tip: \n";
			cin >> tip;
			char desc[100];
			cout << "Desc \n";
			cin >> desc;
			lista_initiala = service.getAll();
			for (int j = 0; j < service.get_lungime(); j++)
				if (!strcmp(lista_initiala[j].get_desc(), desc) && !strcmp(lista_initiala[j].get_tip(), tip) && lista_initiala[j].get_ziua() == zi)
				{
					service.update(zi, bani, tip, desc, lista_initiala[j]);
				}
			break;
		}
		case 6:
		{

			lista_initiala = service.getAll();
			for (i = 0; i < service.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 7: 
		{
			lista_initiala = service.afisare_tip("in");
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 8: 
		{
			int bani;
			cout << "Suma: \n";
			cin >> bani;
			lista_initiala = service.suma_egala(bani);
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 9:
		{
			int bani;
			cout << "Suma: \n";
			cin >> bani;
			lista_initiala = service.suma_mare(bani);
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 10:
		{
			cout << "Dati ziua: \n";
			int zi,suma = 0;
			cin >> zi;
			suma = service.sold(zi);
			cout << "Soldul este: " << suma << "\n";
			break;
		}
		case 11:
		{
			int s = service.suma_in();
			cout << "Suma este: "<< s << "\n";
			break;
		}
		case 12:
		{
			int zi;
			cout << "Dati ziua: \n";
			cin >> zi;
			int mx = service.max_out(zi);
			cout << mx << "\n";
			break;
		}
		case 13:
		{
			service.filtru_tip();
			lista_initiala = service.getAll();
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 14:
		{
			int bani;
			cout << "Dati banii: ";
			cin >> bani;
			service.filtru_mai_mic(bani);
			lista_initiala = service.getAll();
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
			break;
		}
		case 15:
		{
			service.undo();
			lista_initiala = service.getAll();
			for (i = 0; i < lista_initiala.get_lungime(); i++)
				afis(lista_initiala[i]);
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