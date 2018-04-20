//
//  Visite.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Visite_hpp
#define Visite_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Visite {
private:
    bool proposition_achat;
    int prix;
    int idAcheteur;
    int id_visite;
public:
    int getId();
    void setPrix(int);
    Visite();
    Visite(int _id_visite, bool _proposition_achat, float _prix);
    ~Visite();
    void ajouterProposition(int);
};



#endif /* Visite_hpp */
