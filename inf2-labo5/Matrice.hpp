//
//  Matrice.hpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

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
Matrice<T>& operator * (Matrice <T>& m1, const Matrice<T>& m2);

template <typename T>
Matrice<T>& operator * (Matrice <T>& m1, const T& val);

template <typename T>
Matrice<T>& operator + (const Matrice<T>& m1, const Matrice<T>& m2);

template <typename T>
class Matrice {

public:
    Matrice() = default;
    Matrice (unsigned int lignes);
    Matrice (unsigned int lignes, unsigned int colonnes);
    Matrice (const std::vector<std::vector<T>>& newVector);
    
    const T& at(unsigned int position) const;
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
    friend Matrice<T>& operator * (const Matrice <T>& m1, const Matrice<T>& m2);
    friend Matrice<T>& operator * (const Matrice <T>& m1,const T& val);   // les deux sens a faire (commutativite)
    friend Matrice<T>& operator + (const Matrice<T>& m1,const Matrice<T>& m2);
    
private:
    std::vector<std::vector<T>> matrice;
};

#include "MatriceImpl.h"

#endif /* Matrice_hpp */
