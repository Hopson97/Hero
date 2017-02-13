#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Resource_Holder;

class Zone
{
    public:
        Zone();

        void draw();

    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;
};

#endif // ZONE_H_INCLUDED
