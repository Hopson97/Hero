#ifndef BEE_H_INCLUDED
#define BEE_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Entity.h"
#include "../../Animation.h"


class Bee : public Entity
{
    constexpr static int SPEED = 100;

    public:
        Bee();
        ~Bee();

        void onUpdate (World& world, Player& player, float dt) override;

    private:
        void playHitSound() override;

        Animation* m_p_currentAnimation;
        Animation m_animation;
        Animation m_damagedAnimation;

        sf::Sound m_hitSound;
};

#endif // BEE_H_INCLUDED
