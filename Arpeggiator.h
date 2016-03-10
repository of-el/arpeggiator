#ifndef ARPEGGIATOR_H_
#define ARPEGGIATOR_H_

#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"
#include <Windows.h>
#include <string>
#include "callbacks.h" // delete if something get's angry 

// note and frequency
#define A_FREQ 220; 
#define ASharp_FREQ 233;
#define B_FREQ 247;
#define C_FREQ 262;
#define CSharp_FREQ 277;
#define D_FREQ 294;
#define DSharp_FREQ 311;
#define E_FREQ 330;
#define F_FREQ 349;
#define FSharp_FREQ 370;
#define G_FREQ 392;
#define GSharp_FREQ 415;

using namespace std;

class arpeggiator
{
private:
	// System Declarations
	FMOD::System* system;
	FMOD::Sound* sound;
	FMOD::Channel* channel;

	FMOD_RESULT result;

	callbacks tones; // holds sound info for each tone

	// Chord interval declarations
	int dim[2];
	int min[2];
	int maj[2];
	int aug[2];
	int hDim7[3];
	int fDim7[3];
	int min7[3];
	int dom7[3];
	int maj7[3];

	// Arpeggiator Declarations
	string chord;
	string note;
	int bpm; // how fast arpeggio will be
	int sleepTime; // time between notes, conversion bpm to ms

public:
	arpeggiator();
	arpeggiator(string someNote, string someChord, int userBPM);
	~arpeggiator() { sound->release(); system->release(); }

	void FMOD_Initialize();
	void FMODErrorCheck(FMOD_RESULT result);

	void play(); //decide what chord to play
	void playSound(FMOD_CREATESOUNDEXINFO soundInfo);
	void fillChordMap();
	void normalizeInput();
	void playArp(int chordIndexes[]);

};

#endif ARPEGGIATOR_H_
