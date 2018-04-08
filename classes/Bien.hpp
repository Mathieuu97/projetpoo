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
public:
    int id_bien;
    float prix;
    string adresse_bien;
    float nb_m2;
    string type_de_bien;
    
public:

        Bien();
        Bien(int _id, float _prix, string _adr, float _nb_m2, string _type);
        ~Bien();
};

#endif /* Bien_hpp */

