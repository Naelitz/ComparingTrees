// RBT.h
// Author: David Naelitz
// Written for EECS2510 Fall 2017
// Date: 3/25/2017
// Description: This is the header file for the red black tree. 

#pragma once
#include <string>
#include "RBTNode.h"

class RBT
{
public:
	RBT();
	~RBT();
	void Insert(std::string chWord);
	void Traverse();
	void Fixup(RBTNode* startNode);
	void RightRotate(RBTNode* z);
	void LeftRotate(RBTNode* z);
	int GetPointerChanges();
	int GetColorChanges();
	int GetComparisonCount();
	int GetNodeCount();
	int GetHeight();
private:
	RBTNode* Root;
	RBTNode* nil;
	int intPointerChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	int intColorChanges = 0;
	void Traversal(RBTNode* startNode, int height);
};

