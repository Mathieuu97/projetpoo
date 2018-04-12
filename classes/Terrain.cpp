//
//  Terrain.cpp


#include "Terrain.hpp"

Terrain::Terrain(){

}

Terrain::Terrain(float _prix, string _adr, string _ville, float _nb_m2, bool _constructible) : Bien(prix,adresse_bien, ville ,nb_m2){
    constructible = _constructible;
}

Terrain::~Terrain(){

}
