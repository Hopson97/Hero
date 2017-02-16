#include "CDamagedBySword.h"

#include "../../Util/General_Maths.h"

#include "../Player.h"

namespace Component
{
    CDamaged_By_Sword::CDamaged_By_Sword(Entity& entity, float invincibilityTime)
    :   CBase               (entity)
    ,   m_invincibilityTime (invincibilityTime)
    {

    }

    void CDamaged_By_Sword::update(float dt, Player& player)
    {
        auto& sword = player.getSwordEntity();

        if (sword.isSwinging() &&
            m_p_entity->getState() == Entity_State::Walking)
        {
            if (m_p_entity->getSprite().getGlobalBounds().intersects(sword.getBounds()))
            {
                m_p_entity->setState(Entity_State::Damaged);
                m_invincibilityTimer.restart();
            }
        }
        else if (m_p_entity->getState() == Entity_State::Damaged)
        {
            sf::Vector2f vect (player.getPosition().x - m_p_entity->getPosition().x,
                               player.getPosition().y - m_p_entity->getPosition().y);

            auto dist = Maths::getDistance(player.getPosition(), m_p_entity->getPosition());
            Maths::normaliseVector(vect, dist);

            m_p_entity->movePosition(-vect * dt * 150.0f);

            if (m_invincibilityTimer.getElapsedTime().asSeconds() > m_invincibilityTime)
            {
                m_p_entity->setState(Entity_State::Walking);
            }
        }
    }
}
