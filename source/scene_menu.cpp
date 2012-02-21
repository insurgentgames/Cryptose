#include "scene_menu.h"
#include "IwResManager.h"
#include "s3eExt_OSExec.h"
#include "scene_fact.h"
#include "scene_game.h"
#include "scene_help.h"
#include "scene_about.h"
#include "settings.h"
#include "sounds.h"
#include <math.h>

// decrypt button
MenuButtonDecrypt::MenuButtonDecrypt() {
	imageNormalName = std::string("MenuDecrypt");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuDecrypt2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(138,125));
	touchSize = IGRect(276,50);
	z = 2;
	tag = 0;
}
void MenuButtonDecrypt::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void MenuButtonDecrypt::buttonReleased() {
	parent->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneGame());
}

// help button
MenuButtonHelp::MenuButtonHelp() {
	imageNormalName = std::string("MenuHelp");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuHelp2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(138,175));
	touchSize = IGRect(276,50);
	z = 2;
	tag = 0;
}
void MenuButtonHelp::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void MenuButtonHelp::buttonReleased() {
	parent->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneHelp());
}

// about button
MenuButtonAbout::MenuButtonAbout() {
	imageNormalName = std::string("MenuAbout");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuAbout2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(138,225));
	touchSize = IGRect(276,50);
	z = 2;
	tag = 0;
}
void MenuButtonAbout::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void MenuButtonAbout::buttonReleased() {
	parent->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneAbout());
}

// more games button
MenuButtonMoreGames::MenuButtonMoreGames() {
	imageNormalName = std::string("MenuMoreGames");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuMoreGames2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(306,175));
	touchSize = IGRect(60,150);
	z = 2;
	tag = 0;
}
void MenuButtonMoreGames::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void MenuButtonMoreGames::buttonReleased() {
	if(s3eExtOSExecAvailable() == S3E_TRUE)
		s3eOSExecExecute("http://othergames.insurgentgames.com/cryptose/", true);
}

// menu animation
MenuAnimation::MenuAnimation() {
	addFrame(std::string("MenuAnim1"));
	addFrame(std::string("MenuAnim2"));
	addFrame(std::string("MenuAnim3"));
	addFrame(std::string("MenuAnim4"));
	firstFrame();
	this->set(IGPoint(408,175));
	this->setFPS(10);
	z = 2;
	tag = 0;
}

// sound button
MenuSoundButton::MenuSoundButton() {
	imageNormalName = std::string("MenuSound");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuSound2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(450,295));
	touchSize = IGRect(60,50);
	z = 3;
	tag = SceneMenuSound;
	if(Settings::getInstance()->soundEnabled)
		this->setOpacity(255);
	else
		this->setOpacity(128);
}
void MenuSoundButton::buttonPressed() {
	if(Settings::getInstance()->soundEnabled) {
		Settings::getInstance()->soundEnabled = false;
		this->setOpacity(128);
	} else {
		Sounds::getInstance()->playClick();
		Settings::getInstance()->soundEnabled = true;
		this->setOpacity(255);
	}
	Settings::getInstance()->save();
}
void MenuSoundButton::buttonReleased() {
}

// music button
MenuMusicButton::MenuMusicButton() {
	imageNormalName = std::string("MenuMusic");
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelectedName = std::string("MenuMusic2");
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(390,295));
	touchSize = IGRect(60,50);
	z = 3;
	tag = SceneMenuMusic;
	if(Settings::getInstance()->musicEnabled)
		this->setOpacity(255);
	else
		this->setOpacity(128);
}
void MenuMusicButton::buttonPressed() {
	if(Settings::getInstance()->musicEnabled) {
		Sounds::getInstance()->stopMusic();
		Settings::getInstance()->musicEnabled = false;
		this->setOpacity(128);
	} else {
		Settings::getInstance()->musicEnabled = true;
		Sounds::getInstance()->startMusic();
		this->setOpacity(255);
	}
	Settings::getInstance()->save();
}
void MenuMusicButton::buttonReleased() {
}

