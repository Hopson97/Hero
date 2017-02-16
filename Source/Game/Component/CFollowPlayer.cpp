#include "CFollowPlayer.h"

#include "../../Util/General_Maths.h"

#include "../Player.h"

namespace Component
{
    CFollow_Player::CFollow_Player(Entity& entity, int minDist, int speed)
    :   CBase               (entity)
    ,   m_minimumDistance   (minDist)
    ,   m_entitySpeed       (speed)
    {

    }

    void CFollow_Player::update(float dt, Player& player)
    {
        if (m_p_entity->getState() == Entity_State::Walking)
        {
            sf::Vector2f vect (player.getPosition().x - m_p_entity->getPosition().x,
                               player.getPosition().y - m_p_entity->getPosition().y);

            auto dist = Maths::getDistance(player.getPosition(), m_p_entity->getPosition());
            Maths::normaliseVector(vect, dist);

            if (dist > m_minimumDistance)
            {
                m_p_entity->movePosition({vect.x * dt * m_entitySpeed, vect.y * dt * m_entitySpeed});
            }

            if (vect.x > 0)
            {
                m_p_entity->flip(1);
            }
            else
            {
                m_p_entity->flip(-1);
            }
        }
    }
}
