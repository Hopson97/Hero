#include "Equipment_Data.h"

#include <SFML/Graphics.hpp>

#include <array>
#include <cassert>

#include "../../Resource_Managers/Resource_Holder.h"

namespace Equipment
{
    class Database
    {

        public:
            Data_Base()
            {
                addToDatabase(primitiveData, Type::Body,    0, 0, getTxr(Texture_ID::Player_Body_Shirt  ));
                addToDatabase(primitiveData, Type::Head,    0, 0, getTxr(Texture_ID::Player_Head_None   ));
                addToDatabase(primitiveData, Type::Shield,  0, 0, getTxr(Texture_ID::Player_Shield_Wood ));
                addToDatabase(primitiveData, Type::Sword,   0, 0, getTxr(Texture_ID::Player_Sword_Wood  ));
            }

            const Data& getPrimData (int tier) const
            {

            }

            const Data& getIronData (int tier) const
            {

            }

            const Data& getGoldData (int tier) const
            {

            }

            const Data& getMagmaData(int tier) const
            {

            }

        private:
            void addToDatabase(std::array<Data, static_cast<int>(Type::NUM_TYPES)> arr,
                               Type type,
                               int dmg,
                               int health,
                               const sf::Texture& texture)
            {
                arr[static_cast<int>(type)] = {dmg, health, texture};
            }

            const sf::Texture& getTxr(Texture_ID id)
            {
                return getResources().getTexture(id);
            }

            std::array <Data, static_cast<int>(Type::NUM_TYPES)> primitiveData;
            std::array <Data, static_cast<int>(Type::NUM_TYPES)> ironData;
            std::array <Data, static_cast<int>(Type::NUM_TYPES)> goldData;
            std::array <Data, static_cast<int>(Type::NUM_TYPES)> magmaData;
    };


    const Data& getData(Type type, Tier tier)
    {
        static Database database;

        auto tierNumber = static_cast<int>(tier);

        switch (tier)
        {
            case Tier::Primitive:
                return database.getPrimData(tierNumber);

            case Tier::Iron:
                return database.getIronData(tierNumber);

            case Tier::Gold:
                return database.getGoldData(tierNumber);

            case Tier::Magma:
                return database.getMagmaData(tierNumber);
        }
        return database.getPrimData(0); //To get rid of a warning that has no effect
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
