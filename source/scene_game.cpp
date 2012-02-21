#include "scene_game.h"
#include "IwResManager.h"
#include "settings.h"
#include "sounds.h"
#include "scene_fact.h"
#include "scene_menu.h"
#include <string>
#include <string.h>

// new puzzle button
GameButtonNewPuzzle::GameButtonNewPuzzle() {
	switch(Settings::getInstance()->theme) {
	case SettingsThemeHacker:
		imageNormalName = std::string("GameHackerButtonNewPuzzle");
		imageSelectedName = std::string("GameHackerButtonNewPuzzle2");
		break;
	case SettingsThemeDetective:
		imageNormalName = std::string("GameDetectiveButtonNewPuzzle");
		imageSelectedName = std::string("GameDetectiveButtonNewPuzzle2");
		break;
	case SettingsThemeEspionage:
		imageNormalName = std::string("GameEspionageButtonNewPuzzle");
		imageSelectedName = std::string("GameEspionageButtonNewPuzzle2");
		break;
	}
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(100,290));
	touchSize = IGRect(142,60);
	z = 1;
	tag = SceneGameTagButtonNewPuzzle;
}
void GameButtonNewPuzzle::buttonPressed() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	Sounds::getInstance()->playClick();
}
void GameButtonNewPuzzle::buttonReleased() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	((SceneGame*)parent)->deleteSavedGame();
	((SceneGame*)parent)->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneFact());
}
// hint button
GameButtonHint::GameButtonHint() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			imageNormalName = std::string("GameHackerButtonHint");
			imageSelectedName = std::string("GameHackerButtonHint2");
			break;
		case SettingsThemeDetective:
			imageNormalName = std::string("GameDetectiveButtonHint");
			imageSelectedName = std::string("GameDetectiveButtonHint2");
			break;
		case SettingsThemeEspionage:
			imageNormalName = std::string("GameEspionageButtonHint");
			imageSelectedName = std::string("GameEspionageButtonHint2");
			break;
	}
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(241.5,290));
	touchSize = IGRect(141,60);
	z = 1;
	tag = SceneGameTagButtonHint;
}
void GameButtonHint::buttonPressed() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	Sounds::getInstance()->playClick();
}
void GameButtonHint::buttonReleased() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	((SceneGame*)parent)->hint();
}

// menu button
GameButtonMenu::GameButtonMenu() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			imageNormalName = std::string("GameHackerButtonMenu");
			imageSelectedName = std::string("GameHackerButtonMenu2");
			break;
		case SettingsThemeDetective:
			imageNormalName = std::string("GameDetectiveButtonMenu");
			imageSelectedName = std::string("GameDetectiveButtonMenu2");
			break;
		case SettingsThemeEspionage:
			imageNormalName = std::string("GameEspionageButtonMenu");
			imageSelectedName = std::string("GameEspionageButtonMenu2");
			break;
	}
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(382.5,290));
	touchSize = IGRect(141,60);
	z = 1;
	tag = SceneGameTagButtonMenu;
}
void GameButtonMenu::buttonPressed() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	Sounds::getInstance()->playClick();
}
void GameButtonMenu::buttonReleased() {
	if(((SceneGame*)parent)->keyboardUp)
		return;
	((SceneGame*)parent)->saveGame();
	((SceneGame*)parent)->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneMenu());
}

// complete play again button
GameCompleteButtonPlayAgain::GameCompleteButtonPlayAgain() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			imageNormalName = std::string("GameHackerCompletePlay");
			imageSelectedName = std::string("GameHackerCompletePlay2");
			break;
		case SettingsThemeDetective:
			imageNormalName = std::string("GameDetectiveCompletePlay");
			imageSelectedName = std::string("GameDetectiveCompletePlay2");
			break;
		case SettingsThemeEspionage:
			imageNormalName = std::string("GameEspionageCompletePlay");
			imageSelectedName = std::string("GameEspionageCompletePlay2");
			break;
	}
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(240,240));
	touchSize = IGRect(340,40);
	z = 1;
	tag = 0;
}
void GameCompleteButtonPlayAgain::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void GameCompleteButtonPlayAgain::buttonReleased() {
	((SceneGame*)parent)->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneFact());
}

