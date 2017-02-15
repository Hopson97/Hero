#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Entities/Blacksmith.h"

class Resource_Holder;

class Zone
{
    public:
        Zone();

        void update(float dt);

        void draw();

    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;

        Blacksmith m_blacksmith;
};

#endif // ZONE_H_INCLUDED
