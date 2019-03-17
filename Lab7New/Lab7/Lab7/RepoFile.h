#pragma once

#include "Repository.h"
#include "Resurse.h"
#include "fstream"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class RepoFile :public Repository<T> {

public:
	void saveToFile(int ce);
	void loadFromFile(int ce);
};

template <class T>
void RepoFile<T>::saveToFile(int ce)
{
	if (ce == 1)
	{
		T R;
		ofstream fout("In.txt");
		for (int i = 0; i < this->elements.size(); i++)
		{
			string obiect = this->elements[i]->getString();
			fout << obiect << "\n";
		}
		fout.close();
	}
	if (ce == 2) {
		T R;
		string atribut;
		string gol;
		vector<string> atribute;
		vector<string> atrgol;
		char c;
		ofstream fout("In.html");
		fout << "<!DOCTYPE html> \n";
		fout << "<html> \n";
		fout << "  <head> \n";
		fout << "    <style>\n";
		fout << "      table, th, td { \n";
		fout << "	    border: 1px solid black;";
		fout << "      } \n";
		fout << "    </style \n";
		fout << "  </head> \n";
		fout << "  <body> \n";
		fout << "<table style=\"width:100 % \"> \n";
		for (int i = 0; i < this->elements.size(); i++)
		{
			string obiect = this->elements[i]->getString();
			int j = 0;
			while (j < obiect.size())
			{
				if (obiect[j] != ',' && obiect[j] != ' ') {
					atribut.push_back(obiect[j]);
				}
				if (obiect[j] == ',') {
					atribute.push_back(atribut);
					atribut = gol;
				}
				j++;
			}
			if (atribute[0] == "Financiare") {
				if (atribute[3] == "0") {
					fout << "<tr bgcolor=\"#FF0000\"> \n";

					for (int i = 0; i < atribute.size(); i++) {
						fout << "    <td>" << atribute[i] << "</td>" << endl;
					}
					fout << "</tr> \n";
				}
				else {
						fout << "<tr> \n";

						for (int i = 0; i < atribute.size(); i++) {
							fout << "    <td>" << atribute[i] << "</td>" << endl;
						}
						fout << "</tr> \n";
				}
			}
			if (atribute[0] == "Fizice") {
				if (atribute[3] == "0" || atribute[5] == "0") {
					fout << "<tr bgcolor=\"#FF0000\"> \n";

					for (int i = 0; i < atribute.size(); i++) {
						fout << "    <td>" << atribute[i] << "</td>" << endl;
					}
					fout << "</tr> \n";
				}
				else {
					fout << "<tr> \n";

					for (int i = 0; i < atribute.size(); i++) {
						fout << "    <td>" << atribute[i] << "</td>" << endl;
					}
					fout << "</tr> \n";
				}
			}
			atribute = atrgol;
		}
		fout << "</body> \n";
		fout << "</html> \n";
		fout.close();
	}
}

template<class T>
void RepoFile<T>::loadFromFile(int ce)
{
	if (ce == 1) {
		string line;
		T* R;
		ResurseFinanciare rfin ;
		ResurseFizice rfiz;
		ifstream fin("In.txt");
		string atribut;
		string gol;
		char c;
		vector<string> atribute;
		vector<string> atrgol;
		while (getline(fin, line)) {
			for (int j = 0; j < line.size(); j++) {
				c = line[j];
				if (c != ' ' && c != ',') {
					atribut.push_back(c);
				}
				if (c == ',') {
					atribute.push_back(atribut);
					atribut = gol;
				}
			}
			if (atribute[0] == "Financiare") {
				rfin = rfin.pseudoConstructor(atribute);
				R = new ResurseFinanciare(rfin);
				this->elements.push_back(R);
			}
			if (atribute[0] == "Fizice") {
				rfiz = rfiz.pseudoConstructor(atribute);
				R = new ResurseFizice(rfiz);
				this->elements.push_back(R);
			}
			atribute = atrgol;
		}
	}
	if (ce == 2) {
		int k = 0;
		string line;
		T* R;
		ResurseFinanciare resFin;
		ResurseFizice resFiz;
		ifstream fin("In.html");
		string atribut;
		string gol;
		vector<string> atribute;
		vector<string> atrgol;
		while (getline(fin, line))
		{

			int strBegin = line.find_first_not_of(" \t");

			if (strBegin != -1)
			{
				if (line.substr(strBegin, 4) == "</tr") {
					if (!atribute.empty()) {
						if (atribute[0] == "Financiare") {
							resFin = resFin.pseudoConstructor(atribute);
							R = new ResurseFinanciare(resFin);
							this->elements.push_back(R);
						}
						if (atribute[0] == "Fizice") {
							resFiz = resFiz.pseudoConstructor(atribute);
							R = new ResurseFizice(resFiz);
							this->elements.push_back(R);
						}
					}
					atribute = atrgol;
				}

				if (line.substr(strBegin, 4) != "<td>")
					continue;
				else {
					int j = strBegin + 4;
					while (line[j] != '<') {
						atribut.push_back(line[j]);
						j++;
					}
					atribute.push_back(atribut);
					atribut = gol;
				}
			}


		}
		fin.close();
	}

	
}
