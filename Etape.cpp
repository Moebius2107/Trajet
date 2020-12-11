/*************************************************************************
                           Etape  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "Trajet.h"
#include "Etape.h"
#include "TrajetCompose.h"

Etape::Etape ( const Trajet *unTrajet ) : 
    trajetActuel(unTrajet), precedent(NULL), suivant(NULL) {}

Etape::~Etape ( )
{
    delete precedent;
    delete suivant;
} 

void Etape::Afficher () const
{
	trajetActuel->Afficher();
}

const Trajet *Etape::getTrajet() const 
{
    return trajetActuel;
}

Etape *Etape::getPrecedent() const
{
    return precedent;
}

Etape *Etape::getSuivant() const
{
    return suivant;
}

void Etape::setTrajet( const Trajet *unTrajet ) 
{
    trajetActuel = unTrajet;
}

void Etape::setSuivant( Etape *uneEtape ) 
{
    suivant = uneEtape;
}

void Etape::setPrecedent( Etape *uneEtape ) 
{
    precedent = uneEtape;
}



