#include "ig_scene.h"
#include "ig_resource_manager.h"
#include "ig_distorter.h"
#include "IwResManager.h"

IGScene::IGScene() {
	IGScene::unloadResources();
}

void IGScene::unloadResources() {
	// unload all resource groups
	int numGroups = IwGetResManager()->GetNumGroups();
	for(int i=0; i<numGroups; i++) {
		CIwResGroup* group = IwGetResManager()->GetGroup(i); 
		IwGetResManager()->DestroyGroup(group);
	}

	// delete resources in memory
	IGResourceManager::getInstance()->freeAllResources();
}

void IGScene::display() {
	// clear the screen
	Iw2DSetColour(IGDistorter::getInstance()->colorBlackInt);
	Iw2DFillRect(CIwSVec2(0,0), CIwSVec2(Iw2DGetSurfaceWidth(), Iw2DGetSurfaceHeight()));

	// display all the children
	IGNode::display();
}
