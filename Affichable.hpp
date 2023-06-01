////////////////////////////////////////////////////////////////////////////////
/// \file   Affichable.hpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// Les declarations et prototypes de la classe abstraite Affichable. 
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
using namespace std;

class Affichable {
public:
	virtual void changerCouleur(ostream& os, char couleur) = 0;
	virtual void afficher(ostream& os, char couleur) = 0;
};
