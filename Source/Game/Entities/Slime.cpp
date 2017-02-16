#include "Slime.h"

#include <iostream>

#include "../../Resource_Managers/Resource_Holder.h"

#include "../Component/CFollowPlayer.h"


Slime::Slime()
:   Entity  (getResources().getTexture(Texture_ID::Entity_Slime), {50, 50}, {200, 200})
{
    addComponent(std::make_unique<Component::CFollow_Player>(*this, 25, SPEED));
}

void Slime::onUpdate(World& world, Player& player, float dt)
{ }

