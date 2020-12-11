
/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Trajet.h"
#include "TrajetCompose.h"
#include "Liste.h"

TrajetCompose::TrajetCompose(const Liste *UneListe) : 
        Trajet(UneListe->getPremiere()->getTrajet()->getDepart(), 
               UneListe->getDerniere()->getTrajet()->getArrivee())
{
	etapes = new Liste;
    const Etape *x = UneListe->getPremiere();
    while (x != NULL) {
        etapes->pushBack(x->getTrajet(), 1);
        x = x->getSuivant();
    }
}

TrajetCompose::~TrajetCompose()
{
	delete etapes;
} 

void TrajetCompose::Afficher() const
{
    cout << "Depart : " << etapes->getPremiere()->getTrajet()->getDepart() << "   "
         << "Arrivee : " << etapes->getDerniere()->getTrajet()->getArrivee() << endl;
	etapes->Afficher();
}


