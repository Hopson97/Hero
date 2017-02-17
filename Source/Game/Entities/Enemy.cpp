#include "Enemy.h"

Enemy::Enemy(const sf::Texture& texture,
             const sf::Vector2f& size,
             const sf::Vector2f& position,
             bool center,
             int health,
             int coinDropLow,
             int coinDropHigh,
             int expGainLow,
             int expGainHigh)
:   Entity (texture, size, position, center, health, coinDropLow, coinDropHigh, expGainLow, expGainHigh)
{

}

Enemy::~Enemy()
{

}

void Enemy::onUpdate(World& world, Player& player, float dt)
{

}

void Enemy::playHitSound()
{

}
