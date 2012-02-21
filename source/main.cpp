#include "config.h" // edit config.h to set the device you're building for
#include <stdlib.h>
#include <time.h>
#include "s3e.h"
#include "IwGx.h"
#include "Iw2D.h"
#include "derbh.h"
#include "ig2d/ig.h"
#include "ig2d/ig_global.h"
#include "scene_menu.h"
#include "settings.h"
#include "sounds.h"


// attempt to lock frame rate to 30 fps
#define	MS_PER_FRAME (1000 / 30)

void gameInit() {
	// seed the random number generator
	srand(time(NULL));
	
	// load archives
	if(dzArchiveAttach("sounds.dz") == S3E_RESULT_ERROR)
		IGLog("Error attaching derbh archive sounds.dz");

	// iphone, bada only need gles1
	if(AIRPLAY_DEVICE == "bada" || AIRPLAY_DEVICE == "iphone") {
		if(dzArchiveAttach("gles1.dz") == S3E_RESULT_ERROR)
			IGLog("Error attaching derbh archive gles1.dz");
	}
	// android needs gles1 and gles1-atitc
	else if(AIRPLAY_DEVICE == "android") {
		char buildStyle[128];
		if(s3eConfigGetString("RESMANAGER", "ResBuildStyle", buildStyle) == S3E_RESULT_SUCCESS) {
			if((strcmp(buildStyle, "gles1") != 0) && strcmp(buildStyle, "gles1-atitc") != 0)
				sprintf(buildStyle, "gles1");

			char buffer[128];
			sprintf(buffer, "%s.dz", buildStyle);
			if(dzArchiveAttach(buffer) == S3E_RESULT_ERROR) {
				sprintf(buffer, "Error attaching derbh archive %s.dz", buildStyle);
				IGLog(buffer);
			}
		} else {
			IGLog("Error, no buildStyle");
		}
	}
	
	// init
	Iw2DInit();
	IwResManagerInit();
	//IwMemBucketDebugSetBreakpoint(10756);
	touchesInit();
	IGDistorter::getInstance()->set(480, 320);
	IGResourceManager::getInstance();
	Settings::getInstance();
	Sounds::getInstance();
}

void gameStart() {
	// start with the menu scene
	IGDirector::getInstance()->switchScene(new SceneMenu()); 
}

void gameShutdown() {
	// unload all extra resource groups
	IGScene::unloadResources();
	
	// shut down the game
	IGDirector::shutdown();

	// shutdown
	touchesShutdown();
	IGDistorter::shutdown();
	IGResourceManager::shutdown();
	Settings::shutdown();
	Sounds::shutdown();
	IwResManagerTerminate();
	Iw2DTerminate();
	dzArchiveDetach();
}

void gameJustGenerateTextures() {
	// load all the textures and exit (to generate compressed ones)
	IwGetResManager()->LoadGroup("about.group");
	IwGetResManager()->LoadGroup("fact.group");
	IwGetResManager()->LoadGroup("game_detective.group");
	IwGetResManager()->LoadGroup("game_espionage.group");
	IwGetResManager()->LoadGroup("game_hacker.group");
	IwGetResManager()->LoadGroup("help.group");
	IwGetResManager()->LoadGroup("menu.group");
}

int main(int argc, char* argv[]) {
	gameInit();
	
	// uncomment to just generate textures and not load the game
	//gameJustGenerateTextures(); return 0;

	gameStart();
	
	// game loop
	int32 frame = 0;
	while(1) { 
		// let airplay do it's thing each frame
		s3eDeviceYield(0); 
		s3eKeyboardUpdate();
		s3ePointerUpdate();
		int64 start = s3eTimerGetMs();
		
		// update
		frame++;
		IGDirector::getInstance()->update();
		if(s3eDeviceCheckQuitRequest())
			break; 
		
		// render graphics
		IGDirector::getInstance()->display();
		Iw2DSurfaceShow();
		
		// attempt frame rate
		while((s3eTimerGetMs() - start) < MS_PER_FRAME) {
			int32 yield = (int32) (MS_PER_FRAME - (s3eTimerGetMs() - start));
			if(yield < 0)
				break;
			s3eDeviceYield(yield);
		}
	}
	
	// shutdown
	gameShutdown();
	return 0;
} 
