//
//  main.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Agence.hpp"
#include "Bien.hpp"
#include "Client.hpp"
#include "Appartement.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    Agence UnToitPourTous;
    
    cout << "            " << " -------------------------------" << endl;
    cout << "            " << "|   Bienvenue sur l'interface   |" << endl;
    cout << "            " << "|  de gestion d'UnToitPourTous  |" << endl;
    cout << "            " << "|                               |" << endl;
    cout << "            " << "|   Tapez 'aide'pour afficher   |" << endl;
    cout << "            " << "|   les commandes disponibles   |" << endl;
    cout << "            " << " -------------------------------" << endl << endl << endl;
    
    
    do
    {
    
        cout << "Veuillez saisir une commande: " << endl;
    
        string commande="";
    
        cin >> commande;
        
    
        if(commande=="aide"){
            cout << endl << "commandes disponibles: "<< endl << endl;
            cout << "Creer un nouveau [client/bien/proposition]:        tapez 'nouveau'"<< endl;
            cout << "Rechercher un bien [appartement/maison/terrain/local] :        tapez 'rechercher'"<< endl;
            cout << "Quitter:        tapez 'q'" << endl << endl;
        }
    
        if(commande=="nouveau"){
            cout << "Que voulez vous creer ? [client/bien/proposition]" << endl;
            cin >> commande;
            if(commande=="client")
                UnToitPourTous.ajouterClient();
            if(commande=="bien")
                UnToitPourTous.ajouterBien();
        }
        
        if(commande=="q"){
            UnToitPourTous.quitterAgence();
        }
        
    } while (!UnToitPourTous.termine);
}
