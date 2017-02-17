#include "Loot.h"

#include "../Util/Random.h"

Loot::Loot(int coinDropLow, int coinDropHigh, int expGainLow, int expGainHigh)
:   m_expGainLow    (expGainLow)
,   m_expGainHigh   (expGainHigh)
,   m_coinDropLow   (coinDropLow)
,   m_coinDropHigh  (coinDropHigh)
{ }

int Loot::getCoin() const
{
    return Random::integer(m_coinDropLow, m_coinDropHigh);
}

int Loot::getExp() const
{
    return Random::integer(m_expGainLow, m_expGainHigh);
}
