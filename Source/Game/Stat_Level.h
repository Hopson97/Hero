#ifndef STAT_LEVEL_H_INCLUDED
#define STAT_LEVEL_H_INCLUDED

class Stat_Level
{
    public:
        Stat_Level(int start = 1);

        void addExp(int exp);

        int getLevel            () const;
        int getExp              () const;
        int getExpForNextLevel  () const;

        bool hasLeveledUp       ();

    private:
        int m_level                 = 1;
        double m_currentXP          = 0;
        double m_expForNextLevel    = 10;

        bool m_hasLeveledUp = false;
};

#endif // STAT_LEVEL_H_INCLUDED
