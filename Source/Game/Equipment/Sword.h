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

        bool isSwinging() const;

    private:
        sf::RectangleShape m_slashEffect;

        Animation m_swordAnimation;
        Animation m_slashAnimation;

        Equippable* m_p_sword;
        bool m_isSwinging = false;
        sf::Clock m_slashTimer;
};

#endif // SWORD_H_INCLUDED
