#ifndef ZBEACH_H_INCLUDED
#define ZBEACH_H_INCLUDED

#include "Zone.h"

class ZBeach : public Zone
{
    public:
        ZBeach();

        void onUpdate (World& world, Player& player, float dt) override;
        void onDraw   () override;

    private:
        void addEnemy();

        int m_enemyCount = 0;
};


#endif // ZBEACH_H_INCLUDED
