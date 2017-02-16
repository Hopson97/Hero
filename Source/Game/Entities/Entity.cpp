#include "Entity.h"

#include "../../Display.h"

Entity::Entity(const sf::Texture& texture,
               const sf::Vector2f& size,
               const sf::Vector2f& position,
               bool center)
:   m_position  (position)
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

void Entity::update(World& world, Player& player, float dt)
{
    for(auto& comp : m_components)
    {
        comp->update(dt, player);
    }

    switch (m_state)
    {
        case Entity_State::Dying:
            break;

        case Entity_State::Walking:
            break;

        case Entity_State::Damaged:
            break;
    }

    onUpdate(world, player, dt);
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



void Entity::addComponent(std::unique_ptr<Component::CBase> comp)
{
    m_components.push_back(std::move(comp));
}


