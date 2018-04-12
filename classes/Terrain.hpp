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
#include "bien.hpp"

using namespace std;

class Terrain : public Bien {
protected:
    bool constructible;

public:
    Terrain();
    Terrain(float _prix, string _adr, string ville, float _nb_m2, bool _constructible);
    ~Terrain();
};
#endif /* Terrain_hpp */
