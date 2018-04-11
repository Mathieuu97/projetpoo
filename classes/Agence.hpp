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
#include "Vendeur.hpp"
#include "Acheteur.hpp"
using namespace std;

class Agence {
private:
    vector<Vendeur *> ListeVendeur;
    vector<Acheteur *> ListeAcheteur;
protected:
    Agence();
    ~Agence();
    void ajouterClient(Client*);
    void ajouterBien(Bien*);
    void nouvellePropositionAchat(float);
};



#endif /* Agence_hpp */
