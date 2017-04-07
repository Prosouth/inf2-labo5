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
class Matrice {

public:
    Matrice() = default;
    Matrice (unsigned int lignes);
    Matrice (unsigned int lignes,unsigned int colonnes);
    
    T at(unsigned int position) const;
    unsigned int size() const;
    void resize(unsigned int nbLignes);
    void resize(unsigned int nbLignes,unsigned int nbColonnes);
    bool estVide() const;
    bool estCarre() const;
    bool estReguliere() const;
    
    void push(unsigned int position,const T& valeur);
    void pop( unsigned int position,const T& valeur);
    Vecteur<T> sommeLigne();
    Vecteur<T> sommeColonne();
    T sommeDiagonaleGD();
    T sommeDiagonaleDG();
    
    friend std::ostream& operator << (std::ostream& os,const Matrice& m);
    friend Matrice<T>& operator * (Matrice <T>& m1, const Matrice<T>& m2);
    friend Matrice<T>& operator * (Matrice <T>& m1,const T& val);   // les deux sens a faire (commutativite)
    friend Matrice<T>& operator + (Matrice& m1,const Matrice& m2);
    
private:
    std::vector<std::vector<T>> matrice;
};


#endif /* Matrice_hpp */
