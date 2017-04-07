//
//  Matrice.cpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//


#include "Matrice.hpp"
#include <exception>

/*template <typename T>
Matrice<T>::Matrice(){
    this->lignes = 0;
}
*/

using namespace std;

template <typename T>
Matrice<T>::Matrice (unsigned int lignes){
    
    vectLignes=Vecteur<T>(lignes);
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes,unsigned int colonnes){
    vectLignes=Vecteur<T>(lignes);
    vectColonnes=Vecteur<T>(colonnes);
}

template <typename T>
T Matrice<T>::at(unsigned int position) const{
    return vectLignes.at(position % vectLignes.size()).at(position / vectColonnes.size());
}

template <typename T>
unsigned int Matrice<T>::size() const{
    return vectLignes.size();
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes){
    vectLignes.resize(nbLignes);
}


template <typename T>
void Matrice<T>::resize(unsigned int nbLignes,unsigned int nbColonnes){
    vectLignes.resize(nbLignes);
    vectColonnes.resize(nbColonnes);
}

template <typename T>
bool Matrice<T>::estVide() const {
    return vectLignes.size()==0 && vectColonnes.size()==0; // on regarde les lignes avant les collones au cas ou le constucteur avec les lignes seulement est appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre() const {
    return vectLignes.size()==vectColonnes.size();
}

template <typename T>
bool Matrice<T>::estReguliere() const{
    for (T& t : vectLignes){
        if (!(t.size() == vectLignes.at(0))){ // si une des lignes pas egale a la premiere alors pas reguliere
            return false;
        }
    }
    return true;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne(){
    Vecteur <T> tempVecteur = Vecteur<T>(vectLignes.size());
    for(int i =0 ;i < tempVecteur.size();i++){
        for(T& t : vectLignes.at(i)){
            tempVecteur.at(i) += t;
        }
    }
}

template <typename T>
Vecteur<T> Matrice<T>::sommeColonne(){
    Vecteur <T> tempVecteur = Vecteur<T>(vectLignes.size());
    for(int i =0 ;i < tempVecteur.size();i++){
        for(T& t : vectLignes.at(i)){
            tempVecteur.at(i) += t;
        }
    }
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    for(int i = 0; i< vectLignes.size();i++){
        if (i)
    }
    
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    
}

template <typename T>
std::ostream& operator << (std::ostream& os,const Matrice<T>& m){

}

template <typename T>
const Matrice<T> operator * (const Matrice<T>& m1,const Matrice<T>& m2){

}

template <typename T>
 const Matrice<T> operator * (const Matrice<T>& m2,const T& val);// les deux sens a faire (commutativite)

template <typename T>
 const Matrice<T>& operator + (Matrice<T>& m1,const Matrice<T>& m2);
