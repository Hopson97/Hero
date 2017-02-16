#ifndef SWORD_H_INCLUDED
#define SWORD_H_INCLUDED

#include <SFML/Audio.hpp>

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

        sf::FloatRect getBounds() const;

        const Equippable& getEquipment() const;

    private:
        sf::RectangleShape m_slashEffect;

        Animation m_swordAnimation;
        Animation m_slashAnimation;

        Equippable* m_p_sword;
        bool m_isSwinging = false;
        sf::Clock m_slashTimer;

        sf::Sound m_swordSwingSound;
};

#endif // SWORD_H_INCLUDED
