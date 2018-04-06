//
//  Client.hpp
//  classes
//
//  Created by Edwin Lebreton on 06/04/2018.
//  Copyright © 2018 Edwin Lebreton. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Client {
protected:
    int id;
    string nom;
    string adresse;
protected:
    Client(int, string, string);
    ~Client();
    
};

#endif /* Client_hpp */
