#include "ZTown.h"

#include "../../Resource_Managers/Resource_Holder.h"
#include "../Entities/Blacksmith.h"
#include "../Player.h"

ZTown::ZTown()
:   Zone (getResources().getTexture(Texture_ID::Zone_Village))
{
    addEntity(std::make_unique<Blacksmith>());
}

void ZTown::onUpdate(World& world, Player& player, float dt)
{
    if (player.getPosition().x < 200)
        player.setPosition({200, player.getPosition().y});
}

void ZTown::onDraw()
{

}
