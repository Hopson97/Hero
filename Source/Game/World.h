#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "Entities/Entity.h"

#include "../Game/Zone.h"

class Player;
class Game_Notice;

class World
{
    public:
        World();

        void update (Player& player, Game_Notice& notice, float dt);
        void draw   ();

    private:
        Zone m_zone;
};

#endif // WORLD_H_INCLUDED
