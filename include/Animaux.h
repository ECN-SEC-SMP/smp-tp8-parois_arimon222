#pragma once
#include "Animal.h"

class Lion : public Animal {
public:
    Lion(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

class Loup : public Animal {
public:
    Loup(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

class Ours : public Animal {
public:
    Ours(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};

class Pierre : public Animal {
public:
    Pierre(int maxX, int maxY);

    void setAttaque(Attaque atq);
    void deplace(int maxX, int maxY);
};