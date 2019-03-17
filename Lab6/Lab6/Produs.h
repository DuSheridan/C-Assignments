#pragma once
class Produs {

private:
	int cod;
	char* nume;
	float pret;
public:
	Produs(int cod, const char* nume, float pret);
	~Produs();
	Produs();
	Produs &operator=(const Produs &Produs);
	Produs(const Produs &Produs);
	int get_cod();
	void set_cod(int cod);
	char* get_nume();
	void set_nume(const char* nume);
	float get_pret();
	void set_pret(float pret);


















};