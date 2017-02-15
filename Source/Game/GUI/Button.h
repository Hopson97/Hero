#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <functional>
#include <SFML/Graphics.hpp>

namespace GUI
{
    class Button
    {
        public:
            Button(const sf::Vector2f& pos,
                   const sf::Vector2f& size,
                   const sf::Texture& texture,
                   std::function<void(void)> func);

            void update ();
            void draw   ();

        private:
            bool touchingMouse();

            std::function<void(void)>   m_function;
            sf::RectangleShape          m_sprite;
    };
}

#endif // BUTTON_H_INCLUDED
