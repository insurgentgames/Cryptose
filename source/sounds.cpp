#include "config.h"
#include "ig2d/ig_global.h"
#include "sounds.h"
#include "settings.h"
#include "derbh.h"
#include <s3eExtensions/s3eExt_BackgroundMusic.h>
#include <s3eExtensions/s3eExt_BackgroundAudio.h>

Sounds* Sounds::instance = NULL;

Sounds* Sounds::getInstance() {
	if(instance == NULL)
		instance = new Sounds();
	return instance;
}

Sounds::Sounds() {
	IGLog("Sounds init");
	
	if(AIRPLAY_DEVICE == "iphone") {
		// for iphone, if there's background music playing, keep it playing
		if(s3eExtBackgroundMusicAvailable() == S3E_TRUE) {
			if(s3eBackgroundMusicGetInt(S3E_BACKGROUNDMUSIC_PLAYBACK_STATE) == S3E_BACKGROUNDMUSIC_PLAYBACK_INTERRUPTED)
				s3eBackgroundMusicPlay();
			if(s3eExtBackgroundAudioIsPlaying() == S3E_TRUE)
				s3eExtBackgroundAudioSetMix(S3E_TRUE);
		}
	}
	
	// set sounds to null
	soundClick = NULL;
	soundSwish = NULL;
	soundType1 = NULL;
	soundType2 = NULL;
	soundType3 = NULL;
	soundDraw1 = NULL;
	soundDraw2 = NULL;
	soundDraw3 = NULL;

	// set default frequency at which all channels will play at, in Hz.
	s3eSoundSetInt(S3E_SOUND_DEFAULT_FREQ, 44100);

	// start playing music?
	if(Settings::getInstance()->musicEnabled) {
		startMusic();
	}
}

Sounds::~Sounds() {
	if(soundClick != NULL) {
		s3eFreeBase(soundClick->buffer);
		delete soundClick;
	}
	if(soundSwish != NULL) {
		s3eFreeBase(soundSwish->buffer);
		delete soundSwish;
	}
	if(soundType1 != NULL) {
		s3eFreeBase(soundType1->buffer);
		delete soundType1;
	}
	if(soundType2 != NULL) {
		s3eFreeBase(soundType2->buffer);
		delete soundType2;
	}
	if(soundType3 != NULL) {
		s3eFreeBase(soundType3->buffer);
		delete soundType3;
	}
	if(soundDraw1 != NULL) {
		s3eFreeBase(soundDraw1->buffer);
		delete soundDraw1;
	}
	if(soundDraw2 != NULL) {
		s3eFreeBase(soundDraw2->buffer);
		delete soundDraw2;
	}
	if(soundDraw3 != NULL) {
		s3eFreeBase(soundDraw3->buffer);
		delete soundDraw3;
	}
}

void Sounds::shutdown() {
	if(instance != NULL)
		delete instance;
}

Sounds::Sound* Sounds::loadSound(const char* filename) {
	Sounds::Sound* sound = new Sounds::Sound();
	s3eFile *fileHandle = s3eFileOpen(filename, "rb");
	sound->fileSize = s3eFileGetSize(fileHandle);
	sound->buffer = (int16*)s3eMallocBase(sound->fileSize);
	memset(sound->buffer, 0, sound->fileSize);
	s3eFileRead(sound->buffer, sound->fileSize, 1, fileHandle);
	s3eFileClose(fileHandle);
	return sound;
}

void Sounds::playSound(Sounds::Sound* sound) {
	int channel = s3eSoundGetFreeChannel();
	if(s3eSoundChannelPlay(channel, sound->buffer, sound->fileSize/2, 1, 0) == S3E_RESULT_ERROR)
		IGLog("Error in s3eSoundChannelPlay");
}

void Sounds::playClick() {
	if(Settings::getInstance()->soundEnabled == false)
		return;
	if(soundClick == NULL)
		soundClick = loadSound("click.raw");
	playSound(soundClick);
}

void Sounds::playSwish() {
	if(Settings::getInstance()->soundEnabled == false)
		return;
	if(soundSwish == NULL)
		soundSwish = loadSound("swish.raw");
	playSound(soundSwish);
}

void Sounds::playType() {
	if(Settings::getInstance()->soundEnabled == false)
		return;
	switch(rand()%3) {
		case 0:
			if(soundType1 == NULL)
				soundType1 = loadSound("type1.raw");
			playSound(soundType1);
			break;
		case 1:
			if(soundType2 == NULL)
				soundType2 = loadSound("type2.raw");
			playSound(soundType2);
			break;
		case 2:
			if(soundType3 == NULL)
				soundType3 = loadSound("type3.raw");
			playSound(soundType3);
			break;
	}
}

void Sounds::playDraw() {
	if(Settings::getInstance()->soundEnabled == false)
		return;
	switch(rand()%3) {
		case 0:
			if(soundDraw1 == NULL)
				soundDraw1 = loadSound("draw1.raw");
			playSound(soundDraw1);
			break;
		case 1:
			if(soundDraw2 == NULL)
				soundDraw2 = loadSound("draw2.raw");
			playSound(soundDraw2);
			break;
		case 2:
			if(soundDraw3 == NULL)
				soundDraw3 = loadSound("draw3.raw");
			playSound(soundDraw3);
			break;
	}
}

void Sounds::startMusic() {
	if(Settings::getInstance()->musicEnabled == false)
		return;
	if(AIRPLAY_DEVICE == "iphone") {
		if(s3eExtBackgroundMusicAvailable() == S3E_TRUE)
			if(s3eBackgroundMusicGetInt(S3E_BACKGROUNDMUSIC_PLAYBACK_STATE) == S3E_BACKGROUNDMUSIC_PLAYBACK_PLAYING)
				return;
	}

	IGLog("Sounds starting music");
	if(s3eAudioIsCodecSupported(S3E_AUDIO_CODEC_MP3))
		s3eAudioPlay("music.mp3", 0);
	else
		IGLog("Sounds mp3 codec not available on this system");
}

void Sounds::stopMusic() {
	IGLog("Sounds stopping music");
	if(s3eAudioIsPlaying() == S3E_TRUE)
		s3eAudioStop();
}
