#include "Blacksmith.h"

#include <iostream>

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

#include "../World.h"

class AOpen_Shop : public Action
{
    public:
        AOpen_Shop()
        {}

        void execute(World& world)
        {

        }

    private:
        std::string m_message;
};

Blacksmith::Blacksmith()
{
    m_sprite.setSize({255, 255});
    m_sprite.setTexture(&getResources().getTexture(Texture_ID::Entity_Blacksmith));
    m_sprite.setPosition(200, 5);

    for (int i = 0 ; i <= 2 ; i++)
    {
        m_animation.addFrame({i * 100, 0, 100, 100}, 0.3);
    }
    m_animation.addFrame({100, 0, 100, 100}, 0.3);
    m_sprite.setTextureRect(m_animation.getFrame());
}

void Blacksmith::update(World& world, Player& player, float dt)
{
    m_sprite.setTextureRect(m_animation.getFrame());

    if (world.getDistanceToPlayer({m_sprite.getPosition().x + m_sprite.getLocalBounds().width / 1.2f,
                                   m_sprite.getPosition().y + m_sprite.getLocalBounds().height / 1.2f}) < 50 )
    {
        world.addAction(std::make_unique<AOpen_Shop>());
    }

}

void Blacksmith::draw()
{
    Display::draw(m_sprite);
}
