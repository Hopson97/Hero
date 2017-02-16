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
    m_enemyCount -= checkForDeadEntities();

    //static sf::Clock clock;

    if (m_enemyCount < 5)
    //if (clock.getElapsedTime().asSeconds() > 0.5)
    {
        addEnemy();
        //clock.restart();
    }
}

void ZForest::onDraw()
{

}

void ZForest::addEnemy()
{
    m_enemyCount++;
    addEntity(std::make_unique<Slime>());
}
