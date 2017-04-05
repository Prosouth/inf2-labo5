//
//  Vecteur.hpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

#ifndef Vecteur_hpp
#define Vecteur_hpp

#include <cstdlib>
#include <vector>
#include <iostream>

template<typename T>
class Vecteur
{
public:
    // Constructeurs par défaut
    Vecteur(const size_t& n);
    Vecteur(const std::vector<T>& vect);
    
    // Surcharge d'opérateurs
    friend std::ostream& operator << (std::ostream& os, const Vecteur<T>& vect);
    friend const Vecteur<T> operator + (const Vecteur<T>& v1, const Vecteur<T>& v2);
    friend const Vecteur<T> operator - (const Vecteur<T>& v1, const Vecteur<T>& v2);
    friend const Vecteur<T> operator * (const T& val, const Vecteur<T>& v2); // valeur
    friend const Vecteur<T> operator * (const Vecteur<T>& v1, const Vecteur<T>& v2); // vecteur

    
    T at(size_t n) const;
    size_t size() const;
    void resize(size_t taille);
    long somme() const;
    
    
private:
   long taille;
   std::vector<T> vecteur;
};



#endif /* Vecteur_hpp */
