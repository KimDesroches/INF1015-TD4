////////////////////////////////////////////////////////////////////////////////
/// \file   main.cpp
/// \authors Kim Desroches et Raissa Oumarou Petitot
///
/// La fonction principale du programme et les fonctions du TD4.
////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include "bibliotheque_cours.hpp"
#include "cppitertools/range.hpp"
#include <string>

#include "VilainHeros.hpp"

using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(std::istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(std::istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

std::string lireString(std::istream& fichier)
{
	std::string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), std::streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

using namespace std;


Heros lireHero(istream& f) {

	string nom = lireString(f);
	string parution = lireString(f);
	string ennemi = lireString(f);
	int nAllies = lireUint8(f);
	vector<string> allies;

	Heros hero(nom, parution, ennemi, allies);
	for ([[maybe_unused]] int i : iter::range(nAllies)) {
		hero.ajouterAllies(lireString(f));
	}
	return hero;
};

Vilain lireVilain(istream& f) {
	string nom = lireString(f);
	string parution = lireString(f);
	string objectif = lireString(f);

	Vilain vilain(nom, parution, objectif);
	return vilain;

}


int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	// Trait de separation
	static const string trait = "═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici
	vector<Heros> listeHeros;
	vector<Vilain> listeVilains;
	vector<shared_ptr<Personnage>> listePersonnages;
	Heros hero;
	Vilain vilain;

	int nHeros = lireUint16(fichierHeros);		
	for ([[maybe_unused]] int i : iter::range(nHeros)) {
		hero = lireHero(fichierHeros);
		listeHeros.push_back(hero);
		hero.afficher(cout, 'b');
		cout << trait << endl;
		listePersonnages.push_back(make_shared<Heros>(hero));
	}
	
	int nVilains = lireUint16(fichierVilains);
	for ([[maybe_unused]] int i : iter::range(nVilains)) {
		vilain = lireVilain(fichierVilains);
		listeVilains.push_back(vilain);
		vilain.afficher(cout, 'r');
		cout << trait << endl;
		listePersonnages.push_back(make_shared<Vilain>(vilain));

	}

	//VilainHeros
	VilainHeros vilainHeros(listeVilains[0], listeHeros[1]);
	vilainHeros.afficher(cout, 'p');
	cout << trait << endl;
	listePersonnages.push_back(make_shared<VilainHeros>(vilainHeros));

	for (auto&& personnage : listePersonnages) {
		personnage->afficher(cout);
		cout << trait << endl;
	}
	
}
