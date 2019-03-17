#pragma once
class Monede {

private:

	int monede_1;
	int monede_5;
	int monede_10;
	int monede_50;
public:

	Monede(int bani_1, int bani_5, int bani_10, int bani_50);
	Monede();
	Monede &operator=(const Monede &nr);
	Monede(const Monede &nr);

	int get_m1();
	int get_m5();
	int get_m10();
	int get_m50();

	void set_m1(int nr);
	void set_m5(int nr);
	void set_m10(int nr);
	void set_m50(int nr);
};