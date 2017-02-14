#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <array>

#include "../Animation.h"
#include "Equipment/Equippable.h"
#include "Equipment/Sword.h"

class Resource_Holder;

class Player
{
    constexpr static int BODY_SIZE  = 100;
    constexpr static int SPEED      = 2;

    public:
        Player();

        void input  ();
        void update (float dt);
        void draw   ();


    private:
        void setEquipmentBody       (Equipment::Tier tier);
        void setEquipmentHeadgear   (Equipment::Tier tier);
        void setEquipmentSword      (Equipment::Tier tier);
        void setEquipmentShield     (Equipment::Tier tier);

        const sf::RectangleShape& getBodySprite() const;

        void moveLegs       (float dt);

        std::array<Equippable, (unsigned)Equipment::Type::NUM_TYPES> m_equipment;

        sf::RectangleShape m_legs;

        Animation m_legsAnimation;

        Sword m_sword;
};

#endif // PLAYER_H_INCLUDED