// complete menu button
GameCompleteButtonMenu::GameCompleteButtonMenu() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			imageNormalName = std::string("GameHackerCompleteMenu");
			imageSelectedName = std::string("GameHackerCompleteMenu2");
			break;
		case SettingsThemeDetective:
			imageNormalName = std::string("GameDetectiveCompleteMenu");
			imageSelectedName = std::string("GameDetectiveCompleteMenu2");
			break;
		case SettingsThemeEspionage:
			imageNormalName = std::string("GameEspionageCompleteMenu");
			imageSelectedName = std::string("GameEspionageCompleteMenu2");
			break;
	}
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;
	this->set(IGPoint(240,280));
	touchSize = IGRect(340,40);
	z = 1;
	tag = 0;
}
void GameCompleteButtonMenu::buttonPressed() {
	Sounds::getInstance()->playClick();
}
void GameCompleteButtonMenu::buttonReleased() {
	((SceneGame*)parent)->removeAllChildren();
	IGDirector::getInstance()->switchScene(new SceneMenu());
}

// empty slot sprite
GameSlot::GameSlot(int _row, int _col, int _tag) {
	row = _row;
	col = _col;

	image = NULL;
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			imageName = std::string("GameHackerSlot");
			break;
		case SettingsThemeDetective:
			imageName = std::string("GameDetectiveSlot");
			break;
		case SettingsThemeEspionage:
			imageName = std::string("GameEspionageSlot");
			break;
	}
	image = IGResourceManager::getInstance()->getImage(imageName);
	//set(IGPoint((float)(41+(col*20)),(float)(41.5+(row*46))), IGRect(20, 23));
	set(IGPoint((float)(19+(col*26)),(float)(41.5+(row*46))), IGRect(26, 23)); // setting it slightly bigger than it was before
	z = 1;
	tag = 0;
	setOpacity(255);
	tag = _tag;
}

bool GameSlot::collidingWith(float x, float y, int centerOffset[]) {
	//return (x > (31+centerOffset[row]+(col*20)) && x < (51+centerOffset[row]+(col*20)) && y > (30+(row*46)) && y < (76+(row*46)));
	return (x > (9+centerOffset[row]+(col*26)) && x < (35+centerOffset[row]+(col*26)) && y > (30+(row*46)) && y < (76+(row*46)));
}

// plaintext label
GamePlaintextLabel::GamePlaintextLabel(char c, int row, int col, int _tag) {
	fontName = std::string("FontCourierNew18");
	font = IGResourceManager::getInstance()->getFont(fontName);
	//set(IGPoint((float)(41+(col*20)),(float)(41.5+(row*46))), IGRect(20, 23));
	set(IGPoint((float)(19+(col*26)),(float)(41.5+(row*46))), IGRect(26, 23));
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			setColor(255,255,255,255);
			break;
		case SettingsThemeDetective:
			setColor(0,0,0,255);
			break;
		case SettingsThemeEspionage:
			setColor(0,0,0,255);
			break;
	}
	setString(std::string(1, c));
	z = 2;
	tag = _tag;
}
void GamePlaintextLabel::setColorDuplicate() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			setColor(255,150,150,255);
			break;
		case SettingsThemeDetective:
			setColor(128,0,0,255);
			break;
		case SettingsThemeEspionage:
			setColor(128,0,0,255);
			break;
	}
}
void GamePlaintextLabel::setColorNormal() {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			setColor(255,255,255,255);
			break;
		case SettingsThemeDetective:
			setColor(0,0,0,255);
			break;
		case SettingsThemeEspionage:
			setColor(0,0,0,255);
			break;
	}
}

// ciphertext label
GameCiphertextLabel::GameCiphertextLabel(char c, int row, int col, int _tag) {
	fontName = std::string("FontCourierNew18");
	font = IGResourceManager::getInstance()->getFont(fontName);
	//set(IGPoint((float)(41+(col*20)),(float)(64.5+(row*46))), IGRect(20, 23));
	set(IGPoint((float)(19+(col*26)),(float)(64.5+(row*46))), IGRect(26, 23));
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			setColor(147,226,134,255);
			break;
		case SettingsThemeDetective:
			setColor(65,109,182,255);
			break;
		case SettingsThemeEspionage:
			setColor(186,36,36,255);
			break;
	}
	setString(std::string(1, c));
	z = 2;
	tag = _tag;
}

// time label
GameTimeLabel::GameTimeLabel(int _min, int _sec) {
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			fontName = std::string("FontCourierNew16");
			font = IGResourceManager::getInstance()->getFont(fontName);
			set(IGPoint(240,15), IGRect(180,30));
			setColor(107,247,100,255);
			break;
		case SettingsThemeDetective:
			fontName = std::string("FontCourierNew14");
			font = IGResourceManager::getInstance()->getFont(fontName);
			set(IGPoint(400,15), IGRect(100,30));
			setColor(0,0,0,196);
			break;
		case SettingsThemeEspionage:
			fontName = std::string("FontCourierNew18");
			font = IGResourceManager::getInstance()->getFont(fontName);
			set(IGPoint(290,18), IGRect(120,24));
			setColor(72,72,72,196);
			break;
	}
	z = 2;
	tag = SceneGameTagTimeLabel;

	// time
	min = _min;
	sec = _sec;
	updateString();

	// start
	start = s3eTimerGetMs();
	stop = false;
}
void GameTimeLabel::update() {
	if(stop)
		return;
	if(s3eTimerGetMs() - start >= 1000) {
		start = s3eTimerGetMs();
		sec++;
		if(sec == 60) {
			sec = 0;
			min++;
		}
		updateString();
	}
}
void GameTimeLabel::updateString() {
	sprintf(formatString, "%02i:%02i", min, sec);
	setString(std::string(formatString));
}

