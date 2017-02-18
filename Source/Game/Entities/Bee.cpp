#include "Bee.h"

#include <iostream>


#include "../Component/CFollowPlayer.h"
#include "../Component/CDamagedBySword.h"
#include "../Component/CDamagePlayer.h"

#include "../../Util/General_Maths.h"
#include "../../Util/Random.h"
#include "../../Resource_Managers/Resource_Holder.h"
#include "../../Display.h"

#include "../Player.h"
#include "../Zone/Zone.h"

Bee::Bee()
:   Enemy (getResources().getTexture(Texture_ID::Entity_Bee),
          {100, 100},
          {(float)Random::integer(0, Display::WIDTH), (float)Random::integer(180, Display::HEIGHT)},
           5,        //Health
          {1, 1,      //Coin drop
           1, 1},    //Exp drop
           m_animation, m_damagedAnimation) //Exp drop
{
    addComponent(std::make_unique<Component::CFollow_Player_AI> (*this, 25, 200, 400));
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

void Bee::onUpdate(Zone& zone, Player& player, float dt)
{
    Enemy::onUpdate(zone, player, dt);

    if(Maths::getDistance(getPosition(), player.getPosition()) <= 400 &&
       m_projectileTimer.getElapsedTime().asSeconds() > 10)
    {
        zone.addProjectile(sf::Vector2f{getPosition().x,
                                        getPosition().y + getSprite().getLocalBounds().height / 2},
                           player.getPosition(),
                           sf::Vector2f{ 25, 25},
                           getResources().getTexture(Texture_ID::Proj_Stinger),
                           5,
                           400);
        m_projectileTimer.restart().asSeconds();
    }
}


Bee::~Bee()
{
    m_hitSound.stop();
}


void Bee::onDamaged()
{
    m_hitSound.play();
}

void Bee::whenDying(Zone& zone, Player& player, float dt)
{ }
