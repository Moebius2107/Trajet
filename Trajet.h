/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés

    char *depart; 
    char *arrivee; 

protected:
//-------------------------------------------- Constructeurs - destructeur
    Trajet(const char *Start, const char *Goal);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0; 
    // Mode d'emploi :
    //
    // Contrat :
    //

    const char *getDepart() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const char *getArrivee() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

};


#endif // TRAJET_H

