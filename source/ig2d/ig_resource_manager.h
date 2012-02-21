#pragma once
#ifndef IG_RESOURCE_MANAGER_H
#define IG_RESOURCE_MANAGER_H

#include "Iw2D.h"
#include "ig_global.h"
#include <string>
#include <vector>

typedef enum {
	IGResourceManagerTypeImage = 0,
	IGResourceManagerTypeFont = 1,
} IGResourceManagerType;

class IGResourceManager {
public:
	// return the instance
	static IGResourceManager* getInstance();
	
	// constructor and destructor
	IGResourceManager();
	~IGResourceManager();
	static void shutdown();

	// get and free resources
	CIw2DImage* getImage(std::string name);
	CIw2DFont* getFont(std::string name);
	void freeImage(std::string name);
	void freeFont(std::string name);
	void freeAllResources();
	
private:
	static IGResourceManager* instance;

	// a resource
	struct Resource {
		std::string name;
		void* data;
		unsigned int count;
		short int type;
	};
	
	// list of resources
	std::vector<IGResourceManager::Resource*> resources;
	
	// load a resource
	void* getResource(std::string name);
	void* free(std::string name);
};

#endif // IG_RESOURCE_MANAGER_H