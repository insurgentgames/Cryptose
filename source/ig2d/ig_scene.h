#pragma once
#ifndef IG_SCENE_H
#define IG_SCENE_H

#include "ig_node.h"

class IGScene: public IGNode {
public:
	IGScene();
	static void unloadResources();
	virtual void display();
};

#endif // IG_SCENE_H