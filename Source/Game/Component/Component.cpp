#include "Component.h"

namespace Component
{
    CBase::CBase(Entity& entity)
    :   m_p_entity (&entity)
    { }
}
