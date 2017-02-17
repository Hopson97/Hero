#include "Stat_Level.h"

#include <iostream>


Stat_Level::Stat_Level(int start)
{

}

void Stat_Level::addExp(int exp)
{
    m_currentXP += exp;

    auto overLoad = m_currentXP - m_expForNextLevel;

    if (overLoad >= 0)
    {
        m_expForNextLevel *= 1.35;
        m_currentXP = overLoad;
        m_level++;
        m_hasLeveledUp = true;
        std::cout << "Leveled up!" << std::endl;
    }
}

int Stat_Level::getLevel() const
{
    return m_level;
}

int Stat_Level::getExp() const
{
    return m_currentXP;
}

int Stat_Level::getExpForNextLevel() const
{
    return m_expForNextLevel;
}

bool Stat_Level::hasLeveledUp()
{
    if (m_hasLeveledUp)
    {
        m_hasLeveledUp = false;
        return true;
    }
    return false;
}

