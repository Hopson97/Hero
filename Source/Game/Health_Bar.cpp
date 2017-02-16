#include "Health_Bar.h"

#include <iostream>

#include "Health.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

Health_Bar::Health_Bar(const Health& health)
:   m_p_health  (&health)
{
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
    m_sprite.setTextureRect(m_stages.getFrame( h / (mh / fr) - 1));
}

void Health_Bar::draw()
{
    Display::draw(m_sprite);
}
