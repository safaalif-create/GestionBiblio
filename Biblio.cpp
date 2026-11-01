#include "Biblio.h"
int Biblio::nbBibliotheques = 0;

Biblio::Biblio(string nom, int capacitMax)
{
	this->nom = nom;
	this->capaciteMax = capaciteMax;
	nbLivres = 0;
	livres = new Livre * [capaciteMax];
	nbBibliotheques++;
}

Biblio::Biblio(const Biblio& B)
{ 
	this->nom = B.nom;
	this->capaciteMax = B.capaciteMax;
	this->nbLivres = B.nbLivres;
	livres = new Livre * [capaciteMax];
	for (int i = 0; i < nbLivres;i++) {
		livres[i] = new Livre(*B.nbLivres[i]);
	}
	nbBibliotheques++;
}

Biblio Biblio::operator=(const Biblio& b)
{
	if (this != &b) {
		for (int i = 0; i < nbLivres;i++)
			delete livres[i];
		delete[] livres;
		nom = b.nom;
		capaciteMax = b.capaciteMax;
		nbLivres = b.nbLivres;
		livres = new Livre * [capaciteMax];
		for (int i = 0; i < nbLivres;i++) {
			livres[i] = new Livre(*b.nbLivres[i]);
		}
		return *this;
	}
}

Biblio::~Biblio()
{
	for (int i = 0; i < nbLivres;i++)
		delete livres[i];
	delete[] livres;
	nbBibliotheques--;


}

Livre Biblio::ajouterLivre(const Livre& l)
{
	if (nbLivres >= capaciteMax)
		cout << "Bibliotheque pleine" << endl;
	livres[nbLivres] = new Livre(l);
	nbLivres++;
	return *livres[nbLivres-1];
}

Biblio Biblio::operator+=(const Livre& l)
{
	ajouterLivre(l);

	return *this;
}

Livre* Biblio::rechercher(int id)const
{
	for (int i = 0;i < nbLivres;i++) {
		if (livres[i]->id == id)
			return livres[i];
	}
	return nullptr;
}

Livre* Biblio::rechercher(string titre)const
{
	for (int i = 0;i < nbLivres;i++) {
		if (livres[i]->titre == titre)
			return livres[i];
	}
	return nullptr;
}

