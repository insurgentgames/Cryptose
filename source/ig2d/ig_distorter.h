#pragma once
#ifndef IG_DISTORTER_H
#define IG_DISTORTER_H

#include "Iw2D.h"
#include "ig_global.h"

class IGDistorter {
public:
	// return the instance
	static IGDistorter* getInstance();
	
	// constructor and destructor
	IGDistorter();
	~IGDistorter();
	static void shutdown();
	
	// initialize
	void set(float _designWidth, float _designHeight);
	
	// do the distortions
	float distortX(float x);
	float distortY(float y);
	float distortBackX(float x);
	float distortBackY(float y);

	// offsets
	float offsetX;
	float offsetY;
	float multiply;

	// some colors
	CIwColour colorBlack;
	uint32 colorBlackInt;
	CIwColour colorWhite;
	uint32 colorWhiteInt;

	// transformation matrix
	CIwMat2D *matrix;

private:
	static IGDistorter* instance;
	
	// resolution graphics were designed for
	float designWidth;
	float designHeight;

	// resolution of the screen
	float screenWidth;
	float screenHeight;
};

#endif // IG_DISTORTER_H