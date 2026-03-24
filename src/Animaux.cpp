#include "../include/Animaux.h"
#include <cstdlib>

// ===========================
// LION
// ===========================
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY) {
    nom = "Lion";
}

// Attaque : Feuille(1) ou Ciseaux(2) au hasard
void Lion::setAttaque(Attaque atq) {
    typeAttaque = Attaque(1 + rand() % 2);
    (void)atq;
}

// Déplacement diagonal : une des 4 directions (±1, ±1), cyclique
void Lion::deplace(int maxX, int maxY) {
    int dx[] = { 1,  1, -1, -1};
    int dy[] = { 1, -1, -1,  1};
    int dir = rand() % 4;
    x = (x + dx[dir] + maxX) % maxX;
    y = (y + dy[dir] + maxY) % maxY;
}

// ===========================
// LOUP
// ===========================
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY) {
    nom = "Loup";
}

// Attaque : une des 3 attaques au hasard
void Loup::setAttaque(Attaque atq) {
    typeAttaque = Attaque(rand() % 3);
    (void)atq;
}

// Déplacement : téléportation sur n'importe quelle cellule du plateau
void Loup::deplace(int maxX, int maxY) {
    x = rand() % maxX;
    y = rand() % maxY;
}

// ===========================
// OURS
// ===========================
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY) {
    nom = "Ours";
}

// Attaque : uniquement Feuille(1)
void Ours::setAttaque(Attaque atq) {
    typeAttaque = Attaque(1);
    (void)atq;
}

// Déplacement : 8 directions (2,1),(1,2),(-1,2),(-2,1),(-2,-1),(-1,-2),(1,-2),(2,-1)
// avec passage cyclique (toroïdal)
void Ours::deplace(int maxX, int maxY) {
    int dx[] = { 2,  1, -1, -2, -2, -1,  1,  2};
    int dy[] = { 1,  2,  2,  1, -1, -2, -2, -1};
    int dir = rand() % 8;
    x = (x + dx[dir] + maxX) % maxX;
    y = (y + dy[dir] + maxY) % maxY;
}

// ===========================
// PIERRE
// ===========================
Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY) {
    nom = "Pierre";
}

// Attaque : uniquement Pierre(0)
void Pierre::setAttaque(Attaque atq) {
    typeAttaque = Attaque(0);
    (void)atq;
}

// Ne se déplace pas
void Pierre::deplace(int maxX, int maxY) {
    (void)maxX;
    (void)maxY;
}