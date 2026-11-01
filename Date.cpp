#include "Date.h"

Date::Date(int j, int m, int a)
{
	if (estValide(j,m,a)) {
		this->jour = j;
		this->mois = m;
		this->annee = a;
	}
	else {
		cout << "Erreur date incompatible!" << endl;
		this->jour = 1;
		this->mois = 1;
		this->annee = 2000;
	}
}

bool Date::estBisextile(int an)
{
	if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0))
		return true;
	else
	return false;
}

void Date::afficherDate() const
{
	cout << "jour/" << this->jour << endl;
	cout << "mois/" << this->mois << endl;
	cout << "annee/" << this->annee << endl;
}

bool Date::estValide(int j, int m, int a)
{
	int Mois[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (j < 0 || j>31 || m < 1 || m>12 || a < 1 || a>2026)
		return false;
    if (m == 2 && estBisextile(a) && j <= 29)
		return true;
	if (j > Mois[m - 1])
		return false;

	return true;
}
