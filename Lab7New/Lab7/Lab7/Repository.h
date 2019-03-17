#pragma once
#include <vector>
#include "Resurse.h"



using namespace std;


template <class T>
class Repository
{
protected:
	vector <T*> elements;
public:
	void addElem(T* pr);
	vector <T*> getAll();
	void update(T* res, T* resNou);
};

template <class T>
void Repository<T>::update(T* res, T* resNou) {
	if ((*resNou).getTip() == "Financiare") {
		for (int i = 0; i < elements.size(); i++) {
			if ((*res).getNume() == elements[i]->getNume() && (*res).getData() == elements[i]->getData() && (*res).getValoare() == elements[i]->getValoare()) {
				elements[i] = resNou;
			}
		}
	
	}
	if ((*resNou).getTip() == "Fizice") {
		for (int i = 0; i < elements.size(); i++)
			if ((*res).getNume() == elements[i]->getNume() && (*res).getData() == elements[i]->getData() && (*res).getValoare() == elements[i]->getValoare()) {
				elements[i] = resNou;
			}
	}
}

template <class T>
void Repository<T>::addElem(T* st)
{
	elements.push_back(st);
}

template <class T>
vector <T*> Repository<T>::getAll()
{
	return this->elements;
}