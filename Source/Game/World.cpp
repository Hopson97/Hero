#include "World.h"

#include <iostream>

#include "Game_Notice.h"

#include "Player.h"
#include "Zone/ZTown.h"

#include "../Util/General_Maths.h"

World::World(Player& player)
:   m_p_player (&player)
{
    m_zone = std::make_unique<ZTown>();
}

void World::input()
{
    m_p_player->input();
}

void World::update(Game_Notice& notice, float dt)
{
    m_p_player->update(*this, dt);
    executeActions();
    m_zone->update(*this, *m_p_player, dt);
}

void World::draw()
{
    m_zone->draw();
    //Don't try to draw stuff before drawing the zone!

    m_p_player->draw();
}

void World::addAction(std::unique_ptr<Action> action)
{
    m_actions.push_back(std::move(action));
}

float World::getDistanceToPlayer(const sf::Vector2f origin)
{
    return Maths::getDistance(m_p_player->getPosition(), origin);
}

Zone_ID World::getZoneID() const
{
    return m_zone->getID();
}


void World::executeActions()
{
    for (auto& action : m_actions)
    {
        action->execute(*this);
    }

    m_actions.clear();
}

void World::setZone(std::unique_ptr<Zone> zone)
{
    m_zone = std::move(zone);
}


