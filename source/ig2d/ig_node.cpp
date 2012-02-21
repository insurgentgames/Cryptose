#include "ig_node.h"
#include "ig_distorter.h"
#include "Iw2D.h"

IGNode::IGNode() {
	sorted = false;
	numChildren = 0;
	parent = NULL;
}

IGNode::~IGNode() {
	removeAllChildren();
}

void IGNode::addChild(IGNode* node) {
	node->parent = this;
	children.push_back(node);
	sorted = false;
	numChildren++;
}

IGNode* IGNode::getChildByTag(int tag) {
	std::vector<IGNode*>::iterator i = children.begin();
	while(i!=children.end()) {
		IGNode* node = *i;
		if(node->tag == tag)
			return node;
		++i;
	}
	return NULL;
}

void IGNode::removeChildByTag(int tag) {
	std::vector<IGNode*>::iterator i = children.begin();
	while(i!=children.end()) {
		IGNode* node = *i;
		if(node->tag == tag) {
			i = children.erase(i);
			delete node;
		} else {
			++i;
		}
	}
}

void IGNode::removeAllChildren() {
	std::vector<IGNode*>::iterator i = children.begin();
	while(i!=children.end()) {
		IGNode* node = *i;
		i = children.erase(i);
		delete node;
	}
}

void IGNode::setZ(int _z) {
	z = _z;
	sorted = false;
}

void IGNode::display() {
	// make sure it's sorted first
	if(sorted == false) {
		std::sort(children.begin(), children.end(), IGNode::compareNodePredicate);
		sorted = true;
	}

	std::vector<IGNode*>::iterator i;
	for(i=children.begin(); i!=children.end(); ++i) {
		IGNode* node = *i;
		node->display();
		Iw2DSetColour(IGDistorter::getInstance()->colorWhiteInt);
	}
}

void IGNode::update() {
	std::vector<IGNode*>::iterator i;
	for(i=children.begin(); i!=children.end(); ++i) {
		IGNode* node = *i;
		node->update();
	}
}

bool IGNode::touch(s3ePointerTouchEvent* event) {
	std::vector<IGNode*>::iterator i;
	for(i=children.begin(); i!=children.end(); ++i) {
		IGNode* node = *i;
		if(node->touch(event)) {
			return true;
		}
	}
	return false;
}

bool IGNode::compareNodePredicate(IGNode* node1, IGNode* node2) {
	return (node1->z < node2->z);
}

bool IGNode::operator < (IGNode node) {
	return this->z < node.z;
}

