//
//  Appartement.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Appartement.hpp"

//CONSTRUCTEURS:
Appartement::Appartement(){
    
}

Appartement::Appartement(int _prix, string _adr, string ville, int _nb_m2, string typeDeBien, int _nb_pieces, int _nb_etages, bool _garage, bool _cave, bool _balcon, int _nb_total_appart) : Bien(prix,adresse_bien, ville, nb_m2, typeDeBien){
    nb_pieces=_nb_pieces;
    nb_etages = _nb_etages;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
    nb_total_appart=_nb_total_appart;
}


//DESTRUCTEUR:
Appartement::~Appartement(){
    
}
