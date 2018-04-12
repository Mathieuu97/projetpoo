//
//  Acheteur.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Acheteur.hpp"

Acheteur::Acheteur(){
    
}

Acheteur::Acheteur(string nom, string adresse): Client(nom,adresse){
    
}

Acheteur::~Acheteur(){
    
}

void Acheteur::ajout_visite(Visite* nouvelleVisite){
    ListeVisites.push_back(nouvelleVisite);
}

void Acheteur::suppression_visite(Visite* aSupprimer){
    for(int i=0; i<ListeVisites.size();i++){
        if(ListeVisites[i]->id_visite==aSupprimer->id_visite)
            ListeVisites.erase(ListeVisites.begin()+i);
    }
}
