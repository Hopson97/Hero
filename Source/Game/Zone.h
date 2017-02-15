#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entities/Entity.h"

class Resource_Holder;
class World;
class Player;

class Zone
{
    public:
        Zone();
        virtual ~Zone() = default;

        void update(World& world, Player& player, float dt);

        void draw();

    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;

        std::vector<std::unique_ptr<Entity>> m_entities;
};

#endif // ZONE_H_INCLUDED
