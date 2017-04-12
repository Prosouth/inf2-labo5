/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : MatriceImpl.h
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 12/04/2017
 But                : Fichier definissant l'implementation de la classe generique Matrice.
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
Matrice<T>::Matrice (int lignes)
{
    if(lignes < 0)
        throw std::invalid_argument("Le nombre de ligne ne peux pas etre negatif");
    this->matrice = Vecteur<Vecteur<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (int lignes, int colonnes)
{
    if(lignes < 0)
        throw std::invalid_argument("Le nombre de ligne ne peux pas etre negatif");
    if(colonnes < 0)
        throw std::invalid_argument("Le nombre de colonne ne peux pas etre negatif");
    
    this->matrice = Vecteur<Vecteur<T>>(lignes);
}

template <typename T>
Matrice<T>::Matrice (const Vecteur<Vecteur<T>>& newVector)
{
    this->matrice = newVector;
}

template <typename T>                        // lecture
const Vecteur<T>& Matrice<T>::at( int position) const
{
    if(position < 0 || position > (*this).size())
        throw std::invalid_argument("Vous accedez a un emplacement non existant");
    return matrice.at(position);
}

template <typename T>                       // ecriture
Vecteur<T>& Matrice<T>::at(int position){
    if(position < 0 || position > (*this).size())
        throw std::invalid_argument("Vous ecrivez a un emplacement non existant");
    return matrice.at(position);
}

template <typename T>
int Matrice<T>::size() const noexcept
{
    int size = 0;
    for (int i=0; i< matrice.at(0).size(); i++)
    {
        size+= i;
    }
    return size;
}

template <typename T>
void Matrice<T>::resize( int nbLignes)
{
    if(nbLignes < 0)
        throw std::invalid_argument("Un nombre de lignes negatif est impossible");
    matrice.resize(nbLignes);
}

template <typename T>
void Matrice<T>::resize(int nbLignes, int nbColonnes)
{
    if(nbLignes < 0 || nbColonnes <0)
        throw std::invalid_argument("Une taille negative est impossible");
    matrice.resize(nbLignes);
    for(vector<T>& vect : matrice)
    {
        vect.resize(nbColonnes);
    }
}

template <typename T>
bool Matrice<T>::estVide() const noexcept
{
    return matrice.size() == 0; //&& vectColonnes.size()==0; // on regarde les lignes avant les colonnes au cas ou le constucteur avec les lignes seulement est appelle car celui avec les colonnes n'existe pas
}

template <typename T>
bool Matrice<T>::estCarre() const noexcept
{
    return matrice.size();//==vectColonnes.size();
}

template <typename T>
bool Matrice<T>::estReguliere() const noexcept
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

template <typename T>
Vecteur<T> Matrice<T>::sommeLigne()
{
    Vecteur<T> tempMatrice(matrice.size());
    for(int i =0 ;i < matrice.size();i++)
    {
        for (int j=0; j< matrice.at(i).size(); j++)

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
std::ostream& operator << (std::ostream& os, const Matrice<T>& m) noexcept
{
    for(int i = 0; i < m.size() - 1; i++)
    {
        os << "|"<< m.at(i) << "|"<< endl;
    }
    os << "|"<< m.at(m.size() - 1) << "|";
    return os;
}

template <typename T>
Matrice<T> operator * (const Matrice<T>& m1, const Matrice<T>& m2)
{
    Matrice <T> matriceTemps;
    for(int i = 0; i < m1.size(); i++)
    {
        for(int j = 0; j < m1.at(i).size(); j++)
        {
            for(int k = 0; k < m2.at(i).size(); k++){

            matriceTemps.at(i).at(j) = m1.at(i).at(k) * m1.at(k).at(j);
            
            }
        }
    }
    return matriceTemps;
}

template <typename T>
Matrice<T> operator * (const T& val, Matrice<T>& m1)
{// les deux sens a faire (commutativite)
    for(int i = 0; i < m1.size(); i++)
    {
        for(int j = 0; j < m1.at(i).size(); j++)
        {
                m1.at(i).at(j) = val * m1.at(i).at(j);
        }
        
    }
    return m1;
}

template <typename T>
Matrice<T> operator * (Matrice<T>& m1, const T& val)
{
    return val * m1;
}



template <typename T>
Matrice<T>  operator + (const Matrice<T>& m1, const Matrice<T>& m2)
{
    Matrice<T> matFinale ;
    for(int i = 0; i < m1.size() ; i++)
    {
            matFinale.at(i) = m1.at(i) + m2.at(i);
    }
    return matFinale;
}

#endif /* MatriceImpl_h */
