#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "State_Base.h"

#include "../Animation.h"

#include "../Game/Player.h"
#include "../Game/Zone.h"

#include "../Game/Game_Notice.h"

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
            Player      m_player;
            Zone        m_zone;
            Game_Notice m_notice;
    };
}

#endif // PLAYING_STATE_H_INCLUDED
