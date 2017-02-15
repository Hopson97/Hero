#ifndef GAME_NOTICE_H_INCLUDED
#define GAME_NOTICE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Game_Notice
{
    enum class Slide_State
    {
        Slide_In,
        Slide_Out,
        Slided
    };

    public:
        Game_Notice();

        void setString  (std::string message);

        void toggleOn   ();
        void toggleOff  ();

        bool canDraw    () const;

        void draw       ();

    private:
        sf::RectangleShape  m_sprite;
        sf::Text            m_text;

        bool m_canDraw;
};

#endif // GAME_NOTICE_H_INCLUDED
