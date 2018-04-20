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

Bien::Bien(int _prix, string _adr, string _ville, int _nb_m2, string _typeDeBien)
{
    id_bien = ++next_id_bien;
    prix = _prix;
    adresse_bien = _adr;
    ville=_ville;
    nb_m2 = _nb_m2;
    typeDeBien=_typeDeBien;
}

void Bien::afficher(){
    cout << id_bien << " " << prix << "€ " << adresse_bien << " " << ville << " " << nb_m2 << " m2" << endl;
}

string Bien::getType(){
    return typeDeBien;
}

int Bien::getPrix(){
    return prix;
}
int Bien::getSurface(){
    return nb_m2;
}
string Bien::getVille(){
    return ville;
}
