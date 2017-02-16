#include "Map_GUI.h"

Zone_ID Map_GUI::Map_Zone::getID() const
{
    return m_id;
}

sf::Vector2f Map_GUI::Map_Zone::getPos() const
{
    return m_position;
}

int Map_GUI::Map_Zone::getLevelReq() const
{
    return m_levelRequied;
}
