//
//  Terrain.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Terrain_hpp
#define Terrain_hpp

#include <stdio.h>
#include <iostream>
#include "Bien.hpp"

using namespace std;

class Terrain : public Bien {
protected:
    bool constructible;

public:
    Terrain();
    Terrain(int _prix, string _adr, string ville, int _nb_m2, string typeDeBien, bool _constructible);
    ~Terrain();
};
#endif /* Terrain_hpp */
