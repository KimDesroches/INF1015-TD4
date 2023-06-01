////////////////////////////////////////////////////////////////////////////////
/// \file   VilainHeros.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe VilainHeros. 
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Personnage.hpp"
#include <vector>
using namespace std;

class VilainHeros : public Heros, public Vilain {
public:
	//TODO: constructeur
	VilainHeros(Vilain v, Heros h) : Personnage(v.getNom() + "-" + h.getNom(), v.getParution() + "-" + h.getParution()),
		Vilain(v.getNom(), v.getParution(), v.getObjectif()), Heros(h.getNom(), h.getParution(),h.getEnnemi(), h.getAllies()), missionSpeciale_(v.getObjectif() + "dans le monde de " + h.getParution()) {};

	void afficher(ostream& os, char couleur = 'w') {
		Vilain::afficher(os, couleur);
		changerCouleur(os, couleur);
		os << "Ennemi : " << Heros::getEnnemi() << "\nAlli�s : \n";
		for (auto&& elem : Heros::getAllies())
			os << "\t" << elem << endl;
		os << "Mission sp�ciale : " << missionSpeciale_ << endl;
		changerCouleur(os);
	}

private:
	string missionSpeciale_;
};