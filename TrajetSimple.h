/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//--- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) -----
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    char *moyen;

//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple(const char *Start, const char *Goal, const char *Means);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    
};


#endif // TRAJET_SIMPLE_H

