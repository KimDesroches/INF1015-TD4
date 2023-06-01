////////////////////////////////////////////////////////////////////////////////
/// \file   VilainHeros.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe VilainHeros. 
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "Heros.hpp"
#include "Vilain.hpp"
#include <vector>
using namespace std;

class VilainHeros : public Heros, public Vilain {
public:
	VilainHeros(Vilain v, Heros h) : Personnage(v.getNom() + "-" + h.getNom(), v.getParution() + "-" + h.getParution()),
		Vilain(v.getNom(), v.getParution(), v.getObjectif()), Heros(h.getNom(), h.getParution(),h.getEnnemi(), h.getAllies()), missionSpeciale_(v.getObjectif() + " dans le monde de " + h.getParution()) {};


	void afficher(ostream& os, char couleur = ' ') {
		Vilain::afficher(os, couleur);
		changerCouleur(os, couleur);
		os << "Ennemi : " << Heros::getEnnemi() << "\nAlliés : \n";
		for (auto&& elem : Heros::getAllies())
			os << "\t" << elem << endl;
		os << "Mission spéciale : " << missionSpeciale_ << endl;
		changerCouleur(os);
	}

private:
	string missionSpeciale_;
};
