#pragma once
#include <string>

/**
 * @brief Classe représentant un type d'attaque (Pierre, Feuille, Ciseaux).
 *
 * Les attaques suivent les règles classiques : Pierre bat Ciseaux, etc.
 */
class Attaque {
private:
    int type; ///< 0: Pierre, 1: Feuille, 2: Ciseaux

public:
    /// @brief Constructeur avec attaque aléatoire
    Attaque();

    /**
     * @brief Constructeur avec attaque spécifique.
     * @param a Type d'attaque (0,1,2)
     */
    Attaque(int a);

    /// @return Le type d'attaque (0,1,2)
    int getTypeAttaque() const;

    /**
     * @brief Résout le combat entre deux attaques.
     * @param a L'attaque adverse
     * @return True si cette attaque bat l'adverse
     */
    bool resoudreAttaque(const Attaque &a) const;

    /// @return Le nom de l'attaque ("Pierre", "Feuille", "Ciseaux")
    std::string getNomAttaque() const;
};