#include "ZForest.h"

#include "../../Resource_Managers/Resource_Holder.h"
#include "../Player.h"

#include "../Entities/Slime.h"

ZForest::ZForest()
:   Zone (getResources().getTexture(Texture_ID::Zone_Forest), Zone_ID::Forest)
{
    addEntity(std::make_unique<Slime>());
}

void ZForest::onUpdate(World& world, Player& player, float dt)
{

}

void ZForest::onDraw()
{

}

void ZForest::addEnemy()
{

}
