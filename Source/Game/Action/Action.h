#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

class World;

class Action
{
    public:
        virtual ~Action() = default;

        virtual void execute(World& world) = 0;
};

#endif // ACTION_H_INCLUDED
