#pragma once
#ifndef IG_NODE_H
#define IG_NODE_H

#include <vector>
#include <algorithm>
#include "s3e.h"

class IGNode {
public:
	std::vector<IGNode*> children;
	int tag; // to identify nodes
	int z; // to sort nodes
	int numChildren;

	// constructor and destructor
	IGNode();
	virtual ~IGNode();

	// manipulate the children
	void addChild(IGNode* node);
	IGNode* getChildByTag(int tag);
	void removeChildByTag(int tag);
	void removeAllChildren();
	void setZ(int _z);
	IGNode* parent;

	// display and update stuff
	virtual void display();
	virtual void update();
	
	// pass a touch to the scene, return true if handled
	virtual bool touch(s3ePointerTouchEvent* event);

	// operator overloaders (compares z)
	static bool compareNodePredicate(IGNode* node1, IGNode* node2);
	bool operator < (IGNode node);

private:
	bool sorted;
};

#endif // IG_NODE_H