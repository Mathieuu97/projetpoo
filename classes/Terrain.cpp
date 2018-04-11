//
//  Terrain.cpp


#include "Terrain.hpp"

Terrain::Terrain(){

}

Terrain::Terrain(float _prix, string _adr, float _nb_m2, bool _constructible) : Bien(prix,adresse_bien,nb_m2){
    constructible = _constructible;
}

Terrain::~Terrain(){

}
