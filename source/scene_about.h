#pragma once
#ifndef SCENE_ABOUT_H
#define SCENE_ABOUT_H

#include "Iw2D.h"
#include "ig2d/ig.h"

// back button
class AboutButtonBack: public IGButton {
public:
	AboutButtonBack();
	void buttonPressed();
	void buttonReleased();
};

// EFF button
class AboutButtonEFF: public IGButton {
public:
	AboutButtonEFF();
	void buttonPressed();
	void buttonReleased();
};

// GnuPG button
class AboutButtonGnuPG: public IGButton {
public:
	AboutButtonGnuPG();
	void buttonPressed();
	void buttonReleased();
};

// Truecrypt button
class AboutButtonTruecrypt: public IGButton {
public:
	AboutButtonTruecrypt();
	void buttonPressed();
	void buttonReleased();
};

// feedback button
class AboutButtonFeedback: public IGButton {
public:
	AboutButtonFeedback();
	void buttonPressed();
	void buttonReleased();
};

// about scene
class SceneAbout: public IGScene {
public:
	SceneAbout();
	~SceneAbout();
	void update();
};

#endif // SCENE_ABOUT_H