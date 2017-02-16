#include "ZForest.h"

#include <iostream>

#include "../../Resource_Managers/Resource_Holder.h"
#include "../Player.h"

#include "../Entities/Slime.h"

ZForest::ZForest()
:   Zone (getResources().getTexture(Texture_ID::Zone_Forest), Zone_ID::Forest)
{

}

void ZForest::onUpdate(World& world, Player& player, float dt)
{
    checkForDeadEntities();
    addEnemy();
}

void ZForest::onDraw()
{

}

void ZForest::addEnemy()
{
    addEntity(std::make_unique<Slime>());
}
