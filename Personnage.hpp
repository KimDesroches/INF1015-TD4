////////////////////////////////////////////////////////////////////////////////
/// \file   Personnage.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe Personnage. 
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include "Affichable.hpp"
#include <iostream>

using namespace std;


class Personnage : public Affichable {
public:
	Personnage(const string& nom = " ", const string& parution = " ") : nom_(nom), parution_(parution) {};
	
	const string& getNom() const { return nom_; }
	const string& getParution() const { return parution_; }

	void changerCouleur(ostream& os, char couleur = 'w') {
		switch (couleur) {
		case 'r':
			os << "\033[91m";
			break;
		case 'b':
			os << "\033[94m";
			break;
		case 'p':
			os << "\033[35m";
			break;
		case 'w':
			os << "\033[0m";
			break;
		default:
			os << "\033[0m";
		}
	}

	void afficher(ostream& os, char couleur = 'w') {
		changerCouleur(os, couleur);
		os << "Nom: " << nom_ << "\nParution: " << parution_ << endl;
		changerCouleur(os);

	}

protected:
	string nom_;
	string parution_;

};