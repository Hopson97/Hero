#ifndef CANIMATION_H_INCLUDED
#define CANIMATION_H_INCLUDED

namespace Component
{
    class CAnimation : public CBase
    {
        public:
            void update(float dt) override;

        private:
            Animation m_animation;
    };
}

#endif // CANIMATION_H_INCLUDED
