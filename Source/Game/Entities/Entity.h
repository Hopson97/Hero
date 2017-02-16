#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../Component/Component.h"

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
        const sf::Vector2f& getPosition() const;

    protected:
        void addComponent(std::unique_ptr<Component::CBase> comp);

        void setTextureRect(const sf::IntRect& rect);
        const sf::RectangleShape& getSprite() const;


    private:
        bool m_isDead = false;

        sf::RectangleShape m_sprite;
        sf::Vector2f m_position;

        std::vector<std::unique_ptr<Component::CBase>> m_components;

};

#endif // ENTITY_H_INCLUDED
