#ifndef ZTOWN_H_INCLUDED
#define ZTOWN_H_INCLUDED

#include "Zone.h"

class ZTown : public Zone
{
    public:
        ZTown();

        void onUpdate (World& world, Player& player, float dt) override;
        void onDraw   () override;

    private:

};

#endif // ZTOWN_H_INCLUDED