// alphabet letter
GameAlphabetLetter::GameAlphabetLetter(int _alphabetLetter, bool used) {
	alphabetLetter = _alphabetLetter;
	char bufferTheme[50], bufferLetter[5], buffer[200];

	// figure out the theme
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker: sprintf(bufferTheme, "Hacker"); break;
		case SettingsThemeDetective: sprintf(bufferTheme, "Detective"); break;
		case SettingsThemeEspionage: sprintf(bufferTheme, "Espionage"); break;
	}

	// figure out the letter
	if(alphabetLetter == GameAlphabetDEL)
		sprintf(bufferLetter, "DEL");
	else if(alphabetLetter == GameAlphabetESC)
		sprintf(bufferLetter, "ESC");
	else
		sprintf(bufferLetter, "%c", alphabetLetter+'A');

	// figure out the names
	if(used) {
		sprintf(buffer, "Game%sAlphabetUsed%s", bufferTheme, bufferLetter);
		imageNormalName = std::string(buffer);
	} else {
		sprintf(buffer, "Game%sAlphabet%s", bufferTheme, bufferLetter);
		imageNormalName = std::string(buffer);
	}
	sprintf(buffer, "Game%sAlphabetPressed%s", bufferTheme, bufferLetter);
	imageSelectedName = std::string(buffer);
	imageNormal = IGResourceManager::getInstance()->getImage(imageNormalName);
	imageSelected = IGResourceManager::getInstance()->getImage(imageSelectedName);
	image = imageNormal;

	// init the rest of the button
	int x = (alphabetLetter % 7);
	int y = (int)(alphabetLetter / 7);
	this->set(IGPoint((float)(90+(50*x)),(float)(88+(50*y))));
	touchSize = IGRect(55,55); // make the buttons a little bigger than they actually are -- seems more responsive
	// touchSize = IGRect(50,50);
	z = 6;
	tag = SceneGameTagAlphabetLetters+alphabetLetter;

	// wait a couple frames before counting touches
	touchCount = 0;
}
void GameAlphabetLetter::buttonPressed() {
	((SceneGame*)parent)->playInputSound();
}
void GameAlphabetLetter::buttonReleased() {
	((SceneGame*)parent)->pressKey(alphabetLetter);
}
void GameAlphabetLetter::update() {
	IGButton::update();
	if(touchCount < 20)
		touchCount++;
}
bool GameAlphabetLetter::touch(s3ePointerTouchEvent* event) {
	if(touchCount < 20)
		return false;
	return IGButton::touch(event);
}

