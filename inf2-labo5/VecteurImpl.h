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
: taille(n) 
{
   vecteur.resize(n);
} // Vecteur initialisé avec la taille?

template<typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vect)
{
   this->taille = vect.size();
   this->vecteur.resize(vect.size());
   for(size_t i = 0; i < taille; i++)
   {
      vecteur.at(i) = vect.at(i);
   }
}

template<typename T>
const T& Vecteur<T>::at(size_t n) const // Lecture
{
   return this->vecteur.at(n);
}

template<typename T> // Ecriture
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
      this->taille = taille;
   } // sinon on lance une exception
   // S'il est plus petit
}


template<typename T>
T Vecteur<T>::somme() const
{
   T somme = 0;
   for(size_t i = 0; i < taille; i++)
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
Vecteur<T> Vecteur<T>::operator + (const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(this->size());
   if(this->size() == v2.size())
   {
      for(size_t i = 0; i < this->size(); i++)
      {
         vectFinal.at(i) = this->at(i) + v2.at(i);
      }
   }

    return vectFinal;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator - (const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(this->size());
   if(this->size() == v2.size())
   {
      for(size_t i = 0; i < this->size(); i++)
      {
         vectFinal.at(i) = this->at(i) - v2.at(i);
      }
   }
   return vectFinal;
}

template<typename T>
Vecteur<T> Vecteur<T>::operator * (const T& val)
{
   for(size_t i = 0; i < this->size(); i++)
   {
      this->at(i) = this->at(i) * val;
   }
   return *this;
}// valeur

template<typename T>
Vecteur<T> Vecteur<T>::operator * (const Vecteur<T>& v2)
{
   Vecteur<T> vTemp(this->size());
   if(this->size() == v2.size())
   {
      for(size_t i = 0; i < this->size(); i++)
      {
         vTemp.at(i) = this->at(i) * v2.at(i);
      }
      return vTemp;
   }
}// vecteur

#endif /* VecteurImpl_h */