#ifndef LOOT_H_INCLUDED
#define LOOT_H_INCLUDED

class Loot
{
    public:
        Loot(int coinDropLow = 1,
             int coinDropHigh = 2,
             int expGainLow = 1,
             int expGainHigh = 2);

        int getCoin () const;
        int getExp  () const;

    private:
        int m_expGainLow;
        int m_expGainHigh;

        int m_coinDropLow;
        int m_coinDropHigh;

};

#endif // LOOT_H_INCLUDED
