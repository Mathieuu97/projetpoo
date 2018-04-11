//
//  Maison.cpp

#include "Maison.hpp"

Maison::Maison(){

}

Maison::Maison(float _prix, string _adr, float _nb_m2, int _nb_pieces, int _nb_etages, bool _garage, bool _jardin, bool _piscine) : Bien(prix,adresse_bien,nb_m2){
    nb_pieces=_nb_pieces;
    nb_etages = _nb_etages;
    garage=_garage;
    jardin=_jardin;
    piscine=_piscine;
}

Maison::~Maison(){

}
