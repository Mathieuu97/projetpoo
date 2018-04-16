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
    
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "               -------------------------------" << endl;
    cout << "              |   Bienvenue sur l'interface   |" << endl;
    cout << "              |  de gestion d'UnToitPourTous  |" << endl;
    cout << "              |                               |" << endl;
    cout << "              |   Tapez 'aide'pour afficher   |" << endl;
    cout << "              |   les commandes disponibles   |" << endl;
    cout << "               -------------------------------" << endl;
    cout << endl << endl << endl << endl << endl << endl << endl;
    
    
    do
    {
    
        cout << "Veuillez saisir une commande: " << endl;
    
        string commande="";
    
        cin >> commande;
        
        if(commande!="aide"&&commande!="nouveau"&&commande!="q")
            cout << endl << "Cette commande n'est pas valide" << endl;
    
        if(commande=="aide"){
            UnToitPourTous.quitterAgenceSiDemande(commande);
            cout << endl << "commandes disponibles: "<< endl << endl;
            cout << "Creer un nouveau [client/bien/proposition]:        tapez 'nouveau'"<< endl;
            cout << "Rechercher un bien [appartement/maison/terrain/local] :        tapez 'recherche'"<< endl;
            cout << "Quitter:        tapez 'q'" << endl << endl;
        }
    
        if(commande=="nouveau"){
            cout << "Que voulez vous creer ? [client/bien/proposition]" << endl;
            cin >> commande;
            UnToitPourTous.quitterAgenceSiDemande(commande);
            if(commande=="client")
                UnToitPourTous.ajouterClient();
            if(commande=="bien")
                UnToitPourTous.ajouterBien();
            if(commande=="proposition")
                UnToitPourTous.nouvellePropositionAchat();
        }
        
        if(commande=="recherche"){
            UnToitPourTous.quitterAgenceSiDemande(commande);
            cout << "Quel type de recherche souhaitez vous effectuer ?" << endl;
            cout << "1. Recherche simple" << endl;
            cout << "2. Recherche avancee" << endl << endl;
            cin >> commande;
            UnToitPourTous.quitterAgenceSiDemande(commande);
            switch (stoi(commande))
            {
                case 1:
                    UnToitPourTous.rechercheSimple();
                    break;
                case 2:
                    UnToitPourTous.demandeRechercheAvancee();
                    break;
                default:
                    cout << "Option non disponible" << endl;
                    break;
            }
        }
        
        UnToitPourTous.quitterAgenceSiDemande(commande);
        
    } while (!UnToitPourTous.termine);
}
