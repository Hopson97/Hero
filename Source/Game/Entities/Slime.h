#ifndef SLIME_H_INCLUDED
#define SLIME_H_INCLUDED

#include "Entity.h"
#include "../../Animation.h"

class Slime : public Entity
{
    constexpr static int SPEED = 100;

    public:
        Slime();

        void onUpdate (World& world, Player& player, float dt) override;

    private:
        Animation m_animation;
};

#endif // SLIME_H_INCLUDED
