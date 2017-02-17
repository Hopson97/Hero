#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Player;

class Projectile
{
    public:
        Projectile(const sf::Vector2f& origin, const sf::Vector2f& target,
                   const sf::Vector2f& size,
                   const sf::Texture& texture,
                   int damage,
                   int speed);

        void update(Player& player, float dt);

        void draw() const;

        bool isDead() const;

    private:
        sf::RectangleShape m_sprite;
        sf::Vector2f m_velocity;

        int m_damage;
        int m_speed;

        bool m_isDead;

};

#endif // PROJECTILE_H_INCLUDED