// game scene
SceneGame::SceneGame() {
	IGScene::IGScene();
	IGLog("SceneGame init");
	unsigned int i, j;

	// load the game
	phraseId = 0;
	savedGameDB = new SQLite3Wrapper("savedGame.db");
	loadGame();

	// init physical keyboard array
	s3eKeys[0]=s3eKeyA; s3eKeys[1]=s3eKeyB; s3eKeys[2]=s3eKeyC; s3eKeys[3]=s3eKeyD; s3eKeys[4]=s3eKeyE; 
	s3eKeys[5]=s3eKeyF; s3eKeys[6]=s3eKeyG; s3eKeys[7]=s3eKeyH; s3eKeys[8]=s3eKeyI; s3eKeys[9]=s3eKeyJ;
	s3eKeys[10]=s3eKeyK; s3eKeys[11]=s3eKeyL; s3eKeys[12]=s3eKeyM; s3eKeys[13]=s3eKeyN; s3eKeys[14]=s3eKeyO;
	s3eKeys[15]=s3eKeyP; s3eKeys[16]=s3eKeyQ; s3eKeys[17]=s3eKeyR; s3eKeys[18]=s3eKeyS; s3eKeys[19]=s3eKeyT;
	s3eKeys[20]=s3eKeyU; s3eKeys[21]=s3eKeyV; s3eKeys[22]=s3eKeyW; s3eKeys[23]=s3eKeyX; s3eKeys[24]=s3eKeyY;
	s3eKeys[25]=s3eKeyZ;

	// load resources, background image
	IGSprite* spriteBackground = NULL;
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			IwGetResManager()->LoadGroup("game_hacker.group");
			spriteBackground = new IGSprite("GameHackerBackground", IGPoint(240,160), 0);
			break;
		case SettingsThemeDetective:
			IwGetResManager()->LoadGroup("game_detective.group");
			spriteBackground = new IGSprite("GameDetectiveBackground", IGPoint(240,160), 0);
			break;
		case SettingsThemeEspionage:
			IwGetResManager()->LoadGroup("game_espionage.group");
			spriteBackground = new IGSprite("GameEspionageBackground", IGPoint(240,160), 0);
			break;
	}
	this->addChild(spriteBackground);
	
	// buttons
	GameButtonNewPuzzle* buttonNewPuzzle = new GameButtonNewPuzzle();
	GameButtonHint* buttonHint = new GameButtonHint();
	GameButtonMenu* buttonMenu = new GameButtonMenu();
	this->addChild(buttonNewPuzzle);
	this->addChild(buttonHint);
	this->addChild(buttonMenu);

	// time
	int sec = (int)(time%60);
	int min = (int)(time/60);
	GameTimeLabel* timeLabel = new GameTimeLabel(min,sec);
	this->addChild(timeLabel);
	
	// draw the phrase
	const unsigned int maxCols = 18; // used to be 21
	const unsigned int maxRows = 4;
	int columnCount[4] = {0,0,0,0}; // count number of columns per row
	unsigned int col = 0;
	unsigned int row = 0;
	for(i=0; i<strlen(ciphertext); i++) {
		// if it's a space in the first column, skip this one
		while(col == 0 && ciphertext[i] == ' ')
			i++;
		
		// if it's a word, see if there's enough space in this line
		if(ciphertext[i] != ' ') {
			for(j=i+1; j<strlen(ciphertext); j++) {
				if(ciphertext[j] == ' ' || ciphertext[j] == '\0')
					break;
			}
			if(col + (j-i) >= maxCols) {
				col = 0;
				row++;
			}
		}

		// if it's a letter, draw empty box and an empty plaintext label
		if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
			GameSlot* slot = new GameSlot(row, col, SceneGameTagSlots+i);
			GamePlaintextLabel* plaintextLabel = new GamePlaintextLabel(' ', row, col, SceneGameTagPlaintextLabels+i);
			this->addChild(slot);
			this->addChild(plaintextLabel);
		}
		// otherwise draw the character
		else {
			if(ciphertext[i] != ' ') {
				GamePlaintextLabel* plaintextLabel = new GamePlaintextLabel(ciphertext[i], row, col, SceneGameTagPlaintextLabels+i);
				this->addChild(plaintextLabel);
			}
		}
		
		// draw the ciphertext
		if(ciphertext[i] != ' ') {
			GameCiphertextLabel* ciphertextLabel = new GameCiphertextLabel(ciphertext[i], row, col, SceneGameTagCiphertextLabels+i);
			this->addChild(ciphertextLabel);
		}

		// count the columns
		columnCount[row]++;
		
		// increment the column
		col++;
		if(col == maxCols) {
			col = 0;
			row++;
		}
	}
	
	// center the text, total width=468, letter width=26
	for(i=0; i<4; i++) {
		int width = columnCount[i];
		int index = -1;
		for(j=0; j<=i; j++) index += columnCount[j];
		if(ciphertext[index] == ' ') width--;
		centerOffset[i] = (468 - (width*26)) / 2;
	}
	row = 0;
	for(i=0; i<strlen(ciphertext); i++) {
		GameSlot* slot = (GameSlot*)this->getChildByTag(SceneGameTagSlots+i);
		if(slot != NULL) {
			row = slot->row;
			slot->position.x += centerOffset[row];
		}

		GamePlaintextLabel* plaintextLabel = (GamePlaintextLabel*)this->getChildByTag(SceneGameTagPlaintextLabels+i);
		if(plaintextLabel != NULL)
			plaintextLabel->position.x += centerOffset[row];

		GameCiphertextLabel* ciphertextLabel = (GameCiphertextLabel*)this->getChildByTag(SceneGameTagCiphertextLabels+i);
		if(ciphertextLabel != NULL)
			ciphertextLabel->position.x += centerOffset[row];
	}
	
	// draw the key
	IGLabel* labelAlphabet = new IGLabel("FontFixedSys14",  "alphabet: ", IGPoint(123,230), IGRect(90,20), 2, SceneGameTagLabelAlphabet);
	IGLabel* labelAnswerKey = new IGLabel("FontFixedSys14", "     key: ", IGPoint(123,250), IGRect(90,20), 2, SceneGameTagLabelAnswerKey);
	IGLabel* labelAlphabetLetter = new IGLabel("FontFixedSys14", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", IGPoint(294,230), IGRect(234,20), 2, SceneGameTagLabelAlphabetLetters);
	IGLabel* labelAnswerKeyLetter = new IGLabel("FontFixedSys14", "__________________________", IGPoint(294,250), IGRect(234,20), 2, SceneGameTagLabelAnswerKeyLetters);
	switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			labelAnswerKey->setColor(140,140,140,255);
			labelAlphabet->setColor(140,140,140,255);
			labelAnswerKeyLetter->setColor(210,220,210,255);
			labelAlphabetLetter->setColor(210,220,210,255);
			break;
		case SettingsThemeDetective:
		case SettingsThemeEspionage:
			labelAnswerKey->setColor(80,80,80,255);
			labelAlphabet->setColor(80,80,80,255);
			labelAnswerKeyLetter->setColor(20,20,20,255);
			labelAlphabetLetter->setColor(20,20,20,255);
			break;
			break;
	}
	this->addChild(labelAnswerKey);
	this->addChild(labelAlphabet);
	this->addChild(labelAnswerKeyLetter);
	this->addChild(labelAlphabetLetter);

	// keyboard
	keyboardUp = false;

	// update the phrase
	updatePhrase();
}

