//
//  VecteurImpl.h
//  inf2-labo5
//
//  Created by Walid Koubaa on 07.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

#ifndef VecteurImpl_h
#define VecteurImpl_h

//
//  Vecteur.cpp
//  inf2-labo5
//
//  Created by Walid Koubaa on 05.04.17.
//  Copyright © 2017 Walid. All rights reserved.
//

#include "Vecteur.hpp"

template<typename T>
Vecteur<T>::Vecteur(const size_t& n)
: taille(n) {}

template<typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vect)
: vecteur(vect) {}

template<typename T>
T& Vecteur<T>::at(size_t n) const
{
    
}

template<typename T>
size_t Vecteur<T>::size() const
{
    return this->size;
}

template<typename T>
void Vecteur<T>::resize(size_t taille)
{
    this->size = taille;
}


template<typename T>
long Vecteur<T>::somme() const
{
    
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Vecteur<T>& vect)
{
    //os << vect.
    
    
    return os;
}

template<typename T>
const Vecteur<T> operator + (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
    Vecteur<T> vectFinal = v1 + v2;
    return vectFinal;
}

template<typename T>
const Vecteur<T> operator - (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
    Vecteur<T> vectFinal = v1 - v2;
    return vectFinal;
}

template<typename T>
const Vecteur<T> operator * (const T& val, Vecteur<T>& v2)
{
    
}// valeur

template<typename T>
const Vecteur<T> operator * (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
    
    
}// vecteur

#endif /* VecteurImpl_h */
