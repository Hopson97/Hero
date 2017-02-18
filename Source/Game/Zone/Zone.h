#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "../Entities/Entity.h"
#include "../Projectile.h"

#include "EZone_ID.h"

class Resource_Holder;
class World;
class Player;

class Zone
{
    public:
        virtual ~Zone() = default;

        void update(World& world, Player& player, float dt);

        void draw();

        Zone_ID getID() const;

        template<typename... Args>
        void addProjectile(Args&&... args)
        {
            m_projetiles.emplace_back(std::forward<Args>(args)...);
        }

    protected:
        Zone(const sf::Texture& background, Zone_ID id);

        void addEntity(std::unique_ptr<Entity>);

        virtual void onUpdate   (World& world, Player& player, float dt) = 0;
        virtual void onDraw     () = 0;

        int checkForDeadEntities(Player& player);
        bool entityDamaged      ();


    private:
        sf::RectangleShape m_background;
        sf::RectangleShape m_shakeGround;

        std::vector<std::unique_ptr<Entity>> m_entities;
        std::vector<Projectile> m_projetiles;

        Zone_ID m_id;
};

#endif // ZONE_H_INCLUDED
