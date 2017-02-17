#include "Bee.h"

#include <iostream>


#include "../Component/CFollowPlayer.h"
#include "../Component/CDamagedBySword.h"
#include "../Component/CDamagePlayer.h"

#include "../../Util/Random.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"

Bee::Bee()
:   Enemy (getResources().getTexture(Texture_ID::Entity_Bee),
          {100, 100},
          {(float)Random::integer(0, Display::WIDTH), (float)Random::integer(300, Display::HEIGHT)},
           10,    //Health
          {3, 5,  //Coin drop
           8, 10},
           m_animation, m_damagedAnimation) //Exp drop
{
    addComponent(std::make_unique<Component::CFollow_Player>    (*this, 25, 200));
    addComponent(std::make_unique<Component::CDamaged_By_Sword> (*this, 0.5));
    addComponent(std::make_unique<Component::CDamage_Player>    (*this, 0.5, 1, 50));

    for (int i = 0 ; i < 3 ; i++)
    {
        m_animation.addFrame({i * 50, 0, 50, 50}, 0.1);
    }
    for (int i = 2 ; i > 0 ; i--)
    {
        m_animation.addFrame({i * 50, 0, 50, 50}, 0.1);
    }
    setTextureRect(m_animation.getFrame());

    for (int i = 0 ; i < 3 ; i++)
    {
        m_damagedAnimation.addFrame({i * 50, 50, 50, 50}, 0.1);
    }
    for (int i = 2 ; i > 0 ; i--)
    {
        m_damagedAnimation.addFrame({i * 50, 50, 50, 50}, 0.1);
    }

    m_hitSound.setBuffer(getResources().getSound(Sound_ID::Dmg_Bee));
}

Bee::~Bee()
{
    m_hitSound.stop();
}


void Bee::playHitSound()
{
    m_hitSound.play();
}
