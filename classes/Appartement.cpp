//
//  Appartement.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Appartement.hpp"

Appartement::Appartement(){
    
}

Appartement::Appartement(float _prix, string _adr, float _nb_m2, int _nb_pieces, int _nb_etages, bool _garage, bool _cave, bool _balcon, int _nb_total_appart) : Bien(prix,adresse_bien,nb_m2){
    nb_pieces=_nb_pieces;
    garage=_garage;
    cave=_cave;
    balcon=_balcon;
    nb_total_appart=_nb_total_appart;
}

Appartement::~Appartement(){
    
}
