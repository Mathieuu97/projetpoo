//
//  Agence.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Agence.hpp"
#include <iostream>
using namespace std;

Agence::Agence(){
    nom="UnToitPourTous";
}


Agence::~Agence(){
    
}

void Agence::ajouterClient(){
	string nom = "";
		string adr = "";
			cout << "Nom : "<< endl;
			cin >> nom;
			cout << nom<< endl;
			cout<< "Adresse du client : "<<endl;
			cin >> adr;
			cout<< adr <<endl;
		string client = "";
			cout << "vendeur ou acheteur ou v&a ? [v/a/v&a]: "<< endl;
			cin >> client;
		if (client == "vendeur" || client == "v"){
			Vendeur v(nom,adr);
			ListeVendeur.push_back(&v);
			cout << "Le vendeur a bien �t� ajout�"<<endl;
			 /*for(int i=0;i<ListeVendeur.size();i++){
			        cout << ListeVendeur[i]->getnom()<< endl;
			    }*/
		}
		else if(client == "acheteur" || client == "a"){
			Acheteur a(nom,adr);
			ListeAcheteur.push_back(&a);
			cout << "L'acheteur a bien �t� ajout�"<<endl;
		}
		else if(client == "v&a"){
				Acheteur a(nom,adr);
				ListeAcheteur.push_back(&a);
				Vendeur v(nom,adr);
				ListeVendeur.push_back(&v);
				cout << "Le client a bien �t� ajout� dans les deux listes"<<endl;
			}

}

void Agence::ajouterBien(){
    
}

void Agence::nouvellePropositionAchat(){
    
}
