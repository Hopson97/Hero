#include "ZBeach.h"

#include "../../Resource_Managers/Resource_Holder.h"
#include "../Player.h"

#include "../Entities/Coral_Slime.h"

#include "../../Util/Random.h"

ZBeach::ZBeach()
:   Zone (getResources().getTexture(Texture_ID::Zone_Beach), Zone_ID::Beach)
{

}

void ZBeach::onUpdate(World& world, Player& player, float dt)
{
    m_enemyCount -= checkForDeadEntities(player);

    static sf::Clock clock;

    if (m_enemyCount < 10)
    //if (clock.getElapsedTime().asSeconds() > 0.5)
    {
        addEnemy();
        clock.restart();
    }
}

void ZBeach::onDraw()
{

}

void ZBeach::addEnemy()
{
    m_enemyCount++;
    addEntity(std::make_unique<Coral_Slime>());
}
