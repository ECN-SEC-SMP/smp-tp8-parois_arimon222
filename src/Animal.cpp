#include "../include/Animal.h"
#include <cstdlib>

// Placement aléatoire, attaque aléatoire
Animal::Animal(int maxX, int maxY) : typeAttaque() {
    x = rand() % maxX;
    y = rand() % maxY;
    vivant = true;
}

// Placement aléatoire, attaque spécifique (a = type d'attaque, b ignoré)
Animal::Animal(int maxX, int maxY, int a, int b) : typeAttaque() {
    x = a % maxX;
    y = b % maxY;
    vivant = true;
}

std::string Animal::getNom() const {
    return nom;
}

int Animal::getX() const {
    return x;
}

int Animal::getY() const {
    return y;
}

bool Animal::getVivant() const {
    return vivant;
}

Attaque Animal::getAttaque() const {
    return typeAttaque;
}

void Animal::setVivant(bool v) {
    vivant = v;
}

// Chaque animal choisit son attaque via setAttaque(), puis on résout le combat.
// Retourne true si *this gagne (son attaque est plus forte que celle de a).
// En cas d'égalité, on tire au sort.
bool Animal::attaque(Animal &a) {
    // Chaque combattant choisit son attaque avant le combat
    setAttaque(Attaque());
    a.setAttaque(Attaque());

    bool victoireThis = typeAttaque.resoudreAttaque(a.getAttaque());
    bool victoireA    = a.getAttaque().resoudreAttaque(typeAttaque);

    if (victoireThis) {
        a.setVivant(false);
        return true;
    } else if (victoireA) {
        setVivant(false);
        return false;
    } else {
        // Égalité : tirage au sort
        if (rand() % 2 == 0) {
            a.setVivant(false);
            return true;
        } else {
            setVivant(false);
            return false;
        }
    }
}