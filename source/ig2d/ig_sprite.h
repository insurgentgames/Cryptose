#pragma once
#ifndef IG_SPRITE_H
#define IG_SPRITE_H

#include "Iw2D.h"
#include "ig_global.h"
#include "ig_distorter.h"
#include "ig_node.h"
#include <string>

class IGSprite: public IGNode {
public:
	CIw2DImage* image;
	IGPoint position;
	IGRect size;
	std::string imageName;
	
	// constructor and destructor
	IGSprite();
	IGSprite(const IGSprite& s);
	IGSprite(const char *resource, IGPoint _position, int _z=0, int _tag=0);
	IGSprite(const char *resource, IGPoint _position, IGRect _size, int _z=0, int _tag=0);
	virtual ~IGSprite();

	// set where the sprite will display
	void set(IGPoint _position);
	void set(IGPoint _position, IGRect _size);
	void setColor(uint8 r, uint8 g, uint8 b, uint8 a);
	void setOpacity(uint8 opacity);
	void changeImage(const char *resource);
	
	// display
	virtual void display();
	
protected:
	uint32 color;
};

#endif // IG_SPRITE_H
