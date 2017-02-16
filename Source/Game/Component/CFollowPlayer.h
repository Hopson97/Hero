#ifndef CFOLLOWPLAYER_H_INCLUDED
#define CFOLLOWPLAYER_H_INCLUDED

#include "Component.h"

class Player;
class Entity;

namespace Component
{
    class CFollow_Player : public CBase
    {
        public:
            CFollow_Player(Entity& entity, int minDist, int speed);

            void update(float dt, Player& player) ;

        private:
            int m_minimumDistance;
            int m_entitySpeed;
    };
}
#endif // CFOLLOWPLAYER_H_INCLUDED
