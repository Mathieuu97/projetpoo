//
//  Visite.cpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#include "Visite.hpp"

Visite::Visite()
{

}

Visite::Visite(int _id_visite, bool _proposition_achat, float _prix)
{
	id_visite = _id_visite;
	proposition_achat = _proposition_achat;
	prix = _prix;
}
