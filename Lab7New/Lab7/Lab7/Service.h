#pragma once
#include "vector"
#include "RepoFile.h"
#include "Validator.h"

template <class T>
class Service {
private:

	RepoFile<T> & repo;

public:

	Service(RepoFile<T> &repo) : repo{ repo } {}

	void addElem(T* p);
	vector<T*> getAll();
	void saveToFile(int ok);
	void loadFromFile(int ok);
	vector<T*> cautare(string nume, string data);
	void modificare(T* res, T* resNou);

};
template <class T>
vector<T*> Service<T>::cautare(string nume, string data) {
	vector<T*> gasite;
	vector<T*> v = getAll();
	for (int i = 0; i < v.size(); i++) {
		if ((*v[i]).getNume() == nume || (*v[i]).getData() == data)
			gasite.push_back(v[i]);
	}
	return gasite;
}

template <class T>
void Service<T>::modificare(T* res, T* resNou) {
	this->repo.update(res, resNou);
	saveToFile(1);
	saveToFile(2);
}

template <class T>
void Service<T>::addElem(T* p) {

	this->repo.addElem(p);
	saveToFile(1);
	saveToFile(2);
}

template <class T>
vector<T*> Service<T>::getAll() {
	return this->repo.getAll();
}

template <class T>
void Service<T>::saveToFile(int ok) {
	this->repo.saveToFile(ok);
}

template <class T>
void Service<T>::loadFromFile(int ok) {
	this->repo.loadFromFile(ok);

}