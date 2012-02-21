#pragma once
#ifndef IG_GLOBAL_H
#define IG_GLOBAL_H

#include "Iw2D.h"

// debug to the console
void IGLog(const char* str);

// points and rects
class IGPoint {
public:
	float x, y;
	
	IGPoint();
	IGPoint(float _x, float _y);
	IGPoint(int _x, int _y);
	IGPoint(const IGPoint& p);
	virtual ~IGPoint();
};

class IGRect {
public:
	float width, height;

	IGRect();
	IGRect(float _width, float _height);
	IGRect(int _width, int _height);
	IGRect(const IGRect& r);
	virtual ~IGRect();
};

#endif // IG_GLOBAL_H