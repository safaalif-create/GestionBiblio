#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int jour;
	int mois;
	int annee;
public:
	Date(int=1, int=1, int=2000);
	bool estBisextile(int);
	void afficherDate()const;
	bool estValide(int, int, int);
};

