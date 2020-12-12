#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Etape.h"
#include "Liste.h"

void ajouterUnTrajet(Catalogue *UneCatalogue);

void afficherLeCatalogue(Catalogue *UneCatalogue);

void rechercherUnParcours(Catalogue *UneCatalogue);

void rechercherAvanceeUnParcours(Catalogue *UneCatalogue);

int main()
{

	// TrajetSimple ts1("paris", "lyon", "avion");

	// ts1.Afficher();

	// TrajetSimple ts2 = ts1;

	// ts2.Afficher();
	Catalogue *catalogue = new Catalogue;

	while (1)
	{

		cout << endl;
		cout << "|******************************************" << endl;
		cout << "| 1 - Add a path							" << endl;		                                      
		cout << "| 2 - Display the catalog					" << endl;
		cout << "| 3 - Search for a course					" << endl;										
		cout << "| 4 - Search for a course (advanced mode)	" << endl;						
		cout << "| 5 - Exit									" << endl;														
		cout << "Enter the corresponding number : ";

		char option;
		cin >> option;

		if (option == '1') {
			ajouterUnTrajet(catalogue);
		}
		else if (option == '2') {
			catalogue->Afficher();//afficherLeCatalogue(catalogue);
		}
		else if (option == '3')
		{
			
			char *villeDepart = new char[100];
			char *villeArrivee = new char[100];

			cout << "From : ";
			cin >> villeDepart;
			cout << "To : ";
			cin >> villeArrivee;

			catalogue->RechercheSimple(villeDepart, villeArrivee);
			//rechercherUnParcours(catalogue);
		}
		else if (option == '4')
		{
			rechercherAvanceeUnParcours(catalogue);
		}
		else if (option == '5')
		{
			break;
		}
		else
		{
			cout << "Invalid choice. Please enter a number between 1 and 5 ! ";
		}
	}
	cout << "\n";

	return 0;
}

void ajouterUnTrajet(Catalogue *UneCatalogue)
{
	cout << "Enter the number of steps on the route, "
		 << "1 if it's a direct route : ";
	int N;
	cin >> N;

	char *villeDepart = new char[100];
	char *villeSuivant = new char[100];
	char *transport = new char[100];

	cout << "From : ";
	cin >> villeDepart;

	if (N == 1) {
		cout << "To : ";
		cin >> villeSuivant;

		cout << "By : ";
		cin >> transport;

		UneCatalogue->AjouterTrajetSimple(villeDepart, villeSuivant, transport);
	} else {
		Liste *ListeDeTrajets = new Liste;

		for (int i = 1; i <= N; i++) {
			if (i < N) {
				cout << "Next : ";
			} else {
				cout << "To : ";
			}
			cin >> villeSuivant;

			cout << "By : ";
			cin >> transport;

			const TrajetSimple *trajet_simple = new TrajetSimple(villeDepart, villeSuivant, transport);
			ListeDeTrajets->pushBack(trajet_simple, 1);
 
			//villeDepart = new char[strlen(villeSuivant) + 1];
			//strcpy(villeDepart, villeSuivant);
			*villeDepart = *villeSuivant;
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

	cout << "From : ";
	cin >> villeDepart;
	cout << "To : ";
	cin >> villeArrivee;

	UneCatalogue->RechercheSimple(villeDepart, villeArrivee);
}

void rechercherAvanceeUnParcours(Catalogue *UneCatalogue) {
	char *villeDepart = new char[100];
	char *villeArrivee = new char[100];

	cout << "From : ";
	cin >> villeDepart;
	cout << "To : ";
	cin >> villeArrivee;

	UneCatalogue->RechercheAvancee(villeDepart, villeArrivee);
}
