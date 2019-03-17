#include "stdafx.h"
#include "Ui.h"
#include "Resurse.h"
#include "ResurseFinanciare.h"
#include "Repository.h"
#include <iostream>
#include <vector>
#include "RepoFile.h"
#include <string>
#include "Validator.h"
using namespace std;


int ok = 1, op, logat = 1;
vector<Resurse> v;


void Ui::meniu() {


	while (ok) {

		cout << "1.Adaugare resurse financiara \n";
		cout << "2.Get resurse\n";
		cout << "3.Save to file csv resurse \n";
		cout << "4.Load from file csv resurse \n";
		cout << "5.Adaugare resurse fizice \n";
		cout << "6.Login \n";
		cout << "7.Logout \n";
		cout << "8.Cautare Resurse \n";
		cout << "9.Modificare resurse \n";
		cout << "10.Save to file html resurse \n";
		cout << "11.Load from file html resurse \n";
		cout << "0.Iesire \n";


		cin >> op;

		if (op == 1) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				cout << "nume: \n";
				string n;
				cin >> n;
				cout << "Data: \n";
				string d;
				cin >> d;
				cout << "valoare: \n";
				double val;
				cin >> val;
				cout << "Valuta: \n";
				string valuta;
				cin >> valuta;
				Validator v;
				ResurseFinanciare res = ResurseFinanciare(n, d, val, valuta);
				try {
					v.validate(res);
				}
				catch (exception &ex) {
					cout << ex.what();
				}
				Resurse *R = new ResurseFinanciare(res);
				service.addElem(R);

			}
		}
		if (op == 2) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				vector<Resurse*> ve;
				ve = service.getAll();
				for (int i = 0; i < ve.size(); i++) {
					cout << (*ve[i]).getString() << endl;
				}
			}
		}

		if (op == 3) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				service.saveToFile(1);
			}
		}

		if (op == 4) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				service.loadFromFile(1);
			}
		}

		if (op == 5) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				cout << "nume: \n";
				string n;
				cin >> n;
				cout << "Data: \n";
				string d;
				cin >> d;
				cout << "valoare: \n";
				double val;
				cin >> val;
				cout << "Durata viata: \n";
				int durata;
				cin >> durata;
				cout << "Numarul: \n";
				int nr;
				cin >> nr;

				Validator v;
				ResurseFizice res = ResurseFizice(n, d, val, durata, nr);
				try {
					v.validate(res);
				}
				catch (exception &ex) {
					cout << ex.what();
				}
				Resurse* R = new ResurseFizice(res);
				service.addElem(R);
			}
		}
		if (op == 6) {
			cout << "Nume: ";
			string n;
			cin >> n;
			cout << "Parola: ";
			string p;
			cin >> p;
			ifstream f("Useri.txt");
			string nume, parola;
			while (f >> nume >> parola) {
				if (nume == n && parola == p)
				{
					logat = 1;
					cout << "Bine ai venit " << n << "e" << " ! \n";
				}

			}
		}

		if (op == 7) {
			logat = 0;
		}

		if (op == 8) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				vector<Resurse*> v;
				cout<<"Nume: \n";
				string n;
				cin>>n;
				cout<<"Data: \n";
				string d;
				cin>>d;
				v = service.cautare(n,d);
				for(int i = 0; i < v.size() ; i++){
					cout<<(*v[i]).getString();
				}
			}
		}

		if(op==9) {
			if (logat == 0) {
				cout << "Trebuie sa va autentificati!!! \n";
			}
			else {
				cout<<"Nume: \n";
				string n;
				cin>>n;
				cout<<"Data: \n";
				string d;
				cin>>d;
				cout<<"Tipul: \n";
				string t;
				cin>>t;
				cout << "Valoare: \n";
				int val;
				cin >> val;
				if(t == "Financiare"){
					cout<<"Valuta: \n";
					string v;
					cin>>v;
					Resurse* R = new Resurse(n, d, val);
					Resurse* resFin = new ResurseFinanciare(n, d, val, v);
					service.modificare(R,resFin);
				}
				else{
					cout<<"Durata: \n";
					int durata;
					cin>>durata;
					cout<<"NrEx: \n";
					int nrex;
					cin>>nrex;
					Resurse* R = new Resurse(n, d, val);
					Resurse* resFiz = new ResurseFizice(n, d, val, durata, nrex);
					service.modificare(R,resFiz);
				}
			}
		}

		
		if (op == 0) {
			ok = 0;
		}

	}


}
