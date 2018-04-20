//
//  Visite.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Visite.hpp"


//CONSTRUCTEURS :
Visite::Visite()
{

}

Visite::Visite(int _id_visite, bool _proposition_achat, float _prix)
{
	id_visite = _id_visite;
	proposition_achat = _proposition_achat;
	prix = _prix;
}


//DESTRUCTEUR :
Visite::~Visite(){
    //dtor
}

//ACCESSEUR permettant d'acceder l'identifiant d'une visite (attribut privé) : 
int Visite::getId(){
    return id_visite;
}

//MUTATEUR permettant de modifier le prix ou attribuer un prix à une proposition d'achat : 
void Visite::setPrix(int nvxPrix){
    prix=nvxPrix;
}

//Ajout d'une proposition d'achat avec le prix proposé par le client acheteur : 
void Visite::ajouterProposition(int proposition){
    
    //Passage du booléen à vrai permettant de savoir qu'une proposition d'achat à été faite suite à la visite:
    proposition_achat=true;
    
    //Affectation du prix proposé par l'acheteur dans l'attribut "prix":
    prix=proposition;
}
