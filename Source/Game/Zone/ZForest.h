#ifndef ZFOREST_H_INCLUDED
#define ZFOREST_H_INCLUDED

class ZForest : public Zone
{
    public:
        ZForest();

        void onUpdate (World& world, Player& player, float dt) override;
        void onDraw   () override;

    private:
        void addEnemy();

        int m_enemyCount = 0;
};

#endif // ZFOREST_H_INCLUDED
