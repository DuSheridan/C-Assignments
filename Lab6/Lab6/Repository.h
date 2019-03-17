#pragma once
#include "Produs.h"
#include <vector>
using namespace std;

template <class T>
class Repository
{
protected:
	vector <T> elements;
public:
	virtual void add_elem(T &pr);
	vector <T> getAll();

};
template <class T>
virtual void Repository<T>::add_elem(T &st)
{
	elements.push_back(st);
}
template <class T>
vector <T> Repository<T>::getAll()
{
	return this->elements;
}