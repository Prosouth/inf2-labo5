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
    VecteurNotesFinal.add(vecteurNotes2);
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
    vecteurIdentiteFinal.add(vecteurIdentite2);
    vecteurIdentiteFinal.add(vecteurIdentite3);
    vecteurIdentiteFinal.add(vecteurIdentite4);

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
    vecteurAleatoireFinal.add(vecteurAl2);
    vecteurAleatoireFinal.add(vecteurAl3);
    vecteurAleatoireFinal.add(vecteurAl4);
    
    
    Matrice<int> matrice (VecteurNotesFinal);
    Matrice<int> matriceIdentite (vecteurIdentiteFinal);
    Matrice<int> matriceAleatoire(vecteurAleatoireFinal);
    //Matrice<int> addMatrice = matriceIdentite + matriceIdentite;
    Matrice<int> multMatrice = 2 * matrice;
    //Matrice<int> multMatrice2 = matrice * matrice;

    Vecteur<int> noteLaboratoire(10);
    cout << matrice.at(0).at(0)  << endl;
    
    cout << "La matrice n°1 est :" << endl;
    cout << matrice << endl;

    cout << "La matrice identité est elle régulière ? :"
         << (matriceIdentite.estReguliere() ? "oui": "non") << endl;
    cout << "La matrice identité est elle vide ? :"
         << (matriceIdentite.estVide() ? "oui": "non") << endl;
    cout << "La matrice identité est elle carre ? :"
         << (matriceIdentite.estCarre() ? "oui": "non") << endl;

    cout << "La somme de la colonne de la matrice identite 4x4 est : " << endl ;
    affichervector(matriceIdentite.sommeColonne());
    
    cout << "La somme de la ligne de la matrice identite 4x4 est : " << endl ;
    affichervector(matriceAleatoire.sommeLigne());
    
    //cout << "Addition de matrices : " << matriceIdentite + matriceIdentite << endl;
    cout << "Multiplication de matrice n°1 par un scalaire: \n" << multMatrice << endl;
    //cout << "Multiplication de matrice n°1 par elle meme : \n" << multMatrice2 << endl;

    cout << "La somme diagonale GD de la matrice identité 4x4 est : " << matriceIdentite.sommeDiagonaleGD() << endl;
    cout << "La somme diagonale DG de la matrice identité 4x4 est : " << matriceIdentite.sommeDiagonaleDG() << endl;
    
    
    cout << endl << endl;
    
    cout << "Nous testons ici les potentielles exceptions que l'on pourrait avoir avec une matrice mal instanciee :" << endl;
    
    
    
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
    //vect1.resize(-1);
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
