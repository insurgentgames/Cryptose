#pragma once
#ifndef SCENE_FACT_H
#define SCENE_FACT_H

#include "Iw2D.h"
#include "ig2d/ig.h"

// random fact
class FactLabel: public IGLabel {
public:
	FactLabel();
};

// continue sprite
class FactContinue: public IGSprite {
public:
	FactContinue();
	void update();
	int stage;
	int fadeCount;
	int64 start;
};

// scene fact
class SceneFact: public IGScene {
public:
	SceneFact();
	~SceneFact();
	bool touch(s3ePointerTouchEvent* event);
};

#endif // SCENE_FACT_H