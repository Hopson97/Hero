#ifndef HEALTH_H_INCLUDED
#define HEALTH_H_INCLUDED

#include <SFML/System/Clock.hpp>

class Health
{
    public:
        Health(int max);

        int getValue    () const;
        int getMaxValue () const;

        void damage (int amount);
        void heal   (int amount);

        void setMax (int val);

    private:
        int m_value = 0;
        int m_maxValue = 0;

        sf::Clock m_damageTimer;

};

#endif // HEALTH_H_INCLUDED
