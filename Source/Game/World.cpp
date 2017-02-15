#include "World.h"

#include <iostream>

#include "Game_Notice.h"

#include "Player.h"

World::World(Player& player)
:   m_p_player (&player)
{ }

void World::input()
{
    m_p_player->input();
}

void World::update(Game_Notice& notice, float dt)
{
    m_p_player->update(*this, dt);
    executeActions();
    m_zone.update(*this, *m_p_player, dt);
}

void World::draw()
{
    m_zone.draw();
    //Don't try to draw stuff before drawing the zone!

    m_p_player->draw();
}

void World::addAction(std::unique_ptr<Action> action)
{
    m_actions.push_back(std::move(action));
}

float World::getDistanceToPlayer(const sf::Vector2f origin)
{
    auto xd     = m_p_player->getPosition().x - origin.x;
    auto yd     = m_p_player->getPosition().y - origin.y;
    auto result = std::sqrt(xd * xd + yd * yd);

    return result;
}

void World::executeActions()
{
    for (auto& action : m_actions)
    {
        action->execute(*this);
    }

    m_actions.clear();
}


