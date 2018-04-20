//
//  Agence.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Agence_hpp
#define Agence_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <list>
#include "Vendeur.hpp"
#include "Acheteur.hpp"
using namespace std;

class Agence {
private:
    string nom;
    map<string, Vendeur *> ListeVendeur;
    map<string, Acheteur *> ListeAcheteur;
public:
    bool termine;
    Agence();
    ~Agence();
    void ajouterClient();
    void ajouterBien();
    void nouvellePropositionAchat();
    void rechercheSimple();
    void demandeRechercheAvancee();
    void rechercheAvancee(string, int , int, string);
    void quitterAgenceSiDemande(string);
    bool acheteurExiste(string);
    bool VendeurExiste(string);
    void recherche_bien_fichier();
    
    Acheteur getAcheteur(string);
    Vendeur getVendeur(string);
};



#endif /* Agence_hpp */
