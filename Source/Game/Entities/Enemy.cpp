#include "Enemy.h"

Enemy::Enemy(const sf::Texture& texture,
             const sf::Vector2f& size,
             const sf::Vector2f& position,
             int health,
             const Loot& loot,
             Animation& roamAnimation,
             Animation& dmgAnimation)
:   Entity              (texture, size, position, true, health, loot)
,   m_p_currentAnimation    (&m_animation)
,   m_animation             (&roamAnimation)
,   m_damagedAnimation      (&dmgAnimation)
{

}

Enemy::~Enemy()
{

}

void Enemy::onUpdate(World& world, Player& player, float dt)
{
    switch(getState())
    {
        case Entity_State::Poll_Death:
        case Entity_State::Dying:
        case Entity_State::Damaged:
            m_p_currentAnimation = &m_damagedAnimation;
            break;

        case Entity_State::Walking:
            m_p_currentAnimation = &m_animation;
            break;
    }

    setTextureRect((*m_p_currentAnimation)->getFrame());
}

void Enemy::playHitSound()
{

}


