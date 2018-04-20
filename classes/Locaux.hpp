//
//  Locaux.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Locaux_hpp
#define Locaux_hpp

#include <stdio.h>
#include <iostream>
#include "Bien.hpp"

using namespace std;

class Locaux: public Bien {
protected:
    float taille_vitrine;
    bool piece_stockage;

public:
    Locaux();
    Locaux(int _prix, string _adr, string ville, int _nb_m2, string typeDeBien, float _taille_vitrine, bool _piece_stock);
    ~Locaux();
};
#endif /* Locaux_hpp */