SceneGame::~SceneGame() {
	// delete handle to db
	if(savedGameDB != NULL)
		delete savedGameDB;
}

void SceneGame::update() {
	unsigned int i;

	// if keyboard is up, check for key press
	if(keyboardUp) {
		// update the keyboard state
		s3eKeyboardUpdate();

		// see if a key is pressed
		for(i=0; i<26; i++) {
			if(s3eKeyboardGetState(s3eKeys[i]) != 0) {
				pressKey(i);
				playInputSound();
			}
		}
	}

	// check for back button pressed
	if(s3eKeyboardGetState(s3eKeyAbsBSK) != 0) {
		GameButtonMenu* buttonMenu = (GameButtonMenu*)this->getChildByTag(SceneGameTagButtonMenu);
		buttonMenu->buttonPressed();
	}
	
	// update the other nodes
	IGNode::update();
}

bool SceneGame::touch(s3ePointerTouchEvent* event) {
	// don't handle if the touch is up, not down
	if(event->m_Pressed != 1)
		return IGNode::touch(event);
	
	char debugStr[200];
	float x = IGDistorter::getInstance()->distortBackX((float)event->m_x);
	float y = IGDistorter::getInstance()->distortBackY((float)event->m_y);

	// touch input for the keyboard
	if(!keyboardUp) {
		// touching inside the puzzle area?
		if(y > 30 && y <= 214) {
			unsigned int i;
			for(i=0; i<strlen(ciphertext); i++) {
				if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
					GameSlot* slot = (GameSlot*)this->getChildByTag(SceneGameTagSlots+i);
					if(slot != NULL) {
						if(slot->collidingWith(x, y, centerOffset)) {
							// touching a character, pop up the keyboard
							sprintf(debugStr, "SceneGame touching slot %i, ciphertext %c, plaintext %c", i, ciphertext[i], plaintext[i]);
							Sounds::getInstance()->playClick();
							IGLog(debugStr);
							selectedChar = ciphertext[i];
							popUpKeyboard();
							return true;
						}
					}
				}
			}
		}
	}
	return IGNode::touch(event);
}

void SceneGame::popUpKeyboard() {
	if(keyboardUp == false) {
		keyboardUp = true;
		
		// add black background
		IGSprite* keyboardBlack = new IGSprite("BackgroundBlack", IGPoint(240,160), 4, SceneGameTagKeyboardBlack);
		keyboardBlack->setOpacity(64);
		this->addChild(keyboardBlack);

		// display the selected letter
		IGSprite* selectedLetterBackground = new IGSprite("GameAlphabetSelectedLetterBackground", IGPoint(240,48), 5, SceneGameTagKeyboardLabelSelectedBackground);
		this->addChild(selectedLetterBackground);
		char buffer[200];
		sprintf(buffer, "Selected Letter: %c", selectedChar);
		IGLabel* labelSelectedLetter = new IGLabel("FontCourierNew18", std::string(buffer), IGPoint(240,48), IGRect(480,30), 6, SceneGameTagKeyboardLabelSelectedLetter);
		labelSelectedLetter->setColor(255, 255, 255, 255);
		this->addChild(labelSelectedLetter);

		// add the keys
		for(int i=GameAlphabetA; i<=GameAlphabetESC; i++) {
			GameAlphabetLetter* letterButton = new GameAlphabetLetter(i, isLetterUsed(i));
			this->addChild(letterButton);
		}
	}
}

