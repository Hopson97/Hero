#include "Game_Notice.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

#include <iostream>

Game_Notice::Game_Notice()
{
    m_text.setFont(getResources().getFont(Font_ID::RS));
    m_text.setCharacterSize(20);
    m_text.setPosition(10, 6);

    m_sprite.setSize({250, 28});
    m_sprite.setPosition(5, 5);
    m_sprite.setOutlineThickness(2);
    m_sprite.setOutlineColor(sf::Color::Black);
    m_sprite.setFillColor({50, 255, 255, 190});
}

void Game_Notice::setString(std::string message)
{
    if (message.length() > 23) //Max for one line
    {
        std::string sub1 = message.substr(0, 23);
        std::string sub2 = message.substr(24, message.length() - 1);

        message = sub1 + "\n" + sub2;
    }
    m_text.setString(std::move(message));
    toggleOn();
}

void Game_Notice::toggleOn  ()  { m_canDraw = true;  }
void Game_Notice::toggleOff ()  { m_canDraw = false; }

bool Game_Notice::canDraw() const { return m_canDraw; }

void Game_Notice::draw()
{
    if (canDraw())
    {
        Display::draw(m_sprite);
        Display::draw(m_text);

    }
}
