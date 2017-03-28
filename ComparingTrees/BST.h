#pragma once
#include "BSTNode.h"

class BST
{
public:
	void Insert(std::string chWord);
	void Traverse();
	int GetPointerChanges();
	int GetComparisonCount();
	int GetNodeCount();
	BSTNode* Root;
	BST();
	~BST();
private:
	BSTNode* ptrCurrentNode;
	int intPointerChanges = 0;
	int intNodeCount = 0;
	int intComparisonCount = 0;
	int intHeight = 0;
	void Traversal(BSTNode* startNode);
};

