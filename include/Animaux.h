#pragma once
#include "Animal.h"

/**
 * @brief Classe représentant un Lion.
 *
 * Le Lion se déplace en diagonale et attaque avec Feuille ou Ciseaux.
 */
class Lion : public Animal {
public:
    /**
     * @brief Constructeur du Lion.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    Lion(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

/**
 * @brief Classe représentant un Loup.
 *
 * Le Loup se téléporte aléatoirement et peut attaquer avec n'importe quoi.
 */
class Loup : public Animal {
public:
    /**
     * @brief Constructeur du Loup.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    Loup(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

/**
 * @brief Classe représentant un Ours.
 *
 * L'Ours se déplace en L (comme le cavalier aux échecs) et attaque toujours avec Feuille.
 */
class Ours : public Animal {
public:
    /**
     * @brief Constructeur de l'Ours.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    Ours(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

/**
 * @brief Classe représentant une Pierre.
 *
 * La Pierre ne se déplace pas et attaque toujours avec Pierre.
 */
class Pierre : public Animal {
public:
    /**
     * @brief Constructeur de la Pierre.
     * @param maxX Largeur maximale du plateau
     * @param maxY Hauteur maximale du plateau
     */
    Pierre(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};