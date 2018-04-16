//
//  Maison.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Maison_hpp
#define Maison_hpp

#include <stdio.h>
#include <iostream>
#include "Bien.hpp"

using namespace std;

class Maison : public Bien {
protected:
    int nb_pieces;
    int nb_etages;
    bool garage;
    bool jardin;
    bool piscine;

public:
    Maison();
    Maison(int _prix, string _adr, string _ville, int _nb_m2, string typeDeBien, int _nb_pieces, int _nb_etages, bool _garage, bool _jardin, bool _piscine);
    ~Maison();
};

#endif /* Maison_hpp */
