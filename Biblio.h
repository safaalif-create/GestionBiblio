#pragma once
#include<iostream>
#include"Livre.h"
using namespace std;
class Biblio
{
private:
	string nom;
	Livre** livres;
	int nbLivres;
	int capaciteMax;
	static int nbBibliotheques;
public:
	Biblio(string nom, int capacitMax);
	Biblio(const Biblio&);
	Biblio operator=(const Biblio&);
	~Biblio();
	Livre  ajouterLivre(const Livre&);
	Biblio operator+=(const Livre&);
	Livre* rechercher(int)const;
	Livre* rechercher(string)const;
};

