#pragma once
#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "Iw2D.h"
#include "ig2d/ig.h"

// custom buttons
class MenuButtonDecrypt: public IGButton {
public:
	MenuButtonDecrypt();
	void buttonPressed();
	void buttonReleased();
};
class MenuButtonHelp: public IGButton {
public:
	MenuButtonHelp();
	void buttonPressed();
	void buttonReleased();
};
class MenuButtonAbout: public IGButton {
public:
	MenuButtonAbout();
	void buttonPressed();
	void buttonReleased();
};
class MenuButtonMoreGames: public IGButton {
public:
	MenuButtonMoreGames();
	void buttonPressed();
	void buttonReleased();
};

// animation
class MenuAnimation: public IGAnimation {
public:
	MenuAnimation();
};

// sound and music buttons
typedef enum {
	SceneMenuSound = 1,
	SceneMenuMusic = 2
} SceneMenuTag;
class MenuSoundButton: public IGButton {
public:
	MenuSoundButton();
	void buttonPressed();
	void buttonReleased();
};
class MenuMusicButton: public IGButton {
public:
	MenuMusicButton();
	void buttonPressed();
	void buttonReleased();
};

// menu scene
class SceneMenu: public IGScene {
public:
	SceneMenu();
	~SceneMenu();
	void update();
	bool touch(s3ePointerTouchEvent* event);

private:
	IGSprite* themeHacker;
	IGSprite* themeDetective;
	IGSprite* themeEspionage;
	int64 themeMovingStart;
	int themeMovingCount;
	int themeCurrent; // 0 hacker, 1 detective, 2 espionage
	bool themeMoving;
	bool themeDirection; // true is right, false is left
	float themeTouchX, themeTouchY;
};

#endif // SCENE_MENU_H