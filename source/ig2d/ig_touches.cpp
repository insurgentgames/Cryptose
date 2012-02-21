#include "ig_touches.h"

void touchesInit() {
	// set up callbacks
	if(s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE)) {
		s3ePointerRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)touchesButtonEvent, NULL);
		//s3ePointerRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)touchesMotionEvent, NULL);
	} else {
		s3ePointerRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)touchesButtonEvent, NULL);
		//s3ePointerRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)touchesMotionEvent, NULL);
	}
}

void touchesShutdown() {
	if(s3ePointerGetInt(S3E_POINTER_MULTI_TOUCH_AVAILABLE)) {
		s3ePointerUnRegister(S3E_POINTER_TOUCH_EVENT, (s3eCallback)touchesButtonEvent);
		//s3ePointerUnRegister(S3E_POINTER_TOUCH_MOTION_EVENT, (s3eCallback)touchesMotionEvent);
	} else {
		s3ePointerUnRegister(S3E_POINTER_BUTTON_EVENT, (s3eCallback)touchesButtonEvent);
		//s3ePointerUnRegister(S3E_POINTER_MOTION_EVENT, (s3eCallback)touchesMotionEvent);
	}
}

void touchesButtonEvent(s3ePointerTouchEvent* event) {
	IGDirector::getInstance()->touch(event);
}

/*void touchesMotionEvent(s3ePointerTouchEvent* event) {
}*/
