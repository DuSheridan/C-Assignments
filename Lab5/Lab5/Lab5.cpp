// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ui.h"
#include <iostream>
#include "teste.h"
#include "assert.h"

using namespace std;

int main()
{
	teste();
	Repository repo;
	Controller service(repo);
	Ui ui(service);

	ui.meniu();

    return 0;
}

