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


//CONSTRUCTEUR:
Agence::Agence(){
    nom="UnToitPourTous";
    termine=false;
}


//DESTRUCTEUR:
Agence::~Agence(){

}

// Ajout d'un nouveau client vendeur ou acheteur : 
void Agence::ajouterClient(){
	    string nom = "";
		string adr = "";
        string client = "";

        // On demande à l'utlisateur les différentes informations nécéssaires à son enregistrement (nom, adresse et si il est vendeur ou acheteur ou les deux) via le "cout":
        // Récupération des informations via le "cin":
			cout << "Nom : "<< endl;
			cin >> nom;
			cout << nom<< endl;

			cout<< "Adresse du client : "<<endl;
			cin >> adr;
			cout<< adr <<endl;
		      
			cout << "vendeur ou acheteur ou v&a ? [v/a/v&a]: "<< endl;
			cin >> client;

        //Si le client est un vendeur : on l'ajoute à la liste des clients vendeurs : 
		if (client == "vendeur" || client == "v"){
            ListeVendeur[nom]=new Vendeur(nom,adr);
			cout << "Le vendeur a bien ete ajoute"<<endl;
    
        //On ajoute les information du Vendeur dans "Vendeur.txt" :
            ofstream fichier("Vendeur.txt", ios::out | ios::app);
            if(fichier)
            {
                fichier << nom << "/" << adr << " " << endl;
                fichier.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier !" << endl;            
		}
        
        //Si le client est un acheteur : on l'ajoute à la liste des clients acheteurs :
		else if(client == "acheteur" || client == "a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
			cout << "L'acheteur a bien ete ajoute"<<endl;
            
        /*On ajoute les information de l'Acheteur dans "Acheteur.txt" : */
            ofstream fichier("Acheteur.txt", ios::out | ios::app);
            if(fichier)
            {
                fichier << nom << "/" << adr << " " << endl;
                fichier.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier !" << endl;
		}

        //Si le client est à la fois un vendeur et un acheteur, on l'ajoute dans les deux listes : 
		else if(client == "v&a"){
            ListeAcheteur[nom]=new Acheteur(nom,adr);
            ListeVendeur[nom]=new Vendeur(nom,adr);
			cout << "Le client a bien ete ajoute dans les deux listes"<<endl;
            
            /*On ajoute les information du client Vendeur & Acheteur dans "Vendeur.txt" & "Acheteur.txt"*/
            ofstream fichierV("Vendeur.txt", ios::out | ios::app);
            if(fichierV)
            {
                fichierV << nom << "/" << adr << " " << endl;
                fichierV.close();
            }
            else 
                cerr << "Impossible d'ouvrir le fichier Vendeur.txt !" << endl;
		}
            ofstream fichierA("Acheteur.txt", ios::out | ios::app);
            if(fichierA)
            {
                fichierA << nom << "/" << adr << " " << endl;
                fichierA.close();
                
            }

}

//Ajout d'un nouveau bien à vendre dans la liste des biens du vendeur concerné : 
void Agence::ajouterBien(){
    string nom="";
    string adr="";
    string ville="";
    string type="";
    int prix;
    int nb_m2;
    int id_vendeur;

    //Demande du nom du vendeur du nouveau bien tant que l'on ne le trouve pas dans la liste des vendeurs (nécéssaire en cas d'erreur de frappe):
    do{
        cout << "Veuillez saisir le nom du propriétaire : " << endl;
        cin >> nom;

    }while(!(this->VendeurExiste(nom)));
    
    //Demande et récupération des informations nécéssaires à l'enregistrement du bien :
    cout << "Veuillez saisir l'adresse du bien :" << endl;
    cin >> adr;
    cout << "Adresse enregistrée : " << adr <<endl;
    
    cout << "Veuillez saisir la ville où se trouve le bien :" << endl;
    cin >> ville;
    cout << "Ville enregistrée : " << ville <<endl;
    
    
    cout << "Quel est le type du bien que vous souhaitez vendre ?" << endl;
    cout << "1. appartement" << endl;
    cout << "2. maison" << endl;
    cout << "3. terrain" << endl;
    cout << "4. local" << endl;
    
    cin >> type;
    
    //SWITCH = Sécurisation du type de bien : il doit faire partie de ceux proposés : 
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

    //Création d'un nouveau bien avec les caractéristiques données par le client : 
    cout << "Bien enregistré" << endl;
    Bien bien_enregistre = Bien(prix, adr, ville, nb_m2, type);

    /*On ajoute les information de l'Acheteur dans "Acheteur.txt"*/
    ofstream fichier("Bien.txt", ios::out | ios::app);
    if(fichier)
    {
        fichier << type << "/" << nom << "/" << adr << "/" << ville << "/" << prix << "/" << nb_m2 << " " << endl;
        fichier.close();
    }
    else 
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    
    //Ajout du nouveau bien créé dans la liste des biens du vendeur concerné :
    getVendeur(nom).ajout_bien(&bien_enregistre);
    
    
}


//Ajout d'une proposition d'achat d'un client acheteur : 
void Agence::nouvellePropositionAchat(){

    string str= "";
    string identifiant;
    int derniereVisite;

    //Demande du nom de l'acheteur tant que l'on ne le trouve pas dans la liste des acheteurs (nécéssaire en cas d'erreur de frappe):
    do{
        cout << "Veuillez saisir votre nom: " << endl;
        cin >> str;
        identifiant=str;
    }while(!(this->acheteurExiste(identifiant)));
    

    //Demande de la référence de la visite du bien tant que l'on ne le trouve pas dans la liste des visites faites par cet acheteur :
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

//Présentation de tout les biens disponibles dans l'agence :
void Agence::rechercheSimple(){

    cout << "Voici l'ensemble des biens disponibles à l'achat: " << endl << endl;

    //Parcours de toutes les listes de biens de tout les vendeurs enregistrés dans l'agence : 
    for(map<string, Vendeur*>::iterator i = ListeVendeur.begin() ; i != ListeVendeur.end() ; ++i){

        //Affichage des caractéristiques de chacuns de ces biens :
        i->second->afficherBiens();
    }
    recherche_bien_fichier();
}


//Recherche de biens selon certains critères souhaités par le client :
void Agence::demandeRechercheAvancee(){
    
    string type;
    int prix_max;
    int surface;
    string ville;
    
    //Demande et récupération des critères exigés par le client : 
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


//Fonction permettant de rechercher un bien spécifique selon certaines exigences demandées par le client :
void Agence::rechercheAvancee(string _type, int _prix_max, int _surface, string _ville){
    map<string, Vendeur*>::iterator i;
    
    //Parcours de toutes les listes de biens de chaque vendeur de la liste vendeurs : 
    for(i = ListeVendeur.begin() ; i != ListeVendeur.end() ; ++i){

        //Affichage des biens et leurs caractéristiques seulement si ils répondent au critères entrés en paramètres :
        i->second->afficherBiensCriteres(_type, _prix_max, _surface, _ville);
    }
}


//Fonction permettant de quitter l'application : 
void Agence::quitterAgenceSiDemande(string com){
    if(com=="q")
        termine=true;
}

//Recherche si un acheteur se trouve dans la liste des acheteurs selon son nom rentré en paramètre de la fonction : Renvoie un booléen 
bool Agence::acheteurExiste(string identifiant){
    return (ListeAcheteur.find(identifiant)!=ListeAcheteur.end());
}

//Recherche si un vendeur se trouve dans la liste des vendeurs selon son nom rentré en paramètre de la fonction : Renvoie un booléen 
bool Agence::VendeurExiste(string identifiant){
    return (ListeVendeur.find(identifiant)!=ListeVendeur.end());
}


//Renvoie d'un objet ACHETEUR selon son identifiant entré en paramètre : 
Acheteur Agence::getAcheteur(string identifiant){
    Acheteur tmp;
    map<string, Acheteur*>::iterator i;

    //Parcours de la liste des acheteurs jusqu'à trouver celui ayant l'id renseigné en paramètre de la fonction :
    i=ListeAcheteur.find(identifiant);
    if(i != ListeAcheteur.end())
        tmp= *i->second;

    //Message en cas d'erreur :
    else
        cout << "Cet acheteur n'existe pas" << endl;
    return tmp;
}

//Renvoie d'un objet VENDEUR selon son identifiant entré en paramètre :
Vendeur Agence::getVendeur(string identifiant){
    Vendeur tmp;
    map<string, Vendeur*>::iterator i;

     //Parcours de la liste des vendeurs jusqu'à trouver celui ayant l'id renseigné en paramètre de la fonction :
    i=ListeVendeur.find(identifiant);
    if(i != ListeVendeur.end())
        tmp= *i->second;
    else
        cout << "Ce vendeur n'existe pas" << endl;
    return tmp;
    
}


void Agence::recherche_bien_fichier() {
    
// le constructeur de ifstream permet d'ouvrir un fichier en lecture 
    ifstream fichier( "Bien.txt" ); 
  
    if ( fichier ) // ce test échoue si le fichier n'est pas ouvert 
    { 
        string ligne; // variable contenant chaque ligne lue 
  
        // cette boucle s'arrête dès qu'une erreur de lecture survient 
        while ( getline( fichier, ligne ) ) 
        { 
            // afficher la ligne à l'écran 
            cout << ligne << "m2" << endl;
        }
    }
}










