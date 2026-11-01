// GestionBiblio.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Date.h"
#include "Livre.h"
#include "Biblio.h"
int main()
{
    Date d1(28, 9, 2024);
    Date d2(15, 8, 2025);

    Livre l1("Roman","Hugo",d1);
    Livre l2("Poeme", "jack", d2);

    Biblio B1("biblioMedia", 300);
    Biblio B2("bibliocasa", 500);
    
    B1 += l1;
    B1 += l2;
    cout << "recherche par titre:" << endl;
    Livre* p = B1.rechercher("Roman");
    if (p != nullptr)
        p->afficher();
    else
        cout << "livre introuvable" << endl;
    cout << "recherche par Id" << endl;
    Livre* p2 = B1.rechercher(1);
    if (p2 != nullptr)
        p2->afficher();
    else
        cout << "livre introuvable" << endl;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
