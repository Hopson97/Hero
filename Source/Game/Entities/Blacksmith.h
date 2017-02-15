#ifndef BLACKSMITH_H_INCLUDED
#define BLACKSMITH_H_INCLUDED

#include "Entity.h"

class Blacksmith : public Entity
{
    public:
        Blacksmith();

        void update (float dt) override;
        void draw   () override;

    private:
        sf::RectangleShape  m_sprite;
        Animation           m_animation;
};

#endif // BLACKSMITH_H_INCLUDED
