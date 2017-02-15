#include "Player.h"

#include <cmath>
#include <iostream>

#include "../Display.h"
#include "../Resource_Managers/Resource_Holder.h"

Player::Player()
:   m_sword         (m_equipment[(int)Equipment::Type::Sword])
{
    m_legs.setPosition(500, 500);

    setEquipmentBody        (Equipment::Tier::Primitive);
    setEquipmentHeadgear    (Equipment::Tier::Primitive);
    setEquipmentSword       (Equipment::Tier::Primitive);
    setEquipmentShield      (Equipment::Tier::Primitive);

    m_equipment[(int)Equipment::Type::Body].setUp({BODY_SIZE, BODY_SIZE}, m_legs, {0, -BODY_SIZE});

    m_equipment[(int)Equipment::Type::Head].setUp({BODY_SIZE, BODY_SIZE},
                                                   getBody().getSprite(),
                                                  {0, -BODY_SIZE});

    m_equipment[(int)Equipment::Type::Shield].setUp({75, 75},
                                                     getBody().getSprite(),
                                                    {0, 10},
                                                    { getBody().getSprite().getOrigin().x + BODY_SIZE / 3, getBody().getSprite().getOrigin().y});

    m_equipment[(int)Equipment::Type::Sword].setUp({Sword::SWORD_SIZE, Sword::SWORD_SIZE},
                                                    m_equipment[(int)Equipment::Type::Body].getSprite(),
                                                   {0, -35},
                                                   { getBody().getSprite().getOrigin().x - BODY_SIZE / 1.5f, getBody().getSprite().getOrigin().y});

    m_legs.setTexture(&getResources().getTexture(Texture_ID::Player_Legs));
    m_legs.setSize({BODY_SIZE, BODY_SIZE});

    auto rect = m_legs.getLocalBounds();
    m_legs.setOrigin(rect.left  + rect.width / 2.0f,
                     m_legs.getOrigin().y);

    for (int i = 0 ; i <= 2 ; i++)
    {
        m_legsAnimation.addFrame({i * 50, 0, 50, 40}, 0.05);
    }
    m_legsAnimation.addFrame({2 * 50, 0, 50, 40}, 0.05);
    m_legs.setTextureRect(m_legsAnimation.getFrame());
}

void Player::input()
{
    static sf::Clock c;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_sword.isSwinging() && c.getElapsedTime().asSeconds() > 0.5f)
    {
        m_sword.slash();
        c.restart();
    }

    for (auto& eq : m_equipment)
    {
        eq.input();
    }
}

void Player::update(World& world, float dt)
{
    m_sword.update();

    moveLegs(dt);
    for (auto& eq : m_equipment)
    {
        eq.update();
    }

    //window edge collisions
    {
        auto x = m_legs.getPosition().x;
        auto y = m_legs.getPosition().y;

        if (x < 0)              m_legs.setPosition(0, y);
        if (y - BODY_SIZE < 0)  m_legs.setPosition(x, BODY_SIZE);

        if (x > Display::WIDTH)                 m_legs.setPosition(Display::WIDTH,  y);
        if (y + BODY_SIZE > Display::HEIGHT)    m_legs.setPosition(x,               Display::HEIGHT - BODY_SIZE);
    }
}

void Player::draw()
{
    m_sword.draw();
    for (auto& eq : m_equipment)
    {
        eq.draw();
    }
    Display::draw(m_legs);
}

void Player::setPosition(const sf::Vector2f& pos) { m_legs.setPosition(pos); }

const sf::Vector2f& Player::getPosition() const { return m_legs.getPosition(); }

//Just some setters for the equpment tiers
void Player::setEquipmentBody(Equipment::Tier tier)
{ m_equipment[(int)Equipment::Type::Body].setData(Equipment::getData(Equipment::Type::Body, tier)); }

void Player::setEquipmentHeadgear(Equipment::Tier tier)
{ m_equipment[(int)Equipment::Type::Head].setData(Equipment::getData(Equipment::Type::Head, tier)); }

void Player::setEquipmentShield(Equipment::Tier tier)
{ m_equipment[(int)Equipment::Type::Shield].setData(Equipment::getData(Equipment::Type::Shield, tier)); }

void Player::setEquipmentSword(Equipment::Tier tier)
{
    m_equipment[(int)Equipment::Type::Sword].setData(Equipment::getData(Equipment::Type::Sword, tier));
    m_sword.upgrade(tier);
}

//getters for equipment
const Equippable& Player::getBody       () const { return m_equipment[(int)Equipment::Type::Body];      }
const Equippable& Player::getHeadgear   () const { return m_equipment[(int)Equipment::Type::Head];      }
const Equippable& Player::getSword      () const { return m_equipment[(int)Equipment::Type::Sword];     }
const Equippable& Player::getShield     () const { return m_equipment[(int)Equipment::Type::Shield];    }

void Player::moveLegs(float dt)
{
    if (sf::Mouse::getPosition(Display::get()).x > m_legs.getPosition().x)
    {
        m_legs.setScale(1, 1);
    }
    else
    {
        m_legs.setScale(-1, 1);
    }

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
