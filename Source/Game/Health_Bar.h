#ifndef HEALTH_BAR_H_INCLUDED
#define HEALTH_BAR_H_INCLUDED


#include <SFML/Graphics.hpp>

#include "../Animation.h"

class Health;

class Health_Bar
{
    public:
        Health_Bar(const Health& health);

        void update     ();
        void draw       ();

    private:
        const Health*   m_p_health;
        Animation       m_stages;
        sf::RectangleShape m_sprite;
};

#endif // HEALTH_BAR_H_INCLUDED
