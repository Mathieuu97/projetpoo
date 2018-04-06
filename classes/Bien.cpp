//
//  Bien.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "Bien.hpp"

using namespace std;

Bien::Bien()
{
    //ctor
}


Bien::~Bien()
{
    //dtor
}

Bien::Bien(int _id, float _prix, string _adr, float _nb_m2, string _type)
{
    id_bien = _id;
    prix = _prix;
    adresse_bien = _adr;
    nb_m2 = _nb_m2;
    type_de_bien = _type;
}


