#include "Arpeggiator.h"
#include <iostream>

arpeggiator::arpeggiator()
{
	FMOD_Initialize();
	bpm = 120;
	chord = "C major";
}

arpeggiator::arpeggiator(string someNote, string someChord, int userBPM)
{
	FMOD_Initialize();
	note = someNote;
	chord = someChord;
	normalizeInput(); // set the chord to standard form
	bpm = userBPM;
	sleepTime = 60000 / bpm; // ms per beat
	fillChordMap();
}

void arpeggiator::normalizeInput()
{
	//capitalize first letter
	note[0] = toupper(note[0]);

	//if it's not between A and G, improper input.
	if (note[0] < 'A' || note[0] > 'G')
	{
		cout << "improper input." << endl;
		exit(-1);
	}

	if (note[1] == 'f' || note[1] == 'F' || note[1] == 'b')
	{
		switch (note[0])
		{
		case 'A':
			note[0] = 'G';
			note[1] = 'S';
			break;
		case 'B':
			note[0] = 'A';
			note[1] = 'S';
			break;
		case 'C':
			note[0] = 'B';
			note[1] = ' ';
			break;
		case 'D':
			note[0] = 'C';
			note[1] = 'S';
			break;
		case 'E':
			note[0] = 'D';
			note[1] = 'S';
			break;
		case 'F':
			note[0] = 'E';
			note[1] = ' ';
			break;
		case 'G':
			note[0] = 'F';
			note[1] = 'S';
			break;
		default:
			break;
		}
	}
	else if (note[1] == '#' || note[1] == 's')
	{
		note[1] = 'S';
	}

	for (int i = 0; i < chord.length(); i++)
	{
		chord[i] = tolower(chord[i]);
	}
}

void arpeggiator::FMOD_Initialize()
{
	//initialize FMOD system
	//not allowed to use FMOD without the rigorous initialization

	//create FMOD interface object
	FMODErrorCheck(FMOD::System_Create(&system));

	//Check version
	unsigned int version;
	FMODErrorCheck(system->getVersion(&version));

	if (version < FMOD_VERSION){
		cout << "Using old version " << version << endl;
	}

	//Get number of drivers
	int numDrivers;
	FMODErrorCheck(system->getNumDrivers(&numDrivers));


	FMOD_CAPS caps;
	FMOD_SPEAKERMODE speakerMode;
	if (numDrivers == 0){  //no sound drivers found = no sound :(
		FMODErrorCheck(system->setOutput(FMOD_OUTPUTTYPE_NOSOUND));
	}
	else{
		//Get driver caps
		FMODErrorCheck(system->getDriverCaps(0, &caps, 0, &speakerMode));
		//set speaker mode to stereo, because what else would we do
		FMODErrorCheck(system->setSpeakerMode(speakerMode));
	}

	if (caps & FMOD_CAPS_HARDWARE_EMULATED){
		//set DSP buffer larger if something went wrong in the settings
		FMODErrorCheck(system->setDSPBufferSize(1024, 10));
	}

	//Initializing the system
	FMODErrorCheck(system->init(64, FMOD_INIT_NORMAL, 0));
}

void arpeggiator::FMODErrorCheck(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << endl;
		exit(-1);
	}
}

void arpeggiator::playSound(FMOD_CREATESOUNDEXINFO soundInfo)
{
	system->createStream(nullptr, FMOD_OPENUSER, &soundInfo, &sound);
	system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
}

void arpeggiator::play()
{
	if (chord[chord.length() - 1] == '7') // seventh chords
	{
		switch (chord[0])
		{
		case 'm':
			if (chord[1] == 'a') // major 7
			{
				playArp(maj7);
			}
			else // minor 7
			{
				playArp(min7);
			}
			break;
		case 'h': // half diminished 7
			playArp(hDim7);
			break;
		case 'f': // fully diminished 7
			playArp(fDim7);
			break;
		case 'd': // dominant 7
			playArp(dom7);
			break;
		default: // default to dominant 7
			playArp(dom7);
			break;
		}
	}
	else // triads
	{
		switch (chord[0])
		{
		case 'd': // diminished
			playArp(dim);
			break;
		case 'a': // augmented
			playArp(aug);
			break;
		case 'm':
			if (chord[1] == 'a') // major
			{
				playArp(maj);
			}
			else // minor
			{
				playArp(min);
			}
			break;
		default: // default to major
			playArp(maj);
			break;
		}
	}
}

void arpeggiator::playArp(int chordIndexes[])
{
	// find the start index
	int index = 0;

	switch (note[0]){
	case 'A':
		index = 0;
		if (note.length() > 1)
		{
			if (note[1] == 'S')
			{
				index = 1;
			}
		}
		break;

	case 'B':
		index = 2;
		break;

	case 'C':
		index = 3;
		if (note.length() > 1)
		{
			if (note[1] == 'S')
			{
				index = 4;
			}
		}
		break;

	case 'D':
		index = 5;
		if (note.length() > 1)
		{
			if (note[1] == 'S')
			{
				index = 6;
			}
		}
		break;

	case 'E':
		index = 7;
		break;

	case 'F':
		index = 8;
		if (note.length() > 1)
		{
			if (note[1] == 'S')
			{
				index = 9;
			}
		}
		break;

	case 'G':
		index = 10;
		if (note.length() > 1)
		{
			if (note[1] == 'S')
			{
				index = 11;
			}
		}
		break;

	default:
		index = 3;
		break;
	}

	if (chord[chord.length() - 1] == '7') // seventh chords have 4 notes, 3 intervals
	{
		for (int i = 0; i < 4; i++)
		{
			playSound(tones.tone[index]); // play the tone at the index
			index += chordIndexes[i]; // increment the index an interval, starts at 0
			index %= 12; // wrap to keep it in the octave
			Sleep(sleepTime); // wait for next note
		}
	}
	else // regular triads have 3 notes, 2 intervals
	{
		for (int i = 0; i < 3; i++)
		{
			playSound(tones.tone[index]); // play the tone at the index
			index += chordIndexes[i]; // increment the index an interval, starts at 0
			index %= 12; // wrap to keep it in the octave
			Sleep(sleepTime); // wait for next note
		}
	}

}

void arpeggiator::fillChordMap() // set the intervals between notes in the chord
{
	// initialize diminished triad
	dim[0] = 3;
	dim[1] = 3;

	// minor triad
	min[0] = 3;
	min[1] = 4;

	// major triad
	maj[0] = 4;
	maj[1] = 3;

	// augmented triad
	aug[0] = 4;
	aug[1] = 4;


	// half dim 7
	hDim7[0] = 3;
	hDim7[1] = 3;
	hDim7[2] = 4;

	// full dim 7
	fDim7[0] = 3;
	fDim7[1] = 3;
	fDim7[2] = 3;

	// minor 7
	min7[0] = 3;
	min7[1] = 4;
	min7[2] = 3;

	// maj 7
	maj7[0] = 4;
	maj7[1] = 3;
	maj7[2] = 4;

	// dominant 7
	dom7[0] = 4;
	dom7[1] = 3;
	dom7[2] = 3;
}