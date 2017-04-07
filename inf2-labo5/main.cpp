//
//  main.cpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//
#include <iostream>
#include "Matrice.hpp"
#include "Vecteur.hpp"

using namespace std;

int main() 
{
    
    Matrice<int> matrice(5,5);
    Matrice<double> matrice2(4,4);
    Vecteur<int> noteLaboratoire(10);
    //noteLaboratoire.
    //noteLaboratoire.somme();
   cout << "Hello, World!";
    cout <<matrice2 << endl;

    return EXIT_SUCCESS;
}
