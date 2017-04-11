/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : Matrice.hpp
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 07/04/2017
 But                :
 Remarque(s)        : 
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
#ifndef Matrice_hpp
#define Matrice_hpp

#include <iostream>
#include <vector>
#include "Vecteur.hpp"

template <typename T>
class Matrice;

template <typename T>
std::ostream& operator << (std::ostream& os, const Matrice<T>& m);

template <typename T>
Matrice<T> operator * (const Matrice <T>& m);

template <typename T>
Matrice<T> operator * (const T& val);

template <typename T>
Matrice<T>& operator + (const Matrice<T>& m);

template <typename T>
class Matrice {

public:
    Matrice() = default;
    Matrice (unsigned int lignes);
    Matrice (unsigned int lignes, unsigned int colonnes);
    Matrice (const std::vector<std::vector<T>>& newVector);
    
    const T& at(unsigned int position) const;
    T& at(unsigned int position);
    unsigned int size() const;
    void resize(unsigned int nbLignes);
    void resize(unsigned int nbLignes, unsigned int nbColonnes);
    bool estVide() const;
    bool estCarre() const;
    bool estReguliere() const;
    
    //void push(unsigned int position,const T& valeur);
    void pop(unsigned int position,const T& valeur);
    std::vector<T> sommeLigne();
    std::vector<T> sommeColonne();
    T sommeDiagonaleGD();
    T sommeDiagonaleDG();
    
    friend std::ostream& operator << <> (std::ostream& os,const Matrice<T>& m);
    Matrice<T>& operator * ( const Matrice<T>& m);
    Matrice<T>& operator * (const T& val);   // les deux sens a faire (commutativite)
    Matrice<T>& operator +(const Matrice<T>& m);
    
private:
    std::vector<std::vector<T>> matrice;
};

#include "MatriceImpl.h"

#endif /* Matrice_hpp */
