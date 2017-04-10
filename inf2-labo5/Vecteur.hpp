/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : Vecteur.hpp
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 07/04/2017
 But                :
 Remarque(s)        : 
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
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
Vecteur<T> operator + (const Vecteur<T>& v);

template <typename T>
Vecteur<T> operator - (const Vecteur<T>& v);

template <typename T>
Vecteur<T> operator * (const T& val); // valeur

template <typename T>
Vecteur<T> operator * (const Vecteur<T>& v); // vecteur

template<typename T>
class Vecteur
{
public:
   // Constructeurs par défaut
   Vecteur(const size_t& n);
   Vecteur(const std::vector<T>& vect);
    
   // Surcharge d'opérateurs
   friend std::ostream& operator << <> (std::ostream& os, const Vecteur<T>& vect);
   Vecteur<T> operator + (const Vecteur<T>& v1);
   Vecteur<T> operator - (const Vecteur<T>& v1);
   Vecteur<T> operator * (const T& val); // valeur
   Vecteur<T> operator * (const Vecteur<T>& v2); // vecteur
    
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
