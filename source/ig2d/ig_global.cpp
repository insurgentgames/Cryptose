#include "ig_global.h"

// debug message to console
void IGLog(const char* str) {
	char newStr[256];
	sprintf(newStr, "IG2D: %s", str);
	s3eDebugOutputString(newStr);
}

// IGPoint methods
IGPoint::IGPoint() {
	x = 0;
	y = 0;
}

IGPoint::IGPoint(float _x, float _y) {
	x = _x;
	y = _y;
}

IGPoint::IGPoint(int _x, int _y) {
	x = (float)_x;
	y = (float)_y;
}

IGPoint::IGPoint(const IGPoint& p) {
	x = p.x;
	y = p.y;
}

IGPoint::~IGPoint() {
}

// IGRect methods
IGRect::IGRect() {
	width = 0;
	height = 0;
}

IGRect::IGRect(float _width, float _height) {
	width = _width;
	height = _height;
}

IGRect::IGRect(int _width, int _height) {
	width = (float)_width;
	height = (float)_height;
}

IGRect::IGRect(const IGRect& r) {
	width = r.width;
	height = r.height;
}

IGRect::~IGRect() {
}
