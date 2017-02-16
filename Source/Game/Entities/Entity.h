#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../../Animation.h"

class World;
class Player;

class Entity
{
    public:
        Entity(const sf::Texture& texture,
               const sf::Vector2f& size,
               const sf::Vector2f& position,
               bool center = false);

        void update(World& world, Player& player, float dt);
        virtual void onUpdate (World& world, Player& player, float dt) = 0;

        void draw ();

        bool isDead() const;

        void movePosition(const sf::Vector2f& vec);

    protected:
        void setTextureRect(const sf::IntRect& rect);

        const sf::RectangleShape& getSprite() const;

        sf::Vector2f m_position;

    private:
        bool m_isDead = false;

        sf::RectangleShape m_sprite;

};

#endif // ENTITY_H_INCLUDED
