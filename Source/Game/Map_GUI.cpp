#include "Map_GUI.h"

#include "../Display.h"
#include "../Resource_Managers/Resource_Holder.h"

#include <iostream>

Map_GUI::Map_GUI()
:   m_exitButton({Display::WIDTH - 200, 10},
                 {200, 100},
                 getResources().getTexture(Texture_ID::GUI_Exit_Button),
                 [&]() { m_shouldExit = true; })
{ }

void Map_GUI::resetBool()
{
    m_shouldExit = false;
}


bool Map_GUI::shouldExit()
{
    return m_shouldExit;
}

void Map_GUI::update()
{
    m_exitButton.update();
}

void Map_GUI::draw()
{
    Display::draw(m_background);
    m_exitButton.draw();
}
