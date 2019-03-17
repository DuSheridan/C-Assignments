#pragma once
#include "stdafx.h"
#include "Repository.h"
#include "Produs.h"
#include "fstream"

template <class T>
class RepoFile:public Repository<T> 
{

//private:
	//vector <T> elements;
	

public:
	void save_to_file();
	void load_from_file();
	virtual void add_elem(T &pr);
};

template <class T>
void RepoFile<T>::save_to_file()
{
	ofstream fout("f.txt");
	for (unsigned int i = 0; i < this->elements.size(); ++i)
		fout << this->elements[i].get_cod() << " " << this->elements[i].get_nume() << " " << this->elements[i].get_pret() << endl;
	fout.close();
}

template<class T>
void RepoFile<T>::load_from_file()
{
	ifstream fin("f.txt");
	int cod;
	char nume[30];
	float pret;
	while (fin >> cod >> nume >> pret)
	{
		Produs P(cod, nume, pret);
		this->elements.push_back(P);
	}
	fin.close();
}

template <class T>
void RepoFile<T>::add_elem(T &pr)
{
	this->Repository<T>::add_elem(pr);
	save_to_file();
}