/*************************************************************************
                           Liste  -  description (Unsorted and Doubly Linked List)
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/


#if ! defined ( LISTE_H )
#define LISTE_H

#include "Trajet.h"
#include "Etape.h"

class Liste
{

private:
    Etape *premiere; 
    Etape *derniere;
    int size;

public:

    Liste ( );

    virtual ~Liste ( );

    void Afficher ( ) const;
    Etape *getPremiere( ) const;
    Etape *getDerniere( ) const;
    void pushBack ( const Trajet *unTrajet, const bool ordre); // <= un Trajet c'est class mère de TrajetSimple et TrajetCompose
    void pop_front ( );
    bool Empty( );
    int getSize ( ) const;
    int getPosition ( const Etape *uneEtape ) const;
    void remove ( const Etape *uneEtape );  // The delete opetation in Doubly LinkedList is more efficient 
                                            // if pointer to the node to be deleted is given.

};


#endif // LISTE_H

