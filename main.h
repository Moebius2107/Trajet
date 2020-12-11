
//--------- Interface du module <Main> (fichier Main.h) ------------------
#if ! defined ( MAIN_H )
#define MAIN_H

#include "Catalogue.h"

int main ( );

void ajouterUnTrajet( Catalogue *UneCatalogue);

void afficherLeCatalogue( Catalogue *UneCatalogue);

void rechercherUnParcours( Catalogue *UneCatalogue);

void rechercherAvanceeUnParcours( Catalogue *UneCatalogue);


#endif // MAIN_H

