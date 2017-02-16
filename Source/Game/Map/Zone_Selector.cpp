#include "Map_GUI.h"

#include "../../Display.h"

Map_GUI::Zone_Selector::Zone_Selector()
:   m_circle  (50)
{
    m_circle.setFillColor({0, 0, 0, 0});
    m_circle.setOutlineThickness(3);
    m_circle.setOutlineColor({255, 0, 0, 150});
}

void Map_GUI::Zone_Selector::moveTo(const Map_Zone& zone)
{
    m_p_zone = &zone;
    m_circle.setPosition(zone.getPos());
}

void Map_GUI::Zone_Selector::draw()
{
    Display::draw(m_circle);
}

const Map_GUI::Map_Zone& Map_GUI::Zone_Selector::getZone() const
{
    return *m_p_zone;
}

