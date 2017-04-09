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

template <typename T>
void affichervector(const vector<T>& vect){
    cout << "[";
    for( int i =0 ; i < vect.size() - 1;i++ ){
        cout << vect.at(i) << ", ";
    }
    cout << vect.at(vect.size() - 1) << "]" << endl;
}

int main() 
{
    vector<vector<int>> vectNotes = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> vectIdentite = {{1,0,0,0},
                                       {0,1,0,0},
                                       {0,0,1,0},
                                       {0,0,0,1}};
    vector<vector<int>> vectAleatoire ={{1,2,3,4,5},
                                        {6,7,8,9,10},
                                        {10,9,8,7,6},
                                        {5,4,3,2,1} };
    Matrice<int> matrice(5,5);
    Matrice<int> matrice2(vectNotes);
    Matrice<int> matriceIdentite(vectIdentite);
    Matrice<int> matriceAleatoire(vectAleatoire);
    //Matrice<int> addMatrice= matriceIdentite + matriceIdentite;
    
    Vecteur<int> noteLaboratoire(10);
    //noteLaboratoire.
    //noteLaboratoire.somme();
    //matrice.push(0, 3);
    
    cout << matrice2.at(3) << endl;
    cout << matrice2.at(4) << endl;
    cout << matrice2.at(5) << endl;
    cout << matrice2.at(6) << endl;
    cout << matrice2.at(7) << endl;
    cout << matrice2.at(0) << endl;
    
    cout << matrice2 << endl;
    
    cout << "La matrice identité est elle régulière ? :" << (matriceIdentite.estReguliere() ? "oui": "non") << endl;
    cout << "La matrice identité est elle vide ? :" << (matriceIdentite.estVide() ? "oui": "non") << endl;
    affichervector(matriceIdentite.sommeColonne());
    affichervector(matriceAleatoire.sommeLigne());
    
    //cout << addMatrice << endl;
    
    cout << matriceIdentite.sommeDiagonaleGD() << endl;
    cout << matriceIdentite.sommeDiagonaleDG() << endl;
    
    
    
    
    //##############################################################3
    // Tests pour les vecteurs
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {2,23,45,3,2,4,56,77,3,3};
    vector<int> vide = {0,0,0,0,0,0,0,0,0,0};
    
    Vecteur<int> vect1(v1);
    Vecteur<int> vect2(v2);
    cout << vect1 << endl;
    cout << "La somme de vect1 est de : ";
    cout << vect1.somme() << endl;
    cout << "Affichage vect1.at(2) : " << vect1.at(2) << endl;
    
    cout << vect2 << endl;
    cout << "La somme de vect2 est de : ";
    cout << vect2.somme() << endl;
    
    cout << "2 * vect1 = " << (2 * vect1) << endl;
   // cout << "vect1 * vect2 = " << (vect1 * vect2) << endl;
    Vecteur<int> vect3(vide);
    //cout << vect1 + vect2;
    //cout << vect2 - vect1 << endl;
    
    cout << "v1 + v2 = " << vect3 << endl;
    
    return EXIT_SUCCESS;
}
