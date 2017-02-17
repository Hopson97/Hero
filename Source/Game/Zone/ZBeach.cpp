#include "ZBeach.h"

#include "../../Resource_Managers/Resource_Holder.h"
#include "../Player.h"

#include "../Entities/Slime.h"
#include "../Entities/Bee.h"
#include "../Entities/Blacksmith.h"

#include "../../Util/Random.h"

ZBeach::ZBeach()
:   Zone (getResources().getTexture(Texture_ID::Zone_Beach), Zone_ID::Beach)
{

}

void ZBeach::onUpdate(World& world, Player& player, float dt)
{

}

void ZBeach::onDraw()
{

}

void ZBeach::addEnemy()
{

}
