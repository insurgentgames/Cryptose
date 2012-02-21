#pragma once
#ifndef SOUNDS_H
#define SOUNDS_H

#include "s3eSound.h"
#include "s3eAudio.h"

class Sounds {
public:
	// return the instance
	static Sounds* getInstance();
	
	// constructor and destructor
	Sounds();
	~Sounds();
	static void shutdown();

	// play audio
	void playClick();
	void playSwish();
	void playType();
	void playDraw();

	// music
	void startMusic();
	void stopMusic();

private:
	static Sounds* instance;

	// a sound
	struct Sound {
		int16* buffer;
		int32 fileSize;
	};

	// sound methods
	Sounds::Sound* loadSound(const char* filename);
	void playSound(Sounds::Sound* sound);
	
	// sound buffers
	Sounds::Sound* soundClick;
	Sounds::Sound* soundSwish;
	Sounds::Sound* soundType1;
	Sounds::Sound* soundType2;
	Sounds::Sound* soundType3;
	Sounds::Sound* soundDraw1;
	Sounds::Sound* soundDraw2;
	Sounds::Sound* soundDraw3;
};

#endif // SOUNDS_H