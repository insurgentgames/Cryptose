#pragma once
#ifndef IG_LABEL_H
#define IG_LABEL_H

#include <string>
#include "ig_sprite.h"

class IGLabel: public IGSprite {
public:
	std::string fontName;
	CIw2DFont* font;

	// constructor and destructor
	IGLabel();
	IGLabel(const IGLabel& s);
	IGLabel(const char *resource, std::string _str, IGPoint _position, IGRect _size, int _z=0, int _tag=0);
	virtual ~IGLabel();

	// display
	virtual void display();

	// set the string
	void setString(std::string _str);

	// alignment
	CIw2DFontAlign alignHorizontal;
	CIw2DFontAlign alignVertical;

protected:
	std::string str;
};

#endif // IG_LABEL_H