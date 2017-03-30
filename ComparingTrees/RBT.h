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
private:
	RBTNode* Root;
	RBTNode* nil;
	int intPointerChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	int intColorChanges = 0;
	void Traversal(RBTNode* startNode);
};

