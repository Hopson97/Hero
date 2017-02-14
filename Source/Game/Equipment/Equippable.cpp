#include "Equippable.h"

#include <iostream>

#include "../../Display.h"


void Equippable::setData(const Equipment::Data& data)
{
    m_p_data = &data;
    m_sprite.setTexture(&m_p_data->getTexture());
}


void Equippable::setUp( const sf::Vector2f&          size,
                        const sf::RectangleShape&    attatchment,
                        const sf::Vector2f&          offset,
                        const sf::Vector2f&          origin)
{
    if(!m_isSetup)
    {
        m_sprite.setSize(size);

        m_p_attatchment     = &attatchment;
        m_attatchmentOffset = offset;
        m_isSetup = true;

        if (origin == sf::Vector2f{0, 0})
        {
            auto rect = m_sprite.getLocalBounds();
            m_sprite.setOrigin(rect.left  + rect.width / 2.0f,
                               m_sprite.getOrigin().y);
        }
        else
        {
            m_sprite.setOrigin(origin);
        }
    }
}

void Equippable::input()
{
    if (sf::Mouse::getPosition(Display::get()).x > m_sprite.getPosition().x)
    {
        m_sprite.setScale(1, 1);
    }
    else
    {
        m_sprite.setScale(-1, 1);
    }
}


void Equippable::update()
{
    m_sprite.setPosition(m_p_attatchment->getPosition() + m_attatchmentOffset);
}

void Equippable::draw()
{
    Display::draw(m_sprite);
}


const Equipment::Data& Equippable::getData      ()  const
{ return *m_p_data; }


const sf::RectangleShape& Equippable::getSprite ()  const
{ return m_sprite;  }

void Equippable::setTextureRect(const sf::IntRect& rect)
{ m_sprite.setTextureRect(rect); }

