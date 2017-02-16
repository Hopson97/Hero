#include "Blacksmith.h"

#include <iostream>

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

#include "../World.h"

Blacksmith::Blacksmith()
:   Entity  (getResources().getTexture(Texture_ID::Entity_Blacksmith), {255, 255}, {200, 5})
{
    for (int i = 0 ; i <= 2 ; i++)
    {
        m_animation.addFrame({i * 100, 0, 100, 100}, 0.3);
    }
    m_animation.addFrame({100, 0, 100, 100}, 0.3);
    setTextureRect(m_animation.getFrame());
}

void Blacksmith::onUpdate(World& world, Player& player, float dt)
{
    setTextureRect(m_animation.getFrame());

    if (world.getDistanceToPlayer({m_position.x + getSprite().getLocalBounds().width / 1.2f,
                                   m_position.y + getSprite().getLocalBounds().height / 1.2f}) < 50 )
    {

    }

}
