#include "settings.h"
#include "ig2d/ig_global.h"

Settings* Settings::instance = NULL;

Settings* Settings::getInstance() {
	if(instance == NULL)
		instance = new Settings();
	return instance;
}

Settings::Settings() {
	IGLog("Settings init");
	this->load();
	lastFact = 0;
}

Settings::~Settings() {
}

void Settings::shutdown() {
	if(instance != NULL)
		delete instance;
}

void Settings::load() {
	SQLite3Wrapper db("settings.db");
	db.exe("SELECT * FROM settings");
	std::vector<std::string>::iterator i;
	i = db.vdata.begin();

	// theme
	std::string themeStr = *i;
	if(themeStr == "hacker")
		theme = SettingsThemeHacker;
	else if(themeStr == "detective")
		theme = SettingsThemeDetective;
	else if(themeStr == "espionage")
		theme = SettingsThemeEspionage;
	
	// sound
	++i;
	std::string soundStr = *i;
	if(soundStr == "0")
		soundEnabled = false;
	else
		soundEnabled = true;

	// music
	++i;
	std::string musicStr = *i;
	if(musicStr == "0")
		musicEnabled = false;
	else
		musicEnabled = true;
}

void Settings::save() {
	SQLite3Wrapper db("settings.db");
	char themeStr[20];
	if(theme == SettingsThemeHacker)
		sprintf(themeStr, "hacker");
	else if(theme == SettingsThemeDetective)
		sprintf(themeStr, "detective");
	else if(theme == SettingsThemeEspionage)
		sprintf(themeStr, "espionage");
	char buffer[100];
	sprintf(buffer, "UPDATE settings SET theme='%s',sound='%i',music='%i';", themeStr, (soundEnabled ? 1 : 0), (musicEnabled ? 1 : 0));
	db.exe(std::string(buffer));
}
