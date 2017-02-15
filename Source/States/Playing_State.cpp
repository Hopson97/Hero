#include "Playing_State.h"

#include "../Resource_Managers/Resource_Manager.h"
#include "../Application.h"
#include "../Display.h"

#include <iostream>

namespace State
{
    Playing::Playing(Application& application)
    :   State_Base  (application)
    ,   m_player    ()
    ,   m_zone      ()
    {
        m_notice.setString("Press space to interact.");
    }

    void Playing::input(const sf::Event& e)
    {

    }

    void Playing::input()
    {
        m_player.input();
    }

    void Playing::update(float dt)
    {
        m_player.update(dt);
        m_zone.update(dt);

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
        m_zone.draw();
        m_player.draw();
        m_notice.draw();
    }

}
