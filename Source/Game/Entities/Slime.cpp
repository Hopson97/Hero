#include "Slime.h"

#include <iostream>


#include "../Component/CFollowPlayer.h"
#include "../Component/CDamagedBySword.h"

#include "../../Util/Random.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"


Slime::Slime()
:   Entity  (getResources().getTexture(Texture_ID::Entity_Slime),
             {50, 50},
             {(float)Random::integer(0, Display::WIDTH), (float)Random::integer(300, Display::HEIGHT)},
             true)

{
    addComponent(std::make_unique<Component::CFollow_Player>    (*this, 25, SPEED));
    addComponent(std::make_unique<Component::CDamaged_By_Sword> (*this, 0.3));
}

void Slime::onUpdate(World& world, Player& player, float dt)
{ }

