/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : MatriceImpl.h
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 07/04/2017
 But                :
 Remarque(s)        : 
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
#ifndef MatriceImpl_h
#define MatriceImpl_h

#include "Matrice.hpp"
#include <exception>

using namespace std;

template <typename T>
Matrice<T>::Matrice (unsigned int lignes)
{
    this->matrice = Vecteur<Vecteur<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (unsigned int lignes, unsigned int colonnes)
{
    this->matrice = Vecteur<Vecteur<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (const Vecteur<Vecteur<T>>& newVector)
{
    this->matrice = newVector;
}

template <typename T>
const Vecteur<T>& Matrice<T>::at(unsigned int position) const
{
    return matrice.at(position / matrice.size());
}

template <typename T>
Vecteur<T>& Matrice<T>::at(unsigned int position){
    return matrice.at(position / matrice.size());
}

template <typename T>
unsigned int Matrice<T>::size() const
{
    unsigned int size = 0;
    for (int i = 0; i < matrice.size(); i++)
        
    {
        size += matrice.at(i).size();
    }
    return (unsigned int) size;
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes)
{
    matrice.resize(nbLignes);
}

template <typename T>
void Matrice<T>::resize(unsigned int nbLignes, unsigned int nbColonnes)
{
    matrice.resize(nbLignes);
    for(vector<T>& vect : matrice)
    {
        vect.resize(nbColonnes);
    }
}

template <typename T>
bool Matrice<T>::estVide() const 
{
    return matrice.size() == 0; //&& vectColonnes.size()==0; // on regarde les lignes avant les colonnes au cas ou le constucteur avec les lignes seulement est appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre() const 
{
    return matrice.size();//==vectColonnes.size();
}

template <typename T>
bool Matrice<T>::estReguliere() const
{
    for (int i = 0; i < matrice.size(); i++)
    {
        if (matrice.at(i).size() != matrice.at(0).size())
        { // si la taille d'une des lignes n'est pas egale a la premiere alors la matrice n'est pas reguliere
            return false;
        }
    }
    return true;
}
/*
template <typename T>
void Matrice<T>::push(unsigned int position,const T& valeur){
    matrice.at(position)=valeur;
}
*/
template <typename T>
void Matrice<T>::pop(unsigned int position,const T& valeur)
{
     matrice.at(position) = 0;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne()
{
    Vecteur<T> tempMatrice(matrice.size());
    for(int i = 0 ;i < tempMatrice.size(); i++)
    {
        for (int j = 0; j < matrice.size(); j++)

        {
            tempMatrice.at(i) += matrice.at(i).at(j);
        }
    }
    return tempMatrice;
}

template <typename T>
Vecteur<T> Matrice<T>::sommeColonne()
{
    Vecteur<T> tempMatrice(matrice.size());
    for(int i = 0; i < tempMatrice.size(); i++)
    {
        for (int j = 0; j< matrice.size(); j++)
            
        {
            tempMatrice.at(i) += matrice.at(i).at(j);
        }
    }
    return tempMatrice;
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD()
{
    if(!estReguliere())
    {
        throw invalid_argument("Votre matrice n'est pas carree, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i < matrice.size();i++)
    {
        for(int j = 0; j < matrice.at(i).size(); j++)
        {
            if(i == j)
            {
            sommeDiagonale += matrice.at(i).at(j);
            }
        }
    }
    return sommeDiagonale;
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG()
{
    if(!estReguliere())
    {
        throw invalid_argument("Votre matrice n'est pas carré, la diagonale n'existe pas.");
    }
    T sommeDiagonale = 0;
    for(int i = 0; i < matrice.size(); i++)
    {
        for(int j = 0; j < matrice.at(i).size(); j++)
        {
            if(i == (matrice.at(i).size() - j))
            {
                sommeDiagonale += matrice.at(i).at(j);
            }        
        }
    }
    return sommeDiagonale;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const Matrice<T>& m)
{
    os << "[";
    for(int i = 0; i <= m.size() - 1; i++)
    {
        os << m.at(i) << ", ";
    }
    os << m.at(m.size() - 1) << "]";
    return os;
}

template <typename T>
Matrice<T>& Matrice<T>::operator * ( const Matrice<T>& m)
{
    Matrice <T> matriceTemps= m;
    for(int i = 0; i < m.size(); i++)
    {
        for(int j = 0; j < m.at(i).size(); j++)
        {
            matriceTemps.at(i).at(j) = m.at(i).at(j) * (*this).at(i).at(j);
        }
    }
    return matriceTemps;
}

template <typename T>
Matrice<T>& Matrice<T>::operator * (const T& val)
{// les deux sens a faire (commutativite)
    for(int i = 0; i < matrice.size(); i++)
    {
        matrice.at(i) *= val;
    }
    return *this;
}

template <typename T>
Matrice<T>&  Matrice<T>::operator + (const Matrice<T>& m){
    for(int i = 0; i < m.size() ; i++)
    {
        for(int j = 0; j < m.size(); j++)
        {     
            matrice.at(i).at(j) += m.at(i).at(j);
        }
    }
    return *this;
}

#endif /* MatriceImpl_h */