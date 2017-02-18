#include "Zone.h"

#include <iostream>

#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"

#include "../Entities/Blacksmith.h"
#include "../World.h"
#include "../Player.h"

Zone::Zone(const sf::Texture& background, Zone_ID id)
:   m_id (id)
{
    m_background.setSize({(float)Display::get().getSize().x,
                          (float)Display::get().getSize().y});

    m_shakeGround.setSize({(float)Display::get().getSize().x,
                           (float)Display::get().getSize().y});

    m_background  .setTexture(&background);
    m_shakeGround .setTexture(&background);
}

void Zone::update(World& world, Player& player, float dt)
{
    for (auto& entity : m_entities)
    {
        entity->update(*this, player, dt);
    }

    for (auto projectile = m_projetiles.begin() ; projectile != m_projetiles.end() ; )
    {
        projectile->update(player, dt);

        if(projectile->isDead())
        {
            projectile = m_projetiles.erase(projectile);
        }
        else
        {
            projectile++;
        }
    }
    onUpdate(world, player, dt);
}

void Zone::draw()
{
    Display::draw(m_background);
    Display::draw(m_shakeGround);

    for (auto& entity : m_entities)
    {
        entity->draw();
    }
    for(auto& projectile : m_projetiles)
    {
        projectile.draw();
    }
    onDraw();
}

Zone_ID Zone::getID() const
{
    return m_id;
}


int Zone::checkForDeadEntities(Player& player)
{
    int count = 0;
    for (auto itr = m_entities.begin(); itr != m_entities.end() ; )
    {
        auto& entity = *itr;

        if ((*itr)->isDead())
        {
            count++;
            player.addExp   (entity->getLoot().getExp ());
            player.addCoins (entity->getLoot().getCoin());

            itr = m_entities.erase(itr);
        }
        else
        {
            itr++;
        }
    }
    return count;
}

bool Zone::entityDamaged()
{
    for (auto& entity : m_entities)
    {
        if (entity->getState() == Entity_State::Damaged)
        {
            return true;
        }
    }
    return false;
}



void Zone::addEntity(std::unique_ptr<Entity> entity )
{
    m_entities.push_back(std::move(entity));
}
