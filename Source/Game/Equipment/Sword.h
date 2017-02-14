#ifndef SWORD_H_INCLUDED
#define SWORD_H_INCLUDED

#include "../../Animation.h"

class Equippable;

class Sword
{
    public:
        Sword(Equippable& sword);

        void slash();

        void draw();

        void update();

    private:
        sf::RectangleShape m_slashEffect;

        Animation m_swordAnimation;
        Animation m_slashAnimation;

        Equippable* m_p_sword;
};

#endif // SWORD_H_INCLUDED
