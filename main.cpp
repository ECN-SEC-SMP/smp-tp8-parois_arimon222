#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "include/Animal.h"
#include "include/Animaux.h"

const int MAXX = 10;
const int MAXY = 10;

// Affiche le plateau : L=Lion, U=Loup, O=Ours, P=Pierre, .=vide
void afficherPlateau(const std::vector<Animal*>& animaux) {
    char grille[MAXX][MAXY];
    for (int i = 0; i < MAXX; i++)
        for (int j = 0; j < MAXY; j++)
            grille[i][j] = '.';

    for (Animal* a : animaux) {
        if (a->getVivant()) {
            char c = '?';
            if (a->getNom() == "Lion")   c = 'L';
            if (a->getNom() == "Loup")   c = 'U';
            if (a->getNom() == "Ours")   c = 'O';
            if (a->getNom() == "Pierre") c = 'P';
            grille[a->getX()][a->getY()] = c;
        }
    }

    std::cout << "+----------+" << std::endl;
    for (int j = 0; j < MAXY; j++) {
        std::cout << "|";
        for (int i = 0; i < MAXX; i++)
            std::cout << grille[i][j];
        std::cout << "|" << std::endl;
    }
    std::cout << "+----------+" << std::endl;
}

// Crée un nouvel animal de la même espèce, placé aléatoirement
Animal* spawner(Animal* a) {
    if (a->getNom() == "Lion")   return new Lion(MAXX, MAXY);
    if (a->getNom() == "Loup")   return new Loup(MAXX, MAXY);
    if (a->getNom() == "Ours")   return new Ours(MAXX, MAXY);
    if (a->getNom() == "Pierre") return new Pierre(MAXX, MAXY);
    return nullptr;
}

// Résout les conflits sur chaque cellule :
// - même espèce → spawn d'un nouvel animal de cette espèce
// - espèces différentes → combats jusqu'à ce qu'il n'en reste qu'un
void resoudreConflits(std::vector<Animal*>& animaux) {
    std::vector<Animal*> nouveaux;

    for (int i = 0; i < MAXX; i++) {
        for (int j = 0; j < MAXY; j++) {
            // Collecter les animaux vivants sur cette cellule
            std::vector<int> indices;
            for (int k = 0; k < (int)animaux.size(); k++) {
                if (animaux[k]->getVivant() &&
                    animaux[k]->getX() == i &&
                    animaux[k]->getY() == j) {
                    indices.push_back(k);
                }
            }

            if (indices.size() < 2) continue;

            // Tant qu'il reste plusieurs animaux sur la cellule
            while (indices.size() > 1) {
                // Vérifier si tous de la même espèce
                bool memeEspece = true;
                std::string espece = animaux[indices[0]]->getNom();
                for (int idx : indices)
                    if (animaux[idx]->getNom() != espece) { memeEspece = false; break; }

                if (memeEspece) {
                    // Reproduction : spawn d'un nouvel animal
                    Animal* bebe = spawner(animaux[indices[0]]);
                    if (bebe) nouveaux.push_back(bebe);
                    break; // fin des conflits sur cette cellule
                }

                // Choisir deux animaux d'espèces différentes
                int ia = rand() % indices.size();
                int ib;
                do { ib = rand() % indices.size(); } while (
                    ib == ia ||
                    animaux[indices[ib]]->getNom() == animaux[indices[ia]]->getNom()
                );

                animaux[indices[ia]]->attaque(*animaux[indices[ib]]);

                // Retirer les morts de la liste locale
                std::vector<int> survivants;
                for (int idx : indices)
                    if (animaux[idx]->getVivant()) survivants.push_back(idx);
                indices = survivants;
            }
        }
    }

    // Ajouter les nouveaux nés au tableau global
    for (Animal* a : nouveaux)
        animaux.push_back(a);
}

int nbVivants(const std::vector<Animal*>& animaux) {
    int n = 0;
    for (Animal* a : animaux)
        if (a->getVivant()) n++;
    return n;
}

int main() {
    srand(time(NULL));

    // Initialisation : 25% du plateau, 6 animaux par type
    const int nbParType = 6;
    std::vector<Animal*> animaux;

    for (int i = 0; i < nbParType; i++) animaux.push_back(new Lion(MAXX, MAXY));
    for (int i = 0; i < nbParType; i++) animaux.push_back(new Loup(MAXX, MAXY));
    for (int i = 0; i < nbParType; i++) animaux.push_back(new Ours(MAXX, MAXY));
    for (int i = 0; i < nbParType; i++) animaux.push_back(new Pierre(MAXX, MAXY));

    std::cout << "=== Debut du jeu ===" << std::endl;
    afficherPlateau(animaux);

    int tour = 0;
    const int MAX_TOURS = 10000;
    while (nbVivants(animaux) > 1 && tour < MAX_TOURS) {
        tour++;

        // 1. Déplacer tous les animaux vivants
        for (Animal* a : animaux)
            if (a->getVivant())
                a->deplace(MAXX, MAXY);

        // 2. Résoudre conflits (combats + reproduction)
        resoudreConflits(animaux);

        // 3. Afficher le plateau
        std::cout << "--- Tour " << tour
                  << " (" << nbVivants(animaux) << " animaux) ---" << std::endl;
        afficherPlateau(animaux);

        // Attente de 10 secondes avant le prochain tour
        sleep(2);
    }

    if (tour >= MAX_TOURS) {
        std::cout << "=== Limite de " << MAX_TOURS << " tours atteinte ===" << std::endl;
    } else if (nbVivants(animaux) == 1) {
        for (Animal* a : animaux)
            if (a->getVivant())
                std::cout << "=== Vainqueur : " << a->getNom() << " ===" << std::endl;
    } else {
        std::cout << "=== Plus aucun animal vivant ===" << std::endl;
    }

    for (Animal* a : animaux)
        delete a;

    return 0;
}