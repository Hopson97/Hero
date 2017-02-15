#include "Map_GUI.h"

#include "../Display.h"
#include "../Resource_Managers/Resource_Holder.h"

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
    std::cout   << "X: "  << sf::Mouse::getPosition(Display::get()).x
                << " Y: " << sf::Mouse::getPosition(Display::get()).y
                << "\n";

    m_exitButton.update();
}

void Map_GUI::draw()
{
    Display::draw(m_background);
    m_exitButton.draw();
    m_selector  .draw();
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
:   m_selector  (50)
{
    m_selector.setFillColor({0, 0, 0, 0});
    m_selector.setOutlineThickness(3);
    m_selector.setOutlineColor({255, 0, 0, 150});
}

void Zone_Selector::moveTo(const Map_Zone& zone)
{
    m_p_zone = &zone;
    m_selector.setPosition(zone.getPos());
}

void Zone_Selector::draw()
{
    Display::draw(m_selector);
}

const Map_Zone& Zone_Selector::getZone() const
{
    return *m_p_zone;
}

