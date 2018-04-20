//  Locaux.cpp

#include "Locaux.hpp"

Locaux::Locaux(){

}

Locaux::Locaux(int _prix, string _adr, string ville, int _nb_m2, string typeDeBien, float _taille_vitrine, bool _piece_stock) : Bien(prix,adresse_bien, ville ,nb_m2, typeDeBien){
   taille_vitrine =_taille_vitrine;
   piece_stockage = _piece_stock;
}

Locaux::~Locaux(){

}
