/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 20/11/2020
    copyright            : (C) 2020 par Francine Jin et Tran Quang Huy
    e-mail               : jinfrancine@hotmail.com
*************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

Catalogue::Catalogue()
{
    trajets = new Liste;
}

Catalogue::~Catalogue()
{
    delete trajets;
}

void Catalogue::Afficher() const
{
    trajets->Afficher();
}

void Catalogue::AjouterTrajetSimple(const char *villeDepart,
                                    const char *villeArrivee,
                                    const char *transport)
{
    const TrajetSimple *unTrajetSimple =
      new TrajetSimple(villeDepart, villeArrivee, transport);
    trajets->pushBack(unTrajetSimple, 0);

    cout << "Ajout réussi dans le catalogue du ";
    unTrajetSimple->Afficher();

}

void Catalogue::AjouterTrajetCompose(const Liste *uneListe)
{
    const TrajetCompose *unTrajetCompose = new TrajetCompose(uneListe);
    trajets->pushBack(unTrajetCompose, 0);

    cout << "Ajout réussi dans le catalogue du trajet composé : " << endl;
    unTrajetCompose->Afficher();
}

void Catalogue::RechercheSimple(const char *Start, const char *Goal) const
{
    int nombreParcours = 0;
    const Etape *x = trajets->getPremiere();
    while (x != NULL) {

        if (strcmp(x->getTrajet()->getDepart(), Start) == 0 &&
            strcmp(x->getTrajet()->getArrivee(), Goal) == 0) {

            nombreParcours++;
            cout << "Parcours " << nombreParcours << " : " << endl;
            x->Afficher();

        }
        x = x->getSuivant();
    }
    cout << "Nombre total de parcours possibles : " << nombreParcours << endl;
}

void Catalogue::RechercheAvancee(const char *Start, const char *Goal) const
{
    int nombreParcours = 0;
    const Etape *x = trajets->getPremiere();

    while (x != NULL) {

        if (strcmp(x->getTrajet()->getDepart(), Start) == 0) {

            bool *visited = new bool[trajets->getSize()];
            visited[trajets->getPosition(x)] = 1;                                                                                                          \
            Liste *A = new Liste;
            A->pushBack(x->getTrajet(), 0);

            BFS(x->getTrajet(), visited, Goal, A, nombreParcours);

        }
        x = x->getSuivant();
    }
}

void Catalogue::BFS(const Trajet *x, bool *v, const char *Goal,
                    Liste *Chemin, int &nbParcours) const
{
    if (strcmp(x->getArrivee(), Goal) == 0) {
        nbParcours++;
        cout << "\n#Parcours " << nbParcours << " : ";
        Chemin->Afficher();
    } else {
        const Etape *y = trajets->getPremiere();

        while (y != NULL) {

            if (strcmp(x->getArrivee(), y->getTrajet()->getDepart()) == 0 &&
                v[trajets->getPosition(y)] == false) {

                v[trajets->getPosition(y)] = true;
                Chemin->pushBack(y->getTrajet(), 1);

                BFS(y->getTrajet(), v, Goal, Chemin, nbParcours);

                v[trajets->getPosition(y)] = false;
                Chemin->remove(Chemin->getDerniere());                                                                                                       \
            }

            y = y->getSuivant();
        }
    }

}
