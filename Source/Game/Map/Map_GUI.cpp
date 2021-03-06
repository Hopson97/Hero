#include "Map_GUI.h"

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Util/General_Maths.h"

#include "../Zone/ZTown.h"
#include "../Zone/ZForest.h"
#include "../Zone/ZBeach.h"

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

    m_zones.emplace_back(Zone_ID::Beach,
                         sf::Vector2f{455, 110},
                         5);

    m_zones.emplace_back(Zone_ID::Mountains,
                         sf::Vector2f{908, 40},
                         9);

    m_zones.emplace_back(Zone_ID::River,
                         sf::Vector2f{885, 255},
                         14);

    m_zones.emplace_back(Zone_ID::Desert,
                         sf::Vector2f{967, 390},
                         20);

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
            if ((player.getLevel().getLevel() >= zone.getLevelReq()))
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

        case Zone_ID::Beach:
            return std::make_unique<ZBeach>();
            break;

        case Zone_ID::Mountains:
            break;

        case Zone_ID::River:
            break;

        case Zone_ID::Desert:
            break;
    }
    return nullptr;
}
