#ifndef SWORD_H_INCLUDED
#define SWORD_H_INCLUDED

#include "Equipment_Data.h"
#include "../../Animation.h"

class Equippable;

class Sword
{
    public:
        constexpr static int SWORD_SIZE = 135;

        Sword(Equippable& sword);

        void slash();
        void draw();
        void update();

        bool isSwinging() const;

        void upgrade (Equipment::Tier tier);

    private:
        sf::RectangleShape m_slashEffect;

        Animation m_swordAnimation;
        Animation m_slashAnimation;

        Equippable* m_p_sword;
        bool m_isSwinging = false;
        sf::Clock m_slashTimer;
};

#endif // SWORD_H_INCLUDED
