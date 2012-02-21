#include "ig_distorter.h"

IGDistorter* IGDistorter::instance = NULL;

IGDistorter* IGDistorter::getInstance() {
	if(instance == NULL)
		instance = new IGDistorter();
	return instance;
}

IGDistorter::IGDistorter() {
	IGLog("Distorter init");

	screenWidth = (float)Iw2DGetSurfaceWidth();
	screenHeight = (float)Iw2DGetSurfaceHeight();
	matrix = NULL;
	
	char debugStr[200];
	sprintf(debugStr, "screen width: %i, height: %i", (int)screenWidth, (int)screenHeight);
	IGLog(debugStr);
	
	// colors
	colorBlack.Set(0, 0, 0, 255);
	colorBlackInt = colorBlack.Get();
	colorWhite.Set(255, 255, 255, 255);
	colorWhiteInt = colorWhite.Get();
}

IGDistorter::~IGDistorter() {
	if(matrix != NULL)
		delete matrix;
}

void IGDistorter::shutdown() {
	if(instance != NULL)
		delete instance;
}

void IGDistorter::set(float _designWidth, float _designHeight) {
	designWidth = _designWidth;
	designHeight = _designHeight;

	// make sure we're dealing with portrait or landscape
	if(designWidth > designHeight) {
		if(screenHeight > screenWidth) {
			float tmp = screenWidth;
			screenWidth = screenHeight;
			screenHeight = tmp;
		}
	} else {
		if(screenWidth > screenHeight) {
			float tmp = screenWidth;
			screenWidth = screenHeight;
			screenHeight = tmp;
		}
	}
	
	float designAspectRatio = designWidth / designHeight;
	float screenAspectRation = screenWidth / screenHeight;
	if(designAspectRatio == screenAspectRation) {
		multiply = screenHeight / designHeight;
		offsetX = 0;
		offsetY = 0;
	} else if(designAspectRatio < screenAspectRation) {
		multiply = screenHeight / designHeight;
		offsetX = ((screenWidth/multiply) - designWidth) / 2;
		offsetY = 0;
	} else {
		multiply = screenWidth / designWidth;
		offsetX = 0;
		offsetY = ((screenHeight/multiply) - designHeight) / 2;
	}

	char debugStr[200];
	sprintf(debugStr, "design width: %i, height: %i", (int)designWidth, (int)designHeight);
	IGLog(debugStr);
	sprintf(debugStr, "offsetX: %.2f, offsetY: %.2f, multiply: %.2f", offsetX, offsetY, multiply);
	IGLog(debugStr);
	
	// set the scaling matrix
	matrix = new CIwMat2D();
	matrix->SetIdentity();
	matrix->Scale(IW_FIXED(multiply));
	Iw2DSetTransformMatrix(*matrix);
}

float IGDistorter::distortX(float x) {
	return multiply * x + offsetX;
}

float IGDistorter::distortY(float y) {
	return multiply * y + offsetY;
}
float IGDistorter::distortBackX(float x) {
	return x / multiply - offsetX;
}

float IGDistorter::distortBackY(float y) {
	return y / multiply - offsetY;
}

/*void IGDistorter::display(CIw2DImage* image, IGPoint position, IGRect size) {
	Iw2DDrawImage(image, 
		CIwSVec2((int16)(offsetX+multiply*(position.x+size.width/2)), (int16)(offsetY+multiply*(position.y+size.height/2))), 
		CIwSVec2((int16)(multiply*(size.width)), (int16)(multiply*(size.height))));

	Iw2DDrawImageRegion(image,
		CIwSVec2(0, 0),
		CIwSVec2((int16)screenWidth, (int16)screenHeight),
		CIwSVec2((int16)(offsetX),(int16)(offsetY)),
		CIwSVec2((int16)(designWidth+2*offsetX), (int16)(designHeight+2*offsetY)));
}*/
