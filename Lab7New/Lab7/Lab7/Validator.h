#pragma once
#pragma once
#include "stdafx.h"
#include <string>
#include "ResurseFinanciare.h"
#include "ResurseFizice.h"

using namespace std;

class Validator
{
private:
	string mesaj;
public:
	Validator()
	{
		mesaj = "";
	}
	void validate(ResurseFinanciare & RE);
	void validate(ResurseFizice & RF);
	~Validator() {}
};