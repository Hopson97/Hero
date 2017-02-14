#include "Zone.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

Zone::Zone()
{
    m_background.setSize({(float)Display::get().getSize().x,
                          (float)Display::get().getSize().y});

    m_shakeGround.setSize({(float)Display::get().getSize().x,
                           (float)Display::get().getSize().y});

    m_background  .setTexture(&getResources().getTexture(Texture_ID::Zone_Village));
    m_shakeGround .setTexture(&getResources().getTexture(Texture_ID::Zone_Village));
}

void Zone::draw()
{
    Display::draw(m_background);
    Display::draw(m_shakeGround);
}
