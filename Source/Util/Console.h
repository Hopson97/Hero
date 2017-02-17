#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Console
{
    void hook(sf::Vector2f& vect, std::string name);

    void command(const std::string& command);
}

#endif // CONSOLE_H_INCLUDED
