#ifndef SLIME_H_INCLUDED
#define SLIME_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Entity.h"
#include "../../Animation.h"

class Slime : public Entity
{
    constexpr static int SPEED = 100;

    public:
        Slime();
        ~Slime();

        void onUpdate (World& world, Player& player, float dt) override;

    private:
        void playHitSound() override;

        Animation* m_p_currentAnimation;
        Animation m_animation;
        Animation m_damagedAnimation;

        sf::Sound m_hitSound;
};

#endif // SLIME_H_INCLUDED
