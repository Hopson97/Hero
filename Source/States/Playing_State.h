#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "State_Base.h"

#include "../Animation.h"

#include "../Game/Player.h"
#include "../Game/Zone.h"

namespace State
{
    class Playing : public State_Base
    {
        public:
            Playing (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:
            Player  m_player;
            Zone    m_zone;
    };
}

#endif // PLAYING_STATE_H_INCLUDED
