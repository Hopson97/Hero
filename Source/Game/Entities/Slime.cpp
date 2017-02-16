#include "Slime.h"

#include <iostream>


#include "../Component/CFollowPlayer.h"
#include "../Component/CDamagedBySword.h"

#include "../../Util/Random.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"


Slime::Slime()
:   Entity  (getResources().getTexture(Texture_ID::Entity_Slime),
             {100, 100},
             {(float)Random::integer(0, Display::WIDTH), (float)Random::integer(300, Display::HEIGHT)},
             true)
,   m_p_currentAnimation (&m_animation)
{
    addComponent(std::make_unique<Component::CFollow_Player>    (*this, 25, SPEED));
    addComponent(std::make_unique<Component::CDamaged_By_Sword> (*this, 0.3));

    for (int i = 0 ; i < 4 ; i++)
    {
        m_animation.addFrame({i * 50, 0, 50, 50}, 0.1);
    }
    for (int i = 2 ; i > 0 ; i--)
    {
        m_animation.addFrame({i * 50, 0, 50, 50}, 0.1);
    }
    setTextureRect(m_animation.getFrame());

    for (int i = 0 ; i < 4 ; i++)
    {
        m_damagedAnimation.addFrame({i * 50, 50, 50, 50}, 0.1);
    }
    for (int i = 2 ; i > 0 ; i--)
    {
        m_damagedAnimation.addFrame({i * 50, 50, 50, 50}, 0.1);
    }
}

void Slime::onUpdate(World& world, Player& player, float dt)
{
    switch(getState())
    {
        case Entity_State::Dying:
        case Entity_State::Damaged:
            m_p_currentAnimation = &m_damagedAnimation;
            break;

        case Entity_State::Walking:
            m_p_currentAnimation = &m_animation;
            break;
    }

    setTextureRect(m_p_currentAnimation->getFrame());
}

