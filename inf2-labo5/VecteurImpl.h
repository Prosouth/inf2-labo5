//
//  VecteurImpl.h
//  inf2-labo5
//
//  Created by Walid Koubaa on 07.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//
#ifndef VecteurImpl_h
#define VecteurImpl_h

#include "Vecteur.hpp"
#include <exception>

template<typename T>
Vecteur<T>::Vecteur(const size_t& n)
: taille(n) {} // Vecteur initialisé avec la taille?

template<typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vect)
: vecteur(vect) {}

template<typename T>
T& Vecteur<T>::at(size_t n)
{
   return this->vecteur.at(n);
}

template<typename T>
size_t Vecteur<T>::size() const
{
    return this->vecteur.size();
}

template<typename T>
void Vecteur<T>::resize(size_t taille)
{
   if(this->taille > taille)
   {
      this->vecteur.resize(taille);
   } // sinon on lance une exception
}


template<typename T>
T Vecteur<T>::somme() const
{
   T somme = 0;
   for(auto i = this->vecteur.begin(); i != this->vecteur.end(); i++)
   {
      somme += vecteur.at(i);
   }
   return somme;
    
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Vecteur<T>& vect)
{
    os << "[";
    for(size_t i = 0; i < vect.size() - 1; i++)
    {
        os << vect.at(i) << ", ";
    }
    os << vect.at(vect.size() - 1) << "]";
    
    return os;
}

template<typename T>
Vecteur<T>& operator + (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(v1.size());
   if(v1.size() == v2.size())
   {
      for(size_t i = 0; i <= v1.size(); i++)
      {
         vectFinal.at(i) = v1.at(i) + v2.at(i);
      }
   }

    return vectFinal;
}

template<typename T>
Vecteur<T>& operator - (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(v1.size());
   if(v1.size() == v2.size())
   {
      for(size_t i = 0; i <= v1.size(); i++)
      {
         vectFinal.at(i) = v1.at(i) - v2.at(i);
      }
   }

    return vectFinal;
}

template<typename T>
Vecteur<T>& operator * (const T& val, Vecteur<T>& v2)
{
   for(size_t i = 0; i <= v2.size(); i++)
   {
      v2.at(i) = v2.at(i) * val;
   }
   return v2;
}// valeur

template<typename T>
Vecteur<T>& operator * (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vTemp(v1.size());
   if(v1.size() == v2.size())
   {
      for(size_t i = 0; i <= v1.size(); i++)
      {
         vTemp.at(i) = v1.at(i) * v2.at(i);
      }
      return vTemp;
   }
}// vecteur

#endif /* VecteurImpl_h */
