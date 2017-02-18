#include "Entity.h"

#include "../../Display.h"

#include "../../Util/Random.h"

Entity::Entity(const sf::Texture& texture,
               const sf::Vector2f& size,
               const sf::Vector2f& position,
               bool center,
               int health,
               const Loot& loot)
:   m_health        (health)
,   m_position      (position)
,   m_loot          (loot)
{
    m_sprite.setTexture(&texture);
    m_sprite.setSize(size);
    m_sprite.setPosition(position);

    if (center)
    {
        auto rect = m_sprite.getLocalBounds();
        m_sprite.setOrigin(rect.left + rect.width / 2.0f, m_sprite.getOrigin().y);
    }
}

void Entity::update(Zone& zone, Player& player, float dt)
{
    if (m_state != Entity_State::Dying)
    {
        for(auto& comp : m_components)
        {
            comp->update(dt, player);
        }
    }
    else
    {
        m_deathState -= 200 * dt;
        m_sprite.setFillColor({(sf::Uint8)m_deathState,
                               (sf::Uint8)m_deathState,
                               (sf::Uint8)m_deathState,
                               (sf::Uint8)m_deathState});

        if (m_deathState < 50)
        {
            m_isDead = true;
        }
    }

    switch (m_state)
    {
        case Entity_State::Dying:
            whenDying(zone, player, dt);
            break;

        case Entity_State::Walking:
            break;

        case Entity_State::Damaged:
            break;

        case Entity_State::Poll_Death:
            if (m_health.getValue() <= 0)
            {
                m_state = Entity_State::Dying;
            }
            else
            {
                m_state = Entity_State::Walking;
            }
            break;
    }

    onUpdate(zone, player, dt);
    m_sprite.setPosition(m_position);
}



void Entity::draw()
{
    Display::draw(m_sprite);
}

bool Entity::isDead() const { return m_isDead; }


void Entity::movePosition   (const sf::Vector2f& vec)   { m_position += vec;                }
void Entity::setTextureRect (const sf::IntRect& rect)   { m_sprite.setTextureRect(rect);    }
const sf::RectangleShape& Entity::getSprite ()  const   { return m_sprite;                  }
const sf::Vector2f& Entity::getPosition     ()  const   { return m_position;                }


void Entity::flip(int scaleFactor)
{
    m_sprite.setScale(scaleFactor, 1);
}


void Entity::setState(Entity_State state)
{
    m_state = state;
}

Entity_State Entity::getState() const
{
    return m_state;
}


void Entity::hit(int dmg)
{
    onDamaged();
    m_health.damage(dmg);
}

const Health& Entity::getHealth() const
{
    return m_health;
}

void Entity::addComponent(std::unique_ptr<Component::CBase> comp)
{
    m_components.push_back(std::move(comp));
}

const Loot& Entity::getLoot() const
{
    return m_loot;
}


