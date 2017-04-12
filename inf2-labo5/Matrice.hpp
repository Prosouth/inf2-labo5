/*
 --------------------------------------------------------------------------------
 
 Laboratoire        : INF2 Laboratoire n°5
 Fichier            : Matrice.hpp
 Auteur(s)          : Walid Koubaa & Sebastien Saez
 Classe             : INF2-C
 Date de creation   : 12/04/2017
 But                : Classe permettant la creation d'un objet generique Vecteur ayant pour
                      parametre un vecteur de type generique T, et une taille.
                      La classe met a disposition les operateur d'affichage de flux ainsi que divers
                      operateurs effectuant des operations sur le vecteur crée, des getters
                      et deux fonction pour la lecture et l'ecriture des elements de ce Vecteur generique.

 Remarque(s)        :
 Compilateur        : g++ (GCC) 6.3.1 20170306
 
 --------------------------------------------------------------------------------
 */
#ifndef Matrice_hpp
#define Matrice_hpp

#include <iostream>
#include <vector>
#include "Vecteur.hpp"

template <typename T>
class Matrice;

template <typename T>
std::ostream& operator << (std::ostream& os, const Matrice<T>& m) noexcept;

template <typename T>
Matrice<T> operator * (const Matrice<T>& m1, const Matrice<T>& m2);

template <typename T>
Matrice<T> operator * (const T& val, Matrice<T>& m1);

template <typename T>
Matrice<T> operator * (Matrice<T>& m1, const T& val);

template <typename T>
Matrice<T> operator + (const Matrice<T>& m1, const Matrice<T>& m2);

template <typename T>
class Matrice {

public:
    // Constructeurs par défaut
    Matrice() = default;
    Matrice (int lignes);
    Matrice (int lignes, int colonnes);
    Matrice (const Vecteur<Vecteur<T>>& newVector);
    
    //getters et setters
    const Vecteur<T>& at(int position) const;
    Vecteur<T>& at(int position);
    int size() const noexcept;
    void resize(int nbLignes);
    void resize(int nbLignes, int nbColonnes);
    bool estVide() const noexcept;
    bool estCarre() const noexcept;
    bool estReguliere() const noexcept;
    
    //Fonctions de calculs sur une matrice
    Vecteur<T> sommeLigne();
    Vecteur<T> sommeColonne();
    T sommeDiagonaleGD();
    T sommeDiagonaleDG();
    
    // Surcharge d'opérateurs
    friend std::ostream& operator << <> (std::ostream& os,const Matrice<T>& m) noexcept;
    friend Matrice<T> operator * <> (const Matrice<T>& m1, const Matrice<T>& m2);
    friend Matrice<T> operator * <> (const T& val, Matrice<T>& m1);   // les deux sens a faire (commutativite)
    friend Matrice<T> operator * <> (Matrice<T>& m1, const T& val);
    friend Matrice<T> operator + <> (const Matrice<T>& m1, const Matrice<T>& m2);
    
private:
    Vecteur<Vecteur<T>> matrice;
};

#include "MatriceImpl.h"

#endif /* Matrice_hpp */
