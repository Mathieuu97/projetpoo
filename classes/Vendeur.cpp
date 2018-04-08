//
//  Vendeur.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Vendeur.hpp"

Vendeur::Vendeur(int id, string nom, string adresse): Client(id,nom,adresse){
    
}

Vendeur::~Vendeur(){
    
}

void Vendeur::ajout_bien(Bien* nouveauBien){
    ListeBiens.push_back(nouveauBien);
}

void Vendeur::suppression_bien(Bien* aSupprimer){
    for(int i=0; i<ListeBiens.size();i++){
        if(ListeBiens[i]->id_bien==aSupprimer->id_bien)
                ListeBiens.erase(ListeBiens.begin()+i);
    }
}
