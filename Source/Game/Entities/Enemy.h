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
               int health,
               const Loot& loot,
               Animation& roamAnimation,
               Animation& dmgAnimation );

        ~Enemy();

        virtual void onUpdate (Zone& zone, Player& player, float dt) override;

    private:
        void playHitSound() override;

        Animation** m_p_currentAnimation;
        Animation* m_animation;
        Animation* m_damagedAnimation;

        sf::Sound m_hitSound;
};

#endif // ENEMY_H_INCLUDED
