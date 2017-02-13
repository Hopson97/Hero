#include "Player.h"

#include <cmath>
#include <iostream>

#include "../Display.h"
#include "../Resource_Managers/Resource_Holder.h"

Player::Player()
{
    initPart(m_legs);
    initPart(m_body);
    initPart(m_head);

    m_shield.setSize({75, 75});
    m_shield.setOrigin(m_body.getOrigin().x - BODY_SIZE / 3, m_body.getOrigin().y);

    m_sword.setSize({75, 75});
    m_sword.setOrigin(m_body.getOrigin().x - BODY_SIZE / 5, m_body.getOrigin().y);

    m_legs      .setTexture(&getResources().getTexture(Texture_ID::Player_Legs        ));
    m_body      .setTexture(&getResources().getTexture(Texture_ID::Player_Body_Shirt  ));
    m_head      .setTexture(&getResources().getTexture(Texture_ID::Player_Head_None   ));
    m_shield    .setTexture(&getResources().getTexture(Texture_ID::Player_Shield_Wood ));

    for (int i = 0 ; i <= 2 ; i++)
    {
        m_legsAnimation.addFrame({i * 50, 0, 50, 40}, 0.05);
    }
    m_legsAnimation.addFrame({2 * 50, 0, 50, 40}, 0.05);

    m_legs.setTextureRect(m_legsAnimation.getFrame());

}

void Player::update(float dt)
{
    testForFlip();
    moveLegs(dt);
    setBodyPosition();
}

void Player::draw()
{
    Display::draw(m_legs);
    Display::draw(m_body);
    Display::draw(m_head);
    Display::draw(m_shield);
}

void Player::initPart(sf::RectangleShape& shape)
{
     shape.setSize({BODY_SIZE, BODY_SIZE});

    auto rect = shape.getLocalBounds();

    shape.setOrigin( rect.left + rect.width  / 2.0f,
                     rect.top  + rect.height / 2.0f);
}

void Player::testForFlip()
{
    auto mousePos   = sf::Mouse::getPosition(Display::get()).x;
    auto playerPos  = m_legs.getPosition().x;

    if (mousePos > playerPos)
    {
        m_legs.setScale     (1, 1);
        m_body.setScale     (1, 1);
        m_head.setScale     (1, 1);
        m_shield.setScale   (1, 1);
    }
    else
    {
        m_legs.setScale     (-1, 1);
        m_body.setScale     (-1, 1);
        m_head.setScale     (-1, 1);
        m_shield.setScale   (-1, 1);
    }
}

void Player::moveLegs(float dt)
{
    auto mousePos   = sf::Mouse::getPosition(Display::get());
    auto playerPos  = sf::Vector2f(m_legs.getPosition().x,
                                   m_legs.getPosition().y - (BODY_SIZE));

    auto xd = mousePos.x - playerPos.x;
    auto yd = mousePos.y - playerPos.y;

    auto dist = std::sqrt(xd * xd + yd * yd);

    if (dist > 25)
    {
        m_legs.setTextureRect(m_legsAnimation.getFrame());
        m_legs.move(xd * dt * SPEED, yd * dt * SPEED);
    }
    else
    {
        m_legs.setTextureRect({0, 0, 50, 40});
    }
}


void Player::setBodyPosition()
{
    m_body.setPosition(m_legs.getPosition().x, m_legs.getPosition().y - BODY_SIZE);
    m_head.setPosition(m_body.getPosition().x, m_body.getPosition().y - BODY_SIZE);

    m_shield.setPosition(m_body.getPosition().x, m_body.getPosition().y + 10);
}
