//

//  Bien.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Bien_hpp
#define Bien_hpp

#include <stdio.h>

#include<iostream>
#include<string.h>

using namespace std;

class Bien
{
protected:
    static int next_id_bien;
    float prix;
    string adresse_bien;
    string ville;
    float nb_m2;
    int idVendeur;
    
public:
    int id_bien;
        Bien();
        Bien(float _prix, string _adr, string _ville, float _nb_m2);
        ~Bien();
};

#endif /* Bien_hpp */

