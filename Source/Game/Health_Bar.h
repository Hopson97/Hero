#ifndef HEALTH_BAR_H_INCLUDED
#define HEALTH_BAR_H_INCLUDED


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Animation.h"

class Health;

class Health_Bar
{
    public:
        Health_Bar(const Health& health, const sf::SoundBuffer& buff);

        void update     ();
        void draw       ();

        void pop        ();

    private:
        const Health*   m_p_health;
        Animation       m_stages;
        sf::RectangleShape m_sprite;

        bool m_isPopped;
        sf::Clock m_popTimer;
        sf::Sound m_hitSound;
};

#endif // HEALTH_BAR_H_INCLUDED
