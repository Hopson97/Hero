#ifndef GENERAL_MATHS_H_INCLUDED
#define GENERAL_MATHS_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <cmath>

namespace Maths
{
    template<typename T, typename K>
    float getDistance(sf::Vector2<T> v1, sf::Vector2<K> v2)
    {
        int xd = v1.x - v2.x;
        int yd = v1.y - v2.y;

        return std::sqrt(xd * xd + yd * yd);
    }
}

#endif // GENERAL_MATHS_H_INCLUDED
