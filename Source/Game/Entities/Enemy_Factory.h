#ifndef ENEMY_FACTORY_H_INCLUDED
#define ENEMY_FACTORY_H_INCLUDED

#include <memory>

#include "Entity.h"


class Enemy_Factory
{
    public:
        Enemy_Factory();

        std::unique_ptr<Entity> makeSlime ();
        std::unique_ptr<Entity> makeBee   ();

    private:
        std::vector<std::unique_ptr<Entity>> m_entites;
};

#endif // ENEMY_FACTORY_H_INCLUDED
