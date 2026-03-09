#pragma once
#include <string>

class Attaque {
private:
    int type; // 0: Pierre, 1: Feuille, 2: Ciseaux

public:
    Attaque();           // crée une attaque random
    Attaque(int a);      // crée une attaque spécifique

    int getTypeAttaque() const;
    bool resoudreAttaque(const Attaque &a) const; // true si *this est plus forte que a
    std::string getNomAttaque() const;
};