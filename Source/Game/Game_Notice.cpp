#include "Game_Notice.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

#include <iostream>

Game_Notice::Game_Notice()
{
    m_sprite.setSize({250, 28});
    m_sprite.setPosition(Display::WIDTH / 2 - m_sprite.getLocalBounds().width / 2, 10);
    m_sprite.setOutlineThickness(3);
    m_sprite.setOutlineColor(sf::Color::Black);
    m_sprite.setFillColor({80, 0, 255, 225});

    m_text.setFont(getResources().getFont(Font_ID::RS));
    m_text.setCharacterSize(20);
    m_text.setPosition(m_sprite.getPosition().x + 5, 12);
}

void Game_Notice::setString(std::string message)
{
    m_text.setString(std::move(message));
    toggleOn();
}

void Game_Notice::update()
{
    if (m_canDraw && m_timer.getElapsedTime().asSeconds() >= 1.8f)
    {
        m_canDraw = false;
    }
}



void Game_Notice::toggleOn  ()
{
    m_canDraw = true;
    m_timer.restart().asSeconds();
}

bool Game_Notice::canDraw() const { return m_canDraw; }

void Game_Notice::draw()
{
    if (canDraw())
    {
        Display::draw(m_sprite);
        Display::draw(m_text);

    }
}
