//
//  Vendeur.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Vendeur.hpp"


//CONSTRUCTEURS :
Vendeur::Vendeur(){    
}

Vendeur::Vendeur(string nom, string adresse): Client(nom,adresse){   
}

//DESTRUCTEUR :
Vendeur::~Vendeur(){
    
}

//Ajout d'un nouveau bien entré en paramètre dans la liste des biens à vendre du vendeur:
void Vendeur::ajout_bien(Bien* nouveauBien){
    ListeBiens.push_back(nouveauBien);
}

//Fonction permettant d'afficher tout les biens et leurs critères d'un vendeur : 
void Vendeur::afficherBiens(){

    //Parcours de la liste des biens du vendeur :
    for(int i=0;i<ListeBiens.size();i++){

        //Affichage des critères de chaque bien :
        ListeBiens[i]->afficher();
    }
}

//Tri et affichage de seulement certains biens selon certains critères entrés en paramètres : 
void Vendeur::afficherBiensCriteres(string type, int prix, int surface, string ville){
    
    //Parcours de la liste des biens du vendeur : 
    for(int i=0;i<ListeBiens.size();i++){
        
        //Si le bien possède le type, le prix, la surface et la ville entré en paramètre (c'est à dire demandé par le client): 
        if(ListeBiens[i]->getType()==type && ListeBiens[i]->getPrix()==prix
           && ListeBiens[i]->getSurface()==surface && ListeBiens[i]->getVille()==ville)

        //On l'affiche avec ces caractéristiques sinon on passe au bien suivant de la liste : 
        ListeBiens[i]->afficher();
    }
}
