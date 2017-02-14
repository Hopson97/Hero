#include "Sword.h"

#include "Equippable.h"

Sword::Sword(Equippable& sword)
:   m_p_sword (&sword)
{
    for (int i = 0 ; i <= 1 ; i++)
    {
        m_swordAnimation.addFrame({i * 50, 0, 50, 50}, 0.05);
    }
    sword.setTextureRect({0, 0, 50, 50});
}

void Sword::slash()
{

}

void Sword::draw()
{
    Display::draw(m_slashEffect);
}

void Sword::update()
{

}
