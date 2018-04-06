//
//  Vendeur.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Vendeur_hpp
#define Vendeur_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Client.hpp"
#include "Bien.hpp"
using namespace std;

class Vendeur : public Client{
private:
    //vector<Bien *> ListeBiens;
protected:
    Vendeur(int, string, string);
    ~Vendeur();
    void ajout_bien(Bien);
    void suppression_bien(Bien);
};

#endif /* Vendeur_hpp */