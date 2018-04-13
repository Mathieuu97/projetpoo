//
//  Maison.cpp

#include "Maison.hpp"

Maison::Maison(){

}

Maison::Maison(int _prix, string _adr, string _ville, int _nb_m2, string typeDeBien, int _nb_pieces, int _nb_etages, bool _garage, bool _jardin, bool _piscine) : Bien(prix,adresse_bien, ville, nb_m2, typeDeBien){
    nb_pieces=_nb_pieces;
    nb_etages = _nb_etages;
    garage=_garage;
    jardin=_jardin;
    piscine=_piscine;
}

Maison::~Maison(){

}
