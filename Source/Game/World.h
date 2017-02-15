#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include <memory>

#include "Entities/Entity.h"
#include "Zone.h"
#include "Action/Action.h"

class Player;
class Game_Notice;

class World
{
    public:
        World(Player& player);

        void input  ();
        void update (Game_Notice& notice, float dt);
        void draw   ();

        void addAction(std::unique_ptr<Action> action);

        float getDistanceToPlayer(const sf::Vector2f origin);

        void pause      ();
        void resume     ();
        bool isPaused   () const;

    private:
        void executeActions ();

        std::vector<std::unique_ptr<Action>> m_actions;
        Zone m_zone;
        Player* m_p_player = nullptr;

        bool m_isPaused;


};

#endif // WORLD_H_INCLUDED
