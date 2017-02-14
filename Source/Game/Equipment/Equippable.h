#ifndef PLAYER_Equipment_H_INCLUDED
#define PLAYER_Equipment_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Equipment_Data.h"

class Equippable
{
    public:
        void setData (const Equipment::Data& data);

        void setUp(const sf::Vector2f&          size,
                   const sf::RectangleShape&    attatchment,
                   const sf::Vector2f&          offset,
                   const sf::Vector2f&          origin = {0, 0});

        void input  ();
        void update ();
        void draw   ();

        const Equipment::Data& getData() const;
        const sf::RectangleShape& getSprite() const;


    private:
        sf::RectangleShape          m_sprite;
        const sf::RectangleShape*   m_p_attatchment;
        sf::Vector2f                m_attatchmentOffset;

        const Equipment::Data*      m_p_data;

        bool m_isSetup = false;
};

#endif // PLAYER_Equipment_H_INCLUDED
