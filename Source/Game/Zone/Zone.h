#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Entities/Entity.h"

class Resource_Holder;
class World;
class Player;

class Zone
{
    public:
        virtual ~Zone() = default;

        void update(World& world, Player& player, float dt);

        void draw();

    protected:
        Zone(const sf::Texture& background);

        void addEntity(std::unique_ptr<Entity>);

        virtual void onUpdate   (World& world, Player& player, float dt) = 0;
        virtual void onDraw     () = 0;

        int checkForDeadEntities();


    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;

        std::vector<std::unique_ptr<Entity>> m_entities;
};

#endif // ZONE_H_INCLUDED
