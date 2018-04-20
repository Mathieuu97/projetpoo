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


//CONSTRUCTEURS : Initialisation des attributs :
Acheteur::Acheteur(){
    propositionAchat=false;
    montantProposition=0;
}

Acheteur::Acheteur(string nom, string adresse): Client(nom,adresse){
    propositionAchat=false;
    montantProposition=0;
}


//DESTRUCTEUR :
Acheteur::~Acheteur(){
    
}

// Ajout d'une nouvelle visite effectuée par le client dans sa liste de visites :
void Acheteur::ajout_visite(Visite* nouvelleVisite){
    ListeVisites.push_back(nouvelleVisite);
}

//Ajout d'une nouvel proposition d'achat:
void Acheteur::ajouterProposition(int prop, int idVisite){
    
    //Récupération de la visite concernée et affectation du prix proposé par le client
    this->getVisite(idVisite).setPrix(prop);
    montantProposition=prop;
}


//ACCESSEUR permettant de retourner un objet visite selon son identifiant:
Visite Acheteur::getVisite(int id){
    Visite tmp_null;
    
    //Parcours de la liste des visites effectuées par le client:
    for(int i=0; i<ListeVisites.size();i++){
        
        //Si l'identifiant entré en paramètre correspond à celui de la liste que l'on parcours:
        if(ListeVisites[i]->getId()==id)
            
            //On fait une copie de cette visite:
            tmp_null= *ListeVisites[i];
    }
    //Pour ensuite la retourner:
    return tmp_null;
}

bool Acheteur::visiteExiste(int identifiant){
    for(int i=0;i<ListeVisites.size();i++){
        if(ListeVisites[i]->getId()==identifiant)
            return true;
    }
    return false;
}