// scene menu
SceneMenu::SceneMenu() {
	IGScene::IGScene();
	IGLog("SceneMenu init");

	// load the resources
	IwGetResManager()->LoadGroup("menu.group");
	
	// the background
	IGSprite* spriteBackground2 = new IGSprite("BackgroundMenu", IGPoint(240,160), 1);
	this->addChild(spriteBackground2);

	// theme swiping
	IGSprite* spriteBackground1 = new IGSprite("BackgroundBlack", IGPoint(240,160), -1);
	this->addChild(spriteBackground1);
	themeTouchX = 0;
	themeTouchY = 0;
	if(Settings::getInstance()->theme == SettingsThemeHacker)
		themeCurrent = 0;
	else if(Settings::getInstance()->theme == SettingsThemeDetective)
		themeCurrent = 1;
	else
		themeCurrent = 2;
	themeMoving = false;
	themeHacker = new IGSprite("MenuThemeHacker", IGPoint(0,0), 0);
	themeDetective = new IGSprite("MenuThemeDetective", IGPoint(0,0), 0);
	themeEspionage = new IGSprite("MenuThemeEspionage", IGPoint(0,0), 0);
	switch(themeCurrent) {
		case 0: // hacker
			themeEspionage->set(IGPoint(-240,285));
			themeHacker->set(IGPoint(240,285));
			themeDetective->set(IGPoint(720,285));
			break;
		case 1: // detective
			themeHacker->set(IGPoint(-240,285));
			themeDetective->set(IGPoint(240,285));
			themeEspionage->set(IGPoint(720,285));
			break;
		case 2: // espionage
			themeDetective->set(IGPoint(-240,285));
			themeEspionage->set(IGPoint(240,285));
			themeHacker->set(IGPoint(720,285));
			break;
	}
	this->addChild(themeHacker);
	this->addChild(themeDetective);
	this->addChild(themeEspionage);

	// sound and music buttons
	MenuSoundButton* buttonSound = new MenuSoundButton();
	MenuMusicButton* buttonMusic = new MenuMusicButton();
	this->addChild(buttonSound);
	this->addChild(buttonMusic);
	
	// the magnifying glass
	MenuAnimation* anim = new MenuAnimation();
	this->addChild(anim);

	// the menu items
	MenuButtonDecrypt* buttonDecrypt = new MenuButtonDecrypt();
	MenuButtonHelp* buttonHelp = new MenuButtonHelp();
	MenuButtonAbout* buttonAbout = new MenuButtonAbout();
	this->addChild(buttonDecrypt);
	this->addChild(buttonHelp);
	this->addChild(buttonAbout);

	// if it's running on iphone, have more games link. otherwise, don't
	if(s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_IPHONE) {
		IGLog("Cryptose is running on an iPhone, adding Other Games menu item");
		MenuButtonMoreGames* buttonMoreGames = new MenuButtonMoreGames();
		this->addChild(buttonMoreGames);
	} else {
		IGLog("Cryptose is not running on an iPhone, no Other Games menu item");
	}
}

SceneMenu::~SceneMenu() {
}

void SceneMenu::update() {
	// if theme selector is moving, move it
	if(themeMoving) {
		// move the themes a bit
		if(s3eTimerGetMs() - themeMovingStart >= 2) {
			// moving themes right or left
			int inc;			
			if(themeDirection == true)
				inc = -80;
			else
				inc = 80;
			IGPoint hackerPoint(themeHacker->position.x+inc,themeHacker->position.y);
			IGPoint detectivePoint(themeDetective->position.x+inc,themeDetective->position.y);
			IGPoint espionagePoint(themeEspionage->position.x+inc,themeEspionage->position.y);
			
			// move them
			themeHacker->set(hackerPoint);
			themeDetective->set(detectivePoint);
			themeEspionage->set(espionagePoint);
			
			// increment the count
			themeMovingStart = s3eTimerGetMs();
			themeMovingCount++;

			// half point
			if(themeMovingCount == 3) {
				switch(themeCurrent) {
					case 0: // hacker
						if(themeDirection == true) {
							espionagePoint.x += 1440;
							themeEspionage->set(espionagePoint);
						} else {
							detectivePoint.x -= 1440;
							themeDetective->set(detectivePoint);
						}
						break;
					case 1: // detective
						if(themeDirection == true) {
							hackerPoint.x += 1440;
							themeHacker->set(hackerPoint);
						} else {
							espionagePoint.x -= 1440;
							themeEspionage->set(espionagePoint);
						}
						break;
					case 2: // espionage
						if(themeDirection == true) {
							detectivePoint.x += 1440;
							themeDetective->set(detectivePoint);
						} else {
							hackerPoint.x -= 1440;
							themeHacker->set(hackerPoint);
						}
						break;
				}
			}
			
			// done moving?
			if(themeMovingCount == 6) {
				if(themeDirection == true) {
					themeCurrent++;
					if(themeCurrent > 2)
						themeCurrent = 0;
				} else {
					themeCurrent--;
					if(themeCurrent < 0)
						themeCurrent = 2;
				}
				if(themeCurrent == 0)
					Settings::getInstance()->theme = SettingsThemeHacker;
				else if(themeCurrent == 1)
					Settings::getInstance()->theme = SettingsThemeDetective;
				else
					Settings::getInstance()->theme = SettingsThemeEspionage;
				Settings::getInstance()->save();
				themeMoving = false;

				switch(themeCurrent) {
					case 0: IGLog("theme changed to Hacker"); break;
					case 1: IGLog("theme changed to Detective"); break;
					case 2: IGLog("theme changed to Espionage"); break;
				}
			}
		}
	}
	
	IGNode::update();
}

bool SceneMenu::touch(s3ePointerTouchEvent* event) {
	if(IGNode::touch(event))
		return true;
	
	if(themeMoving)
		return false;
	
	float x = IGDistorter::getInstance()->distortBackX((float)event->m_x);
	float y = IGDistorter::getInstance()->distortBackY((float)event->m_y);
	
	// if the event occured within the themes
	if(y >= 270) {
		// touch down
		if(event->m_Pressed) {
			themeTouchX = x;
			themeTouchY = y;
		}
		// release
		else {
			// was there a swipe?
			if(abs((int)(themeTouchX - x)) > 10) {
				Sounds::getInstance()->playSwish();

				// swipe left, move right
				if(themeTouchX < x) {
					themeDirection = false;
				}
				// swipe right, move left
				else {
					themeDirection = true;
				}

				// start the move
				themeMoving = true;
				themeMovingCount = 0;
				themeMovingStart = s3eTimerGetMs();
			}
		}
		return true;
	}

	return false;
}
