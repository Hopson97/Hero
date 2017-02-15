#include "Blacksmith.h"

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

Blacksmith::Blacksmith()
{
    m_sprite.setSize({200, 230});
    m_sprite.setTexture(&getResources().getTexture(Texture_ID::Entity_Blacksmith));
    m_sprite.setPosition(25, 25);

    for (int i = 0 ; i <= 2 ; i++)
    {
        m_animation.addFrame({i * 50, 0, 50, 50}, 0.2);
    }
    m_animation.addFrame({2 * 50, 0, 50, 50}, 0.2);
    m_sprite.setTextureRect(m_animation.getFrame());
}

void Blacksmith::update(float dt)
{
    m_sprite.setTextureRect(m_animation.getFrame());
}

void Blacksmith::draw()
{
    Display::draw(m_sprite);
}
