#include "ig_sprite.h"
#include "ig_resource_manager.h"
#include "ig_distorter.h"

IGSprite::IGSprite() {
	image = NULL;
	position = IGPoint();
	size = IGRect();
	z = 0;
	tag = 0;
	this->setOpacity(255);
}

IGSprite::IGSprite(const IGSprite& s) {
	imageName = s.imageName;
	image = s.image;
	position = IGPoint(s.position);
	size = IGRect(s.size);
	z = s.z;
	tag = s.tag;
	this->setOpacity(255);
}

IGSprite::IGSprite(const char *resource, IGPoint _position, int _z, int _tag) {
	imageName = std::string(resource);
	image = IGResourceManager::getInstance()->getImage(imageName);
	this->set(_position, IGRect(image->GetWidth(), image->GetHeight()));
	z = _z;
	tag = _tag;
	this->setOpacity(255);
}

IGSprite::IGSprite(const char *resource, IGPoint _position, IGRect _size, int _z, int _tag) {
	imageName = std::string(resource);
	image = IGResourceManager::getInstance()->getImage(imageName);
	this->set(_position, _size);
	z = _z;
	tag = _tag;
	this->setOpacity(255);
}

IGSprite::~IGSprite() {
	if(image != NULL)
		IGResourceManager::getInstance()->freeImage(imageName);
}

void IGSprite::set(IGPoint _position) {
	set(_position, IGRect(image->GetWidth(), image->GetHeight()));
}

void IGSprite::set(IGPoint _position, IGRect _size) {
	position = IGPoint(_position);
	size = IGRect(_size);
}

void IGSprite::setColor(uint8 r, uint8 g, uint8 b, uint8 a) {
	CIwColour c = CIwColour();
	c.Set(r, g, b, a);
	color = c.Get();
}

void IGSprite::setOpacity(uint8 opacity) {
	setColor(255, 255, 255, opacity);
}

void IGSprite::changeImage(const char *resource) {
	if(image != NULL)
		IGResourceManager::getInstance()->freeImage(imageName);
	imageName = std::string(resource);
	image = IGResourceManager::getInstance()->getImage(imageName);
	this->set(position, IGRect(image->GetWidth(), image->GetHeight()));
}

void IGSprite::display() {
	if(image != NULL) {
		// set the opacity
		Iw2DSetColour(color);
		
		// display the image
		Iw2DDrawImage(image,
			CIwSVec2((int16)((position.x-size.width/2)+IGDistorter::getInstance()->offsetX), 
				(int16)((position.y-size.height/2)+IGDistorter::getInstance()->offsetY)),
			CIwSVec2((int16)size.width, (int16)size.height));
	}
}