void SceneGame::removeKeyboard() {
	if(keyboardUp == true) {
		keyboardUp = false;

		// remove black background, selected letter label
		this->removeChildByTag(SceneGameTagKeyboardBlack);
		this->removeChildByTag(SceneGameTagKeyboardLabelSelectedBackground);
		this->removeChildByTag(SceneGameTagKeyboardLabelSelectedLetter);

		// remove the keys
		for(int i=GameAlphabetA; i<=GameAlphabetESC; i++) {
			this->removeChildByTag(SceneGameTagAlphabetLetters+i);
		}
	}
}

void SceneGame::pressKey(int k) {
	// delete
	if(k == GameAlphabetDEL) {
		IGLog("SceneGame touched DEL");
		inverseAnswerKey[selectedChar-'A'] = '_';
		updatePhrase();
		removeKeyboard();
	}
	// escape
	else if(k == GameAlphabetESC) {
		IGLog("SceneGame touched ESC");
		removeKeyboard();
	}
	// a letter
	else {
		char buffer[200];
		sprintf(buffer, "SceneGame touched letter %c", 'A'+k);
		IGLog(buffer);
		
		// if there's a duplicate, get rid of it
		for(int i=0; i<26; i++) {
			if(inverseAnswerKey[i] == k+'A')
				inverseAnswerKey[i] = '_';
		}
		
		inverseAnswerKey[selectedChar-'A'] = k+'A';
		updatePhrase();
		removeKeyboard();
	}
}

void SceneGame::updatePhrase() {
	unsigned int i,j;
	
	// create the answer key from the inverse
	strcpy(answerKey, "__________________________");
	for(i=0; i<26; i++) {
		for(j=0; j<26; j++) {
			if(inverseAnswerKey[j] == ('A'+i))
				answerKey[i] = j+'A';
		}
	}
	
	// update the plaintext label
	for(i=0; i<strlen(plaintext); i++) {
		// if it's a letter decrypt it with answerKey
		if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
			GamePlaintextLabel* label = (GamePlaintextLabel*)this->getChildByTag(SceneGameTagPlaintextLabels+i);

			int index = ciphertext[i]-'A';
			if(inverseAnswerKey[index] != '_')
				label->setString(std::string(1,inverseAnswerKey[index]));
			else
				label->setString(std::string(" "));
		}
	}
	
	/*// check for duplicates
	int count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	bool duplicates = false;
	
	// set the color of each plaintext label to normal color
	for(i=0; i<strlen(plaintext); i++) {
		if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
			GamePlaintextLabel* label = (GamePlaintextLabel*)this->getChildByTag(SceneGameTagPlaintextLabels+i);
			label->setColorNormal();
		}
	}

	// count how many of each letter is used in the answer key
	for(i=0; i<26; i++) {
		if(inverseAnswerKey[i] != '_') {
			count[inverseAnswerKey[i]-'A']++;
			if(count[inverseAnswerKey[i]-'A'] > 1)
				duplicates = true;
		}
	}

	// change duplicate letters to duplicate color
	if(duplicates) {
		for(i=0; i<26; i++) {
			if(count[i] > 1) {
				for(j=0; j<strlen(plaintext); j++) {
					if(inverseAnswerKey[ciphertext[j]-'A'] == i+'A') {
						GamePlaintextLabel* label = (GamePlaintextLabel*)this->getChildByTag(SceneGameTagPlaintextLabels+j);
						label->setColorDuplicate();
					}
				}
			}
		}
	}*/

	// update the key label
	IGLabel* labelAnswerKeyLetters = (IGLabel*)this->getChildByTag(SceneGameTagLabelAnswerKeyLetters);
	labelAnswerKeyLetters->setString(std::string(inverseAnswerKey));

	// check for a win
	bool win = true;
	for(i=0; i<26; i++) {
		if(frequency[i] > 0) {
			if(inverseAnswerKey[i] != inverseKey[i])
				win = false;
		}
	}
	if(win) {
		// stop the timer
		GameTimeLabel* timeLabel = (GameTimeLabel*)this->getChildByTag(SceneGameTagTimeLabel);
		if(timeLabel != NULL)
			timeLabel->stop = true;

		// remove the answer key
		this->removeChildByTag(SceneGameTagLabelAlphabet);
		this->removeChildByTag(SceneGameTagLabelAnswerKey);
		this->removeChildByTag(SceneGameTagLabelAlphabetLetters);
		this->removeChildByTag(SceneGameTagLabelAnswerKeyLetters);

		// remove the buttons
		this->removeChildByTag(SceneGameTagButtonNewPuzzle);
		this->removeChildByTag(SceneGameTagButtonHint);
		this->removeChildByTag(SceneGameTagButtonMenu);
		
		// remove the actual puzzle
		for(i=0; i<strlen(ciphertext); i++) {
			this->removeChildByTag(SceneGameTagSlots+i);
			this->removeChildByTag(SceneGameTagPlaintextLabels+i);
			this->removeChildByTag(SceneGameTagCiphertextLabels+i);
		}

		// add the phrase
		IGLabel* phraseLabel = new IGLabel("FontCourierNew18", std::string(plaintext), IGPoint(240,122), IGRect(380,184), 1);
		switch(Settings::getInstance()->theme) {
		case SettingsThemeHacker:
			phraseLabel->setColor(255, 255, 255, 255);
			break;
		case SettingsThemeDetective:
		case SettingsThemeEspionage:
			phraseLabel->setColor(0, 0, 0, 255);
			break;
		}
		this->addChild(phraseLabel);

		// add complete buttons
		GameCompleteButtonPlayAgain* buttonCompletePlayAgain = new GameCompleteButtonPlayAgain();
		GameCompleteButtonMenu* buttonCompleteMenu = new GameCompleteButtonMenu();
		this->addChild(buttonCompletePlayAgain);
		this->addChild(buttonCompleteMenu);

		// start a new game
		this->newGame();
	}
}

