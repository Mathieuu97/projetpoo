//
//  Agence.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Agence.hpp"
#include <iostream>
#include <fstream>
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
            
            /*On ajoute les information du Vendeur dans "Vendeur.txt"*/
            ofstream fichier("Vendeur.txt", ios::out | ios::app);
            if(fichier)
            {
                fichier << nom << " " << adr << " " << endl;
                fichier.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier !" << endl;
            
            
		}
    
		else if(client == "acheteur" || client == "a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
			//Acheteur a(nom,adr);
			//ListeAcheteur.push_back(&a);
			cout << "L'acheteur a bien ete ajoute"<<endl;
            
            /*On ajoute les information de l'Acheteur dans "Acheteur.txt"*/
            ofstream fichier("Acheteur.txt", ios::out | ios::app);
            if(fichier)
            {
                fichier << "Nom : " << nom << " Adresse : " << adr << endl;
                fichier.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier !" << endl;
		}
		else if(client == "v&a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
            ListeVendeur[nom]=new Vendeur(nom,adr);
				/*Acheteur a(nom,adr);
				ListeAcheteur.push_back(&a);
				Vendeur v(nom,adr);
				ListeVendeur.push_back(&v);*/
				cout << "Le client a bien ete ajoute dans les deux listes"<<endl;
            
            /*On ajoute les information du client Vendeur & Acheteur dans "Vendeur.txt" & "Acheteur.txt"*/
            ofstream fichierV("Vendeur.txt", ios::out | ios::app);
            if(fichierV)
            {
                fichierV << nom << " " << adr << endl;
                //fichierV.put('\n');
                fichierV.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier Vendeur.txt !" << endl;
			}
            ofstream fichierA("Acheteur.txt", ios::out | ios::app);
            if(fichierA)
            {
                fichierA << nom << " " << adr << endl;
                fichierA.close();
                
            }
    /*
            else 
                cerr << "Impossible d'ouvrir le fichier Acheteur.txt !" << endl;
			}*/
}

void Agence::ajouterBien(){
    string nom="";
    string adr="";
    string ville="";
    string type="";
    int prix;
    int nb_m2;
    int id_vendeur;
    
    do{
        cout << "Veuillez saisir votre nom: " << endl;
        cin >> nom;
    }while(!(this->VendeurExiste(nom)));
    
    cout << "Veuillez saisir l'adresse du bien:" << endl;
    cin >> adr;
    cout << "Adresse enregistrée : " << adr <<endl;
    
    cout << "Veuillez saisir la ville où se trouve le bien:" << endl;
    cin >> ville;
    cout << "Ville enregistrée : " << ville <<endl;
    
    
    cout << "Quel est le type du bien que vous souhaitez vendre ?" << endl;
    cout << "1. appartement" << endl;
    cout << "2. maison" << endl;
    cout << "3. terrain" << endl;
    cout << "4. local" << endl;
    
    cin >> type;
    
    
    switch (stoi(type))
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
    
    cout << "Type du bien enregistré : "<<type<<endl;
    
    cout<< "A quel prix souhaitez vous vendre ce bien ?"<<endl;
    cin>>prix;
    cout << "Prix enregistré : "<< prix << endl;
    
    cout << "Quelle est la surface de votre bien (en m2) ?" << endl;
    cin >> nb_m2;
    
    cout << "Surface enregistrée : "<< nb_m2<< endl;
    
    Bien bien_enregistre = Bien(prix, adr, ville, nb_m2, type);
    
    //getVendeur(nom).ajout_bien(&bien_enregistre);
    
    
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

bool Agence::VendeurExiste(string identifiant){
    return (ListeVendeur.find(identifiant)!=ListeVendeur.end());
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

Vendeur Agence::getVendeur(string identifiant){
    Vendeur tmp;
    map<string, Vendeur*>::iterator i;
    i=ListeVendeur.find(identifiant);
    if(i != ListeVendeur.end())
        tmp= *i->second;
    else
        cout << "Ce vendeur n'existe pas" << endl;
    return tmp;
    
}











