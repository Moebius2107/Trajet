/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char *Start, const char *Goal, 
                           const char *Means) : Trajet(Start, Goal)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    moyen = new char[strlen(Means) + 1];
	strcpy(moyen, Means);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	delete [] moyen;
} //----- Fin de TrajetSimple

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() const
{
	cout << "Trajet de " << getDepart() << " à " << getArrivee() 
            << " en " << moyen << " " << endl;
}