void SceneGame::hint() {
	IGLog("pressed hint");
	
	unsigned int i;
	int rnd, index;
	bool found = false;
	std::vector<int> notAnswered;
	std::vector<int> incorrectAnswers;
	std::vector<int> correctAnswers;
	
	// count how many answers, and how many of them are correct
	for(i=0; i<26; i++) {
		if(inverseAnswerKey[i] != '_') {
			if(inverseAnswerKey[i] == inverseKey[i])
				correctAnswers.push_back(i);
			else
				incorrectAnswers.push_back(i);
		} else {
			notAnswered.push_back(i);
		}
	}

	// if there are no answers, supply a random one
	if(incorrectAnswers.size() + correctAnswers.size() == 0) {
		while(!found) {
			index = rand()%26;
			if(frequency[index] > 0)
				found = true;
		}
	}
	
	// if there are answers but some are wrong, fix one of the wrong answers
	else if(incorrectAnswers.size() > 0) {
		while(!found) {
			rnd = rand()%incorrectAnswers.size();
			index = incorrectAnswers[rnd];
			if(frequency[index] > 0)
				found = true;
		}
	}

	// otherwise supply a random answer that hasn't been answered
	else {
		while(!found) {
			rnd = rand()%notAnswered.size();
			index = notAnswered[rnd];
			if(frequency[index] > 0)
				found = true;
		}
	}

	// if there's a duplicate, get rid of it
	for(int i=0; i<26; i++) {
		if(inverseAnswerKey[i] == inverseKey[index])
			inverseAnswerKey[i] = '_';
	}
	
	// give the hint and update the phrase
	inverseAnswerKey[index] = inverseKey[index];
	updatePhrase();
}

void SceneGame::playInputSound() {
	switch(Settings::getInstance()->theme) {
	case SettingsThemeHacker:
		Sounds::getInstance()->playType();
		break;
	case SettingsThemeDetective:
	case SettingsThemeEspionage:
		Sounds::getInstance()->playDraw();
		break;
	}
}

void SceneGame::loadGame() {
	savedGameDB->exe("SELECT * FROM savedGame");
	if(savedGameDB->vdata.size() == 0) {
		// start a new game
		newGame();
	} else {
		// load the game
		strcpy(plaintext,			savedGameDB->vdata[0].c_str());
		strcpy(ciphertext,			savedGameDB->vdata[1].c_str());
		strcpy(key,					savedGameDB->vdata[2].c_str());
		strcpy(inverseKey,			savedGameDB->vdata[3].c_str());
		strcpy(answerKey,			savedGameDB->vdata[4].c_str());
		strcpy(inverseAnswerKey,	savedGameDB->vdata[5].c_str());
		time = atoi(savedGameDB->vdata[6].c_str());

		// if the key so far is blank, reset the time to 0
		if(strcmp(inverseAnswerKey, "__________________________") == 0) {
			time = 0;
			GameTimeLabel* timeLabel = (GameTimeLabel*)this->getChildByTag(SceneGameTagTimeLabel);
			if(timeLabel != NULL) {
				timeLabel->min = 0;
				timeLabel->sec = 0;
			}
		}
		IGLog("game loaded");
	}

	// do frequency analysis
	calculateFrequency();
}

