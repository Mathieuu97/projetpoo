//
//  Client.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Client.hpp"

int Client::nextIdCLient = 0;

Client::Client(){
    idClient=nextIdCLient++;
}

Client::Client(string _nom, string _adresse){
    idClient=nextIdCLient++;
    nom=_nom;
    adresse=_adresse;
}

Client::~Client(){
    
}
