#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Etape.h"
#include "Liste.h"
#include "main.h"

int main()
{

	//Catalogue *catalogue = new Catalogue;

	TrajetSimple *ts1 = new TrajetSimple("paris", "berlin", "avion");

	TrajetSimple *ts2 = ts1;

	cout << ts1 << " " << ts2 << endl;

	ts2 = new TrajetSimple("hehe", "hihi", "dsds");
	
	cout << ts1 << " " << ts2 << endl;

	// while (1)
	// {
	// 	cout << '\n';
	// 	cout << "|************************************************************|\n";
	// 	cout << "| 1 - Ajouter un trajet                                      |\n";
	// 	cout << "| 2 - Afficher le catalogue                                  |\n";
	// 	cout << "| 3 - Rechercher un parcours                                 |\n";
	// 	cout << "| 4 - Rechercher un parcours (avancée)                       |\n";
	// 	cout << "| 5 - Quitter l'application                                  |\n";
	// 	cout << "Tapez le numéro correspondant à l'action de votre choix : ";

	// 	char option;
	// 	cin >> option;

	// 	if (option == '1') {
	// 		ajouterUnTrajet(catalogue);
	// 	}
	// 	else if (option == '2') {
	// 		afficherLeCatalogue(catalogue);
	// 	}
	// 	else if (option == '3')
	// 	{
	// 		rechercherUnParcours(catalogue);
	// 	}
	// 	else if (option == '4')
	// 	{
	// 		rechercherAvanceeUnParcours(catalogue);
	// 	}
	// 	else if (option == '5')
	// 	{
	// 		cout << "Toutes les donnees seront perdues. \n"
	//			 << "Avez-vous encore besoin de quitter ce programme? (Y/N) ";
	// 		char x; cin >> x;
	// 		if (x == 'Y' || x == 'y')
	// 		{
	// 			cout << "BYE\n";
	// 			break;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		cout << "Choix invalide. Entre 1 et 5, svp...";
	// 	}
	// }
	// cout << "\n";

	return 0;
}

void ajouterUnTrajet(Catalogue *UneCatalogue)
{
	cout << "Entrez le nombre d'étapes que comporte le trajet, \n"
		 << "1 si c'est un trajet direct : ";
	int N;
	cin >> N;

	char *villeDepart = new char[100];
	char *villeSuivant = new char[100];
	char *transport = new char[100];

	cout << "Ville de depart : ";
	cin >> villeDepart;

	if (N == 1) {
		cout << "Ville d'arrivee : ";
		cin >> villeSuivant;

		cout << "Moyen de transport : ";
		cin >> transport;

		UneCatalogue->AjouterTrajetSimple(villeDepart, villeSuivant, transport);
	} else {
		Liste *ListeDeTrajets = new Liste;

		for (int i = 1; i <= N; i++) {
			if (i < N) {
				cout << "Ville suivante : ";
			} else {
				cout << "Ville d'arrivee : ";
			}
			cin >> villeSuivant;

			cout << "Moyen de transport : ";
			cin >> transport;

			const TrajetSimple *trajet_simple = new TrajetSimple(villeDepart, villeSuivant, transport);
			ListeDeTrajets->pushBack(trajet_simple, 1);
			
			villeDepart = new char[strlen(villeSuivant) + 1];
			strcpy(villeDepart, villeSuivant);
		}

		UneCatalogue->AjouterTrajetCompose(ListeDeTrajets);
	}
}

void afficherLeCatalogue(Catalogue *UneCatalogue) {
	UneCatalogue->Afficher();
}

void rechercherUnParcours(Catalogue *UneCatalogue) {
	char *villeDepart = new char[100];
	char *villeArrivee = new char[100];

	cout << "Ville de depart : ";
	cin >> villeDepart;
	cout << "Ville d'arrivee : ";
	cin >> villeArrivee;

	UneCatalogue->RechercheSimple(villeDepart, villeArrivee);
}

void rechercherAvanceeUnParcours(Catalogue *UneCatalogue) {
	char *villeDepart = new char[100];
	char *villeArrivee = new char[100];

	cout << "Ville de depart : ";
	cin >> villeDepart;
	cout << "Ville d'arrivee : ";
	cin >> villeArrivee;

	UneCatalogue->RechercheAvancee(villeDepart, villeArrivee);
}