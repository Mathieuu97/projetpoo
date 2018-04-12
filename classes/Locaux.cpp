//  Locaux.cpp

#include "Locaux.hpp"

Locaux::Locaux(){

}

Locaux::Locaux(float _prix, string _adr, string ville, float _nb_m2, float _taille_vitrine, bool _piece_stock) : Bien(prix,adresse_bien, ville ,nb_m2){
   taille_vitrine =_taille_vitrine;
   piece_stockage = _piece_stock;
}

Locaux::~Locaux(){

}
