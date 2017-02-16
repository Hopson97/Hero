#ifndef CDAMAGEPLAYER_H_INCLUDED
#define CDAMAGEPLAYER_H_INCLUDED

#include <SFML/System/Clock.hpp>

#include "Component.h"

class Player;
class Entity;

namespace Component
{
    class CDamage_Player : public CBase
    {
        public:
            CDamage_Player(Entity& entity, float coolDown, int damage, int distance);

            void update(float dt, Player& player) ;

        private:
            float m_coolDown;
            sf::Clock m_coolDownTimer;

            int m_entityDamage;
            int m_distanceToDamage;
    };
}

#endif // CDAMAGEPLAYER_H_INCLUDED
