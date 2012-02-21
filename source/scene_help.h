#pragma once
#ifndef SCENE_HELP_H
#define SCENE_HELP_H

#include "Iw2D.h"
#include "ig2d/ig.h"

// children
typedef enum {
	SceneHelpTagPage = 1,
	SceneHelpTagContinue = 2
} SceneHelpTag;

// continue sprite
class HelpContinue: public IGSprite {
public:
	HelpContinue();
	void update();
	void startOver();
	int fadeCount;
	int64 start;
};

// help scene
class SceneHelp: public IGScene {
public:
	SceneHelp();
	~SceneHelp();
	bool touch(s3ePointerTouchEvent* event);
	int stage;
};

#endif // SCENE_HELP_H