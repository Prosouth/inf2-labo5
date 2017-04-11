/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : main.cpp
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 07/04/2017
 But                :
 Remarque(s)        : 
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
#include <iostream>
#include "Matrice.hpp"
#include "Vecteur.hpp"

using namespace std;

template <typename T>
void affichervector(const Vecteur<T>& vect){
    cout << "[";
    for( int i =0 ; i < vect.size() - 1;i++ ){
        cout << vect.at(i) << ", ";
    }
    cout << vect.at(vect.size() - 1) << "]" << endl;
}

int main() 
{
    
    //##############################################################
    // Tests pour les matrices
    
    
    // Matrice de notes
    vector<int> VectorNotes {1,2,3};
    vector<int> VectorNotes2 {4,5,6};
    vector<int> VectorNotes3 {7,8,9};
    
    Vecteur<int> vecteurNotes(VectorNotes);
    Vecteur<int> vecteurNotes2(VectorNotes2);
    Vecteur<int> vecteurNotes3(VectorNotes3);

    vector<Vecteur <int>> v {vecteurNotes};
    
    Vecteur<Vecteur<int>> VecteurNotesFinal {v};
    VecteurNotesFinal.add(vecteurNotes);
    VecteurNotesFinal.add(vecteurNotes3);


    // Matrice identite 4x4
    vector<int> vectorIdentite {1,0,0,0};
    vector<int> vectorIdentite2 {0,1,0,0};
    vector<int> vectorIdentite3 {0,0,1,0};
    vector<int> vectorIdentite4 {0,0,0,1};
    
    Vecteur<int> vecteurIdentite(vectorIdentite);
    Vecteur<int> vecteurIdentite2(vectorIdentite2);
    Vecteur<int> vecteurIdentite3(vectorIdentite3);
    Vecteur<int> vecteurIdentite4(vectorIdentite4);

    vector<Vecteur <int>> vIdentite {vecteurIdentite};
    
    Vecteur<Vecteur<int>> vecteurIdentiteFinal {vIdentite};
    VecteurNotesFinal.add(vecteurIdentite2);
    VecteurNotesFinal.add(vecteurIdentite3);
    VecteurNotesFinal.add(vecteurIdentite4);

    // Matrice aleatoire
    
    vector<int> vectorAl1 {1,2,3,4,5};
    vector<int> vectorAl2 {6,7,8,9,10};
    vector<int> vectorAl3 {10,9,8,7,6};
    vector<int> vectorAl4 {5,4,3,2,1};
    
    Vecteur<int> vecteurAl1(vectorAl1);
    Vecteur<int> vecteurAl2(vectorAl2);
    Vecteur<int> vecteurAl3(vectorAl3);
    Vecteur<int> vecteurAl4(vectorAl4);
    
    vector<Vecteur <int>> vAl {vecteurAl1};
    
    Vecteur<Vecteur<int>> vecteurAleatoireFinal {vAl};
    VecteurNotesFinal.add(vecteurAl2);
    VecteurNotesFinal.add(vecteurAl3);
    VecteurNotesFinal.add(vecteurAl4);
    
    
    Matrice<int> matrice2 (VecteurNotesFinal);
    Matrice<int> matriceIdentite (vecteurIdentiteFinal);
    Matrice<int> matriceAleatoire(vecteurAleatoireFinal);
    //Matrice<int> addMatrice= matriceIdentite + matriceIdentite;
    
    Vecteur<int> noteLaboratoire(10);
    
    cout << matrice2.at(0).at(0)  << endl;
    cout << matrice2.at(1) << endl;
    cout << matrice2.at(2) << endl;
    cout << matrice2.at(4) <<endl;
    cout << matrice2 << endl;
    
    cout << "La matrice identité est elle régulière ? :" << (matriceIdentite.estReguliere() ? "oui": "non") << endl;
    cout << "La matrice identité est elle vide ? :" << (matriceIdentite.estVide() ? "oui": "non") << endl;
    affichervector(matriceIdentite.sommeColonne());
    affichervector(matriceAleatoire.sommeLigne());
    
    //cout << matriceIdentite + matriceIdentite << endl;
    
    //cout << "La somme diagonale GD de la matrice identité est : " << matriceIdentite.sommeDiagonaleGD() << endl;
    //cout << "La somme diagonale DG de la matrice identité est :" << matriceIdentite.sommeDiagonaleDG() << endl;
    
    
    
    
    //##############################################################
    // Tests pour les vecteurs
    vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v2 = {2,23,45,3,2,4,56,77,3,3};
    vector<int> vide = {0,0,0,0,0,0,0,0,0,0};
    
    Vecteur<int> vect1(v1);
    Vecteur<int> vect2(v2);
    Vecteur<int> vect4(vide);
    
    cout << "Vect 1 :" << vect1 << endl;
    cout << "La somme de vect1 est de : ";
    cout << vect1.somme() << endl;
    cout << "Affichage vect1.at(2) : " << vect1.at(2) << endl;
    cout << "Multiplication de vecteurs :" << "vect1 * vect1 = " << (vect1 * vect1) << endl;
    
    cout << "Vect 2 :" << vect2 << endl;
    cout << "La somme de vect2 est de : ";
    cout << vect2.somme() << endl;
    
    cout << "vect1 * 2 = " << vect1 * 2 << endl;
    cout << "2 * vect1 = " << 2 * vect1 << endl;

    cout << "Vect 1 :" << vect1 << endl;

    cout << "Addition de vecteurs :" << vect1 + vect1 << endl;
    cout << "Sourstraction de vecteurs :" << vect1 - vect1 << endl;
    
    return EXIT_SUCCESS;
}
