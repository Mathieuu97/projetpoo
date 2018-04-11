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
protected:
    bool proposition_achat;
    float prix;
public:
    int id_visite;
    Visite();
    Visite(int _id_visite, bool _proposition_achat, float _prix);
    ~Visite();
};



#endif /* Visite_hpp */
