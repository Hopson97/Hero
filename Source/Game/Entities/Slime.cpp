#include "Slime.h"

#include <iostream>

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

#include "../World.h"

#include "../Player.h"
#include "../../Util/General_Maths.h"

Slime::Slime()
:   Entity  (getResources().getTexture(Texture_ID::Entity_Slime), {50, 50}, {200, 200})
{ }

void Slime::onUpdate(World& world, Player& player, float dt)
{
    auto dx = player.getPosition().x - m_position.x;
    auto dy = player.getPosition().y - m_position.y;

    auto dist = Maths::getDistance(player.getPosition(), m_position);

    dx /= dist;
    dy /= dist;

    if (dist > 25)
    {
        movePosition({dx * dt * SPEED, dy * dt * SPEED});
    }
    else
    {

    }
}

