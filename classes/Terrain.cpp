//
//  Terrain.cpp


#include "Terrain.hpp"

//CONSTRUCTEURS:
Terrain::Terrain(){

}

Terrain::Terrain(int _prix, string _adr, string _ville, int _nb_m2, string typeDeBien, bool _constructible) : Bien(prix,adresse_bien, ville ,nb_m2, typeDeBien){
    constructible = _constructible;
}

//DESTRUCTEUR:
Terrain::~Terrain(){

}
