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

//Attribut permettant d'incrementer l'identifiant de chaque nouveau bien pour ne pas avoir un même identifiant pour deux biens différents : 
int Bien::next_id_bien = 0;


//CONSTRUCTEURS:
Bien::Bien()
{
    //Affectation de l'identifiant du bien (avec incrémentation):
    id_bien = ++next_id_bien;
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

//DESTRUCTEUR:
Bien::~Bien()
{
    //dtor
}

//Affichage des caractéristiques du bien:
void Bien::afficher(){
    cout << id_bien << " " << prix << "€ " << adresse_bien << " " << ville << " " << nb_m2 << " m2" << endl;
}

//ACCESSEUR permettant d'acceder au type du bien (attribut privé):
string Bien::getType(){
    return typeDeBien;
}


//ACCESSEUR permettant d'acceder au prix du bien (attribut privé):
int Bien::getPrix(){
    return prix;
}


//ACCESSEUR permettant d'acceder à la surface du bien (attribut privé):
int Bien::getSurface(){
    return nb_m2;
}


//ACCESSEUR permettant d'acceder à l'adresse du bien (attribut privé):
string Bien::getVille(){
    return ville;
}
