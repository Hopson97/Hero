#include "Zone.h"

#include "../Resource_Managers/Resource_Holder.h"
#include "../Display.h"

#include "Entities/Blacksmith.h"
#include "World.h"

Zone::Zone()
{
    m_background.setSize({(float)Display::get().getSize().x,
                          (float)Display::get().getSize().y});

    m_shakeGround.setSize({(float)Display::get().getSize().x,
                           (float)Display::get().getSize().y});

    m_background  .setTexture(&getResources().getTexture(Texture_ID::Zone_Village));
    m_shakeGround .setTexture(&getResources().getTexture(Texture_ID::Zone_Village));

    m_entities.push_back(std::make_unique<Blacksmith>());
}

void Zone::update(World& world, Player& player, float dt)
{
    if (!world.isPaused())
    {
        for (auto& entity : m_entities)
        {
            entity->update(world, player, dt);
        }
    }
}



void Zone::draw()
{
    Display::draw(m_background);
    Display::draw(m_shakeGround);

    for (auto& entity : m_entities)
    {
        entity->draw();
    }
}
