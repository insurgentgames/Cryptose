#include "ig_director.h"
#include "ig_global.h"
#include "Iw2D.h"

IGDirector* IGDirector::instance = NULL;

IGDirector* IGDirector::getInstance() {
	if(instance == NULL)
		instance = new IGDirector();
	return instance;
}

IGDirector::IGDirector() {
	IGLog("Director init");
	scene = NULL;
}

IGDirector::~IGDirector() {
	if(scene != NULL)
		delete scene;
}

void IGDirector::shutdown() {
	if(instance != NULL)
		delete instance;
}

void IGDirector::switchScene(IGScene* _scene) {
	IGScene* sceneToDelete = scene;
	scene = _scene;
	if(sceneToDelete != NULL)
		delete sceneToDelete;
}

void IGDirector::display() {
	if(scene != NULL)
		scene->display();
	Iw2DFinishDrawing();
}

void IGDirector::update() {
	if(scene != NULL)
		scene->update();
}

void IGDirector::touch(s3ePointerTouchEvent* event) {
	if(scene != NULL)
		scene->touch(event);
}
