#include "scene_about.h"
#include "IwResManager.h"
#include "s3eExt_OSExec.h"
#include "scene_menu.h"
#include "sounds.h"

// back button
AboutButtonBack::AboutButtonBack() {
	imageNormalName = std::string("AboutBack1");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("AboutBack2");
	imageSelected = imageNormal;
	image = imageNormal;
	this->set(IGPoint(240,297));
	touchSize = IGRect(220,46);
	z = 1;
	tag = 0;
}
void AboutButtonBack::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void AboutButtonBack::buttonReleased() {
	removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneMenu()); 
}

// EFF button
AboutButtonEFF::AboutButtonEFF() {
	imageNormalName = std::string("AboutEFF");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("AboutEFF");
	imageSelected = imageNormal;
	image = imageNormal;
	this->set(IGPoint(120,167));
	touchSize = IGRect(240,71);
	z = 1;
	tag = 0;
}
void AboutButtonEFF::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void AboutButtonEFF::buttonReleased() {
	if(s3eExtOSExecAvailable() == S3E_TRUE) {
		s3eOSExecExecute("http://www.eff.org/", false);
	}
}

// GnuPG button
AboutButtonGnuPG::AboutButtonGnuPG() {
	imageNormalName = std::string("AboutGnuPG");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("AboutGnuPG");
	imageSelected = imageNormal;
	image = imageNormal;
	this->set(IGPoint(360,167));
	touchSize = IGRect(240,71);
	z = 1;
	tag = 0;
}
void AboutButtonGnuPG::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void AboutButtonGnuPG::buttonReleased() {
	if(s3eExtOSExecAvailable() == S3E_TRUE) {
		s3eOSExecExecute("http://www.gnupg.org/", false);
	}
}

// Truecrypt button
AboutButtonTruecrypt::AboutButtonTruecrypt() {
	imageNormalName = std::string("AboutTruecrypt");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("AboutTruecrypt");
	imageSelected = imageNormal;
	image = imageNormal;
	this->set(IGPoint(120,238));
	touchSize = IGRect(240,71);
	z = 1;
	tag = 0;
}
void AboutButtonTruecrypt::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void AboutButtonTruecrypt::buttonReleased() {
	if(s3eExtOSExecAvailable() == S3E_TRUE) {
		s3eOSExecExecute("http://www.truecrypt.org/", false);
	}
}

// feedback button
AboutButtonFeedback::AboutButtonFeedback() {
	imageNormalName = std::string("AboutFeedback");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("AboutFeedback");
	imageSelected = imageNormal;
	image = imageNormal;
	this->set(IGPoint(360,238));
	touchSize = IGRect(240,71);
	z = 1;
	tag = 0;
}
void AboutButtonFeedback::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void AboutButtonFeedback::buttonReleased() {
	if(s3eExtOSExecAvailable() == S3E_TRUE) {
		s3eOSExecExecute("http://www.insurgentgames.com/contact/", false);
	}
}

// about scene
SceneAbout::SceneAbout() {
	IGScene::IGScene();
	IGLog("SceneAbout init");

	// load the resources
	IwGetResManager()->LoadGroup("about.group");

	// the background
	IGSprite* spriteBackground = new IGSprite("BackgroundLights", IGPoint(240,160), 0);
	this->addChild(spriteBackground);

	// the header, text
	IGSprite* spriteHeader = new IGSprite("AboutHeader", IGPoint(240,39), 1);
	this->addChild(spriteHeader);
	IGSprite* spriteText = new IGSprite("AboutText", IGPoint(240,98), 1);
	this->addChild(spriteText);

	// the buttons
	AboutButtonEFF* buttonEFF = new AboutButtonEFF();
	this->addChild(buttonEFF);
	AboutButtonGnuPG* buttonGnuPG = new AboutButtonGnuPG();
	this->addChild(buttonGnuPG);
	AboutButtonTruecrypt* buttonTruecrypt = new AboutButtonTruecrypt();
	this->addChild(buttonTruecrypt);
	AboutButtonFeedback* buttonFeedback = new AboutButtonFeedback();
	this->addChild(buttonFeedback);
	AboutButtonBack* buttonBack = new AboutButtonBack();
	this->addChild(buttonBack);

	// kevin macleod
	IGSprite* spriteMusicCredit = new IGSprite("AboutMusicCredit", IGPoint(416,304), 2);
	spriteMusicCredit->setOpacity(196);
	this->addChild(spriteMusicCredit);
}

SceneAbout::~SceneAbout() {
}

void SceneAbout::update() {
	// check for back button
	s3eKeyboardUpdate();
	if(s3eKeyboardGetState(s3eKeyAbsBSK) != 0) {
		removeAllChildren();
		IGDirector::getInstance()->switchScene(new SceneMenu());
	}

	// update children
	IGNode::update();
}
