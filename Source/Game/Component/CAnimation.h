#ifndef CANIMATION_H_INCLUDED
#define CANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Component.h"
#include "../../Animation.h"

namespace Component
{
    class CAnimation : public CBase
    {
        public:
            CAnimation(Entity& entity, const sf::IntRect& frameSize, int numFrames, float frameTime);

            void update(float dt) override;

        private:
            Animation m_animation;
    };
}

#endif // CANIMATION_H_INCLUDED
