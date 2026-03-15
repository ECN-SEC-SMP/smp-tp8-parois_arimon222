#pragma once
#include <string>
#include "Attaque.h"

/**
 * @brief Classe de base représentant un animal dans la simulation.
 *
 * Cette classe définit les propriétés communes à tous les animaux :
 * position, état de vie, type d'attaque, etc.
 */
class Animal {
protected:
    std::string nom;    ///< Nom de l'espèce de l'animal
    int x;              ///< Abscisse de l'animal sur le plateau
    int y;              ///< Ordonnée de l'animal sur le plateau
    bool vivant;        ///< Indique si l'animal est vivant
    Attaque typeAttaque; ///< Type d'attaque actuel de l'animal

public:
    /**
     * @brief Constructeur avec placement aléatoire.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    Animal(int maxX, int maxY);

    /**
     * @brief Constructeur avec placement spécifique (attaque aléatoire).
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     * @param a Type d'attaque (ignoré ici)
     * @param b Paramètre ignoré
     */
    Animal(int maxX, int maxY, int a, int b);

    /// @return Le nom de l'espèce
    std::string getNom() const;

    /// @return L'abscisse de l'animal
    int getX() const;

    /// @return L'ordonnée de l'animal
    bool getY() const;

    /// @return True si l'animal est vivant
    bool getVivant() const;

    /// @return Le type d'attaque actuel
    Attaque getAttaque() const;

    /// @param v Nouvel état de vie
    void setVivant(bool v);

    /**
     * @brief Effectue une attaque contre un autre animal.
     * @param a L'animal cible
     * @return True si cet animal gagne le combat
     */
    bool attaque(Animal &a);

    virtual ~Animal() {}

    // Méthodes virtuelles pures
    /**
     * @brief Définit le type d'attaque pour cet animal.
     * @param atq Type d'attaque suggéré (peut être ignoré)
     */
    virtual void setAttaque(Attaque atq) = 0;

    /**
     * @brief Déplace l'animal sur le plateau.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    virtual void deplace(int maxX, int maxY) = 0;
};