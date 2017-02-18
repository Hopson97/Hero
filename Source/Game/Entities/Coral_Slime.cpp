#include "Coral_Slime.h"

#include "Slime.h"

#include <iostream>


#include "../Component/CFollowPlayer.h"
#include "../Component/CDamagedBySword.h"
#include "../Component/CDamagePlayer.h"

#include "../../Util/Random.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"


Coral_Slime::Coral_Slime()
:   Enemy  (getResources().getTexture(Texture_ID::Entity_Coral_Slime),
             {50, 50},
             {(float)Random::integer(0, Display::WIDTH), (float)Random::integer(0, Display::HEIGHT)},
             17,        //Health
             {3, 7,     //Coin drop
             5, 6},    //Exp drop
             m_animation, m_damagedAnimation)
{
    m_hitSound.setBuffer(getResources().getSound(Sound_ID::Dmg_Slime));

    addComponent(std::make_unique<Component::CFollow_Player_AI> (*this, 30, 175, 500));
    addComponent(std::make_unique<Component::CDamaged_By_Sword> (*this, 0.4));
    addComponent(std::make_unique<Component::CDamage_Player>    (*this, 0.5, 5, 50));


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

Coral_Slime::~Coral_Slime()
{
    m_hitSound.stop();
}


void Coral_Slime::onDamaged()
{
    m_hitSound.play();
}
