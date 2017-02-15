#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include <functional>

#include "State_Base.h"

#include "../Game/Player.h"
#include "../Game/Game_Notice.h"
#include "../Game/World.h"
#include "../Game/Map_GUI.h"

enum class Player_State
{
    Roaming,
    Zone_Switch,
};

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
            void roamUpdate         (float dt);
            void zoneSwitchUpdate   (float dt);

            void roamDraw           ();
            void zoneSwitchDraw     ();

            Player      m_player;
            Game_Notice m_notice;
            World       m_world;
            Map_GUI     m_mapGUI;
            Player_State m_playerState = Player_State::Roaming;
    };
}

#endif // PLAYING_STATE_H_INCLUDED
