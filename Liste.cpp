/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
using namespace std;

#include "Trajet.h"
#include "Liste.h"
#include "Etape.h"

Liste::Liste() : size(0) {}

//Liste::Liste() :

Liste::~Liste()
{
    while (!Empty())
        pop_front();
} 

void Liste::Afficher() const
{
	const Etape *x = premiere;
    if (x == NULL) {
        cout << "There is nothing in the list."<<endl;
    } else {
        int i = 1;
        while (x != NULL) {
            cout << i << " : ";
            x->Afficher();
            x = x->getSuivant();
            i++;
        }
    }
}

// Add unTrajet to the end of the list
// Par défaut, ajouter non ordre
void Liste::pushBack(const Trajet *unTrajet, const bool ordre)
{
    //if ((ordre && derniere->getTrajet()->getArrivee() == unTrajet->getDepart()) || !ordre) {
    if (premiere == NULL) {
        premiere = new Etape(unTrajet);
        derniere = premiere;
    } else if (premiere == derniere) {
        premiere->setSuivant(new Etape(unTrajet));
        premiere->getSuivant()->setPrecedent(premiere);
        derniere = premiere->getSuivant();
    } else {
        derniere->setSuivant(new Etape(unTrajet));
        derniere->getSuivant()->setPrecedent(derniere);
        derniere = derniere->getSuivant();
    }
    ++size;
    //} else {
    //    cout << "Pas valide" << endl;
    //}

}

// Remove the trajet from the beginning of the list
void Liste::pop_front( )
{
    if (Empty())
        return;
    Etape *tmpEtape = premiere;
    premiere = premiere->getSuivant();
    delete tmpEtape;
    --size;
}

bool Liste::Empty( )
{
    return size == 0;
}

Etape *Liste::getPremiere() const {
    return premiere;
}
Etape *Liste::getDerniere() const {
    return derniere;
}

int Liste::getSize() const {
    return size;
}

int Liste::getPosition(const Etape *uneEtape) const {
    int pos = 0;
    const Etape *x = premiere;

    while (x != uneEtape) {
        pos++;
        if (x != NULL) {
            x = x->getSuivant();
        }
    }

    if (x == NULL) {
        return -1;
    } else {
        return pos;
    }
}

void Liste::remove(const Etape *uneEtape) {
    if (uneEtape->getPrecedent() != NULL) {
        uneEtape->getPrecedent()
                ->setSuivant(uneEtape->getSuivant());
    } else {
        premiere = uneEtape->getSuivant();
    }

    if (uneEtape->getSuivant() != NULL) {
        uneEtape->getSuivant()
                ->setPrecedent(uneEtape->getPrecedent());
    }
}
