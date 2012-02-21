#pragma once
#ifndef IG_BUTTON_H
#define IG_BUTTON_H

#include "Iw2D.h"
#include "ig_global.h"
#include "ig_distorter.h"
#include "ig_sprite.h"

class IGButton: public IGSprite {
public:
	CIw2DImage* imageNormal; // normal image
	CIw2DImage* imageSelected; // selected image
	std::string imageNormalName;
	std::string imageSelectedName;
	IGRect touchSize;

	// constructors and destructors
	IGButton();
	IGButton(const IGButton& b);
	IGButton(const char *resource, const char *selectedResource, IGPoint _position, IGRect _size, IGRect _touchSize, int _z=0, int _tag=0);
	virtual ~IGButton();
	
	// pass a touch to the sprite, return true if handled
	bool touch(s3ePointerTouchEvent* event);
	virtual void buttonReleased();
	virtual void buttonPressed();
};

#endif // IG_BUTTON_H