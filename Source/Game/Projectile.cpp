#include "Projectile.h"

#include "../Util/General_Maths.h"
#include "../Display.h"

Projectile::Projectile(const sf::Vector2f& origin,
                       const sf::Vector2f& target,
                       const sf::Vector2f& size,
                       const sf::Texture& texture,
                       int damage,
                       int speed)
:   m_damage    (damage)
,   m_speed     (speed)
{
    auto dist = Maths::getDistance(target, origin);

    m_velocity = { target.x - m_sprite.getPosition().x,
                   target.y - m_sprite.getPosition().x};

    Maths::normaliseVector(m_velocity, dist);
}

void Projectile::update(Player& player, float dt)
{
    m_sprite.move({m_velocity.x * dt * m_speed / 2,
                   m_velocity.y * dt * m_speed / 2});
}

void Projectile::draw() const
{
    Display::draw(m_sprite);
}

bool Projectile::isDead() const
{
    return m_isDead;
}
