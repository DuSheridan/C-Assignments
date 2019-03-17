#pragma once
class Tranzactie{
private:
	int ziua;
	int bani;
	char* tip;
	char* desc;
public:
	Tranzactie(int ziua, int bani, const char* tip, const char* desc);
	Tranzactie(const Tranzactie &Tranzactie);
	Tranzactie();
	Tranzactie &operator=(const Tranzactie &Tranzactie);
	int get_ziua();
	void set_ziua(int ziua);
	int get_bani();
	void set_bani(int bani);
	char* get_tip();
	void set_tip(const char* tip);
	char* get_desc();
	void set_desc(const char* desc);
	~Tranzactie();
};