#pragma once
#ifndef IG_TOUCHES_H
#define IG_TOUCHES_H

#include "s3e.h"
#include "ig_director.h"

// init and shutdown
void touchesInit();
void touchesShutdown();

// touch callbacks
void touchesButtonEvent(s3ePointerTouchEvent* event);
//void touchesMotionEvent(s3ePointerTouchEvent* event);

#endif // IG_TOUCHES_H