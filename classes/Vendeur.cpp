//
//  Vendeur.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Vendeur.hpp"

Vendeur::Vendeur(){
    
}

Vendeur::Vendeur(string nom, string adresse): Client(nom,adresse){
    
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

vector<Bien*> Vendeur::getListeBiens(){
    return ListeBiens;
}

void Vendeur::afficherBiens(){
    for(int i=0;i<ListeBiens.size();i++){
        ListeBiens[i]->afficher();
    }
}

void Vendeur::afficherBiensCriteres(string type, int prix, int surface, string ville){
    for(int i=0;i<ListeBiens.size();i++){
        if(ListeBiens[i]->getType()==type && ListeBiens[i]->getPrix()==prix
           && ListeBiens[i]->getSurface()==surface && ListeBiens[i]->getVille()==ville)
        ListeBiens[i]->afficher();
    }
}
