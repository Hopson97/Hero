#ifndef CFOLLOWPLAYER_H_INCLUDED
#define CFOLLOWPLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Component.h"

class Player;
class Entity;

namespace Component
{
    class CFollow_Player_AI : public CBase
    {
        public:
            CFollow_Player_AI(Entity& entity, int minDist, int speed, int minDistToFollow);

            void update(float dt, Player& player) ;

        private:
            sf::Vector2f getVect();
            void tryFlip(const sf::Vector2f& vect);

            int m_minimumDistance;
            int m_entitySpeed;
            int m_distToFollow;

            sf::Clock       m_actionTimer;
            sf::Vector2f    m_target;
    };
}
#endif // CFOLLOWPLAYER_H_INCLUDED
