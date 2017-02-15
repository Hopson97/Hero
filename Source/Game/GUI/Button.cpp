#include "Button.h"

#include "../../Display.h"

#include <iostream>

namespace GUI
{
    Button::Button(const sf::Vector2f& pos,
                   const sf::Vector2f& size,
                   const sf::Texture& texture,
                   std::function<void(void)> func)
    :   m_function  (func)
    {
        m_sprite.setPosition    (pos);
        m_sprite.setSize        (size);
        m_sprite.setTexture     (&texture);
    }


    void Button::update()
    {
        if (touchingMouse() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_function();
        }
    }

    void Button::draw()
    {
        Display::draw(m_sprite);
    }

    bool Button::touchingMouse()
    {
        return m_sprite.getGlobalBounds().contains(sf::Mouse::getPosition(Display::get()).x,
                                                   sf::Mouse::getPosition(Display::get()).y);
    }


}
