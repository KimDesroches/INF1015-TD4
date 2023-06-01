////////////////////////////////////////////////////////////////////////////////
/// \file   Heros.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe Heros. 
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Personnage.hpp"
#include <vector>
using namespace std;

class Heros: virtual public Personnage {
public:
	Heros(const string& nom = " ", const string& parution = " ", const string& ennemi = " ", vector<string> allies = {}) : Personnage(nom, parution), ennemi_(ennemi), allies_(allies) {};

	void ajouterAllies(const string& allie) { 
		allies_.push_back(allie); 
	}

	void afficher(ostream& os, char couleur = ' ') {
		Personnage::afficher(os, couleur);
		changerCouleur(os, couleur);
		os << "Ennemi: " << ennemi_ << "\nAlliés:\n ";
		for (auto&& elem : allies_)
			os << "\t" << elem << endl;
		changerCouleur(os);
	}

	const string& getEnnemi() const { return ennemi_; }
	vector<string> getAllies() { return allies_; }
	
private:
	string ennemi_;
	vector<string> allies_;
};