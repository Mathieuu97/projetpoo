//
//  Acheteur.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Acheteur_hpp
#define Acheteur_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Client.hpp"
#include "Visite.hpp"
using namespace std;

class Acheteur : public Client{
private:
    vector<Visite *> ListeVisites;
    bool propositionAchat;
    int montantProposition;
    Visite getVisite(int);
public:
    Acheteur();
    Acheteur(string, string);
    ~Acheteur();
    void ajout_visite(Visite*);
    void suppression_visite(Visite*);
    void ajouterProposition(int, int);
    bool visiteExiste(int);
};

#endif /* Acheteur_hpp */
