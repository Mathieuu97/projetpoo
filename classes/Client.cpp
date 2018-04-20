//
//  Client.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Client.hpp"

//Attribut permettant d'incrementer l'identifiant de chaque nouveau client pour ne pas avoir un même identifiant pour deux clients différents : 
int Client::nextIdCLient = 0;

//CONSTRUCTEURS:
Client::Client(){
    //Affectation de l'identifiant du client avec incrémentation:
    idClient=nextIdCLient++;
}

Client::Client(string _nom, string _adresse){
    idClient=nextIdCLient++;
    nom=_nom;
    adresse=_adresse;
}

//DESTRUCTEUR:
Client::~Client(){
    
}

//ACCESSEUR permettant d'acceder à l'identifiant d'un client (attribut privé):
int Client::getId(){
    return idClient;
}
