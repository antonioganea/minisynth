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
    float pwm;
    float volume;
    public:
        void play(float frequency, OscillatorType oscType, unsigned int duration);
        void playNote(int note, OscillatorType oscType, unsigned int duration);
        SoundSynth();
        ~SoundSynth();
        void setPWM(float pwm);
        void setVolume(float vol);
};

#endif // SOUNDSYNTH_HPP_INCLUDED
