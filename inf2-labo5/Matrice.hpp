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
    Vecteur<T> sommeLigne();
    Vecteur<T> sommeLigne();
    T sommeDiagonaleGD();
    T sommeDiagonaleDG();
    
    friend std::ostream& operator << (std::ostream& os,const Matrice& m);
    friend const Matrice operator * (const Matrice& m1,const Matrice& m2);
    friend const Matrice operator * (const Matrice& m2,const T& val);// les deux sens a faire (commutativite)
    friend const Matrice& operator + (Matrice& m1,const Matrice& m2);
    
private:
    unsigned int lignes, colonnes;
    Vecteur <T> vectLignes,vectColonnes;
};


#endif /* Matrice_hpp */
