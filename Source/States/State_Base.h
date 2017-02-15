#ifndef STATE_BASE_H_INCLUDED
#define STATE_BASE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Resource_Managers/Resource_Holder.h"

class Application;

namespace State
{
    class State_Base
    {
        public:
            State_Base(Application& app);
            virtual ~State_Base() = default;

            virtual void input  (const sf::Event& e)    = 0;
            virtual void input  ()                      = 0;
            virtual void update (float dt)              = 0;
            virtual void draw   ()                      = 0;

        protected:
            Application* m_p_application;

    };
}

#endif // STATE_BASE_H_INCLUDED
