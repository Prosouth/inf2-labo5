//
//  Matrice.cpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

#include "Matrice.hpp"

template <typename T>
Matrice<T>::Matrice(){
    this->lignes = 0;
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes){
    this->lignes =lignes;
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes,unsigned int colonnes){
    this->lignes=lignes;
    this->colonnes=colonnes;
    
}

template <typename T>
T Matrice<T>::at(unsigned int position) const{
    return ;
}

template <typename T>
unsigned int Matrice<T>::size() const{
    return lignes;
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes){
    lignes =nbLignes;
}


template <typename T>
void Matrice<T>::resize(unsigned int nbLignes,unsigned int nbColonnes){
    this->lignes=nbLignes;
    this->colonnes=nbColonnes;
}

template <typename T>
bool Matrice<T>::estVide(){
    return lignes==0 && colonnes==0; // on regarde les lignes avant les collones au cas ou le constucteurs avec les lignes seulement et appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre(){
    return lignes==colonnes;
}

template <typename T>
bool Matrice<T>::estReguliere(){
    for (unsigned int l : lignes)
        if (lignes.size() == lignes[0]);
    retun true;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne(){


}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne();

template <typename T>

T Matrice<T>::sommeDiagonaleGD();
template <typename T>

T Matrice<T>::sommeDiagonaleDG();

template <typename T>
 std::ostream& operator << <>(std::ostream& os,const Matrice<T>& m);

template <typename T>

 const Matrice operator * <>(const Matrice<T>& m1,const Matrice<T>& m2);

template <typename T>
 const Matrice operator * <>(const Matrice<T>& m2,const T& val);// les deux sens a faire (commutativite)

template <typename T>
 const Matrice& operator + <>(Matrice<T>& m1,const Matrice<T>& m2);
