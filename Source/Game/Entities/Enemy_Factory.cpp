#include "Enemy_Factory.h"

namespace
{
    enum class Enemy_ID
    {
        Slime,
        Bee,

        NUM_ENEMIES
    };
}


Enemy_Factory::Enemy_Factory()
{

}

std::unique_ptr<Entity> Enemy_Factory::makeSlime()
{
}

std::unique_ptr<Entity> Enemy_Factory::makeBee()
{

}

