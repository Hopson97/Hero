#include "Playing_State.h"

#include "../Resource_Managers/Resource_Manager.h"
#include "../Application.h"
#include "../Display.h"

#include <iostream>

namespace State
{
    Playing::Playing(Application& application)
    :   State_Base  (application)
    ,   m_world     (m_player)
    {
        m_notice.setString("Press space to interact.");
    }

    void Playing::input(const sf::Event& e)
    { }

    void Playing::input()
    {
        m_world.input();
    }

    void Playing::update(float dt)
    {
        m_world.update (m_notice, dt);

        if (m_player.getPosition().x >= Display::WIDTH  - 200 &&
            m_player.getPosition().y <= 200)
        {
            m_notice.setString("Press space to interact!");
        }
        else
        {
            m_notice.toggleOff();
        }
    }

    void Playing::draw()
    {
        m_world.draw    ();
        m_notice.draw   ();
    }

}
