#include "scene_fact.h"
#include "IwResManager.h"
#include "sqlite3_wrapper.h"
#include "scene_game.h"
#include "sounds.h"
#include "settings.h"

// fact label
FactLabel::FactLabel() {
	fontName = std::string("FontGeorgia17");
	font = IGResourceManager::getInstance()->getFont(fontName);
	set(IGPoint(240,125), IGRect(420,190));
	//setColor(144,215,144,0);
	setColor(144,215,144,255);
	z = 1;
	
	// random fact
	char buffer[256];
	SQLite3Wrapper db("facts.db");
	db.exe("SELECT COUNT(*) FROM facts;");
	std::string numFactsStr = *(db.vdata.begin());
	int numFacts = atoi(numFactsStr.c_str());
	int rnd = Settings::getInstance()->lastFact;
	while(rnd == Settings::getInstance()->lastFact)
		rnd = (rand()%numFacts) + 1;
	sprintf(buffer, "SELECT fact FROM facts WHERE id=%i;", rnd);
	db.exe(buffer);
	std::string factStr = *(db.vdata.begin());
	setString(factStr);
}

// continue sprite
FactContinue::FactContinue() {
	imageName = std::string("FactContinue");
	image = IGResourceManager::getInstance()->getImage(imageName);
	set(IGPoint(240,270));
	setOpacity(0);
	z = 1;
	
	// fade
	stage = 0;
	fadeCount = 0;
	start = s3eTimerGetMs();
}
void FactContinue::update() {
	switch(stage) {
	case 0:
		if(s3eTimerGetMs() - start >= 200) { // .2 seconds
			start = s3eTimerGetMs();
			stage = 1;
		}
		break;
	case 1:
		if(fadeCount < 50) {
			if(s3eTimerGetMs() - start >= 10) { // .01 seconds
				start = s3eTimerGetMs();
				fadeCount++;
				setOpacity((uint8)(fadeCount*(float)(255.0/50.0)));
			}
		}
		break;
	}
}

// scene fact
SceneFact::SceneFact() {
	IGScene::IGScene();
	IGLog("SceneFact init");

	// load the resources
	IwGetResManager()->LoadGroup("fact.group");
	
	// the background
	IGSprite* spriteBackground = new IGSprite("BackgroundLights", IGPoint(240,160), 0);
	this->addChild(spriteBackground);

	// the fact
	FactLabel* fact = new FactLabel();
	this->addChild(fact);

	// the continue sprite
	FactContinue* continueSprite = new FactContinue();
	this->addChild(continueSprite);
}

SceneFact::~SceneFact() {
}

bool SceneFact::touch(s3ePointerTouchEvent* event) {
	if(event->m_Pressed == 0) {
		Sounds::getInstance()->playClick();
		removeAllChildren();
		IGDirector::getInstance()->switchScene(new SceneGame());
	}
	return true;
}