void SceneGame::saveGame() {
	// get the time
	GameTimeLabel* timeLabel = (GameTimeLabel*)this->getChildByTag(SceneGameTagTimeLabel);
	if(timeLabel == NULL)
		time = 0;
	else
		time = (timeLabel->min*60) + timeLabel->sec;
	
	// add slashes to the plaintext and ciphertext
	char plaintextBuffer[170];
	char ciphertextBuffer[170];
	unsigned int i=0, j=0;
	while(i<strlen(plaintext))  {
		if(plaintext[i] == '\'' || plaintext[i] == '\"') {
			plaintextBuffer[j] = '\\';
			j++;
		}
		plaintextBuffer[j] = plaintext[i];
		i++; j++;
	}
	plaintextBuffer[j] = '\0';
	i = 0; j = 0;
	while(i<strlen(ciphertext))  {
		if(ciphertext[i] == '\'' || ciphertext[i] == '\"') {
			ciphertextBuffer[j] = '\\';
			j++;
		}
		ciphertextBuffer[j] = ciphertext[i];
		i++; j++;
	}
	ciphertextBuffer[j] = '\0';
	
	// now save it
	char buffer[1024];
	sprintf(buffer, "DELETE FROM savedGame; INSERT INTO savedGame (plaintext,ciphertext,key,inverseKey,answerKey,inverseAnswerKey,time) VALUES('%s','%s','%s','%s','%s','%s','%i');", plaintextBuffer, ciphertextBuffer, key, inverseKey, answerKey, inverseAnswerKey, time);
	//sprintf(buffer, "UPDATE savedGame set plaintext='%s',ciphertext='%s',key='%s',inverseKey='%s',answerKey='%s',inverseAnswerKey='%s',time='%i';", plaintextBuffer, ciphertextBuffer, key, inverseKey, answerKey, inverseAnswerKey, time);
	savedGameDB->exe(std::string(buffer));
	
	IGLog("game saved");
}

void SceneGame::newGame() {	
	unsigned int i,j;

	// generate a random key
	strcpy(key, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	for(i=0; i<26; i++) {
		int r = i + (rand() % (26-i));
		char temp = key[i];
		key[i] = key[r];
		key[r] = temp;
	}

	// generate the inverse key
	strcpy(inverseKey, "__________________________");
	for(i=0; i<26; i++) {
		for(j=0; j<26; j++) {
			if(key[j] == ('A'+i))
				inverseKey[i] = j+'A';
		}
	}

	// init the answer key
	strcpy(answerKey, "__________________________");
	strcpy(inverseAnswerKey, answerKey);
	
	// set up the plaintext phrase
	char buffer[256];
	SQLite3Wrapper phrasesDB("phrases.db");
	phrasesDB.exe("SELECT COUNT(*) FROM phrases;");
	std::string numPhrasesStr = *(phrasesDB.vdata.begin());
	int numPhrases = atoi(numPhrasesStr.c_str());
	int rnd = phraseId;
	while(rnd == phraseId) {
		rnd = (rand()%numPhrases) + 1;
	}
	phraseId = rnd;
	sprintf(buffer, "SELECT phrase FROM phrases WHERE id=%i;", phraseId);
	phrasesDB.exe(buffer);
	std::string phraseString = *(phrasesDB.vdata.begin());
	strcpy(plaintext, phraseString.c_str());
	for(i=0; i<strlen(plaintext); i++)
		plaintext[i] = toupper(plaintext[i]);
	sprintf(buffer, "plaintext phrase: %s", plaintext);
	IGLog(buffer);
	IGLog("(if you, the player, are reading this... haha, good job at cheating)");
	
	// encrypt the phrase
	ciphertext[strlen(plaintext)] = '\0';
	for(i=0; i<strlen(plaintext); i++) {
		// if it's a letter, encrypt
		if(plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
			ciphertext[i] = key[plaintext[i]-'A'];
		}
		// otherwise keep it the same
		else {
			ciphertext[i] = plaintext[i];
		}
	}
	
	// set time to 0
	time = 0;
	GameTimeLabel* timeLabel = (GameTimeLabel*)this->getChildByTag(SceneGameTagTimeLabel);
	if(timeLabel != NULL) {
		timeLabel->min = 0;
		timeLabel->sec = 0;
	}
	
	// save the new game
	IGLog("new game created");
	saveGame();
}

void SceneGame::deleteSavedGame() {
	savedGameDB->exe(std::string("DELETE FROM savedGame;"));
}

void SceneGame::calculateFrequency() {
	int unsigned i;
	for(i=0; i<26; i++)
		frequency[i] = 0;
	for(i=0; i<strlen(ciphertext); i++) {
		if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
			frequency[ciphertext[i]-'A']++;
		}
	}
}

bool SceneGame::isLetterUsed(int alphabetLetter) {
	if(alphabetLetter == GameAlphabetDEL || alphabetLetter == GameAlphabetESC)
		return false;
	return (answerKey[alphabetLetter] != '_');
}
