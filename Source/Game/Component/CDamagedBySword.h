#ifndef CDAMAGEDBYSWORD_H_INCLUDED
#define CDAMAGEDBYSWORD_H_INCLUDED

#include <SFML/System/Clock.hpp>

#include "Component.h"

class Player;
class Entity;

namespace Component
{
    class CDamaged_By_Sword : public CBase
    {
        public:
            CDamaged_By_Sword(Entity& entity, float invincibilityTime);

            void update(float dt, Player& player) ;

        private:
            float m_invincibilityTime;
            sf::Clock m_invincibilityTimer;
    };
}

#endif // CDAMAGEDBYSWORD_H_INCLUDED
