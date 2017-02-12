#include "Playing_State.h"

#include "../Resource_Managers/Resource_Manager.h"
#include "../Application.h"
#include "../Display.h"

#include <iostream>

namespace State
{
    Playing::Playing(Application& application)
    :   State_Base  (application)
    ,   m_player    (application.getResources())
    ,   m_zone      (application.getResources())
    {
    }

    void Playing::input(const sf::Event& e)
    {

    }

    void Playing::input()
    {

    }

    void Playing::update(float dt)
    {
        m_player.update(dt);
    }

    void Playing::draw()
    {
        m_zone.draw();

        m_player.draw();
    }

}
