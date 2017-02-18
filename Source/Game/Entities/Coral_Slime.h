#ifndef CORAL_SLIME_H_INCLUDED
#define CORAL_SLIME_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Enemy.h"
#include "../../Animation.h"

class Coral_Slime : public Enemy
{
    constexpr static int SPEED = 100;

    public:
        Coral_Slime();
        ~Coral_Slime();

    private:
        void onDamaged() override;

        Animation m_animation;
        Animation m_damagedAnimation;

        sf::Sound m_hitSound;
};


#endif // CORAL_SLIME_H_INCLUDED
