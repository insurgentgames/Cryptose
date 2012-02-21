#include "ig_label.h"
#include "ig_resource_manager.h"

IGLabel::IGLabel() {
	image = NULL;
	position = IGPoint();
	size = IGRect();
	z = 0;
	tag = 0;
	this->setOpacity(255);
	str = std::string("");
	font = NULL;
	alignHorizontal = IW_2D_FONT_ALIGN_CENTRE;
	alignVertical = IW_2D_FONT_ALIGN_CENTRE;
}

IGLabel::IGLabel(const IGLabel& s) {
	image = NULL;
	position = IGPoint(s.position);
	size = IGRect(s.size);
	z = s.z;
	tag = s.tag;
	fontName = s.fontName;
	font = s.font;
	alignHorizontal = s.alignHorizontal;
	alignVertical = s.alignVertical;
	color = s.color;
	setString(s.str);
}

IGLabel::IGLabel(const char *resource, std::string _str, IGPoint _position, IGRect _size, int _z, int _tag) {
	image = NULL;
	set(_position, _size);
	z = _z;
	tag = _tag;
	fontName = std::string(resource);
	font = IGResourceManager::getInstance()->getFont(fontName);
	alignHorizontal = IW_2D_FONT_ALIGN_CENTRE;
	alignVertical = IW_2D_FONT_ALIGN_CENTRE;
	setOpacity(255);
	setString(_str);
}

IGLabel::~IGLabel() {
	if(font != NULL)
		IGResourceManager::getInstance()->freeFont(fontName);
}

void IGLabel::display() {
	if(font != NULL) {
		Iw2DSetFont(font);		// set the font
		Iw2DSetColour(color);	// set the color
		
		// draw the string
		Iw2DDrawString(str.c_str(),
			CIwSVec2((int16)((position.x-size.width/2)+IGDistorter::getInstance()->offsetX), (int16)((position.y-size.height/2)+IGDistorter::getInstance()->offsetY)),
			CIwSVec2((int16)size.width, (int16)size.height),
			alignHorizontal, alignVertical);
	}
}

void IGLabel::setString(std::string _str) {
	str = _str;
}
