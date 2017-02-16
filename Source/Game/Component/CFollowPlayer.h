#ifndef CFOLLOWPLAYER_H_INCLUDED
#define CFOLLOWPLAYER_H_INCLUDED

class Player;
class Entity;

namespace Component
{
    class CFollow_Player
    {
        public:
            void update(Entity& entity, const Player& player);
    };
}
#endif // CFOLLOWPLAYER_H_INCLUDED
