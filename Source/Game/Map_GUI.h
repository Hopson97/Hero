#ifndef MAP_GUI_H_INCLUDED
#define MAP_GUI_H_INCLUDED

#include "GUI/Button.h"

class Map_GUI
{
    public:
        Map_GUI();

        void resetBool();
        bool shouldExit();
        void update();
        void draw();

    private:
        sf::RectangleShape m_background;
        GUI::Button m_exitButton;

        bool m_shouldExit;

};

#endif // MAP_GUI_H_INCLUDED
