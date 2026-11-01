#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
class Livre
{
private:
    const int id;
    string titre;
    string auteur;
    Date parution;
    int* notes;
    int nbNotes;
    static int compteurId;
    int nbInstances;
    int capacite;
public:
    Livre(string, string, Date);
    Livre(const Livre&);
    Livre operator=(const Livre&);
    void afficher()const;
    void ajouterNotes(int note);
    double moyenne()const;
    ~Livre();
};

