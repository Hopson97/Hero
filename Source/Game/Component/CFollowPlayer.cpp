#include "CFollowPlayer.h"

#include "../../Util/General_Maths.h"

#include "../Player.h"

#include "../../Util/Random.h"
#include "../../Display.h"

#include "../Entities/Entity.h"


namespace Component
{
    CFollow_Player_AI::CFollow_Player_AI(Entity& entity, int minDist, int speed, int minDistToFollow)
    :   CBase               (entity)
    ,   m_minimumDistance   (minDist)
    ,   m_entitySpeed       (speed)
    ,   m_distToFollow      (minDistToFollow)
    {

    }

    void CFollow_Player_AI::update(float dt, Player& player)
    {
        if (m_p_entity->getState() == Entity_State::Walking)
        {
            auto dist = Maths::getDistance(player.getPosition(), m_p_entity->getPosition());

            if (dist <= m_distToFollow)
            {
                m_target = player.getPosition();

                auto vect = getVect();
                Maths::normaliseVector(vect, dist);

                if (dist > m_minimumDistance)
                {
                    m_p_entity->movePosition({vect.x * dt * m_entitySpeed, vect.y * dt * m_entitySpeed});
                }

                tryFlip(vect);
            }
            else
            {
                if (m_actionTimer.getElapsedTime().asSeconds() > 2.5)
                {
                    m_target = {Random::integer(0, Display::WIDTH), Random::integer(180, Display::HEIGHT)};
                    m_actionTimer.restart();
                }

                auto vect = getVect();
                Maths::normaliseVector(vect, dist);
                m_p_entity->movePosition({vect.x * dt * m_entitySpeed / 2, vect.y * dt * m_entitySpeed / 2});

                tryFlip(vect);
            }
        }
    }

    sf::Vector2f CFollow_Player_AI::getVect()
    {
        return {m_target.x - m_p_entity->getPosition().x,
                m_target.y - m_p_entity->getPosition().y};
    }

    void CFollow_Player_AI::tryFlip(const sf::Vector2f& vect)
    {
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







