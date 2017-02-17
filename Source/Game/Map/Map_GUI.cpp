#include "Map_GUI.h"

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Util/General_Maths.h"

#include "../Zone/ZTown.h"
#include "../Zone/ZForest.h"

#include "../Player.h"
#include "../Game_Notice.h"

#include <iostream>

Map_GUI::Map_GUI()
:   m_exitButton({Display::WIDTH - 200, 10},
                 {200, 100},
                 getResources().getTexture(Texture_ID::GUI_Exit_Button),
                 [&]() { m_shouldExit = true; })
{
    m_background.setTexture(&getResources().getTexture(Texture_ID::World_Map));
    m_background.setSize ({Display::WIDTH, Display::HEIGHT});

    m_zones.emplace_back(Zone_ID::Town,
                         sf::Vector2f{13, 0},
                         1);

    m_zones.emplace_back(Zone_ID::Forest,
                         sf::Vector2f{297, 24},
                         1);

    m_selector.moveTo(m_zones.front());
}

void Map_GUI::resetBool()
{
    m_shouldExit = false;
}


bool Map_GUI::shouldExit()
{
    return m_shouldExit;
}

void Map_GUI::update(const Player& player, Game_Notice& notice)
{
    for (auto& zone : m_zones)
    {
        if (Maths::getDistance(sf::Mouse::getPosition(Display::get()), zone.getPos()) < 100)
        {
            if ((player.getLevel() >= zone.getLevelReq()) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)))
                    m_selector.moveTo(zone);
            }
            else
            {
                notice.toggleOn();
                notice.setString("Level " + std::to_string(zone.getLevelReq()) + " required!");
            }
        }
    }

    m_exitButton.update();
}

void Map_GUI::draw()
{
    Display::draw(m_background);
    m_exitButton.draw();
    m_selector  .draw();
}


Zone_ID Map_GUI::getZoneID()
{
    return m_selector.getZone().getID();
}


std::unique_ptr<Zone> Map_GUI::getZone()
{
    switch (m_selector.getZone().getID())
    {
        case Zone_ID::Town:
            return std::make_unique<ZTown>();

        case Zone_ID::Forest:
            return std::make_unique<ZForest>();
    }
    return nullptr;
}
