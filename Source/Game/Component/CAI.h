#ifndef CAI_H_INCLUDED
#define CAI_H_INCLUDED

namespace Component
{
    class CAI
    {
        public:
            CAI(Entity& entity);

            void update(float dt);
    };
}

#endif // CAI_H_INCLUDED
