#include "CDamagePlayer.h"

#include "../../Util/General_Maths.h"
#include "../Player.h"

namespace Component
{
    CDamage_Player::CDamage_Player(Entity& entity, float coolDown, int damage, int distance)
    :   CBase               (entity)
    ,   m_coolDown          (coolDown)
    ,   m_entityDamage      (damage)
    ,   m_distanceToDamage  (distance)
    { }

    void CDamage_Player::update(float dt, Player& player)
    {
        if (Maths::getDistance(player.getPosition(), m_p_entity->getPosition()) < m_distanceToDamage)
        {
            if (m_coolDownTimer.getElapsedTime().asSeconds() > m_coolDown)
            {
                player.hit(m_entityDamage);
                m_coolDownTimer.restart();
            }
        }
    }
}
