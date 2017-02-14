#include "Sword.h"

#include <iostream>

#include "Equippable.h"

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

Sword::Sword(Equippable& sword)
:   m_p_sword (&sword)
{
    for (int i = 0 ; i <= 1 ; i++)
    {
        m_swordAnimation.addFrame({i * 50, 0, 50, 50}, 0);
    }
    sword.setTextureRect(m_swordAnimation.getFrame(0));

    m_slashEffect.setSize({SWORD_SIZE, SWORD_SIZE});
    for (int i = 0 ; i <= 2 ; i++)
    {
        m_slashAnimation.addFrame({i * 50, 0, 50, 50}, 0.1);
    }
    m_slashAnimation.addFrame({0, 0, 50, 50}, 0.15);
    m_slashEffect.setTextureRect(m_slashAnimation.getFrame(0));
}

void Sword::slash()
{
    m_p_sword->setTextureRect(m_slashAnimation.getFrame(1));
    m_isSwinging = true;
    m_slashTimer.restart();
}

void Sword::draw()
{
    if (m_isSwinging)
    {
        Display::draw(m_slashEffect);
    }
}

void Sword::update()
{
    m_slashEffect.setOrigin     (m_p_sword->getSprite().getOrigin   ());
    m_slashEffect.setScale      (m_p_sword->getSprite().getScale    ());
    m_slashEffect.setPosition   (m_p_sword->getSprite().getPosition ());

    if(m_isSwinging)
    {
        m_slashEffect.setTextureRect(m_slashAnimation.getFrame());
        if (m_slashAnimation.isOnFinalFrame())
        {
            m_isSwinging = false;
            m_slashEffect.setTextureRect(m_slashAnimation.getFrame(0));
            m_p_sword->setTextureRect(m_swordAnimation.getFrame(0));
        }
    }
}

bool Sword::isSwinging() const
{
    return m_isSwinging;
}

void Sword::upgrade(Equipment::Tier tier)
{
    switch(tier)
    {
        case Equipment::Tier::Primitive:
            m_slashEffect.setTexture(&getResources().getTexture(Texture_ID::Player_Wood_Slash));
            break;

        case Equipment::Tier::Iron:
            break;

        case Equipment::Tier::Gold:
            break;

        case Equipment::Tier::Magma:
            break;
    }
}


