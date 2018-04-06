//
//  Bien.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Bien_hpp
#define Bien_hpp

#include <stdio.h>

#include<iostream>
#include<string.h>

using namespace std;

class Bien
{
protected:
    int id_bien;
    float prix;
    string adresse_bien;
    float nb_m2;
    string type_de_bien;

public:

        Bien();
        ~Bien();
};

#endif /* Bien_hpp */

