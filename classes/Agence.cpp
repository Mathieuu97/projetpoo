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
            ListeVendeur[nom]=new Vendeur(nom,adr);
			//Vendeur v(nom,adr);
			//ListeVendeur.push_back(&v);
			cout << "Le vendeur a bien ete ajoute"<<endl;
			 /*for(int i=0;i<ListeVendeur.size();i++){
			        cout << ListeVendeur[i]->getnom()<< endl;
			    }*/
		}
		else if(client == "acheteur" || client == "a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
			//Acheteur a(nom,adr);
			//ListeAcheteur.push_back(&a);
			cout << "L'acheteur a bien ete ajoute"<<endl;
		}
		else if(client == "v&a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
            ListeVendeur[nom]=new Vendeur(nom,adr);
				/*Acheteur a(nom,adr);
				ListeAcheteur.push_back(&a);
				Vendeur v(nom,adr);
				ListeVendeur.push_back(&v);*/
				cout << "Le client a bien ete ajoute dans les deux listes"<<endl;
			}

}

void Agence::ajouterBien(){
    
}

void Agence::nouvellePropositionAchat(){
    string str= "";
    string identifiant;
    int derniereVisite;
    do{
        cout << "Veuillez saisir votre nom: " << endl;
        cin >> str;
        identifiant=str;
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

void Agence::rechercheSimple(){
    map<string, Vendeur*>::iterator i;

    cout << "Voici l'ensemble des biens disponibles à l'achat: " << endl << endl;
    for(i = ListeVendeur.begin() ; i != ListeVendeur.end() ; ++i){
        i->second->afficherBiens();
    }

    /*for(int i=0;i<ListeVendeur.size();i++){
        ListeVendeur[i]->afficherBiens();
    }*/
}

void Agence::demandeRechercheAvancee(){
    
    string type;
    int prix_max;
    int surface;
    string ville;
    
    cout << "Veuillez saisir les informations complementaires a votre recherche: " << endl << endl;
    
    string str="";
    
    cout << "Quel type de bien recherchez vous ?" << endl;
    cout << "1. Appartement" << endl;
    cout << "2. Maison" << endl;
    cout << "3. Terrain" << endl;
    cout << "4. Local" << endl;
    
    cin >> str;
    
    
    switch (stoi(str))
    {
        case 1:
            type= "appartement";
            break;
        case 2:
            type= "maison";
            break;
        case 3:
            type= "terrain";
            break;
        case 4:
            type= "Local";
        default:
            cout << "Option non disponible" << endl;
    }
    
    cout << "Quel est le prix maximum du bien que vous recherchez ?" << endl;
    cin >> str;
    prix_max=stoi(str);
    
    cout << "Quel est la surface minimum du bien que vous recherchez ?" << endl;
    cin >> str;
    surface=stoi(str);
    
    cout << "Dans quelle ville se trouve le bien que vous recherchez ?" << endl;
    cin >> str;
    ville=str;
    
    this->rechercheAvancee(type, prix_max, surface, ville);
}

void Agence::rechercheAvancee(string _type, int _prix_max, int _surface, string _ville){
    map<string, Vendeur*>::iterator i;
    
    for(i = ListeVendeur.begin() ; i != ListeVendeur.end() ; ++i){
        i->second->afficherBiensCriteres(_type, _prix_max, _surface, _ville);
    }
    /*for(int i=0;i<ListeVendeur.size();i++){
        ListeVendeur[i]->afficherBiensCriteres(_type, _prix_max, _surface, _ville);
    }*/
}

void Agence::quitterAgenceSiDemande(string com){
    if(com=="q")
        termine=true;
}

bool Agence::acheteurExiste(string identifiant){
    return (ListeAcheteur.find(identifiant)!=ListeAcheteur.end());
    /*for(int i=0;i<ListeAcheteur.size();i++){
        if(ListeAcheteur[i]->getId()==identifiant)
            return true;
     return false;
    }*/
}

Acheteur Agence::getAcheteur(string identifiant){
    Acheteur tmp;
    map<string, Acheteur*>::iterator i;
    i=ListeAcheteur.find(identifiant);
    if(i != ListeAcheteur.end())
        tmp= *i->second;
    else
        cout << "Cet acheteur n'existe pas" << endl;
    return tmp;
    
    /*Acheteur tmp_null;
    for(int i=0;i<ListeAcheteur.size();i++){
        if(ListeAcheteur[id]->getId()==identifiant)
            tmp_null= *ListeAcheteur[i];
    }
    return tmp_null;*/
}









