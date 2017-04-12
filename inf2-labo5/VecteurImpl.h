/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : VecteurImpl.h
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 07/04/2017
 But                :
 Remarque(s)        : 
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
#ifndef VecteurImpl_h
#define VecteurImpl_h

#include "Vecteur.hpp"
#include <exception>


template<typename T>
Vecteur<T>::Vecteur()
{
    vecteur = std::vector<T>{};
}

template<typename T>
Vecteur<T>::Vecteur(const size_t& n)
{
   if(taille < 0)
       throw std::invalid_argument("La taille de votre vecteur est negative");

   this->taille = n;
   vecteur.resize(n);
} 

template<typename T>
Vecteur<T>::Vecteur(const std::vector<T>& vect)
{
    if(taille < 0)
        throw std::invalid_argument("La taille de votre vecteur est negative");
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
    if(n < 0 || n > (*this).size())
        throw std::invalid_argument("Vous accedez a un element non existant");
   return this->vecteur.at(n);
}

template<typename T> // Ecriture
T& Vecteur<T>::at(size_t n)
{
    if(n < 0 || n > (*this).size())
        throw std::invalid_argument("Vous ecrivez a un emplacement non existant");
   return this->vecteur.at(n);
}

template<typename T>
size_t Vecteur<T>::size() const noexcept
{
    return this->vecteur.size();
}

template<typename T>
void Vecteur<T>::resize(int taille)
{
    if(taille < 0)
        throw std::invalid_argument("Une taille negative est impossible");
   
    this->vecteur.resize(taille);
    this->taille = taille;
}

// On part du principe que l'on somme des types numeriques,
// pour d'autres types specifiques il faudrait specialiser la fonction
template<typename T>
T Vecteur<T>::somme() const
{
   T somme = 0;
   T sommeCheck = 0;
   for(size_t i = 0; i < taille; i++)
   {
      somme += vecteur.at(i);
    if(sommeCheck > somme)      // cas ou on deborderait du maximum du type generique choisi
        throw std::out_of_range("Depassement de capacite de la somme !");
       sommeCheck += vecteur.at(i);
   }
   return somme;
    
}

template<typename T>
void Vecteur<T>::add(T elem)
{
   vecteur.push_back(elem);
   taille++;
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Vecteur<T>& vect) noexcept
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
Vecteur<T> operator + (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(v1.size());
    if(v1.size() != v2.size()){
        throw std::invalid_argument("Taille des vecteurs incompatibles pour etre sommee");
    }
    for(size_t i = 0; i < v1.size(); i++)
    {
        vectFinal.at(i) = v1.at(i) + v2.at(i);
    }
   

    return vectFinal;
}

template<typename T>
Vecteur<T> operator - (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vectFinal(v1.size());
    if(v1.size() != v2.size()){
        throw std::invalid_argument("Taille des vecteurs incompatibles pour etre soustraite");
    }
    for(size_t i = 0; i < v1.size(); i++)
    {
        vectFinal.at(i) = v1.at(i) - v2.at(i);
    }
   
   return vectFinal;
}

template<typename T>
Vecteur<T> operator * (const T& val, Vecteur<T>& v1) noexcept
{
   for(size_t i = 0; i < v1.size(); i++)
   {
      v1.at(i) = v1.at(i) * val;
   }
   return v1;
}// valeur

template<typename T>
Vecteur<T> operator * (Vecteur<T>& v1, const T& val) noexcept
{
   return val * v1;
}

template<typename T>
Vecteur<T> operator * (const Vecteur<T>& v1, const Vecteur<T>& v2)
{
   Vecteur<T> vTemp(v1.size());
    if(v1.size() != v2.size()){
        throw std::invalid_argument("Taille des vecteurs incompatible pour etre multiplies");
    }
    for(size_t i = 0; i < v1.size(); i++)
    {
        vTemp.at(i) = v1.at(i) * v2.at(i);
    }
   
   return vTemp;
}// vecteur

#endif /* VecteurImpl_h */
