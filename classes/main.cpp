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
    
    //Création de l'objet Agence :
    Agence UnToitPourTous;
    
    //Affichage du menu de l'application:
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
        //Demande ce que souhaite faire le client:
        cout << "Veuillez saisir une commande: " << endl;
    
        string commande="";
    
        //Récupération de la demande du client:
        cin >> commande;
        
        //Si la commande demander est différentes de celles proposées:
        if(commande!="aide"&&commande!="nouveau"&&commande!="q")
            
            //On affiche alors un message d'erreur:
            cout << endl << "Cette commande n'est pas valide" << endl;
    
        //Affichage de l'aide : Donne les commandes à entrer en fonction de ce que souhaite le client:
        if(commande=="aide"){
            UnToitPourTous.quitterAgenceSiDemande(commande);
            cout << endl << "commandes disponibles: "<< endl << endl;
            cout << "Creer un nouveau [client/bien/proposition]:        tapez 'nouveau'"<< endl;
            cout << "Rechercher un bien [appartement/maison/terrain/local] :        tapez 'recherche'"<< endl;
            cout << "Quitter:        tapez 'q'" << endl << endl;
        }
    
        //Si la commande entrée est "nouveau":
        if(commande=="nouveau"){
            //Demande au client ce qu'il souhaite ajouter de nouveau:
            cout << "Que voulez vous creer ? [client/bien/proposition]" << endl;
            
            //Récupération de son souhait:
            cin >> commande;
            UnToitPourTous.quitterAgenceSiDemande(commande);
         
        //Appel des différentes fonctionnalités en fonction de la commande entrée :
            //Ajout d'un nouveau client:
            if(commande=="client")
                UnToitPourTous.ajouterClient();
            
            //Ajout d'un nouveau bien:
            if(commande=="bien")
                UnToitPourTous.ajouterBien();
            
            //Ajout d'une nouvelle proposition d'achat:
            if(commande=="proposition")
                UnToitPourTous.nouvellePropositionAchat();
        }
        
        //Si la commande entrée est "recherche":
        if(commande=="recherche"){
            UnToitPourTous.quitterAgenceSiDemande(commande);
            
            //Deux types de recherche sont disponibles :
            cout << "Quel type de recherche souhaitez vous effectuer ?" << endl;
            
            //Recherche simple = affichage de tous les biens disponibles de l'agence : 
            cout << "1. Recherche simple" << endl;
            
            //Recherche avancée = affichage seulement des biens correspondant aux critères spécifiés par le client :
            cout << "2. Recherche avancee" << endl << endl;
            
            //Récupération du type de recherche souhaité par le client:
            cin >> commande;
            UnToitPourTous.quitterAgenceSiDemande(commande);
            
            //Selon le choix du client :
            switch (stoi(commande))
            {
                    //Appel de la fonction de recherche simple:
                case 1:
                    UnToitPourTous.rechercheSimple();
                    break;
                    
                    //Appel de la fonction de recherche avancée:
                case 2:
                    UnToitPourTous.demandeRechercheAvancee();
                    break;
                    
                    //Message d'erreur:
                default:
                    cout << "Option non disponible" << endl;
                    break;
            }
        }
        
        UnToitPourTous.quitterAgenceSiDemande(commande);
        
    } while (!UnToitPourTous.termine);
}
