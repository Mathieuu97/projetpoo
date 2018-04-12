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
    propositionAchat=false;
    montantProposition=0;
}

Acheteur::Acheteur(string nom, string adresse): Client(nom,adresse){
    propositionAchat=false;
    montantProposition=0;
}

Acheteur::~Acheteur(){
    
}

void Acheteur::ajout_visite(Visite* nouvelleVisite){
    ListeVisites.push_back(nouvelleVisite);
}

void Acheteur::suppression_visite(Visite* aSupprimer){
    for(int i=0; i<ListeVisites.size();i++){
        if(ListeVisites[i]->getId()==aSupprimer->getId())
            ListeVisites.erase(ListeVisites.begin()+i);
    }
}

void Acheteur::ajouterProposition(int prop, int idVisite){
    this->getVisite(idVisite).setPrix(prop);
    montantProposition=prop;
}

Visite Acheteur::getVisite(int id){
    Visite tmp_null;
    for(int i=0; i<ListeVisites.size();i++){
        if(ListeVisites[i]->getId()==id)
            tmp_null= *ListeVisites[i];
    }
    return tmp_null;
}

bool Acheteur::visiteExiste(int identifiant){
    for(int i=0;i<ListeVisites.size();i++){
        if(ListeVisites[i]->getId()==identifiant)
            return true;
    }
    return false;
}
