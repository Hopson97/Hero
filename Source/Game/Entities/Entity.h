#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../Component/Component.h"
#include "../Health.h"
#include "../Loot.h"

class Zone;
class Player;

enum class Entity_State
{
    Walking,
    Damaged,
    Poll_Death,
    Dying
};

class Entity
{
    public:
        Entity(const sf::Texture& texture,
               const sf::Vector2f& size,
               const sf::Vector2f& position,
               bool center = false,
               int health  = 1,
               const Loot& loot = {0, 0, 0, 0});

        void update(Zone& zone, Player& player, float dt);
        virtual void onUpdate (Zone& zone, Player& player, float dt) = 0;

        virtual ~Entity() = default;

        void draw ();

        bool isDead() const;

        void movePosition(const sf::Vector2f& vec);
        const sf::Vector2f& getPosition() const;

        void flip(int scaleFactor);

        void setState(Entity_State state);
        Entity_State getState() const;

        const sf::RectangleShape& getSprite() const;

        void hit(int dmg);
        const Health& getHealth() const;

        const Loot& getLoot() const;

    protected:
        void addComponent(std::unique_ptr<Component::CBase> comp);

        void setTextureRect(const sf::IntRect& rect);

        virtual void onDamaged(){};
        virtual void whenDying(Zone& zone, Player& player, float dt){};

    private:
        Health m_health;

        bool m_isDead = false;

        sf::RectangleShape m_sprite;
        sf::Vector2f m_position;

        Entity_State m_state = Entity_State::Walking;

        std::vector<std::unique_ptr<Component::CBase>> m_components;

        float m_deathState = 255;

        Loot m_loot;
};

#endif // ENTITY_H_INCLUDED
