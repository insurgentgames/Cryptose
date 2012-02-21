#include "ig_button.h"
#include "ig_resource_manager.h"

IGButton::IGButton() {
	imageNormal = NULL;
	imageSelected = NULL;
	image = NULL;
	position = IGPoint();
	size = IGRect();
	z = 0;
	tag = 0;
}

IGButton::IGButton(const IGButton& b) {
	imageNormal = b.imageNormal;
	imageSelected = b.imageSelected;
	image = imageNormal;
	position = IGPoint(b.position);
	size = IGRect(b.size);
	z = b.z;
	tag = b.tag;
}

IGButton::IGButton(const char *resource, const char *selectedResource, IGPoint _position, IGRect _size, IGRect _touchSize, int _z, int _tag) {
	imageNormalName = std::string(resource);
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string(selectedResource);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(_position, _size);
	touchSize = _touchSize;
	z = _z;
	tag = _tag;
}

IGButton::~IGButton() {
	image = NULL;
	IGResourceManager::getInstance()->freeImage(imageNormalName);
	IGResourceManager::getInstance()->freeImage(imageSelectedName);
}

bool IGButton::touch(s3ePointerTouchEvent* event) {
	float x = IGDistorter::getInstance()->distortBackX((float)event->m_x);
	float y = IGDistorter::getInstance()->distortBackY((float)event->m_y);
	
	// if the event occured within this button
	if(x >= position.x - (touchSize.width/2) &&
		x < position.x + (touchSize.width/2) && 
		y >= position.y - (touchSize.height/2) &&
		y < position.y + (touchSize.height/2)) {
		// touch down
		if(event->m_Pressed) {
			image = imageSelected;
			buttonPressed();
		}
		// release
		else {
			image = imageNormal;
			buttonReleased();
		}
		return true;
	} else {
		image = imageNormal;
	}
	return false;
}

void IGButton::buttonPressed() {
	// for overriding
}

void IGButton::buttonReleased() {
	// for overriding
}