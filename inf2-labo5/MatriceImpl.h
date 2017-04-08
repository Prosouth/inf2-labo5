//
//  MatriceImpl.h
//  inf2-labo5
//
//  Created by Walid Koubaa on 07.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

#ifndef MatriceImpl_h
#define MatriceImpl_h

#include "Matrice.hpp"
#include <exception>
#include <vector>

using namespace std;

template <typename T>
Matrice<T>::Matrice (unsigned int lignes){
    matrice = vector<vector<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes,unsigned int colonnes){
    matrice=vector<vector<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (const vector<vector<T>>& newVector){
    matrice = newVector;
}

template <typename T>
const T& Matrice<T>::at(unsigned int position) const{
    return matrice.at(position / matrice.size()).at(position % matrice.size());
}

template <typename T>
unsigned int Matrice<T>::size() const{
    unsigned int size = 0;
    for(const vector<T>& vect: matrice){
        size+= vect.size();
    }
    return (unsigned int) size;
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes){
    matrice.resize(nbLignes);
}


template <typename T>
void Matrice<T>::resize(unsigned int nbLignes,unsigned int nbColonnes){
    matrice.resize(nbLignes);
    for(vector<T>& vect : matrice)
        vect.resize(nbColonnes);
}

template <typename T>
bool Matrice<T>::estVide() const {
    return matrice.size()==0; //&& vectColonnes.size()==0; // on regarde les lignes avant les collones au cas ou le constucteur avec les lignes seulement est appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre() const {
    return matrice.size();//==vectColonnes.size();
}

template <typename T>
bool Matrice<T>::estReguliere() const{
    for (const vector<T>& t : matrice){
        if (t.size() != matrice.at(0).size()){ // si la taille d'une des lignes n'est pas egale a la premiere alors la matrice n'est pas reguliere
            return false;
        }
    }
    return true;
}
/*
template <typename T>
void Matrice<T>::push(unsigned int position,const T& valeur){
    matrice.at(position)=valeur;
}
*/
template <typename T>
void Matrice<T>::pop( unsigned int position,const T& valeur){
     matrice.at(position) = 0;
   
}
/*
template <typename T>
void Matrice<T>::affect(const std::vector<vector<T>>& newVector){
    matrice = newVector;
}
*/

template <typename T>
vector<T> Matrice<T>::sommeLigne(){
    vector<T> tempMatrice(matrice.size());
    for(int i =0 ;i < tempMatrice.size();i++){
        for(T& t : matrice.at(i)){
            tempMatrice.at(i) += t;
        }
    }
    return tempMatrice;
}

template <typename T>
vector<T> Matrice<T>::sommeColonne(){
    vector<T> tempMatrice(matrice.size());
    for(int i =0 ;i < tempMatrice.size();i++){
        for(T& t : matrice.at(i)){
            tempMatrice.at(i) += t;
        }
    }
    return tempMatrice;
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i< matrice.size();i++){
        for(int j =0 ; j <matrice.at(i).size(); j++){
            if(i==j){
            sommeDiagonale+= matrice.at(i).at(j);
            }
        }
    }
    return sommeDiagonale;
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG(){
    if(!estReguliere()){
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i< matrice.size();i++){
        for(int j =0 ; j <matrice.at(i).size(); j++){
            if(i==(matrice.at(i).size() - j)){
                sommeDiagonale+= matrice.at(i).at(j);
            }        }
    }
    return sommeDiagonale;
}

template <typename T>
std::ostream& operator << (std::ostream& os,const Matrice<T>& m){
    os << "[";
    for( int i =0 ; i < m.size() - 1;i++ ){
        os << m.at(i) << ", ";
    }
    os << m.at(m.size() - 1) << "]";
    return os;
}

template <typename T>
Matrice<T>& operator * (Matrice <T>& m1, const Matrice<T>& m2){
    for(int i = 0; i< m2.size();i++){
        for(int j =0 ; j <m2.size(); j++){
            m1.at(i).at(j) *= m2.at(i).at(j);
        }
    }
    return m1;
}

template <typename T>
Matrice<T>&  operator * (Matrice <T>& m1,const T& val){// les deux sens a faire (commutativite)
    for(int i =0; i< m1.size(); i++){
        m1.at(i) *= val;
    }
    return m1;
}
template <typename T>
Matrice<T>&  operator + (const Matrice<T>& m1,const Matrice<T>& m2){
    for(int i = 0; i< m1.size();i++){
        m1.at(i)+=m2.at(i);
    }
    return m1;
}

#endif /* MatriceImpl_h */
