# Simulation de Batailles Animales

Ce projet est une simulation de batailles animales sur un plateau toroïdal en C++, inspirée du jeu Pierre-Feuille-Ciseaux. Quatre espèces d'animaux (Lion, Loup, Ours, Pierre) évoluent sur une grille 10x10, avec des règles spécifiques de déplacement et d'attaque. La simulation se déroule en tours : déplacement, résolution des conflits (combats ou reproduction), jusqu'à ce qu'une espèce domine ou qu'une limite de tours soit atteinte.

## Structure du projet

- **include/** : En-têtes des classes
  - `Animal.h` : Classe de base abstraite pour les animaux
  - `Animaux.h` : Classes dérivées pour chaque espèce
  - `Attaque.h` : Classe pour gérer les types d'attaques
- **src/** : Implémentations
  - `Animal.cpp` : Implémentation de la classe de base
  - `Animaux.cpp` : Implémentations des espèces spécifiques
  - `Attaque.cpp` : Logique des attaques
- **main.cpp** : Programme principal gérant la simulation
- **Makefile** : Pour la compilation
- Autres fichiers : `.gitignore`, `tp-template.pdf` (sujet), exécutable `jeu`, objets compilés

## Règles du jeu

### Déplacements
- **Lion** : Diagonales (±1, ±1)
- **Loup** : Téléportation aléatoire sur n'importe quelle case
- **Ours** : Mouvements en L (comme le cavalier aux échecs : 8 directions possibles)
- **Pierre** : Immobile

### Attaques (Pierre=0, Feuille=1, Ciseaux=2)
- **Lion** : Feuille ou Ciseaux aléatoire
- **Loup** : Aléatoire parmi les 3 types
- **Ours** : Toujours Feuille
- **Pierre** : Toujours Pierre

### Résolution des conflits
Sur une même case :
- Si animaux de la même espèce → reproduction (création d'un nouvel animal)
- Sinon → combats successifs entre animaux d'espèces différentes jusqu'à ce qu'il n'en reste qu'un

Les combats utilisent les règles Pierre-Feuille-Ciseaux classiques.

## Compilation et exécution

Utilisez le Makefile fourni :

```bash
make
./jeu
```

## Fonctionnalités

- Plateau toroïdal : les animaux peuvent sortir d'un côté et réapparaître de l'autre
- Affichage en temps réel du plateau avec symboles (L=Lion, U=Loup, O=Ours, P=Pierre, .=vide)
- Simulation automatique avec pause de 2 secondes entre les tours
- Arrêt quand une seule espèce survit ou après 10000 tours maximum

## Architecture

Le code utilise l'héritage en C++ :
- `Animal` : classe de base avec méthodes virtuelles pures pour `setAttaque` et `deplace`
- Classes dérivées : `Lion`, `Loup`, `Ours`, `Pierre` implémentent les comportements spécifiques
- `Attaque` : gère les types d'attaques et leur résolution

Tous les fichiers sont documentés avec des commentaires Doxygen.