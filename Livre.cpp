#include "Livre.h"
#include"Date.h"
int Livre::compteurId = 0;

Livre::Livre(string titre, string auteur, Date parution)
	:id(++compteurId),titre(titre),auteur(auteur),parution(parution),notes(nullptr),nbNotes(0)
{
}

Livre::Livre(const Livre& L):id(++compteurId)
{
	this->titre = L.titre;
	this->auteur= L.auteur;
	this->parution = L.parution;
	this->nbNotes = L.nbNotes;
	this->capacite = L.capacite;
	this->nbInstances = L.nbInstances;
	notes = new int[nbNotes];
	nbInstances++;
}

Livre Livre::operator=(const Livre&liv)
{
	this->titre = liv.titre;
	this->auteur = liv.auteur;
	this->parution = liv.parution;
	this->nbNotes = liv.nbNotes;
	notes = new int[nbNotes];
	return *this;
}

void Livre::afficher() const
{
	cout << "titre:" << this->titre;
	cout << "auteur:" << this->auteur;
	cout << "parution:"; 
	this->parution.afficherDate();
}

void Livre::ajouterNotes(int note)
{
	if (note >= 0 || note <= 20 )
		this->notes[nbNotes] = note;
	nbNotes++;
}

double Livre::moyenne() const
{ 
	double s = 0;
	for (int i = 0;i < nbNotes;i++)
		s += notes[i];
	return s;
}

Livre::~Livre()
{
	nbInstances--;
	delete notes;

}
