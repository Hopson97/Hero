#ifndef Equipment_DATA_H_INCLUDED
#define Equipment_DATA_H_INCLUDED



class Resource_Holder;

namespace sf
{
    class Texture;
}

namespace Equipment
{
    enum class Type
    {
        Head,
        Body,
        Sword,
        Shield,

        NUM_TYPES
    };

    enum class Tier
    {
        Primitive,
        Iron,
        Gold,
        Magma,
    };

    class Data
    {
        public:
            Data() = default;
            Data(int dmg, int health, const sf::Texture& texture);

            int getDamageBonus() const;
            int getHealthBonus() const;

            const sf::Texture& getTexture() const;

        private:
            int m_damageBonus;
            int m_healthBonus;
            const sf::Texture* m_texture;
    };

    const Data& getData(Type type, Tier tier);
}


#endif // Equipment_DATA_H_INCLUDED
