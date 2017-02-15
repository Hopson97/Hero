#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entities/Blacksmith.h"

class Resource_Holder;

class Zone
{
    public:
        Zone();

        void update(World& world, float dt);

        void draw();

    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;

        Blacksmith m_blacksmith;

        std::vector<std::unique_ptr<Entity>> m_entities;
};

#endif // ZONE_H_INCLUDED
