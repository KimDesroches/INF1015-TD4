////////////////////////////////////////////////////////////////////////////////
/// \file   Vilain.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe Vilain. 
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Personnage.hpp"
#include <vector>
using namespace std;

class Vilain : virtual public Personnage {
public:
	Vilain(const string& nom = " ", const string& parution = " ", const string& objectif = " ") : Personnage(nom, parution), objectif_(objectif) {}

	void afficher(ostream& os, char couleur = ' ') {
		Personnage::afficher(os, couleur);
		changerCouleur(os, couleur);
		os << "Objectif: " << objectif_ << endl;
		changerCouleur(os);
	}

	const string& getObjectif() const { return objectif_; }

private:
	string objectif_;

};