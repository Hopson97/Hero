#include "Blacksmith.h"

#include "../../Display.h"
#include "../../Resource_Managers/Resource_Holder.h"

#include "../World.h"

class Talk_Action : public Action
{
    public:
        Talk_Action(std::string message)
        :   m_message (std::move(message))
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
    m_sprite.setPosition(5, 5);

    for (int i = 0 ; i <= 2 ; i++)
    {
        m_animation.addFrame({i * 100, 0, 100, 100}, 0.2);
    }
    m_animation.addFrame({2 * 100, 0, 100, 100}, 0.2);
    m_sprite.setTextureRect(m_animation.getFrame());
}

void Blacksmith::update(World& world, Player& player, float dt)
{
    m_sprite.setTextureRect(m_animation.getFrame());


}

void Blacksmith::draw()
{
    Display::draw(m_sprite);
}
