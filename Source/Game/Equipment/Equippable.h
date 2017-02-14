#ifndef PLAYER_Equipment_H_INCLUDED
#define PLAYER_Equipment_H_INCLUDED

#include "Equipment_Data.h"

class Equippable
{
    public:
        Equippable   () = default;
        Equippable   (const Equipment::Data& data);

    private:
        const Equipment::Data* m_p_data;
};

#endif // PLAYER_Equipment_H_INCLUDED
