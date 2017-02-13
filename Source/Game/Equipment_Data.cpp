#include "Equipment_Data.h"

#include <SFML/Graphics.hpp>

#include <vector>
#include <cassert>

#include "../Resource_Managers/Resource_Holder.h"

namespace Equipment
{
    namespace
    {
        std::vector<Data> primitiveData (static_cast<int>(Type::NUM_TYPES));
        std::vector<Data> ironData      (static_cast<int>(Type::NUM_TYPES));
        std::vector<Data> goldData      (static_cast<int>(Type::NUM_TYPES));
        std::vector<Data> magmaData     (static_cast<int>(Type::NUM_TYPES));

        void addToDatabase(std::vector<Data>& vect,
                           Type type,
                           int dmg,
                           int health,
                           const sf::Texture& texture)
        {
            vect[static_cast<int>(type)] = {dmg, health, texture};
        }

        const sf::Texture& getTxr(const Resource_Holder& holder, Texture_ID id)
        {
            return holder.textures.get(id);
        }
    }


    void initData(const Resource_Holder& holder)
    {
        addToDatabase(primitiveData, Type::Body,    0, 0, getTxr(holder, Texture_ID::Player_Body_Shirt  ));
        addToDatabase(primitiveData, Type::Head,    0, 0, getTxr(holder, Texture_ID::Player_Head_None   ));
        addToDatabase(primitiveData, Type::Shield,  0, 0, getTxr(holder, Texture_ID::Player_Shield_Wood ));
        addToDatabase(primitiveData, Type::Sword,   0, 0, getTxr(holder, Texture_ID::Player_Sword_Wood  ));

        //more to come tbh
    }

    const Data& getData(Type type, Tier tier)
    {
        auto tierNumber = static_cast<int>(tier);

        switch (tier)
        {
            case Tier::Primitive:
                return primitiveData.at(tierNumber);

            case Tier::Iron:
                return ironData.at(tierNumber);

            case Tier::Gold:
                return goldData.at(tierNumber);

            case Tier::Magma:
                return magmaData.at(tierNumber);
        }
    }


    Data::Data(int dmg, int health, const sf::Texture& texture)
    :   m_damageBonus   (dmg)
    ,   m_healthBonus   (health)
    ,   m_texture       (&texture)
    { }

    int Data::getDamageBonus() const
    {
        return m_damageBonus;
    }

    int Data::getHealthBonus() const
    {
        return m_healthBonus;
    }

    const sf::Texture& Data::getTexture() const
    {
        return *m_texture;
    }

}
