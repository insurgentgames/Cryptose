#include "ig_animation.h"
#include "ig_resource_manager.h"

IGAnimation::IGAnimation() {
	image = NULL;
	position = IGPoint();
	size = IGRect();
	z = 0;
	tag = 0;
	delay = 0;
	start = s3eTimerGetMs();
	currentFrame = frames.begin();
}

IGAnimation::~IGAnimation() {
	std::vector<IGAnimation::Frame*>::iterator i = frames.begin();
	while(i!=frames.end()) {
		IGAnimation::Frame* frame = *i;
		if(frame->image != NULL)
			IGResourceManager::getInstance()->freeImage(frame->name);
		i = frames.erase(i);
		delete frame;
	}
	image = NULL;
}

void IGAnimation::update() {
	if((s3eTimerGetMs() - start) >= delay) {
		start = s3eTimerGetMs();
		
		// next frame
		currentFrame++;
		if(currentFrame == frames.end()) {
			currentFrame = frames.begin();
		}
		image = ((IGAnimation::Frame*)(*currentFrame))->image;
	}
}

void IGAnimation::firstFrame() {
	currentFrame = frames.begin();
	image = ((IGAnimation::Frame*)(*currentFrame))->image;
}

void IGAnimation::addFrame(std::string name) {
	IGAnimation::Frame* frame = new IGAnimation::Frame;
	frame->name = name;
	frame->image = IGResourceManager::getInstance()->getImage(frame->name);
	frames.push_back(frame);
}

void IGAnimation::setFPS(float framesPerSecond) {
	delay = 1000 / framesPerSecond;
}