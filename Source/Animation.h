#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>

class Animation
{
    struct Frame
    {
        Frame(const sf::IntRect& frame, float timeToNextFrame)
        :   frame           (frame)
        ,   timeToNextFrame (timeToNextFrame) {}

        sf::IntRect frame;
        float       timeToNextFrame;
    };

    public:
        void addFrames(int numFrames, const sf::IntRect& frameSize, float time);

        void addFrame (const sf::IntRect& frame, float timeToNextFrame);

        const sf::IntRect getFrame();
        const sf::IntRect getFrame(int index);

        bool isOnFinalFrame() const;
        void reset();

        int getNumFrames() { return m_frames.size(); }

    private:
        std::vector<Frame> m_frames;

        sf::Clock   m_timer;
        unsigned    m_currentFrame      = 0;
        float       m_longestFrameTime  = 0;
};

#endif // ANIMATION_H_INCLUDED
