#ifndef SOUNDSYNTH_HPP_INCLUDED
#define SOUNDSYNTH_HPP_INCLUDED

#include <SFML/Audio.hpp>

class SoundSynth
{
    sf::SoundBuffer sBuffer;
    sf::Sound sound;
    sf::Int16 * rawSamples;
    void generate(float frequency, unsigned int duration);
    public:
        void play(float frequency);
        void playNote(int note);
        SoundSynth();
        ~SoundSynth();
};

#endif // SOUNDSYNTH_HPP_INCLUDED
