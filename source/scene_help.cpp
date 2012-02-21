#include "scene_help.h"
#include "IwResManager.h"
#include "scene_menu.h"
#include "sounds.h"

// continue sprite
HelpContinue::HelpContinue() {
	imageName = std::string("HelpContinue");
	image = IGResourceManager::getInstance()->getImage(imageName);
	set(IGPoint(240,297));
	z = 1;
	tag = SceneHelpTagContinue;
	startOver();
}
void HelpContinue::update() {
	if(fadeCount < 50) {
		if(s3eTimerGetMs() - start >= 10) { // .01 seconds
			start = s3eTimerGetMs();
			fadeCount++;
			setOpacity((uint8)(fadeCount*(float)(255.0/50.0)));
		}
	}
}
void HelpContinue::startOver() {
	setOpacity(0);
	fadeCount = 0;
	start = s3eTimerGetMs();
}

// help scene
SceneHelp::SceneHelp() {
	IGScene::IGScene();
	IGLog("SceneHelp init");

	stage = 0;

	// load the resources
	IwGetResManager()->LoadGroup("help.group"); 

	// page
	IGSprite* pageSprite = new IGSprite("HelpPage1", IGPoint(240,160), 0, SceneHelpTagPage);
	this->addChild(pageSprite);

	// continue
	HelpContinue* continueSprite = new HelpContinue();
	this->addChild(continueSprite);
}

SceneHelp::~SceneHelp() {
}

bool SceneHelp::touch(s3ePointerTouchEvent* event) {
	IGSprite* pageSprite = NULL;
	HelpContinue* continueSprite = NULL;

	if(event->m_Pressed == 0) {
		switch(stage) {
			case 0: // switch to page 2
				// change sprites
				this->removeChildByTag(SceneHelpTagPage);
				pageSprite = new IGSprite("HelpPage2", IGPoint(240,160), 0, SceneHelpTagPage);
				this->addChild(pageSprite);

				// restart continue
				continueSprite = (HelpContinue*)this->getChildByTag(SceneHelpTagContinue);
				continueSprite->startOver();

				// next stage
				stage++;
				break;
			case 1: // switch to page 3
				// change sprites
				this->removeChildByTag(SceneHelpTagPage);
				pageSprite = new IGSprite("HelpPage3", IGPoint(240,160), 0, SceneHelpTagPage);
				this->addChild(pageSprite);

				// restart continue
				continueSprite = (HelpContinue*)this->getChildByTag(SceneHelpTagContinue);
				continueSprite->startOver();

				// next stage
				stage++;
				break;
			case 2: // go back to menu
				removeAllChildren();
				IGDirector::getInstance()->switchScene(new SceneMenu());
				break;
		}
	} else {
		Sounds::getInstance()->playClick();
	}
	return true;
}