#include "Health.h"

#include <algorithm>

Health::Health(int max)
:   m_value     (max)
,   m_maxValue  (max)
{

}

int Health::getValue() const
{
    return m_value;
}

int Health::getMaxValue() const
{
    return m_maxValue;
}

void Health::damage(int amount)
{
    if (m_damageTimer.getElapsedTime().asSeconds() > 0.2)
    {
        m_damageTimer.restart();
        m_value -= amount;
    }
}

void Health::heal(int amount)
{
    m_value += amount;
    m_value = std::min(m_value, m_maxValue);
}

void Health::setMax(int val)
{
    m_maxValue = val;
}
