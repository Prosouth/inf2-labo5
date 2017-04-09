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

template <typename T>
class Vecteur;

template <typename T>
std::ostream& operator << (std::ostream& os, const Vecteur<T>& vect);

template <typename T>
Vecteur<T> operator + (const Vecteur<T>& v1);

template <typename T>
Vecteur<T> operator - (const Vecteur<T>& v1);

template <typename T>
Vecteur<T> operator * (const T& val, const Vecteur<T>& v2); // valeur

template <typename T>
Vecteur<T> operator * (const Vecteur<T>& v1); // vecteur

template<typename T>
class Vecteur
{
public:
   // Constructeurs par défaut
   Vecteur(const size_t& n);
   Vecteur(const std::vector<T>& vect);
    
   // Surcharge d'opérateurs
   friend std::ostream& operator << <> (std::ostream& os, const Vecteur<T>& vect);
   friend Vecteur<T> operator + (const Vecteur<T>& v1) ;
   friend Vecteur<T> operator - (const Vecteur<T>& v1);
   friend Vecteur<T> operator * (const T& val, const Vecteur<T>& v2); // valeur
   friend Vecteur<T> operator * (const Vecteur<T>& v1, const Vecteur<T>& v2); // vecteur
    
   const T& at(size_t n) const; // Lecture
   T& at(size_t n); // Ecriture
   size_t size() const;
   void resize(size_t taille);
   T somme() const;
    
private:
   size_t taille;
   std::vector<T> vecteur;
};

#include "VecteurImpl.h"

#endif /* Vecteur_hpp */
