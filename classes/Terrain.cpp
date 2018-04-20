//
//  Terrain.cpp


#include "Terrain.hpp"

Terrain::Terrain(){

}

Terrain::Terrain(int _prix, string _adr, string _ville, int _nb_m2, string typeDeBien, bool _constructible) : Bien(prix,adresse_bien, ville ,nb_m2, typeDeBien){
    constructible = _constructible;
}

Terrain::~Terrain(){

}
