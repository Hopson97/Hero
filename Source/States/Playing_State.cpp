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
    { }

    void Playing::input(const sf::Event& e)
    { }

    void Playing::input()
    {
        m_world.input();
    }

    void Playing::update(float dt)
    {
/*
        std::cout << " X: " << sf::Mouse::getPosition(Display::get()).x
                  << " Y: " << sf::Mouse::getPosition(Display::get()).y
                  << "\n";
*/
        m_notice.update();

        switch(m_playerState)
        {
            case Player_State::Roaming:
                roamUpdate(dt);
                break;

            case Player_State::Zone_Switch:
                zoneSwitchUpdate(dt);
                break;
        }
    }

    void Playing::draw()
    {
        switch(m_playerState)
        {
            case Player_State::Roaming:
                roamDraw();
                break;

            case Player_State::Zone_Switch:
                zoneSwitchDraw();
                break;
        }
        m_notice.draw();
    }


    void Playing::roamUpdate(float dt)
    {
       m_world.update (m_notice, dt);

        if (m_player.getPosition().x >= Display::WIDTH  - 200 &&
            m_player.getPosition().y <= 200)
        {
            m_notice.setString("Press space to interact!");
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                m_playerState = Player_State::Zone_Switch;
                m_mapGUI.resetBool();
            }
        }
    }

    void Playing::roamDraw()
    {
        m_world.draw ();
    }

    void Playing::zoneSwitchUpdate(float dt)
    {
        m_mapGUI.update(m_player, m_notice);
        if (m_mapGUI.shouldExit())
        {
            if (m_mapGUI.getZoneID() != m_world.getZoneID())
            {
                std::cout << "not" << std::endl;
                m_world.setZone(std::move(m_mapGUI.getZone()));
            }
            //get zone
            //set zone
            m_playerState = Player_State::Roaming;
        }
    }


    void Playing::zoneSwitchDraw()
    {
        m_mapGUI.draw();
    }
}
