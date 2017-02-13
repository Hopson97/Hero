#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Animation.h"

class Resource_Holder;

class Player
{
    constexpr static int BODY_SIZE  = 100;
    constexpr static int SPEED      = 2;

    public:
        Player();

        void update(float dt);

        void draw();


    private:
        void initPart(sf::RectangleShape& shape);

        void testForFlip    ();
        void moveLegs       (float dt);
        void setBodyPosition();


        sf::RectangleShape m_legs;
        sf::RectangleShape m_body;
        sf::RectangleShape m_head;
        sf::RectangleShape m_shield;
        sf::RectangleShape m_sword;

        Animation m_legsAnimation;
};

#endif // PLAYER_H_INCLUDED
