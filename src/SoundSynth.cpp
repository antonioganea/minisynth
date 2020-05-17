#include "SoundSynth.h"

#include <cmath>
#include <iostream>

#define TWELTH_ROOT_OF_TWO 1.05946309436
#define SAMPLE_RATE 44100
#define TAU 6.28318

double SoundSynth::osc(double delta, OscillatorType oscType)
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

void SoundSynth::generate(float frequency, unsigned int duration, OscillatorType oscType) {
    double increment = frequency/SAMPLE_RATE;
	double x = 0;
	for (unsigned int i = 0; i < duration; i++) {
		rawSamples[i] = 20000 * osc(x*TAU, oscType);// sin(x*TAU);
		x += increment;
	}

	if (!sBuffer.loadFromSamples(rawSamples, duration, 1, SAMPLE_RATE)) {
		std::cout << "Failed to bind rawSamples to audio buffer" << std::endl;
		return;
	}
}

void SoundSynth::play(float frequency, OscillatorType oscType){
    generate(frequency, 4410, oscType);
    sound.setBuffer(sBuffer);
    sound.play();
}

void SoundSynth::playNote(int note, OscillatorType oscType){
    float frequency = 440 * pow( TWELTH_ROOT_OF_TWO, note);
    play(frequency, oscType);
}

SoundSynth::SoundSynth() {
    rawSamples = new sf::Int16[SAMPLE_RATE * 10]; // Up to 10 seconds of audio
}

SoundSynth::~SoundSynth() {
    delete[] rawSamples;
}
