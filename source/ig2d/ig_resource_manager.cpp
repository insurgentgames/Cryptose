#include "ig_resource_manager.h"

IGResourceManager* IGResourceManager::instance = NULL;

IGResourceManager* IGResourceManager::getInstance() {
	if(instance == NULL)
		instance = new IGResourceManager();
	return instance;
}

IGResourceManager::IGResourceManager() {
	IGLog("ResourceManager init");
}

IGResourceManager::~IGResourceManager() {
	freeAllResources();
}

void IGResourceManager::shutdown() {
	if(instance != NULL)
		delete instance;
}

CIw2DImage* IGResourceManager::getImage(std::string name) {
	// see if the resource has been loaded already
	CIw2DImage* ret = (CIw2DImage*)this->getResource(name);
	if(ret != NULL)
		return (CIw2DImage*)ret;
	
	// resource doesn't exist, so load it
	IGResourceManager::Resource* r = new IGResourceManager::Resource;
	r->name = name;
	r->data = (void*)Iw2DCreateImageResource(name.c_str());
	r->count = 1;
	r->type = IGResourceManagerTypeImage;
	resources.push_back(r);
	return (CIw2DImage*)r->data;
}

CIw2DFont* IGResourceManager::getFont(std::string name) {
	// see if the resource has been loaded already
	CIw2DFont* ret = (CIw2DFont*)this->getResource(name);
	if(ret != NULL)
		return (CIw2DFont*)ret;
	
	// resource doesn't exist, so load it
	IGResourceManager::Resource* r = new IGResourceManager::Resource;
	r->name = name;
	r->data = (void*)Iw2DCreateFontResource(name.c_str());
	r->count = 1;
	r->type = IGResourceManagerTypeFont;
	resources.push_back(r);
	return (CIw2DFont*)r->data;
}

void IGResourceManager::freeImage(std::string name) {
	CIw2DImage* image = (CIw2DImage*)free(name);
	if(image != NULL)
		delete image;
}

void IGResourceManager::freeFont(std::string name) {
	CIw2DFont* font = (CIw2DFont*)free(name);
	if(font != NULL)
		delete font;
}

void IGResourceManager::freeAllResources() {
	std::vector<IGResourceManager::Resource*>::iterator i = resources.begin();
	while(i!=resources.end()) {
		IGResourceManager::Resource* r = *i;
		if(r->data != NULL) {
			if(r->type == IGResourceManagerTypeImage)
				delete (CIw2DImage*)r->data;
			else if(r->type == IGResourceManagerTypeFont)
				delete (CIw2DFont*)r->data;
		}
		i = resources.erase(i);
		delete r;
	}
}

void* IGResourceManager::getResource(std::string name) {
	// see if the resource has been loaded already
	std::vector<IGResourceManager::Resource*>::iterator i = resources.begin();
	while(i!=resources.end()) {
		IGResourceManager::Resource* r = *i;
		if(r->name == name) {
			// found the resource
			r->count++;
			return r->data;
		}
		i++;
	}
	return NULL;
}

void* IGResourceManager::free(std::string name) {
	void* ret = NULL;
	std::vector<IGResourceManager::Resource*>::iterator i = resources.begin();
	while(i!=resources.end()) {
		IGResourceManager::Resource* r = *i;
		if(r->name == name) {
			// found the resource
			r->count--;
			if(r->count == 0) {
				ret = r->data;
				i = resources.erase(i);
				delete r;
			}
			break;
		}
		i++;
	}
	return ret;
}
