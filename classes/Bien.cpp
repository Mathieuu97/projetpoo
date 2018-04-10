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

int Bien::next_id_bien = 0;

Bien::Bien()
{
    id_bien = ++next_id_bien;
}


Bien::~Bien()
{
    //dtor
}

Bien::Bien(float _prix, string _adr, float _nb_m2)
{
    id_bien = ++next_id_bien;
    prix = _prix;
    adresse_bien = _adr;
    nb_m2 = _nb_m2;
}

