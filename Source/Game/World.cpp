#include "World.h"

#include "Game_Notice.h"

#include "Player.h"

World::World()
{

}

void World::update(Player& player, Game_Notice& notice, float dt)
{
    m_zone.update(*this, dt);
}

void World::draw()
{
    m_zone.draw();
}
