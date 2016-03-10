#include "Callbacks.h"
#include "Arpeggiator.h"

callbacks::callbacks()
{
	tone[0] = createToneA();
	tone[1] = createToneASharp();
	tone[2] = createToneB();
	tone[3] = createToneC();
	tone[4] = createToneCSharp();
	tone[5] = createToneD();
	tone[6] = createToneDSharp();
	tone[7] = createToneE();
	tone[8] = createToneF();
	tone[9] = createToneFSharp();
	tone[10] = createToneG();
	tone[11] = createToneGSharp();
}

//create tone based on input frequency
FMOD_RESULT F_CALLBACK toneA(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = A_FREQ; //this is defined outside
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short* buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276) to get true volume to store
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples generated
		samplesElapsed++;
	}
	return FMOD_OK;
}

FMOD_CREATESOUNDEXINFO callbacks::createToneA()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= samplerate*channels*bits per sample per channel (in seconds)
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneA; //this must match the name of the F_CALLBACK function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneASharp(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = ASharp_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneASharp()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneASharp; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneB(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = B_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneB()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneB; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneC(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = C_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneC()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneC; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneCSharp(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = CSharp_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneCSharp()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneCSharp; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneD(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = D_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneD()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneD; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneDSharp(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = DSharp_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneDSharp()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneDSharp; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneE(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = E_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneE()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneE; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneF(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = F_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneF()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneF; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneFSharp(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = FSharp_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneFSharp()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneFSharp; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneG(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = G_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneG()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneG; //this must match the name of the other function

	return soundInfo;
}

FMOD_RESULT F_CALLBACK toneGSharp(FMOD_SOUND *sound, void *data, unsigned int length)
{
	static int const frequency = GSharp_FREQ; //this can be defined once outside the function
	static float const volume = 0.3f;
	static int samplesElapsed = 0;
	signed short *buffer = (signed short *)data;

	//2 channel, stereo stream, 16-bit - 4 bytes per sample
	for (unsigned int sample = 0; sample < length / 4; sample++){
		//position within the sample
		double position = frequency * static_cast<float>(samplesElapsed) / 44100;
		//generator function: value (-1.0 to 1.0) * max volume for 16-bit PCM (3276), result = true volume
		//left channel sample:
		*buffer++ = (signed short)(sin(position * 3.14156 * 2) * 32767.0f * volume);
		//right channel sample:
		*buffer++ = (signed short)(sin(position * 3.14159 * 2) * 32767.0f * volume);

		//increment samples
		samplesElapsed++;
	}
	return FMOD_OK; //for error checking
}

FMOD_CREATESOUNDEXINFO callbacks::createToneGSharp()
{
	//set up the sound information/parameters
	//(44.1k sample rate, stereo channels, etc)
	FMOD_CREATESOUNDEXINFO soundInfo;

	memset(&soundInfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	soundInfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);

	//buffer size sufficient for one second
	soundInfo.decodebuffersize = 44100;
	//sample length in bytes= rate*channels*bits per sample per channel (signed short)*seconds
	//44100 * 2 * sizeof(signed short) * seconds
	soundInfo.length = 44100.0 * 2.0 * sizeof(signed short)* noteLength;

	//channels and sample rate and format (bit rate)
	soundInfo.numchannels = 2;
	soundInfo.defaultfrequency = 44100;
	soundInfo.format = FMOD_SOUND_FORMAT_PCM16;

	//callback for generating samples
	soundInfo.pcmreadcallback = toneGSharp; //this must match the name of the other function

	return soundInfo;
}