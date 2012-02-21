#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include "sqlite3_wrapper.h"

typedef enum {
	SettingsThemeHacker,
	SettingsThemeDetective,
	SettingsThemeEspionage
} SettingsTheme;

class Settings {
public:
	// return the instance
	static Settings* getInstance();

	// the settings
	SettingsTheme theme;
	bool soundEnabled;
	bool musicEnabled;
	int lastFact;
	
	// constructor and destructor
	Settings();
	~Settings();
	static void shutdown();

	// load, save
	void load();
	void save();
	
private:
	static Settings* instance;
};

#endif // SETTINGS_H