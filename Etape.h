/*************************************************************************
                           Etape  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( ETAPE_H )
#define ETAPE_H

#include "Trajet.h"

class Etape
{

private:
    const Trajet *trajetActuel; 
    Etape *precedent;
    Etape *suivant;

public:

    Etape ( const Trajet *unTrajet );

    virtual ~Etape ( );

    void Afficher( ) const;

    const Trajet *getTrajet ( ) const;

    Etape *getPrecedent ( ) const;

    Etape *getSuivant ( ) const;

    void setTrajet ( const Trajet *unTrajet );
    
    void setPrecedent ( Etape *uneEtape );

    void setSuivant ( Etape *uneEtape );

};


#endif // ETAPE_H

