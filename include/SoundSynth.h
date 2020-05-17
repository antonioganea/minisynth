#ifndef SOUNDSYNTH_HPP_INCLUDED
#define SOUNDSYNTH_HPP_INCLUDED

#include <SFML/Audio.hpp>

enum OscillatorType{
    Sine = 0,
    Square = 1,
    Sawtooth = 2,
    Triangle = 3
};

class SoundSynth
{
    sf::SoundBuffer sBuffer;
    sf::Sound sound;
    sf::Int16 * rawSamples;
    void generate(float frequency, unsigned int duration, OscillatorType oscType);
    double osc(double delta, OscillatorType oscType);
    public:
        void play(float frequency, OscillatorType oscType);
        void playNote(int note, OscillatorType oscType);
        SoundSynth();
        ~SoundSynth();
};

#endif // SOUNDSYNTH_HPP_INCLUDED
