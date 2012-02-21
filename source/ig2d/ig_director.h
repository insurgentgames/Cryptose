#pragma once
#ifndef IG_DIRECTOR_H
#define IG_DIRECTOR_H

#include "s3e.h"
#include "ig_scene.h"

class IGDirector {
public:
	// return the instance of Director
	static IGDirector* getInstance();
	
	// current scene
	IGScene* scene;

	// constructor and destructor
	IGDirector();
	~IGDirector();
	static void shutdown();

	// manage scenes
	void switchScene(IGScene* _scene);

	// display and update
	void display();
	void update();

	// hand touches for the current scene
	void touch(s3ePointerTouchEvent* event);

private:
	static IGDirector* instance;
};

#endif // IG_DIRECTOR_H