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
    vector<vector<int>> vectNotes ={{1,2,3},{4,5,6},{7,8,9}};
    Matrice<int> matrice(5,5);
    Matrice<int> matrice2(vectNotes);
    Vecteur<int> noteLaboratoire(10);
    //noteLaboratoire.
    //noteLaboratoire.somme();
    //matrice.push(0, 3);
    
    cout << "Hello, World!";
    cout <<matrice2 << endl;

    return EXIT_SUCCESS;
}
