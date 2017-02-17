#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <SFML/Audio/Music.hpp>

#include <memory>
#include <stack>

#include "Resource_Managers/Resource_Holder.h"
#include "States/State_Base.h"

class Application
{
    public:
        Application();

        void runMainLoop();

        void pushState(std::unique_ptr<State::State_Base> state);
        void popState ();

    private:
        std::stack<std::unique_ptr<State::State_Base>> m_states;

        sf::Music m_music;


};

#endif // APPLICATION_H_INCLUDED
