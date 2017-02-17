#ifndef SLIME_H_INCLUDED
#define SLIME_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Enemy.h"
#include "../../Animation.h"

class Slime : public Enemy
{
    constexpr static int SPEED = 100;

    public:
        Slime();
        ~Slime();

    private:
        void playHitSound() override;

        Animation m_animation;
        Animation m_damagedAnimation;

        sf::Sound m_hitSound;
};

#endif // SLIME_H_INCLUDED
