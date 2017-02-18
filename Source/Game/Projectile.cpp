#include "Projectile.h"

#include "../Util/General_Maths.h"
#include "../Display.h"

#include "Player.h"

Projectile::Projectile(const sf::Vector2f& origin,
                       const sf::Vector2f& target,
                       const sf::Vector2f& size,
                       const sf::Texture& texture,
                       int damage,
                       int speed)
:   m_damage    (damage)
,   m_speed     (speed)
{
    m_sprite.setSize        (size);
    m_sprite.setPosition    (origin);
    m_sprite.setTexture     (&texture);

    auto dist = Maths::getDistance(target, origin);

    m_velocity = { target.x - m_sprite.getPosition().x,
                   target.y - m_sprite.getPosition().y};

    Maths::normaliseVector(m_velocity, dist);

    if (m_velocity.x < 0)
    {
        m_sprite.setScale(-1, 1);
    }
}

void Projectile::update(Player& player, float dt)
{
    m_sprite.move({m_velocity.x * dt * m_speed,
                   m_velocity.y * dt * m_speed});

    if (m_sprite.getPosition().x < 0 ||
        m_sprite.getPosition().x > Display::WIDTH ||
        m_sprite.getPosition().y < 0 ||
        m_sprite.getPosition().y > Display::HEIGHT)
    {
        m_isDead = true;
    }

    if (Maths::getDistance(m_sprite.getPosition(), player.getPosition()) < 50)
    {
        m_isDead = true;
        player.hit(m_damage);
    }
}

void Projectile::draw() const
{
    Display::draw(m_sprite);
}

bool Projectile::isDead() const
{
    return m_isDead;
}
