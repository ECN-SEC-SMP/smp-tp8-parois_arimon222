#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "../include/Attaque.h"
#include <cstdlib>
using namespace std;

// Crée une attaque random
Attaque::Attaque() {
    type = rand() % 3;
}

// Crée une attaque spécifique
Attaque::Attaque(int a) {
    type = a;
}

int Attaque::getTypeAttaque() const {
    return type;
}

// Retourne true si *this est plus forte que a (i.e. *this bat a)
// Pierre(0) bat Ciseaux(2), Feuille(1) bat Pierre(0), Ciseaux(2) bat Feuille(1)
// Règle : type bat (type + 2) % 3
bool Attaque::resoudreAttaque(const Attaque &a) const {
    return type == (a.getTypeAttaque() + 2) % 3;
}

std::string Attaque::getNomAttaque() const {
    switch (type) {
        case 0: return "Pierre";
        case 1: return "Feuille";
        case 2: return "Ciseaux";
        default: return "Inconnu";
    }
}