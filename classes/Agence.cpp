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
    termine=false;
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
			cout << "Le vendeur a bien ete ajoute"<<endl;
			 /*for(int i=0;i<ListeVendeur.size();i++){
			        cout << ListeVendeur[i]->getnom()<< endl;
			    }*/
		}
		else if(client == "acheteur" || client == "a"){
			Acheteur a(nom,adr);
			ListeAcheteur.push_back(&a);
			cout << "L'acheteur a bien ete ajoute"<<endl;
		}
		else if(client == "v&a"){
				Acheteur a(nom,adr);
				ListeAcheteur.push_back(&a);
				Vendeur v(nom,adr);
				ListeVendeur.push_back(&v);
				cout << "Le client a bien ete ajoute dans les deux listes"<<endl;
			}

}

void Agence::ajouterBien(){
    
}

void Agence::nouvellePropositionAchat(){
    string str= "";
    int identifiant;
    int derniereVisite;
    do{
        cout << "Veuillez saisir votre identifiant client: " << endl;
        cin >> str;
        identifiant=stoi(str);
    }while(!(this->acheteurExiste(identifiant)));
    
    do{
        cout << "Veuillez saisir la reference du bien visite: " << endl;
        cin >> str;
        derniereVisite=stoi(str);
    }while(!(getAcheteur(identifiant).visiteExiste(derniereVisite)));
    
    cout << "Veuillez saisir le montant de la proposition: " << endl;
    cin >> str;
    int proposition=stoi(str);
    this->getAcheteur(identifiant).ajouterProposition(proposition,derniereVisite);
    
    cout << endl << "Proposition enregistree" << endl << endl;
    
}

void Agence::quitterAgence(){
    termine=true;
}

bool Agence::acheteurExiste(int identifiant){
    for(int i=0;i<ListeAcheteur.size();i++){
        if(ListeAcheteur[i]->getId()==identifiant)
            return true;
    }
    return false;
}

Acheteur Agence::getAcheteur(int identifiant){
    Acheteur tmp_null;
    for(int i=0;i<ListeAcheteur.size();i++){
        if(ListeAcheteur[i]->getId()==identifiant)
            tmp_null= *ListeAcheteur[i];
    }
    return tmp_null;
}








