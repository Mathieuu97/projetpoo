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
    int prix;
    string adresse_bien;
    string ville;
    int nb_m2;
    int idVendeur;
    string typeDeBien;
    
public:
    int id_bien;
    Bien();
    Bien(int _prix, string _adr, string _ville, int _nb_m2, string _typeDeBien);
    ~Bien();
    void afficher();
    string getType();
    int getPrix();
    int getSurface();
    string getVille();
};

#endif /* Bien_hpp */

