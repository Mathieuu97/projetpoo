//
//  Appartement.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Appartement_hpp
#define Appartement_hpp

#include <stdio.h>
#include <iostream>
#include "bien.hpp"

using namespace std;

class Appartement : public Bien {
protected:
    int nb_pieces;
    int nb_etages;
    bool garage;
    bool cave;
    bool balcon;
    int nb_total_appart;
public:
    Appartement();
    Appartement(int _prix, string _adr, string ville, int _nb_m2, string typeDeBien, int _nb_pieces, int _nb_etages, bool _garage, bool _cave, bool _balcon, int _nb_total_appart);
    ~Appartement();
};


#endif /* Appartement_hpp */
