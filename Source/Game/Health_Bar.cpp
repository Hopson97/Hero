#include "Health_Bar.h"

#include <iostream>

#include "Health.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

Health_Bar::Health_Bar(const Health& health, const sf::SoundBuffer& buff)
:   m_p_health  (&health)
{
    m_hitSound.setBuffer(buff);

    m_sprite.setTexture(&getResources().getTexture(Texture_ID::Hearts));
    m_sprite.setSize   ({440, 44});

    for (int i = 10 ; i >= 0 ; i--)
    {
        m_stages.addFrame({0, i * 22, 220, 22}, 0.5);
    }
    m_sprite.setTextureRect(m_stages.getFrame());

    std::cout << m_stages.getNumFrames() << std::endl;
}

void Health_Bar::update()
{
    float h  = m_p_health->getValue();
    float mh = m_p_health->getMaxValue();
    float fr = 11;

    auto val = h / (mh / fr) - 1;
    if (val < 0) val = 0;

    m_sprite.setTextureRect(m_stages.getFrame(val));

    if (m_isPopped &&
        m_popTimer.getElapsedTime().asSeconds() > 0.2)
    {
        m_isPopped = false;
        m_sprite.setScale(1, 1);
        m_sprite.setFillColor(sf::Color::White);
    }
}

void Health_Bar::draw()
{
    Display::draw(m_sprite);
}

void Health_Bar::pop()
{
    if (!m_isPopped)
    {
        m_hitSound.play();
        m_popTimer.restart();
        m_isPopped = true;

        m_sprite.setScale(2, 2);
        m_sprite.setFillColor(sf::Color::Yellow);
    }
}

