#ifndef BEE_H_INCLUDED
#define BEE_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Enemy.h"
#include "../../Animation.h"


class Bee : public Enemy
{
    constexpr static int SPEED = 100;

    public:
        Bee();
        ~Bee();

        void onUpdate(Zone& zone, Player& player, float dt) override;

    private:
        void onDamaged() override;
        void whenDying(Zone& zone, Player& player, float dt) override;

        Animation m_animation;
        Animation m_damagedAnimation;

        sf::Sound m_hitSound;

        sf::Clock m_projectileTimer;
};

#endif // BEE_H_INCLUDED
