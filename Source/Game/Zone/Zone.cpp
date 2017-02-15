#include "Zone.h"

#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"

#include "../Entities/Blacksmith.h"
#include "../World.h"

Zone::Zone(const sf::Texture& background)
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
        entity->update(world, player, dt);
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
    onDraw();
}

int Zone::checkForDeadEntities()
{
    int count;
    for (auto itr = m_entities.begin(); itr != m_entities.end() ; )
    {
        if ((*itr)->isDead())
        {
            count++;
            itr = m_entities.erase(itr);
        }
        else
        {
            itr++;
        }
    }
    return count;
}


void Zone::addEntity(std::unique_ptr<Entity> entity )
{
    m_entities.push_back(std::move(entity));
}
