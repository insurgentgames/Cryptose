#pragma once
#ifndef SCENE_GAME_H
#define SCENE_GAME_H

#include "Iw2D.h"
#include "ig2d/ig.h"
#include "sqlite3_wrapper.h"

// new puzzle button
class GameButtonNewPuzzle: public IGButton {
public:
	GameButtonNewPuzzle();
	void buttonPressed();
	void buttonReleased();
};

// hint button
class GameButtonHint: public IGButton {
public:
	GameButtonHint();
	void buttonPressed();
	void buttonReleased();
};

// menu button
class GameButtonMenu: public IGButton {
public:
	GameButtonMenu();
	void buttonPressed();
	void buttonReleased();
};

// complete play again button
class GameCompleteButtonPlayAgain: public IGButton {
public:
	GameCompleteButtonPlayAgain();
	void buttonPressed();
	void buttonReleased();
};

// complete menu button
class GameCompleteButtonMenu: public IGButton {
public:
	GameCompleteButtonMenu();
	void buttonPressed();
	void buttonReleased();
};

// empty slot sprite
class GameSlot: public IGSprite {
public:
	GameSlot(int _row, int _col, int _tag=0);
	bool collidingWith(float x, float y, int centerOffset[]);
	int row, col;
};

// plaintext label
class GamePlaintextLabel: public IGLabel {
public:
	GamePlaintextLabel(char c, int row, int col, int _tag=0);
	void setColorDuplicate();
	void setColorNormal();
};

// ciphertext label
class GameCiphertextLabel: public IGLabel {
public:
	GameCiphertextLabel(char c, int row, int col, int _tag=0);
};

// time label
class GameTimeLabel: public IGLabel {
public:
	GameTimeLabel(int _min=0, int _sec=0);
	void update();
	void updateString();

	unsigned int min;
	unsigned int sec;
	int64 start;
	char formatString[100];
	bool stop;
};

// alphabet letter
class GameAlphabetLetter: public IGButton {
public:
	GameAlphabetLetter(int _alphabetLetter, bool used);
	void buttonPressed();
	void buttonReleased();
	int alphabetLetter;

	// wait a couple frames before touches
	void update();
	bool touch(s3ePointerTouchEvent* event);
	int touchCount;
};

// alphabet letters
typedef enum {
	GameAlphabetA = 0, GameAlphabetB = 1, GameAlphabetC = 2, GameAlphabetD = 3,
	GameAlphabetE = 4, GameAlphabetF = 5, GameAlphabetG = 6, GameAlphabetH = 7,
	GameAlphabetI = 8, GameAlphabetJ = 9, GameAlphabetK = 10, GameAlphabetL = 11,
	GameAlphabetM = 12, GameAlphabetN = 13, GameAlphabetO = 14, GameAlphabetP = 15,
	GameAlphabetQ = 16, GameAlphabetR = 17, GameAlphabetS = 18, GameAlphabetT = 19,
	GameAlphabetU = 20, GameAlphabetV = 21, GameAlphabetW = 22, GameAlphabetX = 23,
	GameAlphabetY = 24, GameAlphabetZ = 25, GameAlphabetDEL = 26, GameAlphabetESC = 27
} GameAlphabetLetters;

// children
typedef enum {
	SceneGameTagLabelAlphabet = 1,
	SceneGameTagLabelAnswerKey = 2,
	SceneGameTagLabelAlphabetLetters = 3,
	SceneGameTagLabelAnswerKeyLetters = 4,
	SceneGameTagKeyboardBlack = 5,
	SceneGameTagKeyboardLabelSelectedBackground = 6,
	SceneGameTagKeyboardLabelSelectedLetter = 7,
	SceneGameTagTimeLabel = 8,
	SceneGameTagButtonNewPuzzle = 9,
	SceneGameTagButtonHint = 10,
	SceneGameTagButtonMenu= 11,
	SceneGameTagSlots = 100,
	SceneGameTagPlaintextLabels = 200,
	SceneGameTagCiphertextLabels = 300,
	SceneGameTagAlphabetLetters = 400
} SceneGameTag;

// game scene
class SceneGame: public IGScene {
public:
	SceneGame();
	~SceneGame();
	void update();
	bool touch(s3ePointerTouchEvent* event);
	void popUpKeyboard();
	void removeKeyboard();
	void pressKey(int k);
	void updatePhrase();
	void hint();
	void playInputSound();

	// save and load
	void loadGame();
	void saveGame();
	void newGame();
	void deleteSavedGame();
	int time; // temp variable holding seconds
	
	// keyboard
	bool keyboardUp;
	char selectedChar;
	s3eKey s3eKeys[26]; // physical keyboard keys
	
	// phrase, max length 72 chars
	char plaintext[73];
	char ciphertext[73];
	char frequency[26];
	int centerOffset[4]; // for centering the phrase
	void calculateFrequency();
	int phraseId;
	bool isLetterUsed(int alphabetLetter);

	// key, 26 chars in alphabet, shuffled
	char key[27];
	char inverseKey[27];
	char answerKey[27];
	char inverseAnswerKey[27];

	// saved game db
	SQLite3Wrapper* savedGameDB;
};

#endif // SCENE_GAME_H