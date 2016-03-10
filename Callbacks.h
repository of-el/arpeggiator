#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include "fmod.hpp"
#include "fmod_errors.h"

class callbacks
{
private:
	int noteLength = 1; // in seconds

public:
	callbacks();

	FMOD_CREATESOUNDEXINFO createToneA();
	FMOD_CREATESOUNDEXINFO createToneASharp();
	FMOD_CREATESOUNDEXINFO createToneB();
	FMOD_CREATESOUNDEXINFO createToneC();
	FMOD_CREATESOUNDEXINFO createToneCSharp();
	FMOD_CREATESOUNDEXINFO createToneD();
	FMOD_CREATESOUNDEXINFO createToneDSharp();
	FMOD_CREATESOUNDEXINFO createToneE();
	FMOD_CREATESOUNDEXINFO createToneF();
	FMOD_CREATESOUNDEXINFO createToneFSharp();
	FMOD_CREATESOUNDEXINFO createToneG();
	FMOD_CREATESOUNDEXINFO createToneGSharp();

	FMOD_CREATESOUNDEXINFO tone[12];
};

#endif CALLBACKS_H_ 