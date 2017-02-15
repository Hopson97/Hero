#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

class Entity;

namespace Component
{
    class CBase
    {
        public:
            virtual void update(float dt) = 0;;

        protected:
            CBase(Entity& entity);

            Entity* m_p_entity;
    };
}




#endif // COMPONENT_H_INCLUDED
