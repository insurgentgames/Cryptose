#pragma once
#ifndef IG_ANIMATION_H
#define IG_ANIMATION_H

#include <vector>
#include <string>
#include "ig_sprite.h"

/* this class is for inheriting */
class IGAnimation: public IGSprite {
public:
	IGAnimation();
	virtual ~IGAnimation();
	void update();
	void firstFrame();
	void addFrame(std::string name);
	void setFPS(float framesPerSecond);
	
protected:
	struct Frame {
		CIw2DImage* image;
		std::string name;
	};
	
	std::vector<IGAnimation::Frame*> frames;
	std::vector<IGAnimation::Frame*>::iterator currentFrame;

	float delay;
	int64 start;
};

#endif // IG_ANIMATION_H