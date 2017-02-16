#ifndef GENERAL_MATHS_H_INCLUDED
#define GENERAL_MATHS_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <cmath>

namespace Maths
{
    template<typename T, typename K>
    float getDistance(const sf::Vector2<T>& v1, const sf::Vector2<K>& v2)
    {
        int xd = v1.x - v2.x;
        int yd = v1.y - v2.y;

        return std::sqrt(xd * xd + yd * yd);
    }

    template<typename T, typename K>
    void normaliseVector(sf::Vector2<T>& vect, K dist)
    {
        vect.x /= dist;
        vect.y /= dist;
    }
}

#endif // GENERAL_MATHS_H_INCLUDED
