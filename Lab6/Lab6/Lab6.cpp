#include "stdafx.h"
#include "teste.h"
#include <iostream>
#include "Ui.h"
#include "ctrl.h"
#include "Repository.h"
#include "RepoFile.h"

int main()
{
	teste();
	RepoFile<Produs> repoFile;
	Controller service(repoFile);
	Ui ui(service);
	ui.meniu();	
    return 0;
}