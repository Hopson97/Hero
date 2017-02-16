#ifndef BLACKSMITH_H_INCLUDED
#define BLACKSMITH_H_INCLUDED

#include "Entity.h"

#include "../../Animation.h"

class Blacksmith : public Entity
{
    public:
        Blacksmith();

        void onUpdate (World& world, Player& player, float dt) override;

    private:
        Animation m_animation;
};

#endif // BLACKSMITH_H_INCLUDED
