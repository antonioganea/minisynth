#include "SoundSynth.h"

#include <cmath>
#include <iostream>

#define TWELTH_ROOT_OF_TWO 1.05946309436
#define SAMPLE_RATE 44100
#define TAU 6.28318

enum OscillatorType{
Sine = 0,
Square = 1,
Sawtooth = 2,
Triangle = 3
};

double osc(double delta, OscillatorType oscType)
{
    switch (oscType)
    {
    case Sine:
        return sin(delta);
    case Square:
        return sin(delta) > 0 ? 1.0 : -1.0;
    case Sawtooth:
        return fmod(delta/TAU,1);
    case Triangle:
        return asin(sin(delta)) * (2.0 / M_PI);
    default:
        return 0.0;
    }
}

void SoundSynth::generate(float frequency, unsigned int duration) {
    double increment = frequency/SAMPLE_RATE;
	double x = 0;
	for (unsigned int i = 0; i < duration; i++) {
		rawSamples[i] = 20000 * osc(x*TAU, Sawtooth);// sin(x*TAU);
		x += increment;
	}

	if (!sBuffer.loadFromSamples(rawSamples, duration, 1, SAMPLE_RATE)) {
		std::cout << "Failed to bind rawSamples to audio buffer" << std::endl;
		return;
	}
}

void SoundSynth::play(float frequency){
    generate(frequency, 4410);
    sound.setBuffer(sBuffer);
    sound.play();
}

void SoundSynth::playNote(int note){
    float frequency = 440 * pow( TWELTH_ROOT_OF_TWO, note);
    play(frequency);
}

SoundSynth::SoundSynth() {
    rawSamples = new sf::Int16[SAMPLE_RATE * 10]; // Up to 10 seconds of audio
}

SoundSynth::~SoundSynth() {
    delete[] rawSamples;
}
