#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <SFML/Audio/Sound.hpp>

#include "Entity.h"
#include "../../Animation.h"


class Enemy : public Entity
{
    constexpr static int SPEED = 100;

    public:
        Enemy( const sf::Texture& texture,
               const sf::Vector2f& size,
               const sf::Vector2f& position,
               bool center = false,
               int health  = 1,
               int coinDropLow = 1,
               int coinDropHigh = 2,
               int expGainLow = 1,
               int expGainHigh = 2);

        ~Enemy();

        void onUpdate (World& world, Player& player, float dt) override;

    private:
        void playHitSound() override;

        Animation* m_p_currentAnimation;
        Animation* m_animation;
        Animation* m_damagedAnimation;

        sf::Sound m_hitSound;
};

#endif // ENEMY_H_INCLUDED
