#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../../Animation.h"

class World;

class Entity
{
    public:
        virtual void update (World& world, float dt) = 0;

        virtual void draw   () = 0;
};

#endif // ENTITY_H_INCLUDED