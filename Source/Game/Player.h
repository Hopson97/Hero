#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <array>

#include "../Animation.h"

#include "Equipment/Equippable.h"
#include "Equipment/Sword.h"

#include "Entities/Entity.h"

#include "Health_Bar.h"
#include "Health.h"

class Resource_Holder;

class Player
{
    constexpr static int BODY_SIZE  = 95;
    constexpr static int SPEED      = 2;

    public:
        Player();

        void input  ();
        void update (World& world, float dt);
        void draw   ();

        void setPosition(const sf::Vector2f&);

        const sf::Vector2f& getPosition () const;

        void setEquipmentBody       (Equipment::Tier tier);
        void setEquipmentHeadgear   (Equipment::Tier tier);
        void setEquipmentSword      (Equipment::Tier tier);
        void setEquipmentShield     (Equipment::Tier tier);

        const Equippable& getBody       () const;
        const Equippable& getHeadgear   () const;
        const Equippable& getSword      () const;
        const Equippable& getShield     () const;

        const Sword& getSwordEntity     () const;

        void hit(int dmg);

    private:
        void moveLegs (float dt);

        std::array<Equippable, (unsigned)Equipment::Type::NUM_TYPES> m_equipment;

        sf::RectangleShape m_legs;

        Animation m_legsAnimation;

        Sword m_sword;

        Health m_health;
        Health_Bar m_healthBar;
};

#endif // PLAYER_H_INCLUDED
