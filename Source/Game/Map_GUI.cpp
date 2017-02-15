#include "Map_GUI.h"

#include "../Display.h"
#include "../Resource_Managers/Resource_Holder.h"
#include "../Util/General_Maths.h"

#include "Zone/ZTown.h"
#include "Zone/ZForest.h"

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
                         sf::Vector2f{415, 15},
                         1);

    m_zones.emplace_back(Zone_ID::Forest,
                         sf::Vector2f{784, 15},
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

void Map_GUI::update()
{
    for (auto& zone : m_zones)
    {
        if (Maths::getDistance(sf::Mouse::getPosition(Display::get()), zone.getPos()) < 100)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                m_selector.moveTo(zone);
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
}


Map_Zone::Map_Zone (Zone_ID id, const sf::Vector2f& pos, int lvlReq)
:   m_id            (id)
,   m_position      (pos)
,   m_levelRequied  (lvlReq)
{ }

Zone_ID Map_Zone::getID() const
{
    return m_id;
}

sf::Vector2f Map_Zone::getPos() const
{
    return m_position;
}

int Map_Zone::getLevelReq() const
{
    return m_levelRequied;
}


Zone_Selector::Zone_Selector()
:   m_circle  (50)
{
    m_circle.setFillColor({0, 0, 0, 0});
    m_circle.setOutlineThickness(3);
    m_circle.setOutlineColor({255, 0, 0, 150});
}

void Zone_Selector::moveTo(const Map_Zone& zone)
{
    m_p_zone = &zone;
    m_circle.setPosition(zone.getPos());
}

void Zone_Selector::draw()
{
    Display::draw(m_circle);
}

const Map_Zone& Zone_Selector::getZone() const
{
    return *m_p_zone;
}

